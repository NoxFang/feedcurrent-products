# FeedCurrent B24M Controller Arduino Example 09: Tuya Communication

## Description
This example demonstrates communication between ESP32 and the Tuya Wi-Fi module via UART. It handles various packets from the Tuya module including heartbeat, product info, work mode, and network status requests.

## File Structure
- `src/B24M_09_tuya_communication.ino` – Arduino source code.
- `precompiled/B24M_09_tuya_communication.bin` – Precompiled firmware binary for ESP32-S3.

## Using the Precompiled Binary
Flash `precompiled/B24M_09_tuya_communication.bin` to address `0x0` using ESP Flash Download Tool or `esptool.py`.

## Compiling from Source
- **Environment**: Arduino IDE with ESP32-S3 board support.
- **Dependencies**: None (uses built-in HardwareSerial).
- **Steps**: Open the `.ino` file, select `esp32-s3-devkitc-1`, and upload.

## Expected Behavior
The device communicates with the Tuya module, responding to heartbeat, product info, work mode, and network status requests.

## Important Notes
- **Tuya module pins**:
  - TXD: GPIO39
  - RXD: GPIO38
- **Baud rate**: 9600 bps
- **Serial Monitor** shows debug messages at 115200 baud.
