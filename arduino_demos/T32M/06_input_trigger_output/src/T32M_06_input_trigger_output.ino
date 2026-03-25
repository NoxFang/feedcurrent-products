/*
* Made by FeedCurrent IoT: https://www.feedcurrent.com
*
* This program reads 32 input states from two PCF8575 I/O expanders
* and controls 32 relays via another two PCF8575 I/O expanders.
* When an input pin is LOW, the corresponding relay is turned ON (active LOW).
* When the input pin is HIGH, the corresponding relay is turned OFF.
*
* I2C Bus-1 Pin Definitions:
* - SDA: GPIO 48
* - SCL: GPIO 47
*
* I2C Addresses:
* - Output1-16:  0x20
* - Output17-32: 0x21
* - Input1-16:   0x24
* - Input17-32:  0x25
*/

#include <Wire.h>
#include <PCF8575.h>

// Define I2C pins
#define I2C_SDA 48
#define I2C_SCL 47

// PCF8575 I2C addresses
#define OUTPUT1_ADDR 0x20
#define OUTPUT2_ADDR 0x21
#define INPUT1_ADDR  0x24
#define INPUT2_ADDR  0x25

// Create PCF8575 objects
PCF8575 pcf8575_IN1(INPUT1_ADDR);   // Inputs 1~16
PCF8575 pcf8575_IN2(INPUT2_ADDR);   // Inputs 17~32
PCF8575 pcf8575_OUT1(OUTPUT1_ADDR); // Outputs 1~16
PCF8575 pcf8575_OUT2(OUTPUT2_ADDR); // Outputs 17~32

void setup() {
  // Initialize I2C with defined SDA and SCL
  Wire.begin(I2C_SDA, I2C_SCL);

  // Start serial communication
  Serial.begin(115200);

  // Initialize all PCF8575 devices
  pcf8575_IN1.begin();
  pcf8575_IN2.begin();
  pcf8575_OUT1.begin();
  pcf8575_OUT2.begin();

  // Turn off all relays at start (LOW = OFF)
  for (int i = 0; i < 16; i++) {
    pcf8575_OUT1.write(i, HIGH);  // HIGH means OFF for relay
    pcf8575_OUT2.write(i, HIGH);
  }

  Serial.println("System started: 32 inputs controlling 32 relays");
}

void loop() {
  uint32_t inputState = 0;

  // Read inputs 1~16
  for (int i = 0; i < 16; i++) {
    if (pcf8575_IN1.read(i)) {
      inputState |= (1UL << i);
    }
  }

  // Read inputs 17~32
  for (int i = 0; i < 16; i++) {
    if (pcf8575_IN2.read(i)) {
      inputState |= (1UL << (i + 16));
    }
  }

  // Control outputs 1~16
  for (int i = 0; i < 16; i++) {
    if (inputState & (1UL << i)) {
      pcf8575_OUT1.write(i, HIGH);  // Input HIGH -> Relay OFF
    } else {
      pcf8575_OUT1.write(i, LOW);   // Input LOW -> Relay ON
    }
  }

  // Control outputs 17~32
  for (int i = 0; i < 16; i++) {
    if (inputState & (1UL << (i + 16))) {
      pcf8575_OUT2.write(i, HIGH);  // Input HIGH -> Relay OFF
    } else {
      pcf8575_OUT2.write(i, LOW);   // Input LOW -> Relay ON
    }
  }

  delay(500);
}