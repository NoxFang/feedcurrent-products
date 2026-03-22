# TA Example 08: Tuya WiFi Module Communication

## Overview
This example demonstrates UART communication between the ESP32-S3 and the onboard Tuya WiFi module. It handles the Tuya serial protocol, including heartbeat, product information, work mode, and network status handshakes, and responds accordingly.

## Hardware
| Component      | Description |
|----------------|-------------|
| Tuya WiFi MCU  | Onboard WiFi module |

### Key Pins
| Signal              | GPIO   |
|---------------------|--------|
| TXD (to Tuya RXD)   | GPIO16 |
| RXD (from Tuya TXD) | GPIO17 |
| Network Button      | Tuya P28 |
| Network LED         | Tuya P16 |

## Tuya Protocol Frames

| Frame (Request from Tuya) | Purpose | Response (ESP32 → Tuya) |
|---------------------------|---------|-------------------------|
| `55 AA 00 00 00 00 FF` | Initial heartbeat | `55 AA 03 00 00 01 00 03` |
| `55 AA 00 01 00 00 00` | Product info request | `55 AA 03 01 00 2A 7B 22 70 ...` (JSON data) |
| `55 AA 00 02 00 00 01` | Work mode request | `55 AA 03 02 00 03 10 1C 14 47` |
| `55 AA 00 03 00 01 00 03` | Network status request | `55 AA 03 03 00 00 05` |
| Subsequent heartbeat | Regular heartbeat | `55 AA 03 00 00 01 01 04` |

> **Note:** The product info response contains a JSON payload with firmware version, product name, etc.

## Dependencies
- `HardwareSerial.h` - Built-in Arduino library

## Usage
1. Upload the sketch to TA
2. Open Serial Monitor at **115200 baud**
3. The ESP32-S3 will automatically respond to Tuya module handshakes
4. Observe packet logs in the Serial Monitor

## Expected Output
ESP32-Tuya serial communication initialized.
Received packet: 55 AA 00 00 00 00 FF
Heartbeat received.
Sent packet: 55 AA 03 00 00 01 00 03
Received packet: 55 AA 00 01 00 00 00
Product info request received.
Sent packet: 55 AA 03 01 00 2A 7B 22 70 ...
...

## Key Code
```cpp
// Configure UART for Tuya module
HardwareSerial tuyaSerial(1);
tuyaSerial.begin(9600, SERIAL_8N1, RXD_PIN, TXD_PIN);

// Send response packet
void sendPacket(uint8_t* packet, size_t size) {
  tuyaSerial.write(packet, size);
  // ... debug print
}

// Process received 7‑byte packet
if (bytesRead >= 2 && incomingPacket[0] == 0x55 && incomingPacket[1] == 0xAA) {
  // Validate length, then process based on command byte
  processTuyaPacket(incomingPacket, 7);
}

## Precompiled Firmware
The `precompiled/` folder is reserved for pre-built `.bin` firmware files.

## Related Resources
- Pin Definition: `../../../pin_definitions/TA/TA_pin_definition.md`
- ESPHome Config (with Tuya): `../../../esphome_configs/TA/TA_esphome.yaml`