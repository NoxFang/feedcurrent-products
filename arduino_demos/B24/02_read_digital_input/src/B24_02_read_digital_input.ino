/*
 * Made by FeedCurrent IoT: https://www.feedcurrent.com
 *
 * Description:
 * This Arduino program reads the state of two 16-channel PCF8575 I/O expanders
 * and prints the state of all input pins (1-24) to the Serial Monitor.
 *
 * Pin Definitions:
 * - SDA: GPIO 8
 * - SCL: GPIO 18
 * - PCF8575 I2C Address: 0x22 for inputs 1-16, 0x25 for inputs 17-24
 */

#include "Arduino.h"
#include "PCF8575.h"

// Define I2C pins
#define I2C_SDA 8  // Define SDA pin
#define I2C_SCL 18 // Define SCL pin

// Set I2C addresses
PCF8575 pcf8575_IN1(0x22); // The I2C address of the first PCF8575 (inputs 1-16)
PCF8575 pcf8575_IN2(0x25); // The I2C address of the second PCF8575 (inputs 17-24)

void setup() {
    Serial.begin(115200);
    // Initialize I2C communication
    Wire.begin(I2C_SDA, I2C_SCL); // Initialize I2C with defined SDA and SCL pins
    // Initialize both PCF8575 modules
    pcf8575_IN1.begin();
    pcf8575_IN2.begin();
    Serial.println("FeedCurrent B24 24 channel input state 0:ON  1:OFF");
}

void loop() {
    if (pcf8575_IN1.read(8)==0) {Serial.print("DI1 state="); Serial.println("on");}
    if (pcf8575_IN1.read(9)==0) {Serial.print("DI2 state="); Serial.println("on");}
    if (pcf8575_IN1.read(10)==0) {Serial.print("DI3 state="); Serial.println("on");}
    if (pcf8575_IN1.read(11)==0) {Serial.print("DI4 state="); Serial.println("on");}
    if (pcf8575_IN1.read(12)==0) {Serial.print("DI5 state="); Serial.println("on");}
    if (pcf8575_IN1.read(13)==0) {Serial.print("DI6 state="); Serial.println("on");}
    if (pcf8575_IN1.read(14)==0) {Serial.print("DI7 state="); Serial.println("on");}
    if (pcf8575_IN1.read(15)==0) {Serial.print("DI8 state="); Serial.println("on");}
    if (pcf8575_IN1.read(0)==0) {Serial.print("DI9 state="); Serial.println("on");}
    if (pcf8575_IN1.read(1)==0) {Serial.print("DI10 state="); Serial.println("on");}
    if (pcf8575_IN1.read(2)==0) {Serial.print("DI11 state="); Serial.println("on");}
    if (pcf8575_IN1.read(3)==0) {Serial.print("DI12 state="); Serial.println("on");}
    if (pcf8575_IN1.read(4)==0) {Serial.print("DI13 state="); Serial.println("on");}
    if (pcf8575_IN1.read(5)==0) {Serial.print("DI14 state="); Serial.println("on");}
    if (pcf8575_IN1.read(6)==0) {Serial.print("DI15 state="); Serial.println("on");}
    if (pcf8575_IN1.read(7)==0) {Serial.print("DI16 state="); Serial.println("on");}
    if (pcf8575_IN2.read(0)==0) {Serial.print("DI17 state="); Serial.println("on");}
    if (pcf8575_IN2.read(1)==0) {Serial.print("DI18 state="); Serial.println("on");}
    if (pcf8575_IN2.read(2)==0) {Serial.print("DI19 state="); Serial.println("on");}
    if (pcf8575_IN2.read(3)==0) {Serial.print("DI20 state="); Serial.println("on");}
    if (pcf8575_IN2.read(4)==0) {Serial.print("DI21 state="); Serial.println("on");}
    if (pcf8575_IN2.read(5)==0) {Serial.print("DI22 state="); Serial.println("on");}
    if (pcf8575_IN2.read(6)==0) {Serial.print("DI23 state="); Serial.println("on");}
    if (pcf8575_IN2.read(7)==0) {Serial.print("DI24 state="); Serial.println("on");}
    delay(1000); // Delay 500ms
}
