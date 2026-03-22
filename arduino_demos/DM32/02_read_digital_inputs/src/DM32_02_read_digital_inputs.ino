#include <Wire.h>
#include "PCF8575.h"

#define I2C_SDA 8
#define I2C_SCL 18

PCF8575 pcf8575_IN1(0x22); // DI1–DI16
PCF8575 pcf8575_IN2(0x24); // DI17–DI32

uint8_t pin_order_dm16[16] = {
    8, 9, 10, 11, 12, 13, 14, 15,
    0, 1, 2, 3, 4, 5, 6, 7
};

uint8_t pin_order_ext[16] = {
    0, 1, 2, 3, 4, 5, 6, 7,
    8, 9, 10, 11, 12, 13, 14, 15
};

void setup() {
    Serial.begin(115200);
    Wire.begin(I2C_SDA, I2C_SCL);

    pcf8575_IN1.begin();
    pcf8575_IN2.begin();

    Serial.println("DI1–DI32 (0=ON 1=OFF)");
}

void loop() {
    Serial.print("DI1–DI32: ");

    // DI1–DI16
    for (int i = 0; i < 16; i++) {
        Serial.print(pcf8575_IN1.read(pin_order_dm16[i]));
        Serial.print(" ");
    }

    // DI17–DI32
    for (int i = 0; i < 16; i++) {
        Serial.print(pcf8575_IN2.read(pin_order_ext[i]));
        Serial.print(" ");
    }

    Serial.println();
    delay(500);
}