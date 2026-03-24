/*
* Made by FeedCurrent IoT: https://www.feedcurrent.com
*
* This program reads 24 input states from two PCF8575 I/O expanders and
* controls a corresponding 24-channel relay module.
* When an input pin is LOW, the corresponding relay is turned ON (LOW means ON for the relay).
* When the input pin is HIGH, the corresponding relay is turned OFF.
*
* Pin Definitions:
* - SDA: GPIO 8
* - SCL: GPIO 18
* - Input I2C Address 1 (inputs 1-16): 0x24
* - Input/Relay I2C Address 2 (inputs 17-24 and relays 1-8): 0x26
* - Relay I2C Address 3 (relays 9-24): 0x25
*/

#include <Wire.h>        // I2C communication
#include <PCF8575.h>     // Library to control the PCF8575 I/O expander

// Define I2C pins
#define SDA 8            // SDA pin
#define SCL 18           // SCL pin

// I2C addresses for the PCF8575 modules
#define INPUT_I2C_ADDRESS_1 0x24   // I2C address for the first input PCF8575 module (inputs 1-16)
#define INPUT_RELAY_I2C_ADDRESS_2 0x26   // I2C address for inputs 17-24 and relays 1-8
#define RELAY_I2C_ADDRESS_3 0x25   // I2C address for relays 9-24

PCF8575 pcf8575_IN1(INPUT_I2C_ADDRESS_1);    // Create an object for the first input PCF8575 (inputs 1-16)
PCF8575 pcf8575_IN2(INPUT_RELAY_I2C_ADDRESS_2);    // Create an object for the second input PCF8575 (inputs 17-24 and relays 1-8)
PCF8575 pcf8575_RL(RELAY_I2C_ADDRESS_3);    // Create an object for the relay PCF8575 (relays 9-24)

void setup() {
  // Initialize I2C communication
  Wire.begin(SDA, SCL);
 
  // Initialize serial communication
  Serial.begin(115200);
 
  // Initialize input and relay modules
  pcf8575_IN1.begin();  // For inputs 1-16
  pcf8575_IN2.begin();  // For inputs 17-24 and relays 1-8
  pcf8575_RL.begin();   // For relays 9-24
 
  // Turn off all relays at the start (LOW means OFF)
  for (int i = 0; i < 8; i++) {
    pcf8575_IN2.write(i, LOW);  // Turn off relays 1-8
  }
  for (int i = 0; i < 16; i++) {
    pcf8575_RL.write(i, LOW);  // Turn off relays 9-24
  }

  Serial.println("System started: Input state controlling 24 relays");
}

void loop() {
  // Read and control relays 1-16
  for (int i = 0; i < 16; i++) {
    bool inputState = pcf8575_IN1.read(i);  // Read input i from the first input module
    if (inputState) {
      pcf8575_RL.write(i, HIGH);  // If input is HIGH, turn the corresponding relay OFF
    } else {
      pcf8575_RL.write(i, LOW);   // If input is LOW, turn the corresponding relay ON
    }
  }

  // Read and control relays 17-24 (shared with second input module)
  for (int i = 0; i < 8; i++) {
    bool inputState = pcf8575_IN2.read(i + 8);  // Read input 17-24 from the second input module (pins 8-15)
    if (inputState) {
      pcf8575_IN2.write(i, HIGH);  // If input is HIGH, turn the corresponding relay OFF (1-8)
    } else {
      pcf8575_IN2.write(i, LOW);   // If input is LOW, turn the corresponding relay ON (1-8)
    }
  }

  // Delay for 500 milliseconds
  delay(500);
}