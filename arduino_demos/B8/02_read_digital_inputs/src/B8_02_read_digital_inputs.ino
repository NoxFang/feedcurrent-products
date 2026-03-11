/*
* Made by FeedCurrent IoT: https://www.feedcurrent.com
*
* Description:
* This Arduino program reads the state of a 16-channel PCF8575 I/O expander
* and prints the state of all input pins to the Serial Monitor. The state of
* each pin is represented as a bit in a 16-bit value, where each bit corresponds
* to an input pin. The program prints the input state in binary format.
*
* Pin Definitions:
* - SDA: GPIO 8
* - SCL: GPIO 18
* - PCF8575 I2C Address: 0x22
*/

#include "Arduino.h"
#include "PCF8575.h"

// Define I2C pins
#define I2C_SDA 8  // Define SDA pin
#define I2C_SCL 18  // Define SCL pin

// Set I2C address
PCF8575 pcf8575_IN1(0x22); // The I2C address of the PCF8575

void setup() {
    Serial.begin(115200);

    // Initialize I2C communication
    Wire.begin(I2C_SDA, I2C_SCL); // Initialize I2C with defined SDA and SCL pins

    pcf8575_IN1.begin(); // Initialize the PCF8575

    Serial.println("B8 Controller 8 channel input state 0:ON  1:OFF");
}

void loop() {
    uint16_t state = 0;

    // Read the state of each pin (assuming 16 pins)
    for (int pin = 0; pin < 8; pin++) {
        if (pcf8575_IN1.read(pin)) {
            state |= (1 << pin); // Set the bit for the active pin
        }
    }

    Serial.print("Input state: ");
    Serial.println(state, BIN); // Print the state of inputs in binary

    delay(500); // Delay 500ms
}