/*
* Made by FeedCurrent IoT: https://www.feedcurrent.com
*
* Description:
* This Arduino program continuously reads 12 digital inputs (P0~P11)
* from a PCF8575 I/O expander and prints their states to the Serial Monitor
* in binary format (0 = ON, 1 = OFF).
*
* Pin Definitions:
* - SDA: GPIO 8
* - SCL: GPIO 18
* - PCF8575 I2C Address: 0x24
*/

#include <Arduino.h>
#include <Wire.h>
#include "PCF8575.h"

// I2C pin definitions
#define I2C_SDA 8
#define I2C_SCL 18

// PCF8575 object with I2C address 0x24
PCF8575 pcf8575_IN1(0x24);

void setup() {
    Serial.begin(115200);

    // Initialize I2C communication
    Wire.begin(I2C_SDA, I2C_SCL);

    // Initialize the PCF8575
    pcf8575_IN1.begin();

    Serial.println("Input state: 0=ON, 1=OFF");
}

void loop() {
    uint16_t state = 0;

    // Read the state of P0~P11
    for (int pin = 0; pin <= 11; pin++) {
        if (pcf8575_IN1.read(pin)) {
            state |= (1 << pin);
        }
    }

    // Print the state in binary format
    Serial.print("Input state: ");
    for (int pin = 11; pin >= 0; pin--) {
        Serial.print((state >> pin) & 1);
    }
    Serial.println();

    delay(500); // Polling delay
}