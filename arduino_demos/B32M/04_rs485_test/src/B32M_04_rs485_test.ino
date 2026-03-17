/*
 * Made by FeedCurrent IoT: https://www.feedcurrent.com
 *
 * Description:
 * This Arduino program tests RS485 communication on the B32M board.
 * It periodically sends a message and prints any received data.
 *
 * Pin Definitions:
 * - RS485 RX: GPIO 38
 * - RS485 TX: GPIO 39
 * - Baud Rate: 9600
 */

#include "Arduino.h"

// Define RS485 pins
#define RS485_RX 38
#define RS485_TX 39

// Create HardwareSerial object for RS485
HardwareSerial rs485(1);  // UART1

void setup() {
    Serial.begin(115200);
    delay(1000);
    
    Serial.println("B32M - RS485 Communication Test");
    Serial.println("Initializing RS485...");
    
    // Initialize RS485 UART
    rs485.begin(9600, SERIAL_8N1, RS485_RX, RS485_TX);
    
    Serial.println("RS485 initialized!");
    Serial.println("Sending test messages every 3 seconds...");
    Serial.println("Waiting for incoming data...\n");
}

void loop() {
    // Send test message
    static unsigned long lastSend = 0;
    if (millis() - lastSend >= 3000) {
        lastSend = millis();
        
        String message = "Hello from FeedCurrent B32M!";
        rs485.println(message);
        
        Serial.print("Sent: ");
        Serial.println(message);
    }
    
    // Check for incoming data
    while (rs485.available()) {
        String received = rs485.readStringUntil('\n');
        received.trim();
        
        Serial.print("Received: ");
        Serial.println(received);
    }
}
