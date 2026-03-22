# Example 09: Tuya WiFi Module Communication

## Description

This example demonstrates basic UART communication between the ESP32-S3 on the
FeedCurrent DM4 and the on‑board Tuya WiFi module. It implements the Tuya serial
protocol to respond to heartbeat, product info, work mode, and network status
queries from the Tuya module.

## Hardware Requirements

### Key Hardware
- FeedCurrent DM4 controller (ESP32‑S3 + Tuya module on‑board)

### Pin Definitions (Tuya UART)

| Signal | GPIO |
|--------|------|
| TXD (ESP32 → Tuya) | GPIO16 |
| RXD (Tuya → ESP32) | GPIO17 |
| Network Button      | Tuya P28 |
| Network LED         | Tuya P16 |

**Baud rate:** 9600

## Software Requirements

### Dependencies
- Arduino IDE with ESP32‑S3 board support
- No additional libraries required (uses `HardwareSerial`)

### Tuya Protocol Summary

| Command Byte | Description | Response Packet |
|--------------|-------------|-----------------|
| 0x00 (heartbeat) | Initial heartbeat | `55 AA 03 00 00 01 00 03` |
| 0x00 (heartbeat) | Subsequent heartbeat | `55 AA 03 00 00 01 01 04` |
| 0x01 | Product info request | JSON payload (pre‑encoded) |
| 0x02 | Work mode request | `55 AA 03 02 00 03 10 1C 14 47` |
| 0x03 | Network status request | `55 AA 03 03 00 00 05` |

**Product Information Response:**  
The example includes a pre‑encoded product information packet. If you need to change the product ID, firmware version, or other fields, modify the `productInfoResponse` array in the sketch accordingly.

### Key Code

```cpp
HardwareSerial tuyaSerial(1);
tuyaSerial.begin(9600, SERIAL_8N1, 17, 16);  // RX=17, TX=16

## Usage

1. Open src/DM4_09_tuya_communication.ino in Arduino IDE.
2. Select board: ESP32S3 Dev Module.
3. Upload and open Serial Monitor at 115200 baud.
4. The Tuya module will start sending heartbeat packets automatically; the ESP32 will respond accordingly.

## Expected Output

ESP32-Tuya serial communication initialized.
Received packet: 55 AA 00 00 00 00 FF
Heartbeat received.
Sent packet: 55 AA 03 00 00 01 00 03
...

## Precompiled Firmware

The `precompiled/` directory is reserved for precompiled `.bin` firmware files that can be flashed directly using the ESP32 download tool.