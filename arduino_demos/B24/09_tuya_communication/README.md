# FeedCurrent B24 Controller Arduino Example 09: Tuya WiFi Module Communication

## Description
This example implements basic UART communication protocol between the ESP32 and the Tuya WiFi module on the B24 board, responding to heartbeat, product info, and other requests.

## File Structure
- `src/B24_09_tuya_communication.ino` – Arduino source code.
- `precompiled/B24_09_tuya_communication.bin` – Precompiled firmware binary for ESP32-S3.

## Using the Precompiled Binary
Flash `precompiled/B24_09_tuya_communication.bin` to address `0x0` using ESP Flash Download Tool or `esptool.py`.

## Compiling from Source
- **Environment**: Arduino IDE with ESP32-S3 board support.
- **Dependencies**: `HardwareSerial` (built-in).
- **Steps**: Open the `.ino` file, select `esp32-s3-devkitc-1`, and upload.

## Expected Behavior
- Opens serial connection to Tuya module at 9600 baud.
- Prints debug messages for received packets and sent responses.

## Important Notes
- **Tuya pins**: TXD=GPIO16, RXD=GPIO17.
- The response packets are hardcoded; ensure your Tuya module's firmware matches these expectations.
- **Serial Monitor** shows debug messages at 115200 baud.
