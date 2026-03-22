#include <Adafruit_PCF8574.h>
#include <HardwareSerial.h>

// Define Modbus RTU frame format constants
#define MODBUS_READ_COILS 0x01
#define MODBUS_READ_REGISTERS 0x03
#define MODBUS_WRITE_SINGLE_REGISTER 0x06
#define MODBUS_WRITE_MULTIPLE_REGISTERS 0x10

/* Example for 16 input buttons that are connected from the GPIO expander pins to ground.
* Note the buttons must be connected with the other side of the switch to GROUND. There is
* a built in pull-up 'resistor' on each input, but no pull-down resistor capability.
*/

#define DM_NUMS 8 


#define SDA_PIN 8
#define SCL_PIN 18
#define ADDRESS_PCF8574     0x24   ////A2 A1 A0 :100 = 0x20+4

#define ST_RX   4 ////ESP32_RCV
#define ST_TX   6 ///ESP32_SEND
typedef enum{KEY_RELEASE=0,KEY_SHORT_PRESSED,KEY_LONG_PRESSED}KEY_STATUS;

typedef struct{
  uint8_t key_index;
  KEY_STATUS key_status;
  long key_time_start;
  long key_time_rec;
  long key_press_time;
  int16_t key_press_cnt; ////Send serial data once every 100 ms
  int16_t key_press_cnt_old;
  float current_light; ///Percentage of 0–4095
}KEY_PRESS_PROP;

KEY_PRESS_PROP key_press_prop[16] = {0};


Adafruit_PCF8574 pcf;
HardwareSerial myst_serial(1);

TwoWire myI2c = TwoWire(0);
ushort dm_num = DM_NUMS;

// Modbus CRC16 Calculation function
uint16_t modbus_crc16(uint8_t *data, uint16_t length) {
  uint16_t crc = 0xFFFF;
 
  for (uint16_t i = 0; i < length; i++) {
    crc ^= data[i];
    for (uint8_t j = 0; j < 8; j++) {
      if (crc & 0x0001) {
        crc = (crc >> 1) ^ 0xA001;
      } else {
        crc = crc >> 1;
      }
    }
  }
  return crc;
}

/**
* Send a Modbus RTU frame
*
* @param serial HardwareSerial object
* @param address Slave address (1-247)
* @param function function code
* @param data
* @param dataLen
*/
void send_modbus_frame(HardwareSerial &serial, uint8_t address, uint8_t function,
                      const uint8_t *data, uint16_t dataLen) {
  // Create a transmit buffer
  uint16_t totalLen = 1 + 1 + dataLen + 2; // address + function code + data + CRC
  uint8_t buffer[totalLen];
 
  buffer[0] = address;
  buffer[1] = function;
 
  memcpy(&buffer[2], data, dataLen);
 
  uint16_t crc = modbus_crc16(buffer, 2 + dataLen);
 
  // Add CRC (low byte first)
  buffer[2 + dataLen] = crc & 0xFF;      // CRC low byte
  buffer[3 + dataLen] = (crc >> 8) & 0xFF; // CRC high byte
 
  // Send the complete frame
  for (uint16_t i = 0; i < totalLen; i++) {
    serial.write(buffer[i]);
  }
 
  // Flush the transmit buffer to ensure all data is sent
  serial.flush();
}

// Encapsulate commonly used Modbus functions

/**
* Send a Read Holding Registers request
*
* @param serial
* @param address
* @param startReg
* @param numRegs
*/
void modbus_read_registers(HardwareSerial &serial, uint8_t address,
                          uint16_t startReg, uint16_t numRegs) {
  uint8_t data[4];
 
 
  data[0] = (startReg >> 8) & 0xFF; // High byte of the register address
  data[1] = startReg & 0xFF;        // Low byte of the register address
  data[2] = (numRegs >> 8) & 0xFF;  // High byte of the register count
  data[3] = numRegs & 0xFF;         // Low byte of the register count
 
  send_modbus_frame(serial, address, MODBUS_READ_REGISTERS, data, sizeof(data));
}

/**
*
* @param serial
* @param address
* @param regAddress
* @param value
*/
void modbus_write_single_register(HardwareSerial &serial, uint8_t address,
                                uint16_t regAddress, uint16_t value) {
  uint8_t data[4];
 
  data[0] = (regAddress >> 8) & 0xFF; // High byte of the register address
  data[1] = regAddress & 0xFF;        // Low byte of the register address
  data[2] = (value >> 8) & 0xFF;      // High byte of the data
  data[3] = value & 0xFF;             // Low byte of the
 
  send_modbus_frame(serial, address, MODBUS_WRITE_SINGLE_REGISTER, data, sizeof(data));
}

/**
*
* @param serial
* @param address
* @param startReg
* @param values
* @param numRegs
*/
void modbus_write_multiple_registers(HardwareSerial &serial, uint8_t address,
                                   uint16_t startReg, const uint16_t *values,
                                   uint16_t numRegs) {

  uint8_t byteCount = numRegs * 2;
  uint8_t data[5 + byteCount];
 

  data[0] = (startReg >> 8) & 0xFF; 
  data[1] = startReg & 0xFF;         
  data[2] = (numRegs >> 8) & 0xFF;   
  data[3] = numRegs & 0xFF;       
  data[4] = byteCount;             
 

  for (uint8_t i = 0; i < numRegs; i++) {
    data[5 + i*2] = (values[i] >> 8) & 0xFF;   
    data[6 + i*2] = values[i] & 0xFF;         
  }
 
  send_modbus_frame(serial, address, MODBUS_WRITE_MULTIPLE_REGISTERS, data, sizeof(data));
}

void setup() {
  Serial.begin(115200);
  myI2c.begin(SDA_PIN,SCL_PIN,100000);
  myst_serial.begin(115200,SERIAL_8N1,ST_RX,ST_TX);///RXPIN FIRST

  while (!Serial) { delay(10); }
  Serial.println("Adafruit PCF8574 button read test");

  if (!pcf.begin(ADDRESS_PCF8574, &myI2c)) {
    Serial.println("err:DMxx Couldn't find PCF8574!");
    while (1);
  }
  else Serial.println("Find PCF8574!");

   

  for (uint8_t p=0; p<DM_NUMS; p++) {
    pcf.pinMode(p, INPUT_PULLUP);
   
    key_press_prop[p].key_index = p+1;
    key_press_prop[p].key_status = KEY_RELEASE;
    key_press_prop[p].key_press_time = 0;
  }

  Serial.println("Now, starting!");


}



static uint16_t input_value_old[2] = {0xff,0xff};
uint16_t input_value[2] = {0} ;
int8_t current_operator_key = -1;
int8_t key_index = -1,key_index_last = -1;
int16_t key_press_cnt_old = 0;
uint16_t write_value=0;

static int8_t get_key_press(int8_t chip,uint16_t key_value)
{
  if(key_value == 0xff || key_value == 0) return -1;

  for(int16_t i=0;i<16;i++)
  {
    if((key_value & (1<<i) ) == 0)  return (chip==0)?i:i+16;
  }
}

static uint16_t getKeycode()
{
  uint16_t input_value = 0,tmp_value;
  uint8_t h_value = 0 ,l_value = 0;
  tmp_value = pcf.digitalReadByte();
  //h_value = tmp_value>>8;
// l_value = tmp_value&0xff;
  //input_value = (l_value<<8 ) | h_value;
  input_value = tmp_value;

  return input_value;
}



static void checkKeyPress(int8_t chip);

static uint16_t key_old_arr[2] = {0};

void loop() {

  input_value[0] = getKeycode();   
  if(key_old_arr[0] != input_value[0])
  {
    key_old_arr[0] = input_value[0];
    Serial.printf("input0:%d\r\n",input_value[0]);
  }
 
  checkKeyPress(0);


  delay(10); // a short debounce delay
}

static void checkKeyPress(int8_t chip)
{
  uint8_t start_index = (chip==0)?0:16;
  if(input_value_old[chip] != input_value[chip])
  {
    input_value_old[chip] = input_value[chip];
    if(input_value[chip] == 0xff)
    {
      Serial.printf("key is released!");
       
      current_operator_key = -1;
      key_index_last = key_index = -1;

      for (uint8_t p=start_index; p<8+start_index; p++) ///all key status init.
      {
        key_press_prop[p].key_index = p+1;
        key_press_prop[p].key_status = KEY_RELEASE;
        key_press_prop[p].key_time_start = 0;
        key_press_prop[p].key_press_time = 0;
        key_press_prop[p].key_time_rec = 0;
        key_press_prop[p].key_press_cnt = 0;
        key_press_prop[p].key_press_cnt_old = 0;
      }
    }
    else ///key press
    {
      //Serial.printf("input_value = %04X \r\n",input_value);
      key_index = get_key_press(chip,input_value[chip]);
      if(key_index >= 0)
      {
        key_index_last = key_index;
        Serial.printf("key %02d # is pressed! \r\n",key_index+1);
        current_operator_key = key_index;
        key_press_prop[current_operator_key].key_status = KEY_SHORT_PRESSED;
        key_press_prop[current_operator_key].key_time_start = millis();
        key_press_prop[current_operator_key].key_press_time = 0;
      }
    }
  }
  else
  {
    if(input_value[chip] != 0xff) ///LONG PRESS!
    {
      //Serial.printf("key long pressed! \r\n");

      key_index = get_key_press(chip,input_value[chip]);
      if(key_index >= 0 && key_index_last == key_index)
      {
        //Serial.printf("key long pressed! key_index = %d\r\n",key_index);

        current_operator_key = key_index;
        key_press_prop[current_operator_key].key_status = KEY_LONG_PRESSED;
        key_press_prop[current_operator_key].key_time_rec = millis();
        key_press_prop[current_operator_key].key_press_time = key_press_prop[current_operator_key].key_time_rec - key_press_prop[current_operator_key].key_time_start;
        key_press_prop[current_operator_key].key_press_cnt = (key_press_prop[current_operator_key].key_press_time % 4080 ) / 100; ////100MS发一次

        //Serial.printf("key long time = %d, cnt = %d \r\n",key_press_prop[current_operator_key].key_press_time,key_press_prop[current_operator_key].key_press_cnt);

        if(key_press_prop[current_operator_key].key_press_cnt_old != key_press_prop[current_operator_key].key_press_cnt)
        {
          key_press_prop[current_operator_key].key_press_cnt_old = key_press_prop[current_operator_key].key_press_cnt;
          /////send st_tx information.
          key_press_prop[current_operator_key].current_light = (float)key_press_prop[current_operator_key].key_press_cnt * 100.0f;
          write_value = (uint16_t) key_press_prop[current_operator_key].current_light;

          Serial.printf("key_long_press_time = %d, current_light = %d \r\n",key_press_prop[current_operator_key].key_press_time,write_value);

          modbus_write_multiple_registers(myst_serial,1,4000+current_operator_key,&write_value,1);


        }
      }
    }
  }

}