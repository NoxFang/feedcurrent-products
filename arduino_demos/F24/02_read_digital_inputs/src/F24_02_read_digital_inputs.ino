/*
* Made by FeedCurrent IoT: https://www.feedcurrent.com
*
* Description:
* This Arduino program reads the state of two 16-channel PCF8575 I/O expanders
* and prints the state of all input pins (1-24) to the Serial Monitor. The state of
* each pin is represented as a bit in a 24-bit value, where each bit corresponds
* to an input pin. The program prints the input state in binary format.
*
* Pin Definitions:
* - SDA: GPIO 8
* - SCL: GPIO 18
* - PCF8575 I2C Address: 0x24 for inputs 1-16, 0x26 for inputs 17-24
*/

#include "Arduino.h"
#include "PCF8575.h"

// Define I2C pins
#define I2C_SDA 8  // Define SDA pin
#define I2C_SCL 18  // Define SCL pin

// Set I2C addresses
PCF8575 pcf8575_IN1(0x24); // The I2C address of the first PCF8575 (inputs 1-16)
PCF8575 pcf8575_IN2(0x26); // The I2C address of the second PCF8575 (inputs 17-24)

void setup() {
    Serial.begin(115200);

    // Initialize I2C communication
    Wire.begin(I2C_SDA, I2C_SCL); // Initialize I2C with defined SDA and SCL pins

    // Initialize both PCF8575 modules
    pcf8575_IN1.begin();
    pcf8575_IN2.begin();

    Serial.println("FeedCurrent F24 24 channel input state 0:ON  1:OFF");
}

void loop() {
    uint32_t state = 0; // Use a 32-bit variable to store the state of all 24 pins

    // Read the state of each pin from the first PCF8575 (inputs 1-16)
    for (int pin = 0; pin < 16; pin++) {
        if (pcf8575_IN1.read(pin)) {
            state |= (1UL << pin); // Set the bit for the active pin (inputs 1-16)
        }
    }

    // Read the state of each pin from the second PCF8575 (inputs 17-24, corresponding to pins 0-7)
    for (int pin = 0; pin < 8; pin++) {
        if (pcf8575_IN2.read(pin)) {
            state |= (1UL << (pin + 16)); // Set the bit for the active pin (inputs 17-24)
        }
    }

    // Print the state of all 24 inputs in binary format
    Serial.print("Input state: ");
    Serial.println(state, BIN); // Print the state of inputs in binary

    delay(500); // Delay 500ms
}