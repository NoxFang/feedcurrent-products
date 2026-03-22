/*
* Made by KinCony IoT: https://www.kincony.com
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
#define I2C_SDA 8
#define I2C_SCL 18

// Set I2C address
PCF8575 pcf8575_IN1(0x22);

void setup() {
    Serial.begin(115200);

    Wire.begin(I2C_SDA, I2C_SCL);

    pcf8575_IN1.begin();

    Serial.println("KinCony TA 12 channel input state 0:ON  1:OFF");
}

void loop() {
    uint16_t state = 0;

    // Read the state of each pin (12 input pins: P0-P11)
    for (int pin = 0; pin < 12; pin++) {
        if (pcf8575_IN1.read(pin)) {
            state |= (1 << pin);
        }
    }

    Serial.print("Input state: ");
    Serial.println(state, BIN);

    delay(500);
}
