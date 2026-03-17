/*
 * Made by FeedCurrent IoT: https://www.feedcurrent.com
 *
 * Description:
 * This Arduino program reads the state of 32 digital inputs on the B32M board
 * via the PCF8575 I/O expanders and prints the state to the Serial Monitor.
 *
 * Pin Definitions:
 * - SDA: GPIO 8
 * - SCL: GPIO 18
 * - PCF8575 I2C Addresses: 0x22 (inputs 1-16), 0x25 (inputs 17-24), 0x26 (inputs 25-32)
 */

#include "Arduino.h"
#include "PCF8575.h"

// Define I2C pins
#define I2C_SDA 8
#define I2C_SCL 18

// Set I2C addresses for input PCF8575 chips
PCF8575 pcf8575_in1(0x22);  // Inputs 1-16
PCF8575 pcf8575_in2(0x25);  // Inputs 17-24 (pins 0-7)
PCF8575 pcf8575_in3(0x26);  // Inputs 25-32 (pins 0-7)

void setup() {
    Serial.begin(115200);
    delay(1000);
    
    Serial.println("B32M - 32 Channel Digital Input Reader");
    Serial.println("Initializing I2C...");
    
    // Initialize I2C communication
    Wire.begin(I2C_SDA, I2C_SCL);
    
    // Initialize all PCF8575 modules
    if (!pcf8575_in1.begin()) {
        Serial.println("Failed to initialize PCF8575 at 0x22");
    }
    if (!pcf8575_in2.begin()) {
        Serial.println("Failed to initialize PCF8575 at 0x25");
    }
    if (!pcf8575_in3.begin()) {
        Serial.println("Failed to initialize PCF8575 at 0x26");
    }
    
    // Set all pins as inputs
    for (int i = 0; i < 16; i++) {
        pcf8575_in1.pinMode(i, INPUT);
    }
    for (int i = 0; i < 8; i++) {
        pcf8575_in2.pinMode(i, INPUT);
        pcf8575_in3.pinMode(i, INPUT);
    }
    
    Serial.println("Initialization complete!");
    Serial.println("Reading input states...\n");
}

void loop() {
    Serial.println("=================================");
    
    // Read inputs 1-16
    Serial.println("Inputs 1-16:");
    for (int i = 0; i < 16; i++) {
        int state = pcf8575_in1.digitalRead(i);
        Serial.print("Input ");
        Serial.print(i + 1);
        Serial.print(": ");
        Serial.println(state == LOW ? "ACTIVE" : "INACTIVE");
    }
    
    // Read inputs 17-24
    Serial.println("\nInputs 17-24:");
    for (int i = 0; i < 8; i++) {
        int state = pcf8575_in2.digitalRead(i);
        Serial.print("Input ");
        Serial.print(i + 17);
        Serial.print(": ");
        Serial.println(state == LOW ? "ACTIVE" : "INACTIVE");
    }
    
    // Read inputs 25-32
    Serial.println("\nInputs 25-32:");
    for (int i = 0; i < 8; i++) {
        int state = pcf8575_in3.digitalRead(i);
        Serial.print("Input ");
        Serial.print(i + 25);
        Serial.print(": ");
        Serial.println(state == LOW ? "ACTIVE" : "INACTIVE");
    }
    
    Serial.println("=================================\n");
    delay(2000);
}
