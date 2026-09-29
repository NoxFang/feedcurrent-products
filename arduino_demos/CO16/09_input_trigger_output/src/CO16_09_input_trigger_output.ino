/*
  Made by FeedCurrent IoT: https://www.feedcurrent.com

  Program functionality:
  This program uses ESP32-S3 to read inputs from PCA9555 I/O expander chip (I2C address 0x24)
  for channels 1-16, and control corresponding relays using PCF8575 I/O expander chip (I2C address 0x22)
  for controlling 16 relays (1-16). When input (DI) is triggered (LOW), corresponding relay (OUTPUT) is activated (LOW).
*/

#include <PCA95x5.h>
#include <Wire.h>
#include <PCF8575.h>

// Initialize the PCA9555 objects for reading inputs (channels 1-16)
PCA9555 input_ioex1;  // For channels 1-16 (I2C address 0x24)

// Set I2C address of the PCF8575 module for output relays
#define I2C_ADDRESS 0x22
PCF8575 pcf8575_R1(I2C_ADDRESS);

void setup() {
    Serial.begin(115200);
    delay(10);

    // Initialize I2C bus: SDA=GPIO8, SCL=GPIO18, 100kHz
    Wire.begin(8, 18, 100000);

    // Initialize PCF8575 for outputs
    pcf8575_R1.begin();

    // Turn off all relays initially (set all pins HIGH - relay OFF)
    for (int i = 0; i < 16; i++) {
        pcf8575_R1.write(i, HIGH);
    }

    // Configure input PCA9555 (for inputs 1-16)
    input_ioex1.attach(Wire, 0x24);
    input_ioex1.polarity(PCA95x5::Polarity::ORIGINAL_ALL);
    input_ioex1.direction(PCA95x5::Direction::IN_ALL);

    delay(50);
}

void loop() {
    // Read input states from XL9535 (inputs 1-16)
    uint16_t inputs_1_16 = input_ioex1.read();
    
    // Control outputs based on inputs
    // When input is LOW, set corresponding output to LOW (activate relay)
    for (int channel = 0; channel < 16; channel++) {
        if (!(inputs_1_16 & (1 << channel))) {
            pcf8575_R1.write(channel, LOW);   // Input triggered, activate relay
        } else {
            pcf8575_R1.write(channel, HIGH);  // Input not triggered, deactivate relay
        }
    }
    
    delay(100);
}