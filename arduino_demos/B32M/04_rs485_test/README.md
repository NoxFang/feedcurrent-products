# FeedCurrent B32M Controller Arduino Example 04: RS485 Communication Test

## Description
This example tests RS485 communication on the B32M board by periodically sending a message and printing any received data.

## File Structure
- `src/B32M_04_rs485_test.ino` – Arduino source code.
- `precompiled/B32M_04_rs485_test.bin` – Precompiled firmware binary for ESP32-S3.

## Using the Precompiled Binary
Flash `precompiled/B32M_04_rs485_test.bin` to address `0x0` using ESP Flash Download Tool or `esptool.py`.

## Compiling from Source
- **Environment**: Arduino IDE with ESP32-S3 board support.
- **Dependencies**: `HardwareSerial` (built-in).
- **Steps**: Open the `.ino` file, select `esp32-s3-devkitc-1`, and upload.

## Expected Behavior
- Sends `"Hello from FeedCurrent B32M!"` every 3 seconds.
- If data is received, it prints: `Received: <message>`.

## Important Notes
- **RS485 pins**: RXD=GPIO38, TXD=GPIO39.
- **Baud rate**: 9600.
- **Serial Monitor** shows debug messages at 115200 baud.
