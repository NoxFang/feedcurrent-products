# F4 Arduino Example 09: Tuya WiFi Module Communication

## Description
This example implements UART communication with the onboard Tuya WiFi module. It listens for binary protocol frames from the Tuya module and responds to predefined commands (heartbeat, product info, work mode, network status) according to the Tuya serial protocol.

## File Structure
- `src/F4_09_tuya_communication.ino` – Arduino source code.
- `precompiled/F4_09_tuya_communication.bin` – Precompiled firmware binary for ESP32‑S3.

## Using the Precompiled Binary
Flash `precompiled/F4_09_tuya_communication.bin` to address `0x0` using ESP Flash Download Tool or `esptool.py`.

## Compiling from Source
- **Environment**: Arduino IDE with ESP32‑S3 board support.
- **Dependencies**: `HardwareSerial` (built‑in).
- **Steps**: Open the `.ino` file, select `esp32-s3-devkitc-1`, and upload.

## Hardware Connections
| Signal | GPIO |
|--------|------|
| TXD (ESP32 → Tuya) | GPIO39 |
| RXD (Tuya → ESP32) | GPIO38 |
| Baud Rate | 9600 |

## Tuya Protocol Overview
The Tuya module sends 7‑byte frames starting with `55 AA`. The ESP32‑S3 responds with appropriate pre‑encoded packets:

| Received Command | Response |
|------------------|----------|
| `55 AA 00 00 00 00 FF` (initial heartbeat) | `55 AA 03 00 00 01 00 03` |
| Subsequent heartbeats | `55 AA 03 00 00 01 01 04` |
| `55 AA 00 01 00 00 00` (product info request) | JSON‑encoded product info packet |
| `55 AA 00 02 00 00 01` (work mode request) | `55 AA 03 02 00 03 10 1C 14 47` |
| `55 AA 00 03 00 01 00 03` (network status request) | `55 AA 03 03 00 00 05` |

## Serial Output
After uploading, open the Serial Monitor at **115200 baud**. The ESP32 will print:
ESP32-Tuya serial communication initialized.

When a valid frame is received, it prints:
Received packet: 55 AA 00 00 00 00 FF
Heartbeat received.
Sent packet: 55 AA 03 00 00 01 00 03

If an incomplete or invalid packet is received, an error message is shown.

## Usage
1. Upload the sketch to the F4 board.
2. Open the Serial Monitor at 115200 baud.
3. The Tuya module will automatically begin communication. The ESP32 will respond to its requests.
4. Observe the packet exchange logs.

## Important Notes
- The example does **not** use AT commands; it works with the native Tuya binary protocol.
- The product information response is hardcoded in the `productInfoResponse` array. Modify it if your product ID, firmware version, or other details differ.
- The UART uses hardware serial port 1 (GPIO38, GPIO39).

## Related Resources
- Pin definition: `../pin_definitions/F4/F4_pin_definition.md`