/*
* Made by FeedCurrent IoT: https://www.feedcurrent.com
*
* Description:
* This Arduino program reads the state of two 16-channel PCF8575 I/O expanders
* and prints the combined state of all 32 input pins to the Serial Monitor.
* Each pin state is represented as a bit in a 32-bit value (printed in binary format).
*
* Pin Definitions:
* - SDA: GPIO 48
* - SCL: GPIO 47
*
* PCF8575 I2C Addresses:
* - 0x24: input pins 1~16
* - 0x25: input pins 17~32
*/

#include "Arduino.h"
#include "PCF8575.h"
#include <Wire.h>

// Define I2C pins
#define I2C_SDA 48  // SDA pin
#define I2C_SCL 47  // SCL pin

// Create PCF8575 instances
PCF8575 pcf8575_IN1(0x24); // Inputs 1~16
PCF8575 pcf8575_IN2(0x25); // Inputs 17~32

void setup() {
    Serial.begin(115200);

    // Initialize I2C with custom SDA and SCL
    Wire.begin(I2C_SDA, I2C_SCL);

    // Initialize both PCF8575 expanders
    pcf8575_IN1.begin();
    pcf8575_IN2.begin();

    Serial.println("FeedCurrent F32 32 channel input state 0:ON  1:OFF");
}

void loop() {
    uint32_t inputState = 0; // 32-bit variable to store combined state

    // Read input pins 1~16
    for (int pin = 0; pin < 16; pin++) {
        if (pcf8575_IN1.read(pin)) {
            inputState |= (1UL << pin); // Set corresponding bit
        }
    }

    // Read input pins 17~32
    for (int pin = 0; pin < 16; pin++) {
        if (pcf8575_IN2.read(pin)) {
            inputState |= (1UL << (pin + 16)); // Set corresponding bit
        }
    }

    Serial.print("Input state: ");
    for (int i = 31; i >= 0; i--) {
        Serial.print(bitRead(inputState, i));
    }
    Serial.println();

    delay(500); // Wait for 500 milliseconds
}