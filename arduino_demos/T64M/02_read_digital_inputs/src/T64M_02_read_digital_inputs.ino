/*
* Made by FeedCurrent IoT: https://www.feedcurrent.com
*
* Description:
* This Arduino program reads the state of 64 input channels using 4 PCF8575 I/O expanders
* and prints the state of all input pins to the Serial Monitor. Each input state is printed
* in binary (0 = ON, 1 = OFF), grouped by 16 bits per chip.
*
* I2C Pin Definitions:
* - SDA: GPIO 12
* - SCL: GPIO 11
*
* PCF8575 Addresses:
* - Input  1~16 : 0x25
* - Input 17~32: 0x24
* - Input 33~48: 0x21
* - Input 49~64: 0x20
*/

#include <Wire.h>
#include <PCF8575.h>

// Define I2C pins
#define SDA_PIN 12
#define SCL_PIN 11

// Create PCF8575 objects
PCF8575 pcf_1(0x25); // Input  1-16
PCF8575 pcf_2(0x24); // Input 17-32
PCF8575 pcf_3(0x21); // Input 33-48
PCF8575 pcf_4(0x20); // Input 49-64

// Array of PCF8575 pointers
PCF8575* pcfArray[4] = { &pcf_1, &pcf_2, &pcf_3, &pcf_4 };

void setup() {
  Serial.begin(115200);
  Wire.begin(SDA_PIN, SCL_PIN); // Initialize I2C

  // Initialize each PCF8575
  for (int i = 0; i < 4; i++) {
    pcfArray[i]->begin();
  }

  Serial.println("KinCony F64 64 channel input state  0:ON  1:OFF");
}

void loop() {
  Serial.println("Reading Inputs...");

  for (int chip = 0; chip < 4; chip++) {
    uint16_t state = 0;

    // Read 16 input pins per PCF8575
    for (int pin = 0; pin < 16; pin++) {
      if (pcfArray[chip]->read(pin)) {
        state |= (1 << pin); // Bit = 1 means OFF (no signal), 0 means ON
      }
    }

    // Display result
    Serial.print("Input ");
    Serial.print(chip * 16 + 1);
    Serial.print("~");
    Serial.print((chip + 1) * 16);
    Serial.print(": ");
    for (int b = 15; b >= 0; b--) {
      Serial.print(bitRead(state, b));
    }
    Serial.println();
  }

  Serial.println(); // Blank line between readings
  delay(500);       // Wait 500ms before next read
}