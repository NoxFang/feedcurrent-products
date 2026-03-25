/*
* Made by FeedCurrent IoT: https://www.feedcurrent.com
*
* This program controls a 32-channel relay board via two PCF8575 I/O expanders.
* It sequentially turns on each relay (1~32) and then turns them off in a loop.
*
* Pin Definitions:
* - SDA: GPIO 48
* - SCL: GPIO 47
*
* PCF8575 I2C Addresses:
* - 0x20: controls relays 1~16
* - 0x21: controls relays 17~32
*
* Delay Time:
* - 200 milliseconds between switching relays
*/

#include <Wire.h>        // Include the Wire library for I2C communication
#include <PCF8575.h>     // Include the PCF8575 library to control the I/O expander

#define SDA_PIN 48           // Define the SDA pin
#define SCL_PIN 47           // Define the SCL pin
#define DELAY_TIME 200       // Define the delay time in milliseconds

// Set I2C addresses of the PCF8575 modules
#define I2C_ADDRESS1 0x20    // PCF8575 for relays 1~16
#define I2C_ADDRESS2 0x21    // PCF8575 for relays 17~32

// Create PCF8575 objects for each module
PCF8575 pcf8575_R1(I2C_ADDRESS1); // For relays 1~16
PCF8575 pcf8575_R2(I2C_ADDRESS2); // For relays 17~32

void setup() {
  // Initialize I2C communication
  Wire.begin(SDA_PIN, SCL_PIN);

  // Initialize serial communication for debugging (optional)
  Serial.begin(115200);
  Serial.println("PCF8575 32-Channel Relay Control: Starting...");

  // Initialize both PCF8575 modules
  pcf8575_R1.begin();
  pcf8575_R2.begin();

  // Turn off all relays initially (set all pins HIGH)
  for (int i = 0; i < 16; i++) {
    pcf8575_R1.write(i, HIGH); // Relays 1~16
    pcf8575_R2.write(i, HIGH); // Relays 17~32
  }
}

void loop() {
  // Sequentially turn on each relay (1~32)
  for (int i = 0; i < 32; i++) {
    if (i < 16) {
      pcf8575_R1.write(i, LOW);  // Turn on relay 1~16
    } else {
      pcf8575_R2.write(i - 16, LOW); // Turn on relay 17~32
    }
    delay(DELAY_TIME);
  }

  // Sequentially turn off each relay (1~32)
  for (int i = 0; i < 32; i++) {
    if (i < 16) {
      pcf8575_R1.write(i, HIGH); // Turn off relay 1~16
    } else {
      pcf8575_R2.write(i - 16, HIGH); // Turn off relay 17~32
    }
    delay(DELAY_TIME);
  }
}