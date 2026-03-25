/*
* Made by FeedCurrent IoT: https://www.feedcurrent.com
*
* This program controls 128 outputs using 8 PCF8575 I/O expanders.
* It sequentially turns on outputs 1 to 128, then turns them off from 128 to 1, in a loop.
*
* I2C Pin Definitions:
* - SDA: GPIO 48
* - SCL: GPIO 47
*
* PCF8575 Addresses:
* - Output  1~16   : 0x27
* - Output 17~32  : 0x26
* - Output 33~48  : 0x23
* - Output 49~64  : 0x22
* - Output 65~80  : 0x25
* - Output 81~96  : 0x24
* - Output 97~112 : 0x21
* - Output113~128 : 0x20
*
* Delay Time:
* - 200 milliseconds between switching outputs
*/

#include <Wire.h>        // Include the Wire library for I2C communication
#include <PCF8575.h>     // Include the PCF8575 library

#define SDA_PIN 48       // Define SDA pin
#define SCL_PIN 47       // Define SCL pin
#define DELAY_TIME 50   // Delay between operations in milliseconds

// Create PCF8575 objects for each chip
PCF8575 pcf_1(0x27); // output 1-16
PCF8575 pcf_2(0x26); // output 17-32
PCF8575 pcf_3(0x23); // output 33-48
PCF8575 pcf_4(0x22); // output 49-64
PCF8575 pcf_5(0x25); // output 65-80
PCF8575 pcf_6(0x24); // output 81-96
PCF8575 pcf_7(0x21); // output 97-112
PCF8575 pcf_8(0x20); // output 113-128

// Array of pointers to PCF8575 objects
PCF8575* pcfArray[8] = {
  &pcf_1, &pcf_2, &pcf_3, &pcf_4,
  &pcf_5, &pcf_6, &pcf_7, &pcf_8
};

void setup() {
  Wire.begin(SDA_PIN, SCL_PIN);  // Initialize I2C with specified pins
  Serial.begin(115200);
  Serial.println("PCF8575 128-Channel Output Control Starting...");

  // Initialize all PCF8575 modules and set all pins to HIGH (OFF)
  for (int i = 0; i < 8; i++) {
    pcfArray[i]->begin();
    for (int j = 0; j < 16; j++) {
      pcfArray[i]->write(j, HIGH);  // Turn off all outputs initially
    }
  }
}

void loop() {
  // Turn ON outputs from 1 to 128 (LOW)
  for (int channel = 0; channel < 128; channel++) {
    int chipIndex = channel / 16;        // Which PCF8575 (0 to 7)
    int pinIndex = channel % 16;         // Which pin on that PCF8575 (0 to 15)
    pcfArray[chipIndex]->write(pinIndex, LOW); // Turn ON the output
    delay(DELAY_TIME);
  }

  // Turn OFF outputs from 128 to 1 (HIGH)
  for (int channel = 127; channel >= 0; channel--) {
    int chipIndex = channel / 16;
    int pinIndex = channel % 16;
    pcfArray[chipIndex]->write(pinIndex, HIGH); // Turn OFF the output
    delay(DELAY_TIME);
  }
}