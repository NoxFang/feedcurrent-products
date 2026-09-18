# B2 Arduino Example 09: Communication with Tuya WiFi Module

## Description
This example demonstrates how the B2 board (ESP32‑S3) communicates with an attached Tuya WiFi module via UART. It listens for specific command packets from the Tuya module and sends the appropriate predefined responses. This is a foundational example for integrating Tuya‑based cloud control.

The handled commands include:
- Heartbeat request
- Product information request
- Work mode request
- Network status request

## File Structure
- `src/B2_09_tuya_communication.ino` – Arduino source code.
- `precompiled/B2_09_tuya_communication.bin` – Precompiled firmware binary for ESP32‑S3.

## Using the Precompiled Binary (.bin)
1. Download the `.bin` file from the `precompiled/` folder.
2. Use the official **ESP Flash Download Tool** or `esptool.py` to flash it to the B2 controller.
3. **Flash Address**: `0x0`.

## Compiling from Source
1. **Environment**: Install Arduino IDE and add ESP32‑S3 board support (via Boards Manager).
2. **Dependencies**: `HardwareSerial.h` (built‑in with ESP32 core).
3. **Steps**: Open `src/B2_09_tuya_communication.ino` in Arduino IDE, select the board `esp32-s3-devkitc-1` and the correct port, then compile and upload.

## Hardware Connections
| Signal | GPIO |
|--------|------|
| Tuya TXD (to ESP32 RX) | GPIO15 |
| Tuya RXD (from ESP32 TX) | GPIO16 |

**Note**: The B2 board provides a dedicated UART interface for the Tuya module. Connect the Tuya module’s TX to GPIO15 and RX to GPIO16.

## Expected Behavior
- After uploading, open the Serial Monitor at **115200 baud** for debug output.
- The ESP32 initializes UART communication with the Tuya module on pins TX=15, RX=16 at **9600 baud**.
- When the Tuya module sends a valid 7‑byte packet (header `0x55 0xAA`), the ESP32 logs the received packet and sends the corresponding response.
- Debug messages (e.g., `Heartbeat received`, `Sent packet: ...`) are printed to the Serial Monitor.

## Important Notes
- **Baud Rate**: Communication with the Tuya module is fixed at **9600 baud**. Do not change this unless your module requires a different rate.
- **Packet Format**: The Tuya module sends 7‑byte packets. The first two bytes must be `0x55 0xAA` (valid header). The third byte indicates the command.
- **Response Packets**: The example handles four request types and replies with predefined byte arrays:
  - Heartbeat request → `heartBeatResponse`
  - Product info request → `productInfoResponse`
  - Work mode request → `workModeResponse`
  - Network status request → `netStatusResponse`
  > **Note**: The array `secondHeartBeatResponse` is defined in the code but **not used**. All heartbeat requests receive the same `heartBeatResponse`.
- **Product Info Payload**: The `productInfoResponse` contains a JSON‑like structure embedded in the byte array. It informs the Tuya module about the product capabilities (name, version, etc.).
- **Serial Monitor**: Use the Serial Monitor to observe the handshake process. It helps in debugging if the Tuya module does not enter the expected state.
- **Incomplete Packets**: The code waits briefly for additional bytes if fewer than 7 are received, and discards the packet if it remains incomplete.

## Related Resources
- Pin definition: `../pin_definitions/B2/B2_pin_definition.md`