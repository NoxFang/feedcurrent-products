# T16M Arduino Example 03: RS485 Communication Test

## Description
This example demonstrates basic RS485 communication using the T16M board. It sends a test message every 3 seconds and prints any received data to the Serial Monitor. The RS485 interface uses UART1 with TX on GPIO13 and RX on GPIO14.

## File Structure
- `src/T16M_03_rs485_test.ino` – Arduino source code.
- `precompiled/T16M_03_rs485_test.bin` – Precompiled firmware binary for ESP32‑S3.

## Using the Precompiled Binary
Flash `precompiled/T16M_03_rs485_test.bin` to address `0x0` using ESP Flash Download Tool or `esptool.py`.

## Compiling from Source
- **Environment**: Arduino IDE with ESP32‑S3 board support.
- **Dependencies**: None beyond the standard ESP32 core.
- **Steps**: Open the `.ino` file, select `esp32-s3-devkitc-1`, and upload.

## Hardware Connections
| Signal | GPIO |
|--------|------|
| RS485 TX | 13 |
| RS485 RX | 14 |

**Note**: The T16M board includes an onboard RS485 transceiver. No external direction control pin is used.

## Expected Behavior
- On startup, the Serial Monitor (115200 baud) shows: `RS485 Test Start`
- Every 3 seconds, the board sends: `Hello from FeedCurrent T16M!`
- If any data is received on the RS485 bus, it is printed as: `Received: [data]`
- The cycle repeats indefinitely.

## Important Notes
- Baud rate: **9600**, 8 data bits, 1 stop bit, no parity.
- The example assumes the RS485 bus is properly terminated and other devices respond with data.
- To test reception, connect another RS485 device that echoes or sends data.

## Related Resources
- Pin definition: `../pin_definitions/T16M/T16M_pin_definition.md`