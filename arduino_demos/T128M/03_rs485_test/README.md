# T128M Arduino Example 03: RS485 Communication Test

## Description
This example demonstrates RS485 communication with direction control using the T128M board. It sends a test message every 3 seconds, toggles the direction pin, and prints any received data to the Serial Monitor. The RS485 interface uses UART1 with TX on GPIO13, RX on GPIO21, and direction control on GPIO14.

## File Structure
- `src/T128M_03_rs485_test.ino` – Arduino source code.
- `precompiled/T128M_03_rs485_test.bin` – Precompiled firmware binary for ESP32‑S3.

## Using the Precompiled Binary
Flash `precompiled/T128M_03_rs485_test.bin` to address `0x0` using ESP Flash Download Tool or `esptool.py`.

## Compiling from Source
- **Environment**: Arduino IDE with ESP32‑S3 board support.
- **Dependencies**: None beyond the standard ESP32 core.
- **Steps**: Open the `.ino` file, select `esp32-s3-devkitc-1`, and upload.

## Hardware Connections
| Signal | GPIO |
|--------|------|
| RS485 TX | 13 |
| RS485 RX | 21 |
| RS485 EN (direction) | 14 |

**Note**: The T128M board includes an onboard RS485 transceiver with direction control. The example manually sets EN high to transmit and low to receive.

## Expected Behavior
- On startup, the Serial Monitor (115200 baud) shows: `RS485 Test Start (with direction control)`
- Every 3 seconds, the board sends: `Hello from FeedCurrent T128M!`
- After sending, it waits 1 second for a response and prints any received data.
- The cycle repeats indefinitely.

## Important Notes
- Baud rate: **9600**, 8 data bits, 1 stop bit, no parity.
- The EN pin (GPIO14) is set HIGH before transmission and LOW after to enable reception.
- To test reception, connect another RS485 device that echoes or sends data.

## Related Resources
- Pin definition: `../pin_definitions/T128M/T128M_pin_definition.md`