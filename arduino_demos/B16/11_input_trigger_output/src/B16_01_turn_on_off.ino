/*
* Made by FeedCurrent IoT: https://www.feedcurrent.com
*
* This program reads 16 input states from a PCF8575 I/O expander and
* controls a corresponding 16-channel relay module. When an input pin
* is LOW, the corresponding relay is turned ON (LOW means ON for the relay).
* When the input pin is HIGH, the corresponding relay is turned OFF.
*
* Pin Definitions:
* - SDA: GPIO 8
* - SCL: GPIO 18
* - Input I2C Address: 0x24
* - Relay I2C Address: 0x25
*/

#include <Wire.h>        // I2C communication
#include <PCF8575.h>     // Library to control the PCF8575 I/O expander

// Define I2C pins
#define SDA 8           // SDA pin
#define SCL 18           // SCL pin

// I2C addresses
#define INPUT_I2C_ADDRESS 0x24   // I2C address for the input PCF8575 module
#define RELAY_I2C_ADDRESS 0x22   // I2C address for the relay PCF8575 module

PCF8575 pcf8575_IN(INPUT_I2C_ADDRESS);    // Create an object for the input PCF8575
PCF8575 pcf8575_RL(RELAY_I2C_ADDRESS);    // Create an object for the relay PCF8575

void setup() {
  // Initialize I2C communication
  Wire.begin(SDA, SCL);
 
  // Initialize serial communication
  Serial.begin(115200);
 
  // Initialize input and relay modules
  pcf8575_IN.begin();
  pcf8575_RL.begin();
 
  // Turn off all relays at the start
  for (int i = 0; i < 16; i++) {
    pcf8575_RL.write(i, LOW);  // Assuming relays are LOW when OFF, setting all relays to OFF initially
  }
 
  Serial.println("System started: Input state controlling 16 relays");
}

void loop() {
  uint16_t inputState = 0;

  // Read the state of 16 inputs
  for (int i = 0; i < 16; i++) {
    if (pcf8575_IN.read(i)) {
      inputState |= (1 << i);  // If input is HIGH, set the corresponding bit
    } else {
      inputState &= ~(1 << i); // Otherwise, clear the corresponding bit
    }
  }
 
  // Control the relays based on the input state
  for (int i = 0; i < 16; i++) {
    if (inputState & (1 << i)) {
      pcf8575_RL.write(i, HIGH);  // If input is HIGH, turn the relay OFF
    } else {
      pcf8575_RL.write(i, LOW);   // If input is LOW, turn the relay ON
    }
  }

  // Delay for 500 milliseconds
  delay(500);
}