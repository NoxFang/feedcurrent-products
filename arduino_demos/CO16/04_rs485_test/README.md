# CO16 Arduino Example 04: RS485 Communication Test

## Description
This example demonstrates basic RS485 communication on the CO16 board using the ESP32‑S3 hardware serial interface.  
It periodically sends a test message over RS485 and listens for incoming messages, printing received data to the Serial Monitor.

## File Structure
- `src/CO16_04_rs485_test.ino` – Arduino source code.
- `precompiled/CO16_04_rs485_test.bin` – Precompiled firmware binary for ESP32‑S3.

## Using the Precompiled Binary (.bin)
1. Download the `.bin` file from the `precompiled/` folder.
2. Use the official **ESP Flash Download Tool** or `esptool.py` to flash it to the CO16 controller.
3. **Flash Address**: `0x0`.

## Compiling from Source
1. **Environment**: Install Arduino IDE and add ESP32‑S3 board support (via Boards Manager).
2. **Dependencies**: `HardwareSerial.h` (built‑in with ESP32 core).
3. **Steps**: Open `src/CO16_04_rs485_test.ino` in Arduino IDE, select the board `esp32-s3-devkitc-1` and the correct port, then compile and upload.

## Hardware Connections
| Signal | GPIO |
|--------|------|
| RS485 RX | GPIO38 |
| RS485 TX | GPIO39 |

**Note**: The CO16 board includes an onboard RS485 transceiver. No external direction control pin is used.

> ⚠️ **Important**: The code comments mention “TXD pin is defined as GPIO 18 and RXD pin is defined as GPIO 8”, but the actual `#define` values are **RS485_RXD = 38** and **RS485_TXD = 39**. Always refer to the `#define` lines in the code.

## Expected Behavior
- On startup, the Serial Monitor (115200 baud) shows: `RS485 Test Start`.
- Every 3 seconds, the board sends: `Hello from FeedCurrent!`.
- If any data is received on the RS485 bus, it is printed as: `Received: [data]`.
- The cycle repeats indefinitely.

## Important Notes
- **Baud rate**: 9600, 8 data bits, 1 stop bit, no parity.
- The example assumes the RS485 bus is properly terminated and other devices respond with data.
- To test reception, connect another RS485 device that echoes or sends data. A simple loopback test can be done by connecting RS485 A/B lines through a converter.

## Related Resources
- Pin definition: `../pin_definitions/CO16/CO16_pin_definition.md`