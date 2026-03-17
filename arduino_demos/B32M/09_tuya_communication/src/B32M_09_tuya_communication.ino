/*
 * Made by FeedCurrent IoT: https://www.feedcurrent.com
 *
 * Description:
 * This Arduino program implements basic UART communication protocol between
 * the ESP32 and the Tuya WiFi module on the B32M board.
 *
 * Pin Definitions:
 * - Tuya TX: GPIO 16
 * - Tuya RX: GPIO 17
 * - Baud Rate: 9600
 */

#include "Arduino.h"

// Define Tuya UART pins
#define TUYA_TX 16
#define TUYA_RX 17

// Create HardwareSerial object for Tuya
HardwareSerial tuyaSerial(2);  // UART2

// Tuya protocol constants
#define TUYA_HEADER 0x55
#define TUYA_VERSION 0xAA

void setup() {
    Serial.begin(115200);
    delay(1000);
    
    Serial.println("B32M - Tuya WiFi Module Communication");
    Serial.println("Initializing Tuya UART...");
    
    // Initialize Tuya UART
    tuyaSerial.begin(9600, SERIAL_8N1, TUYA_RX, TUYA_TX);
    
    Serial.println("Tuya UART initialized!");
    Serial.println("Waiting for Tuya commands...\n");
}

void loop() {
    // Check for incoming data from Tuya module
    while (tuyaSerial.available()) {
        byte data = tuyaSerial.read();
        
        // Print received byte in hex
        Serial.print("Received: 0x");
        if (data < 0x10) Serial.print("0");
        Serial.println(data, HEX);
        
        // Process Tuya protocol (simplified)
        processTuyaData(data);
    }
    
    // Check for commands from Serial Monitor
    if (Serial.available()) {
        String command = Serial.readStringUntil('\n');
        command.trim();
        
        if (command.equalsIgnoreCase("heartbeat")) {
            sendHeartbeat();
        }
        else if (command.equalsIgnoreCase("query")) {
            sendQuery();
        }
        else {
            Serial.println("Unknown command. Use 'heartbeat' or 'query'.");
        }
    }
}

void processTuyaData(byte data) {
    // Simplified Tuya protocol processing
    // In a real implementation, you would parse the full protocol frame
    
    switch (data) {
        case 0x00:
            Serial.println("  -> Heartbeat request");
            sendHeartbeatResponse();
            break;
        case 0x01:
            Serial.println("  -> Product query");
            sendProductInfo();
            break;
        case 0x02:
            Serial.println("  -> Network status query");
            sendNetworkStatus();
            break;
        default:
            break;
    }
}

void sendHeartbeat() {
    // Send heartbeat command
    byte heartbeat[] = {0x55, 0xAA, 0x00, 0x00, 0x00, 0x00};
    tuyaSerial.write(heartbeat, sizeof(heartbeat));
    Serial.println("Sent: Heartbeat command");
}

void sendHeartbeatResponse() {
    // Send heartbeat response
    byte response[] = {0x55, 0xAA, 0x00, 0x00, 0x01, 0x01, 0x01};
    tuyaSerial.write(response, sizeof(response));
    Serial.println("Sent: Heartbeat response");
}

void sendQuery() {
    // Send query command
    byte query[] = {0x55, 0xAA, 0x00, 0x01, 0x00, 0x01, 0x01};
    tuyaSerial.write(query, sizeof(query));
    Serial.println("Sent: Query command");
}

void sendProductInfo() {
    // Send product information (example)
    Serial.println("Sent: Product info response");
    // In real implementation, send actual product info
}

void sendNetworkStatus() {
    // Send network status (example: connected)
    byte status[] = {0x55, 0xAA, 0x00, 0x02, 0x00, 0x01, 0x04};
    tuyaSerial.write(status, sizeof(status));
    Serial.println("Sent: Network status (connected)");
}
