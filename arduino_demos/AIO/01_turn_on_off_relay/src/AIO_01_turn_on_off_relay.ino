/*
 * PCF8574 Relay Control Example
 * 
 * Controls 5 relays connected to PCF8574 via I2C bus.
 * 
 * Made By FeedCurrent
 * https://www.feedcurrent.com
 */

#include <Arduino.h>
#include <Wire.h>
#include "PCF8574.h"

// I2C pin definitions
#define I2C_SDA 8
#define I2C_SCL 18

// Create PCF8574 object with I2C address 0x26
PCF8574 pcf8574(0x26);

void setup() {
  Serial.begin(115200);
  delay(500);
  
  // Initialize I2C with specified SDA and SCL pins
  Wire.begin(I2C_SDA, I2C_SCL);
  
  // Set PCF8574 P3~P7 as OUTPUT (Relays)
  pcf8574.pinMode(P3, OUTPUT);
  pcf8574.pinMode(P4, OUTPUT);
  pcf8574.pinMode(P5, OUTPUT);
  pcf8574.pinMode(P6, OUTPUT);
  pcf8574.pinMode(P7, OUTPUT);
  
  Serial.print("Init pcf8574...");
  if (pcf8574.begin()) {
    Serial.println("OK");
  } else {
    Serial.println("KO");
    while (1); // Stop if initialization fails
  }
  
  // Turn OFF all relays at startup
  for (int pin = P3; pin <= P7; pin++) {
    pcf8574.digitalWrite(pin, LOW);
  }
}

void loop() {
  // Turn ON all relays one by one
  for (int pin = P3; pin <= P7; pin++) {
    pcf8574.digitalWrite(pin, HIGH);
    delay(500);
  }
  
  delay(1000); // Keep all relays ON for a while
  
  // Turn OFF all relays
  for (int pin = P3; pin <= P7; pin++) {
    pcf8574.digitalWrite(pin, LOW);
  }
  
  delay(1000); // Keep all relays OFF for a while
}