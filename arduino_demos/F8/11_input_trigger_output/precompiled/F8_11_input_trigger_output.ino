/*
 * Made by KinCony IoT: https://www.kincony.com
 *
 * This program reads 8 input states from a PCF8575 I/O expander and 
 * controls a corresponding 8-channel relay module. When an input pin 
 * is LOW, the corresponding relay is turned ON (LOW means ON for the relay).
 *
 * Pin Definitions:
 * - SDA: GPIO 8
 * - SCL: GPIO 18
 * - PCF8575 I2C Address: 0x24
 */

#include <Wire.h>
#include <PCF8575.h>

// I2C pins
#define SDA 8
#define SCL 18

// PCF8575 I2C address
#define INPUT_I2C_ADDRESS 0x24   

// Create PCF8575 object
PCF8575 pcf8575_IN(INPUT_I2C_ADDRESS);

void setup() {
  // Initialize I2C communication
  Wire.begin(SDA, SCL);

  // Initialize serial communication
  Serial.begin(115200);
  
  // Initialize PCF8575
  pcf8575_IN.begin();

  // Turn off all relays first (assuming LOW activates the relay)
  for (int i = 8; i < 16; i++) {
    pcf8575_IN.write(i, HIGH);  // Set to HIGH to turn off the relay
  }

  Serial.println("System started: Input state controlling 8 relays");
}

void loop() {
  // Read 16-bit state from PCF8575
  uint16_t inputState = pcf8575_IN.read16(); 

  for (int i = 0; i < 8; i++) {
    bool state = bitRead(inputState, i); // Read digital input state

    Serial.print("DI");
    Serial.print(i + 1);
    Serial.print(" State: ");
    Serial.println(state ? "HIGH" : "LOW");

    // Control relay (LOW activates the relay)
    pcf8575_IN.write(8 + i, state ? HIGH : LOW);
  }

  Serial.println("---------------------");
  delay(500);
}
