# FeedCurrent B8M Arduino Example 09: Communication with Tuya WiFi Module

## Description
This example implements the basic UART communication protocol between the ESP32 and the Tuya WiFi module, responding to heartbeat, product info, and other requests.

## File Structure
- `src/B8M_09_tuya_communication.ino` – Arduino source code.
- `precompiled/B8M_09_tuya_communication.bin` – Precompiled binary.

## Using the Precompiled Binary
Flash `precompiled/B8M_09_tuya_communication.bin` to `0x0`.

## Compiling from Source
- **Dependencies**: `HardwareSerial` (built-in).
- **Steps**: Compile and upload.

## Expected Behavior
- Opens a serial connection to Tuya module at 9600 baud (TX=16, RX=17).
- Prints debug messages for received packets and sent responses.

## Important Notes
- **Pins**: TXD=16, RXD=17 (as defined in code).
- The response packets are hardcoded; ensure your Tuya module's firmware matches these expectations.