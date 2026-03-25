/*
* Made by FeedCurrent IoT: https://www.feedcurrent.com
*
* This Arduino program reads 64 input channels from 4 PCF8575 modules on I2C Bus-2
* and controls 64 output channels on 4 PCF8575 modules on I2C Bus-1.
* When an input pin is pulled LOW (connected to GND), the corresponding output relay is turned ON (LOW).
* Otherwise, the relay is turned OFF (HIGH).
*
* I2C Bus-1 (Outputs):
* - SDA: GPIO 48
* - SCL: GPIO 47
* - Output1~16  : 0x25
* - Output17~32 : 0x24
* - Output33~48 : 0x21
* - Output49~64 : 0x20
*
* I2C Bus-2 (Inputs):
* - SDA: GPIO 12
* - SCL: GPIO 11
* - Input1~16   : 0x25
* - Input17~32  : 0x24
* - Input33~48  : 0x21
* - Input49~64  : 0x20
*/

#include <Wire.h>
#include <PCF8575.h>

// === Create two independent Wire objects ===
TwoWire I2C_Output = TwoWire(0);  // I2C Bus 1 - for output control
TwoWire I2C_Input  = TwoWire(1);  // I2C Bus 2 - for reading inputs

// === Output PCF8575 modules (connected to relays) ===
PCF8575 output_1(0x25, &I2C_Output);  // Output 1-16
PCF8575 output_2(0x24, &I2C_Output);  // Output 17-32
PCF8575 output_3(0x21, &I2C_Output);  // Output 33-48
PCF8575 output_4(0x20, &I2C_Output);  // Output 49-64

// === Input PCF8575 modules ===
PCF8575 input_1(0x25, &I2C_Input);    // Input 1-16
PCF8575 input_2(0x24, &I2C_Input);    // Input 17-32
PCF8575 input_3(0x21, &I2C_Input);    // Input 33-48
PCF8575 input_4(0x20, &I2C_Input);    // Input 49-64

// === Arrays to manage all input/output modules ===
PCF8575* inputArray[4]  = { &input_1, &input_2, &input_3, &input_4 };
PCF8575* outputArray[4] = { &output_1, &output_2, &output_3, &output_4 };

void setup() {
  Serial.begin(115200);
  Serial.println("FeedCurrent 64-Channel Input-Output Mapping Test");

  // Initialize I2C buses
  I2C_Output.begin(48, 47); // SDA: GPIO48, SCL: GPIO47
  I2C_Input.begin(12, 11);  // SDA: GPIO12, SCL: GPIO11

  // Initialize all PCF8575 modules
  for (int i = 0; i < 4; i++) {
    inputArray[i]->begin();
    outputArray[i]->begin();

    // Initially turn off all relays (set to HIGH)
    for (int j = 0; j < 16; j++) {
      outputArray[i]->write(j, HIGH);
    }
  }
}

void loop() {
  for (int chip = 0; chip < 4; chip++) {
    for (int pin = 0; pin < 16; pin++) {
      int globalPin = chip * 16 + pin;  // 0~63
      bool inputState = inputArray[chip]->read(pin);

      // 0 = Signal present (connected to GND), relay ON (output LOW)
      // 1 = No signal, relay OFF (output HIGH)
      outputArray[chip]->write(pin, inputState ? HIGH : LOW);
    }
  }

  delay(200); // Slight delay to avoid excessive reading
}