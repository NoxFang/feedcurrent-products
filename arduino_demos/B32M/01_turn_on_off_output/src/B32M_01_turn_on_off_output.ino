/*
 * Made by FeedCurrent IoT: https://www.feedcurrent.com
 *
 * Description:
 * This Arduino program demonstrates how to control the 32 MOSFET outputs
 * on the B32M board via the PCF8575 output chips. It sequentially turns
 * on each output (pins 0-31) and then turns them off in a loop.
 *
 * Pin Definitions:
 * - SDA: GPIO 8
 * - SCL: GPIO 18
 * - PCF8575 I2C Addresses: 0x26 (outputs 1-8, 25-32), 0x25 (outputs 9-16), 0x24 (outputs 17-24)
 */

#include "Arduino.h"
#include "PCF8575.h"

// Define I2C pins
#define I2C_SDA 8
#define I2C_SCL 18

// Set I2C addresses for output PCF8575 chips
PCF8575 pcf8575_out1(0x26); // Outputs 1-8 (pins 8-15), 25-32 (pins 0-7)
PCF8575 pcf8575_out2(0x25); // Outputs 9-16 (pins 8-15)
PCF8575 pcf8575_out3(0x24); // Outputs 17-24 (pins 0-7)

void setup() {
    Serial.begin(115200);
    delay(1000);
    
    Serial.println("B32M - 32 Channel Output Test");
    Serial.println("Initializing I2C...");
    
    // Initialize I2C communication
    Wire.begin(I2C_SDA, I2C_SCL);
    
    // Initialize all PCF8575 modules
    if (!pcf8575_out1.begin()) {
        Serial.println("Failed to initialize PCF8575 at 0x26");
    }
    if (!pcf8575_out2.begin()) {
        Serial.println("Failed to initialize PCF8575 at 0x25");
    }
    if (!pcf8575_out3.begin()) {
        Serial.println("Failed to initialize PCF8575 at 0x24");
    }
    
    Serial.println("Initialization complete!");
    Serial.println("Starting output test sequence...");
}

void loop() {
    // Turn on outputs 1-8 (0x26, pins 8-15)
    Serial.println("Turning ON outputs 1-8");
    for (int i = 8; i <= 15; i++) {
        pcf8575_out1.digitalWrite(i, LOW); // Active LOW
        delay(200);
    }
    
    // Turn on outputs 9-16 (0x25, pins 8-15)
    Serial.println("Turning ON outputs 9-16");
    for (int i = 8; i <= 15; i++) {
        pcf8575_out2.digitalWrite(i, LOW); // Active LOW
        delay(200);
    }
    
    // Turn on outputs 17-24 (0x24, pins 0-7)
    Serial.println("Turning ON outputs 17-24");
    for (int i = 0; i <= 7; i++) {
        pcf8575_out3.digitalWrite(i, LOW); // Active LOW
        delay(200);
    }
    
    // Turn on outputs 25-32 (0x26, pins 0-7)
    Serial.println("Turning ON outputs 25-32");
    for (int i = 0; i <= 7; i++) {
        pcf8575_out1.digitalWrite(i, LOW); // Active LOW
        delay(200);
    }
    
    delay(1000);
    
    // Turn off outputs 1-8
    Serial.println("Turning OFF outputs 1-8");
    for (int i = 8; i <= 15; i++) {
        pcf8575_out1.digitalWrite(i, HIGH); // Active LOW
        delay(200);
    }
    
    // Turn off outputs 9-16
    Serial.println("Turning OFF outputs 9-16");
    for (int i = 8; i <= 15; i++) {
        pcf8575_out2.digitalWrite(i, HIGH); // Active LOW
        delay(200);
    }
    
    // Turn off outputs 17-24
    Serial.println("Turning OFF outputs 17-24");
    for (int i = 0; i <= 7; i++) {
        pcf8575_out3.digitalWrite(i, HIGH); // Active LOW
        delay(200);
    }
    
    // Turn off outputs 25-32
    Serial.println("Turning OFF outputs 25-32");
    for (int i = 0; i <= 7; i++) {
        pcf8575_out1.digitalWrite(i, HIGH); // Active LOW
        delay(200);
    }
    
    delay(1000);
}
