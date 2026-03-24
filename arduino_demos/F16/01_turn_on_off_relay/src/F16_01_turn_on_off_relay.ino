/*
* Made by FeedCurrent IoT: https://www.feedcurrent.com
*
* This program controls a 16-channel relay board via a PCF8575 I/O expander.
* It sequentially turns on each relay and then turns them off in a loop.
*
* Pin Definitions:
* - SDA: GPIO 8
* - SCL: GPIO 18
*
* Delay Time:
* - 200 milliseconds between switching relays
*/

#include <Wire.h>        // Include the Wire library for I2C communication
#include <PCF8575.h>     // Include the PCF8575 library to control the I/O expander

#define SDA 8            // Define the SDA pin
#define SCL 18           // Define the SCL pin
#define DELAY_TIME 200   // Define the delay time in milliseconds

// Set I2C address of the PCF8575 module
#define I2C_ADDRESS 0x25 // I2C address of the PCF8575 module

PCF8575 pcf8575_R1(I2C_ADDRESS); // Create a PCF8575 object with the specified I2C address

void setup() {
  // Initialize I2C communication
  Wire.begin(SDA, SCL); // SDA on GPIO 8, SCL on GPIO 18 (according to your board's configuration)
 
  // Initialize serial communication for debugging (optional)
  Serial.begin(115200);
  Serial.println("PCF8575 Relay Control: Starting...");

  // Initialize the PCF8575 module
  pcf8575_R1.begin();

  // Turn off all relays initially (set all pins HIGH)
  for (int i = 0; i < 16; i++) {
    pcf8575_R1.write(i, HIGH); // Set all relays to OFF (assuming HIGH means OFF for relays)
  }
}

void loop() {
  // Sequentially turn on each relay
  for (int i = 0; i < 16; i++) {
    pcf8575_R1.write(i, LOW);   // Turn on the relay at pin i (LOW means ON for the relay)
    delay(DELAY_TIME);          // Wait for DELAY_TIME milliseconds
  }

  // Sequentially turn off each relay
  for (int i = 0; i < 16; i++) {
    pcf8575_R1.write(i, HIGH);  // Turn off the relay at pin i (HIGH means OFF for the relay)
    delay(DELAY_TIME);          // Wait for DELAY_TIME milliseconds
  }
}