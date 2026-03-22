#include <HardwareSerial.h>

// Define serial port
HardwareSerial SimSerial(1); // Use hardware serial port 1 (GPIO9 and GPIO10)

void setup() {
  // Initialize USB serial port (default serial port 0)
  Serial.begin(115200);
  while (!Serial) {
    ; // Wait for USB serial port to connect
  }

  // Initialize SIM7600 serial port
  SimSerial.begin(115200, SERIAL_8N1, 9, 10); // RX=GPIO9, TX=GPIO10
  //Serial.println("ESP32-S3 begin work");
}

void loop() {
  // If data is received from the computer, forward it to the SIM7600 module
  if (Serial.available()) {
    while (Serial.available()) {
      char data = Serial.read();
      SimSerial.write(data);
    }
  }

  // If data is received from the SIM7600 module, forward it to the computer
  if (SimSerial.available()) {
    while (SimSerial.available()) {
      char data = SimSerial.read();
      Serial.write(data);
    }
  }
}