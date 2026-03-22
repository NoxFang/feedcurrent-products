/*
* -----------------------------------------------------------------------------
* FeedCurrent DM16 16-Channel Digital Input Reader using PCF8575
*
* This Arduino sketch reads the state of 16 digital input channels from a
* PCF8575 I/O expander over I2C and prints their status to the serial monitor.
*
* Input logic:
*   - Input 0 = ON
*   - Input 1 = OFF (with pull-up logic)
*
* Hardware:
*   - PCF8575 I/O Expander (I2C Address: 0x22)
*   - Custom input pin mapping as defined below
*   - I2C SDA pin: GPIO8
*   - I2C SCL pin: GPIO18
*
* Author: FeedCurrent IoT
* Website: https://www.feedcurrent.com
* License: MIT License
* -----------------------------------------------------------------------------
*/

#include <Wire.h>
#include "PCF8575.h"

// Define I2C pins
#define I2C_SDA 8   // SDA pin
#define I2C_SCL 18  // SCL pin

// Set the I2C address for PCF8575
PCF8575 pcf8575_IN1(0x22); // 0x22 is the I2C address for the DM16 module

void setup() {
    Serial.begin(115200);

    // Initialize I2C with specified SDA and SCL pins
    Wire.begin(I2C_SDA, I2C_SCL);

    // Start communication with PCF8575 device
    pcf8575_IN1.begin();

    Serial.println("FeedCurrent DM16 16 channel input state 0:ON  1:OFF");
}

void loop() {
    // Define custom pin read order to match hardware mapping
    uint8_t pin_order[16] = {
        8, 9, 10, 11, 12, 13, 14, 15,
        0, 1, 2, 3, 4, 5, 6, 7
    };

    Serial.print("Input state: ");

    // Loop through all 16 pins and read their state
    for (int i = 0; i < 16; i++) {
        bool state = pcf8575_IN1.read(pin_order[i]); // Read pin state (HIGH or LOW)
        Serial.print(state); // Print state: 0 = ON, 1 = OFF
        Serial.print(" ");
    }

    Serial.println(); // Print new line
    delay(500);       // Wait for 500ms before next read
}