/*
 * Made by KinCony IoT: https://www.kincony.com
 *
 * This Arduino program implements communication between ESP32-S3 and the Tuya WiFi module
 * via UART (serial communication). It listens for specific packets from the Tuya module
 * and responds according to the predefined commands.
 *
 * Functionality:
 * 1. Heartbeat packet response
 * 2. Product information request handling
 * 3. Work mode request handling
 * 4. Network status request handling
 *
 * Hardware Connections:
 * - TXD (to Tuya RXD): GPIO16
 * - RXD (from Tuya TXD): GPIO17
 * - Baud Rate: 9600
 */

#include <HardwareSerial.h>

HardwareSerial tuyaSerial(1);

#define TXD_PIN 16
#define RXD_PIN 17
#define BAUD_RATE 9600

// Response packets
uint8_t heartBeatResponse[]    = {0x55, 0xAA, 0x03, 0x00, 0x00, 0x01, 0x00, 0x03};
uint8_t productInfoResponse[]  = {
  0x55, 0xAA, 0x03, 0x01, 0x00, 0x2A, 0x7B, 0x22, 0x70, 0x22, 0x3A, 0x22,
  0x63, 0x68, 0x6D, 0x7A, 0x6C, 0x67, 0x6A, 0x70, 0x61, 0x64, 0x70, 0x71,
  0x78, 0x64, 0x6B, 0x6F, 0x22, 0x2C, 0x22, 0x76, 0x22, 0x3A, 0x22, 0x31,
  0x2E, 0x30, 0x2E, 0x30, 0x22, 0x2C, 0x22, 0x6D, 0x22, 0x3A, 0x30, 0x7D, 0xAA
};
uint8_t workModeResponse[]     = {0x55, 0xAA, 0x03, 0x02, 0x00, 0x03, 0x10, 0x1C, 0x14, 0x47};
uint8_t netStatusResponse[]    = {0x55, 0xAA, 0x03, 0x03, 0x00, 0x00, 0x05};
uint8_t secondHeartBeatResponse[] = {0x55, 0xAA, 0x03, 0x00, 0x00, 0x01, 0x01, 0x04};

void sendPacket(uint8_t* packet, size_t size) {
  tuyaSerial.write(packet, size);
  Serial.print("Sent packet: ");
  for (size_t i = 0; i < size; i++) {
    Serial.print(packet[i], HEX);
    Serial.print(" ");
  }
  Serial.println();
}

void processTuyaPacket(uint8_t* packet, size_t size) {
  if (size == 7 && packet[0] == 0x55 && packet[1] == 0xAA) {
    switch(packet[2]) {
      case 0x00:
        if (packet[3] == 0x00 && packet[4] == 0x00 && packet[5] == 0x00 && packet[6] == 0xFF) {
          Serial.println("Heartbeat received.");
          sendPacket(heartBeatResponse, sizeof(heartBeatResponse));
        } else if (packet[3] == 0x01) {
          Serial.println("Product info request received.");
          sendPacket(productInfoResponse, sizeof(productInfoResponse));
        } else if (packet[3] == 0x02) {
          Serial.println("Work mode request received.");
          sendPacket(workModeResponse, sizeof(workModeResponse));
        } else if (packet[3] == 0x03) {
          Serial.println("Network status request received.");
          sendPacket(netStatusResponse, sizeof(netStatusResponse));
        }
        break;
      default:
        Serial.println("Error: Unhandled command received.");
        break;
    }
  }
}

void setup() {
  Serial.begin(115200);
  tuyaSerial.begin(BAUD_RATE, SERIAL_8N1, RXD_PIN, TXD_PIN);
  Serial.println("ESP32-Tuya serial communication initialized.");
}

void loop() {
  if (tuyaSerial.available()) {
    uint8_t incomingPacket[7];
    size_t bytesRead = tuyaSerial.readBytes(incomingPacket, 7);

    if (bytesRead >= 2 && incomingPacket[0] == 0x55 && incomingPacket[1] == 0xAA) {
      if (bytesRead < 7) {
        delay(50);
        while (tuyaSerial.available()) {
          incomingPacket[bytesRead++] = tuyaSerial.read();
          if (bytesRead >= 7) break;
        }
      }
      if (bytesRead < 7) {
        Serial.println("Error: Incomplete packet discarded.");
        return;
      }

      Serial.print("Received packet: ");
      for (size_t i = 0; i < 7; i++) {
        Serial.print(incomingPacket[i], HEX);
        Serial.print(" ");
      }
      Serial.println();

      processTuyaPacket(incomingPacket, 7);
    } else {
      tuyaSerial.flush();
    }
  }
  delay(100);
}
