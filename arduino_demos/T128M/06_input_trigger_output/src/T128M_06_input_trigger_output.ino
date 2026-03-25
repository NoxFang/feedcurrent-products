/*
* Made by FeedCurrent IoT: https://www.feedcurrent.com
*
* This Arduino program reads 128 input channels from 8 PCF8575 modules on I2C Bus-2
* and controls 128 output channels on 8 PCF8575 modules on I2C Bus-1.
* When an input pin is pulled LOW (connected to GND), the corresponding output relay is turned ON (LOW).
* Otherwise, the relay is turned OFF (HIGH).
*
* I2C Bus-1 (Outputs):
* - SDA: GPIO 48
* - SCL: GPIO 47
* - Output1~16    : 0x27
* - Output17~32   : 0x26
* - Output33~48   : 0x23
* - Output49~64   : 0x22
* - Output65~80   : 0x25
* - Output81~96   : 0x24
* - Output97~112  : 0x21
* - Output113~128 : 0x20
*
* I2C Bus-2 (Inputs):
* - SDA: GPIO 12
* - SCL: GPIO 11
* - Input1~16     : 0x27
* - Input17~32    : 0x26
* - Input33~48    : 0x23
* - Input49~64    : 0x22
* - Input65~80    : 0x25
* - Input81~96    : 0x24
* - Input97~112   : 0x21
* - Input113~128  : 0x20
*/

#include <Wire.h>
#include <PCF8575.h>

// Define two I2C buses for independent input/output communication
TwoWire I2C_Output = TwoWire(0); // Bus 1 - Outputs
TwoWire I2C_Input  = TwoWire(1); // Bus 2 - Inputs

// === Output PCF8575 instances ===
PCF8575 output_1(0x27, &I2C_Output);  // Output 1~16
PCF8575 output_2(0x26, &I2C_Output);  // Output 17~32
PCF8575 output_3(0x23, &I2C_Output);  // Output 33~48
PCF8575 output_4(0x22, &I2C_Output);  // Output 49~64
PCF8575 output_5(0x25, &I2C_Output);  // Output 65~80
PCF8575 output_6(0x24, &I2C_Output);  // Output 81~96
PCF8575 output_7(0x21, &I2C_Output);  // Output 97~112
PCF8575 output_8(0x20, &I2C_Output);  // Output 113~128

// === Input PCF8575 instances ===
PCF8575 input_1(0x27, &I2C_Input);  // Input 1~16
PCF8575 input_2(0x26, &I2C_Input);  // Input 17~32
PCF8575 input_3(0x23, &I2C_Input);  // Input 33~48
PCF8575 input_4(0x22, &I2C_Input);  // Input 49~64
PCF8575 input_5(0x25, &I2C_Input);  // Input 65~80
PCF8575 input_6(0x24, &I2C_Input);  // Input 81~96
PCF8575 input_7(0x21, &I2C_Input);  // Input 97~112
PCF8575 input_8(0x20, &I2C_Input);  // Input 113~128

// === Create arrays for easy loop access ===
PCF8575* inputArray[8] = {
  &input_1, &input_2, &input_3, &input_4,
  &input_5, &input_6, &input_7, &input_8
};

PCF8575* outputArray[8] = {
  &output_1, &output_2, &output_3, &output_4,
  &output_5, &output_6, &output_7, &output_8
};

void setup() {
  Serial.begin(115200);
  Serial.println("FeedCurrent 128-Channel Input-Output Mapping Test");

  // Initialize both I2C buses
  I2C_Output.begin(48, 47);  // SDA: GPIO48, SCL: GPIO47
  I2C_Input.begin(12, 11);   // SDA: GPIO12, SCL: GPIO11

  // Initialize all PCF8575 chips and set initial output states
  for (int i = 0; i < 8; i++) {
    inputArray[i]->begin();   // Initialize input chip
    outputArray[i]->begin();  // Initialize output chip

    // Set all output pins HIGH (relay OFF)
    for (int j = 0; j < 16; j++) {
      outputArray[i]->write(j, HIGH);
    }
  }
}

void loop() {
  for (int chip = 0; chip < 8; chip++) {
    for (int pin = 0; pin < 16; pin++) {
      bool inputState = inputArray[chip]->read(pin);

      // If input is LOW (button pressed or contact closed), turn ON relay (set output LOW)
      // Otherwise, turn OFF relay (set output HIGH)
      outputArray[chip]->write(pin, inputState ? HIGH : LOW);
    }
  }

  delay(200); // Delay to prevent I2C bus flooding
}