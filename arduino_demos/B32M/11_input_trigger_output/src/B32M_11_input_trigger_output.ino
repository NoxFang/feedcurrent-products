/*
 * Made by FeedCurrent IoT: https://www.feedcurrent.com
 *
 * Description:
 * This Arduino program links the 32 digital inputs to the 32 MOSFET outputs
 * on the B32M board. When an input is triggered (connected to GND),
 * the corresponding output activates.
 *
 * Pin Definitions:
 * - SDA: GPIO 8
 * - SCL: GPIO 18
 * - Input PCF8575: 0x22 (1-16), 0x25 (17-24), 0x26 (25-32)
 * - Output PCF8575: 0x26 (1-8, 25-32), 0x25 (9-16), 0x24 (17-24)
 */

#include "Arduino.h"
#include "PCF8575.h"

// Define I2C pins
#define I2C_SDA 8
#define I2C_SCL 18

// Input PCF8575 chips
PCF8575 pcf8575_in1(0x22);  // Inputs 1-16
PCF8575 pcf8575_in2(0x25);  // Inputs 17-24 (pins 0-7)
PCF8575 pcf8575_in3(0x26);  // Inputs 25-32 (pins 0-7)

// Output PCF8575 chips
PCF8575 pcf8575_out1(0x26); // Outputs 1-8 (pins 8-15), 25-32 (pins 0-7)
PCF8575 pcf8575_out2(0x25); // Outputs 9-16 (pins 8-15)
PCF8575 pcf8575_out3(0x24); // Outputs 17-24 (pins 0-7)

void setup() {
    Serial.begin(115200);
    delay(1000);
    
    Serial.println("B32M - Input Trigger Output");
    Serial.println("Initializing I2C...");
    
    // Initialize I2C communication
    Wire.begin(I2C_SDA, I2C_SCL);
    
    // Initialize all PCF8575 modules
    bool initOK = true;
    
    if (!pcf8575_in1.begin()) { Serial.println("Failed: 0x22 (in1)"); initOK = false; }
    if (!pcf8575_in2.begin()) { Serial.println("Failed: 0x25 (in2)"); initOK = false; }
    if (!pcf8575_in3.begin()) { Serial.println("Failed: 0x26 (in3)"); initOK = false; }
    if (!pcf8575_out1.begin()) { Serial.println("Failed: 0x26 (out1)"); initOK = false; }
    if (!pcf8575_out2.begin()) { Serial.println("Failed: 0x25 (out2)"); initOK = false; }
    if (!pcf8575_out3.begin()) { Serial.println("Failed: 0x24 (out3)"); initOK = false; }
    
    if (!initOK) {
        Serial.println("Some PCF8575 chips failed to initialize!");
    } else {
        Serial.println("All PCF8575 chips initialized!");
    }
    
    // Set all inputs
    for (int i = 0; i < 16; i++) {
        pcf8575_in1.pinMode(i, INPUT);
    }
    for (int i = 0; i < 8; i++) {
        pcf8575_in2.pinMode(i, INPUT);
        pcf8575_in3.pinMode(i, INPUT);
    }
    
    // Set all outputs to OFF (HIGH for active LOW)
    for (int i = 0; i < 16; i++) {
        pcf8575_out1.digitalWrite(i, HIGH);
    }
    for (int i = 0; i < 16; i++) {
        pcf8575_out2.digitalWrite(i, HIGH);
    }
    for (int i = 0; i < 8; i++) {
        pcf8575_out3.digitalWrite(i, HIGH);
    }
    
    Serial.println("Linking inputs to outputs...");
    Serial.println("Input 1-32 -> Output 1-32");
    Serial.println("Connect input to GND to activate corresponding output.\n");
}

void loop() {
    // Read inputs 1-16 and control outputs 1-16
    for (int i = 0; i < 16; i++) {
        int inputState = pcf8575_in1.digitalRead(i);
        
        // Map inputs 1-8 to outputs 1-8 (0x26, pins 8-15)
        // Map inputs 9-16 to outputs 9-16 (0x25, pins 8-15)
        if (i < 8) {
            pcf8575_out1.digitalWrite(i + 8, inputState);  // Active LOW
        } else {
            pcf8575_out2.digitalWrite(i, inputState);  // Active LOW
        }
    }
    
    // Read inputs 17-24 and control outputs 17-24
    for (int i = 0; i < 8; i++) {
        int inputState = pcf8575_in2.digitalRead(i);
        pcf8575_out3.digitalWrite(i, inputState);  // Active LOW
    }
    
    // Read inputs 25-32 and control outputs 25-32
    for (int i = 0; i < 8; i++) {
        int inputState = pcf8575_in3.digitalRead(i);
        pcf8575_out1.digitalWrite(i, inputState);  // Active LOW
    }
    
    delay(50);  // Small delay for stability
}
