# FeedCurrent B24M Controller Arduino Example 04: RS485 Communication Test

## Description
This example demonstrates RS485 communication on the B24M board. It sends a test message over RS485 and reads any incoming messages, printing them to the Serial Monitor.

## File Structure
- `src/B24M_04_rs485_test.ino` – Arduino source code.
- `precompiled/B24M_04_rs485_test.bin` – Precompiled firmware binary for ESP32-S3.

## Using the Precompiled Binary
Flash `precompiled/B24M_04_rs485_test.bin` to address `0x0` using ESP Flash Download Tool or `esptool.py`.

## Compiling from Source
- **Environment**: Arduino IDE with ESP32-S3 board support.
- **Dependencies**: None (uses built-in HardwareSerial).
- **Steps**: Open the `.ino` file, select `esp32-s3-devkitc-1`, and upload.

## Expected Behavior
The device sends "Hello from KinCony B24!" via RS485 every 2 seconds. Any received data is printed to the Serial Monitor.

## Important Notes
- **RS485 pins** (as defined in code): RXD=GPIO38, TXD=GPIO39.
- **Note**: Code comments may show different pins; always use the `#define` values in the code.
- **Serial Monitor** shows debug messages at 115200 baud.
- **RS485 baud rate**: 9600 bps.
