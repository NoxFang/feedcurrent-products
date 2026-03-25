// Made by FeedCurrent IoT: https://www.feedcurrent.com
// This sketch scans two I2C buses and prints all detected device addresses.
// IIC Bus-1: SDA - GPIO48, SCL - GPIO47
// IIC Bus-2: SDA - GPIO12, SCL - GPIO11

#include <Wire.h>

// Create two I2C bus objects
TwoWire I2C_BUS1 = TwoWire(0);
TwoWire I2C_BUS2 = TwoWire(1);

// Scan function for a specific I2C bus
void scanI2CBus(TwoWire &bus, const char* busName) {
  Serial.println();
  Serial.print("Scanning ");
  Serial.print(busName);
  Serial.println(" at 100kHz...");

  byte error, address;
  int nDevices = 0;

  for (address = 1; address < 127; address++) {
    bus.beginTransmission(address);
    error = bus.endTransmission();

    if (error == 0) {
      Serial.print("I2C device found at address 0x");
      if (address < 16)
        Serial.print("0");
      Serial.print(address, HEX);
      Serial.println("  ✓");
      nDevices++;
    } else if (error == 4) {
      Serial.print("Unknown error at address 0x");
      if (address < 16)
        Serial.print("0");
      Serial.println(address, HEX);
    }
  }

  if (nDevices == 0)
    Serial.println("No I2C devices found.");
  else
    Serial.println("Scan completed.");
}

void setup() {
  Serial.begin(115200);
  delay(1000); // Wait for serial to initialize

  // Initialize IIC Bus-1 (GPIO48 = SDA, GPIO47 = SCL) at 100kHz
  I2C_BUS1.begin(48, 47);

  // Initialize IIC Bus-2 (GPIO12 = SDA, GPIO11 = SCL) at 100kHz
  I2C_BUS2.begin(12, 11);

  // Start scanning both buses
  scanI2CBus(I2C_BUS1, "IIC Bus-1");
  scanI2CBus(I2C_BUS2, "IIC Bus-2");
}

void loop() {
  // Nothing to do in the loop
}