/*
* Made by FeedCurrent IoT: https://www.feedcurrent.com
*
* This program reads 32 input states from three PCF8575 I/O expanders and
* controls a corresponding 32-channel relay module.
* When an input pin is LOW, the corresponding relay is turned ON (LOW means ON for the relay).
* When the input pin is HIGH, the corresponding relay is turned OFF.
*
* Pin Definitions:
* - SDA: GPIO 8
* - SCL: GPIO 18

PCF8575:U27 (relay17-32) i2c address:0x25
PCF8575:U23 (DI1-16) i2c address:0x24
PCF8575:U49 i2c address: 0x26
  PCF8575(pin number0-7):DI17-24
  PCF8575(pin number8-11):relay13-16
  PCF8575(pin number12-15):relay9-12

PCF8575:U62 i2c address: 0x27
  PCF8575(pin number0-7):DI25-32
  PCF8575(pin number8-15):relay1-8
*/

#include <Wire.h>        // I2C communication
#include <PCF8575.h>     // Library to control the PCF8575 I/O expander

// Define I2C pins
#define SDA 8            // SDA pin
#define SCL 18           // SCL pin

// I2C addresses for the PCF8575 modules
#define INPUT_I2C_ADDRESS_1 0x24   
#define INPUT_RELAY_I2C_ADDRESS_2 0x26 
#define RELAY_I2C_ADDRESS_3 0x25 
#define INPUT_RELAY_I2C_ADDRESS_3 0x27   

PCF8575 pcf8575_IN1(INPUT_I2C_ADDRESS_1);   
PCF8575 pcf8575_IN2(INPUT_RELAY_I2C_ADDRESS_2);   
PCF8575 pcf8575_RL(RELAY_I2C_ADDRESS_3);   
PCF8575 pcf8575_IN3(INPUT_RELAY_I2C_ADDRESS_3);

void setup() {
  // Initialize I2C communication
  Wire.begin(SDA, SCL);
 
  // Initialize serial communication
  Serial.begin(115200);
 
  // Initialize input and relay modules
  pcf8575_IN1.begin(); 
  pcf8575_IN2.begin(); 
  pcf8575_IN3.begin();
  pcf8575_RL.begin(); 
 
  // Turn off all relays at the start (LOW means OFF)
  for (int i = 8; i < 16; i++) {
    pcf8575_IN2.write(i, HIGH);
  }
  for (int i = 0; i < 16; i++) {
    pcf8575_RL.write(i, HIGH);
  }
  for (int i = 8; i < 16; i++) {
    pcf8575_IN3.write(i, HIGH); 
  }
  Serial.println("System started: Input state controlling 24 relays");
}

void loop() {
    bool inputState;
    inputState = pcf8575_IN1.read(0);  // input1 control relay1
    if (inputState) {
      pcf8575_IN3.write(8, HIGH);  // If input is HIGH, turn the corresponding relay OFF
    } else {
      pcf8575_IN3.write(8, LOW);   // If input is LOW, turn the corresponding relay ON
    }
 
    inputState = pcf8575_IN1.read(1);  // input2 control relay2
    if (inputState) {
      pcf8575_IN3.write(9, HIGH);  // If input is HIGH, turn the corresponding relay OFF
    } else {
      pcf8575_IN3.write(9, LOW);   // If input is LOW, turn the corresponding relay ON
    }

    inputState = pcf8575_IN1.read(2);  // input3 control relay3
    if (inputState) {
      pcf8575_IN3.write(10, HIGH);  // If input is HIGH, turn the corresponding relay OFF
    } else {
      pcf8575_IN3.write(10, LOW);   // If input is LOW, turn the corresponding relay ON
    }

    inputState = pcf8575_IN1.read(3);  // input4 control relay4
    if (inputState) {
      pcf8575_IN3.write(11, HIGH);  // If input is HIGH, turn the corresponding relay OFF
    } else {
      pcf8575_IN3.write(11, LOW);   // If input is LOW, turn the corresponding relay ON
    }

    inputState = pcf8575_IN1.read(4);  // input5 control relay5
    if (inputState) {
      pcf8575_IN3.write(12, HIGH);  // If input is HIGH, turn the corresponding relay OFF
    } else {
      pcf8575_IN3.write(12, LOW);   // If input is LOW, turn the corresponding relay ON
    }

    inputState = pcf8575_IN1.read(5);  // input6 control relay6
    if (inputState) {
      pcf8575_IN3.write(13, HIGH);  // If input is HIGH, turn the corresponding relay OFF
    } else {
      pcf8575_IN3.write(13, LOW);   // If input is LOW, turn the corresponding relay ON
    }

    inputState = pcf8575_IN1.read(6);  // input7 control relay7
    if (inputState) {
      pcf8575_IN3.write(14, HIGH);  // If input is HIGH, turn the corresponding relay OFF
    } else {
      pcf8575_IN3.write(14, LOW);   // If input is LOW, turn the corresponding relay ON
    }

    inputState = pcf8575_IN1.read(7);  // input8 control relay8
    if (inputState) {
      pcf8575_IN3.write(15, HIGH);  // If input is HIGH, turn the corresponding relay OFF
    } else {
      pcf8575_IN3.write(15, LOW);   // If input is LOW, turn the corresponding relay ON
    }

    inputState = pcf8575_IN1.read(8);  // input9 control relay9
    if (inputState) {
      pcf8575_IN2.write(12, HIGH);  // If input is HIGH, turn the corresponding relay OFF
    } else {
      pcf8575_IN2.write(12, LOW);   // If input is LOW, turn the corresponding relay ON
    }

    inputState = pcf8575_IN1.read(9);  // input10 control relay10
    if (inputState) {
      pcf8575_IN2.write(13, HIGH);  // If input is HIGH, turn the corresponding relay OFF
    } else {
      pcf8575_IN2.write(13, LOW);   // If input is LOW, turn the corresponding relay ON
    }

    inputState = pcf8575_IN1.read(10);  // input11 control relay11
    if (inputState) {
      pcf8575_IN2.write(14, HIGH);  // If input is HIGH, turn the corresponding relay OFF
    } else {
      pcf8575_IN2.write(14, LOW);   // If input is LOW, turn the corresponding relay ON
    }

    inputState = pcf8575_IN1.read(11);  // input12 control relay12
    if (inputState) {
      pcf8575_IN2.write(15, HIGH);  // If input is HIGH, turn the corresponding relay OFF
    } else {
      pcf8575_IN2.write(15, LOW);   // If input is LOW, turn the corresponding relay ON
    }

    inputState = pcf8575_IN1.read(12);  // input13 control relay13
    if (inputState) {
      pcf8575_IN2.write(8, HIGH);  // If input is HIGH, turn the corresponding relay OFF
    } else {
      pcf8575_IN2.write(8, LOW);   // If input is LOW, turn the corresponding relay ON
    }

    inputState = pcf8575_IN1.read(13);  // input14 control relay14
    if (inputState) {
      pcf8575_IN2.write(9, HIGH);  // If input is HIGH, turn the corresponding relay OFF
    } else {
      pcf8575_IN2.write(9, LOW);   // If input is LOW, turn the corresponding relay ON
    }

    inputState = pcf8575_IN1.read(14);  // input15 control relay15
    if (inputState) {
      pcf8575_IN2.write(10, HIGH);  // If input is HIGH, turn the corresponding relay OFF
    } else {
      pcf8575_IN2.write(10, LOW);   // If input is LOW, turn the corresponding relay ON
    }

    inputState = pcf8575_IN1.read(15);  // input16 control relay16
    if (inputState) {
      pcf8575_IN2.write(11, HIGH);  // If input is HIGH, turn the corresponding relay OFF
    } else {
      pcf8575_IN2.write(11, LOW);   // If input is LOW, turn the corresponding relay ON
    }

    inputState = pcf8575_IN2.read(0);  // input17 control relay17
    if (inputState) {
      pcf8575_RL.write(0, HIGH);  // If input is HIGH, turn the corresponding relay OFF
    } else {
      pcf8575_RL.write(0, LOW);   // If input is LOW, turn the corresponding relay ON
    }

    inputState = pcf8575_IN2.read(1);  // input18 control relay18
    if (inputState) {
      pcf8575_RL.write(1, HIGH);  // If input is HIGH, turn the corresponding relay OFF
    } else {
      pcf8575_RL.write(1, LOW);   // If input is LOW, turn the corresponding relay ON
    }

    inputState = pcf8575_IN2.read(2);  // input19 control relay19
    if (inputState) {
      pcf8575_RL.write(2, HIGH);  // If input is HIGH, turn the corresponding relay OFF
    } else {
      pcf8575_RL.write(2, LOW);   // If input is LOW, turn the corresponding relay ON
    }

    inputState = pcf8575_IN2.read(3);  // input20 control relay20
    if (inputState) {
      pcf8575_RL.write(3, HIGH);  // If input is HIGH, turn the corresponding relay OFF
    } else {
      pcf8575_RL.write(3, LOW);   // If input is LOW, turn the corresponding relay ON
    }

    inputState = pcf8575_IN2.read(4);  // input21 control relay21
    if (inputState) {
      pcf8575_RL.write(4, HIGH);  // If input is HIGH, turn the corresponding relay OFF
    } else {
      pcf8575_RL.write(4, LOW);   // If input is LOW, turn the corresponding relay ON
    }

    inputState = pcf8575_IN2.read(5);  // input22 control relay22
    if (inputState) {
      pcf8575_RL.write(5, HIGH);  // If input is HIGH, turn the corresponding relay OFF
    } else {
      pcf8575_RL.write(5, LOW);   // If input is LOW, turn the corresponding relay ON
    }

    inputState = pcf8575_IN2.read(6);  // input23 control relay23
    if (inputState) {
      pcf8575_RL.write(6, HIGH);  // If input is HIGH, turn the corresponding relay OFF
    } else {
      pcf8575_RL.write(6, LOW);   // If input is LOW, turn the corresponding relay ON
    }

    inputState = pcf8575_IN2.read(7);  // input24 control relay24
    if (inputState) {
      pcf8575_RL.write(7, HIGH);  // If input is HIGH, turn the corresponding relay OFF
    } else {
      pcf8575_RL.write(7, LOW);   // If input is LOW, turn the corresponding relay ON
    }

    inputState = pcf8575_IN3.read(0);  // input25 control relay25
    if (inputState) {
      pcf8575_RL.write(8, HIGH);  // If input is HIGH, turn the corresponding relay OFF
    } else {
      pcf8575_RL.write(8, LOW);   // If input is LOW, turn the corresponding relay ON
    }

    inputState = pcf8575_IN3.read(1);  // input26 control relay26
    if (inputState) {
      pcf8575_RL.write(9, HIGH);  // If input is HIGH, turn the corresponding relay OFF
    } else {
      pcf8575_RL.write(9, LOW);   // If input is LOW, turn the corresponding relay ON
    }

    inputState = pcf8575_IN3.read(2);  // input27 control relay27
    if (inputState) {
      pcf8575_RL.write(10, HIGH);  // If input is HIGH, turn the corresponding relay OFF
    } else {
      pcf8575_RL.write(10, LOW);   // If input is LOW, turn the corresponding relay ON
    }

    inputState = pcf8575_IN3.read(3);  // input28 control relay28
    if (inputState) {
      pcf8575_RL.write(11, HIGH);  // If input is HIGH, turn the corresponding relay OFF
    } else {
      pcf8575_RL.write(11, LOW);   // If input is LOW, turn the corresponding relay ON
    }

    inputState = pcf8575_IN3.read(4);  // input29 control relay29
    if (inputState) {
      pcf8575_RL.write(12, HIGH);  // If input is HIGH, turn the corresponding relay OFF
    } else {
      pcf8575_RL.write(12, LOW);   // If input is LOW, turn the corresponding relay ON
    }

    inputState = pcf8575_IN3.read(5);  // input30 control relay30
    if (inputState) {
      pcf8575_RL.write(13, HIGH);  // If input is HIGH, turn the corresponding relay OFF
    } else {
      pcf8575_RL.write(13, LOW);   // If input is LOW, turn the corresponding relay ON
    }

    inputState = pcf8575_IN3.read(6);  // input31 control relay31
    if (inputState) {
      pcf8575_RL.write(14, HIGH);  // If input is HIGH, turn the corresponding relay OFF
    } else {
      pcf8575_RL.write(14, LOW);   // If input is LOW, turn the corresponding relay ON
    }

    inputState = pcf8575_IN3.read(7);  // input32 control relay32
    if (inputState) {
      pcf8575_RL.write(15, HIGH);  // If input is HIGH, turn the corresponding relay OFF
    } else {
      pcf8575_RL.write(15, LOW);   // If input is LOW, turn the corresponding relay ON
    }

  // Delay for 500 milliseconds
  delay(500);
}