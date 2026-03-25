/*
* Made by FeedCurrent IoT: https://www.feedcurrent.com
*
* Description:
* This Arduino program reads the state of 128 digital inputs using 8 PCF8575 I/O expanders.
* Each PCF8575 reads 16 input channels. The input states are printed to the Serial Monitor
* as binary strings grouped by chip.
*
* I2C Pin Definitions:
* - SDA: GPIO 12
* - SCL: GPIO 11
*
* PCF8575 Addresses:
* - Input  1~16   : 0x27
* - Input 17~32  : 0x26
* - Input 33~48  : 0x23
* - Input 49~64  : 0x22
* - Input 65~80  : 0x25
* - Input 81~96  : 0x24
* - Input 97~112 : 0x21
* - Input113~128 : 0x20
*
* Input Status Legend:
* - 0: ON (Active)
* - 1: OFF (Inactive / Pulled HIGH)
*/

#include <Wire.h>
#include <PCF8575.h>

// Define I2C pins
#define I2C_SDA 12
#define I2C_SCL 11

// Define PCF8575 I2C addresses
PCF8575 pcf_inputs[8] = {
  PCF8575(0x27), // Input 1-16
  PCF8575(0x26), // Input 17-32
  PCF8575(0x23), // Input 33-48
  PCF8575(0x22), // Input 49-64
  PCF8575(0x25), // Input 65-80
  PCF8575(0x24), // Input 81-96
  PCF8575(0x21), // Input 97-112
  PCF8575(0x20)  // Input 113-128
};

void setup() {
  Serial.begin(115200);
  Wire.begin(I2C_SDA, I2C_SCL);

  Serial.println("FeedCurrent F128 128 channel input state  0:ON  1:OFF");

  // Initialize all PCF8575 modules
  for (int i = 0; i < 8; i++) {
    pcf_inputs[i].begin();
  }
}

void loop() {
  // Iterate through all 8 chips
  for (int chip = 0; chip < 8; chip++) {
    Serial.print("Input ");
    Serial.print((chip * 16) + 1);
    Serial.print("~");
    Serial.print((chip + 1) * 16);
    Serial.print(": ");

    // Read and print the state of all 16 pins on current chip
    for (int pin = 0; pin < 16; pin++) {
      int state = pcf_inputs[chip].read(pin);
      Serial.print(state);
    }

    Serial.println();
  }

  Serial.println("--------------------------------------------------");
  delay(1000); // Delay 1 second between reads
}