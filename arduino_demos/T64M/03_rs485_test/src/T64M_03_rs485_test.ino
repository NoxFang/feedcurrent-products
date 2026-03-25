/*
* Made by FeedCurrent IoT: https://www.feedcurrent.com
*
* RS485 Communication Test with Direction Control (SP3485EEN)
*
* This program is a simple test for RS485 communication using ESP32-S3.
* It will send a message over RS485 and then read incoming messages.
* The TXD pin is defined as GPIO 13, RXD is GPIO 21, and EN is GPIO 14.
*/

#include <HardwareSerial.h>

// Define RS485 pins
#define RS485_RXD 21     // RS485 Receive
#define RS485_TXD 13     // RS485 Transmit
#define RS485_EN  14     // RS485 Direction control (High: Send, Low: Receive)

// Create a hardware serial object on UART1
HardwareSerial rs485Serial(1);

void setup() {
  // Start serial communication for debugging
  Serial.begin(115200);
  while (!Serial);

  // Set RS485 direction control pin
  pinMode(RS485_EN, OUTPUT);
  digitalWrite(RS485_EN, LOW); // Start in receive mode

  // Initialize RS485 serial communication
  rs485Serial.begin(9600, SERIAL_8N1, RS485_RXD, RS485_TXD);

  Serial.println("RS485 Test Start (with direction control)");
}

void loop() {
  // Prepare the message to send
  String message = "Hello from KinCony T64M!";
 
  // Switch to transmit mode
  digitalWrite(RS485_EN, HIGH);
  delay(2); // Short delay to allow driver to switch
 
  // Send the message
  rs485Serial.println(message);
  rs485Serial.flush(); // Wait for transmission to complete
 
  // Switch back to receive mode
  digitalWrite(RS485_EN, LOW);
 
  Serial.println("Message sent. Waiting for response...");

  // Wait for a response (up to 1 second)
  unsigned long startTime = millis();
  while (millis() - startTime < 1000) {
    if (rs485Serial.available()) {
      String receivedMessage = "";
      while (rs485Serial.available()) {
        char c = rs485Serial.read();
        receivedMessage += c;
      }
      // Print the received message
      Serial.print("Received: ");
      Serial.println(receivedMessage);
      break;
    }
  }

  // Wait before sending the next message
  delay(2000);
}