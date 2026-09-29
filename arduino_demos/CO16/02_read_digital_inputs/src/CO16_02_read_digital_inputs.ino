/*
  Made by FeedCurrent IoT: https://www.feedcurrent.com

  Program functionality:
  This program uses an ESP32-S3 to read inputs from an XL9535 I/O expander chip 
  (I2C address 0x24) via I2C. The XL9535 chip handles channels 1-16. 
  The program reads the state of all these inputs and prints them in binary format 
  to the serial monitor.

  Key points:
  - The I2C bus is initialized on GPIO pins 8 (SDA) and 18 (SCL) with a frequency of 40kHz.
  - The XL9535 chip reads the state of input pins for channels 1-16.
  - The state of the inputs is printed to the serial monitor in binary format every second.
  - Note: The original description mentioned three expander chips, but this implementation
    currently uses only one XL9535 (PCA9555 compatible) at address 0x24.
*/

#include <PCA95x5.h>
#include <Wire.h>

// Initialize the PCA9555 object for XL9535 chip (channels 1-16)
PCA9555 ioex1;  // XL9535 I/O expander at I2C address 0x24, handles channels 1-16

void setup() {
    // Start serial communication for debugging
    Serial.begin(115200);
    delay(2000);  // Wait for 2 seconds to ensure serial monitor is ready

    // Initialize the I2C bus with GPIO 8 as SDA and GPIO 18 as SCL, 40kHz frequency
    Wire.begin(8, 18, 40000);

    // Attach the PCA9555 device at I2C address 0x24
    ioex1.attach(Wire, 0x24);
    
    // Set polarity to original (no inversion)
    ioex1.polarity(PCA95x5::Polarity::ORIGINAL_ALL);
    
    // Configure all 16 pins as inputs
    ioex1.direction(PCA95x5::Direction::IN_ALL);
}

void loop() {
    // Read and print the state of inputs from the XL9535 (channels 1-16)
    Serial.print("1-16 input states: ");
    // Read all 16 pins and print as 16-bit binary value
    Serial.println(ioex1.read(), BIN);

    delay(1000);  // Wait for 1 second before the next reading
}