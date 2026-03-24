/*
* Made by FeedCurrent IoT: https://www.feedcurrent.com
*
* This program controls a 24-channel relay board via two PCF8575 I/O expanders.
* It toggles relay 24 every 2 seconds and prints its status via the serial port.
*
* Pin Definitions:
* - SDA: GPIO 8
* - SCL: GPIO 18
*
* Relay 24 is controlled through the first PCF8575 (I2C_ADDRESS_R1).
*/

#include <Wire.h>        // Include the Wire library for I2C communication
#include <PCF8575.h>     // Include the PCF8575 library to control the I/O expander

#define SDA 8            // Define the SDA pin
#define SCL 18           // Define the SCL pin
#define TOGGLE_DELAY 2000  // Define the toggle delay time (2 seconds)

// Set I2C addresses of the PCF8575 modules
#define I2C_ADDRESS_R1 0x25 // I2C address of the first PCF8575 module (for relays 9-24)
#define I2C_ADDRESS_R2 0x26 // I2C address of the second PCF8575 module (for relays 1-8)

PCF8575 pcf8575_R1(I2C_ADDRESS_R1); // Create a PCF8575 object for the first module (for relays 9-24)
PCF8575 pcf8575_R2(I2C_ADDRESS_R2); // Create a PCF8575 object for the second module (for relays 1-8)

bool relay24State = HIGH; // Initialize relay 24 state to OFF (assuming HIGH is OFF)

void setup() {
  // Initialize I2C communication
  Wire.begin(SDA, SCL); // SDA on GPIO 8, SCL on GPIO 18 (according to your board's configuration)
 
  // Initialize serial communication for debugging
  Serial.begin(115200);
  Serial.println("PCF8575 Relay 24 Toggle Program: Starting...");

  // Initialize the PCF8575 modules
  pcf8575_R1.begin();
  pcf8575_R2.begin();

  // Ensure that all relays are turned off initially (set all pins HIGH)
  for (int i = 0; i < 16; i++) {
    pcf8575_R1.write(i, HIGH); // Set relays 9-24 to OFF (assuming HIGH means OFF for relays)
    pcf8575_R2.write(i, HIGH); // Set relays 1-8 to OFF (assuming HIGH means OFF for relays)
  }
}

void loop() {
  // Toggle relay 24 state (relay 24 corresponds to pin 15 on pcf8575_R1)
  relay24State = !relay24State; // Toggle the state
  pcf8575_R1.write(15, relay24State); // Write the new state to relay 24

  // Print the current state of relay 24 to the serial port
  if (relay24State == LOW) {
    Serial.println("Relay 24 is ON");
  } else {
    Serial.println("Relay 24 is OFF");
  }

  // Wait for 2 seconds before toggling again
  delay(TOGGLE_DELAY);
}