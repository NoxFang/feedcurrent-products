# F16 Arduino Example 04: RS485 Communication Test

## Description
This example demonstrates basic RS485 communication using the F16 board. It sends a test message every 3 seconds and prints any received data to the Serial Monitor. The RS485 interface uses UART1 with TX on GPIO16 and RX on GPIO17.

## File Structure
- `src/F16_04_rs485_test.ino` – Arduino source code.
- `precompiled/F16_04_rs485_test.bin` – Precompiled firmware binary for ESP32‑S3.

## Using the Precompiled Binary
Flash `precompiled/F16_04_rs485_test.bin` to address `0x0` using ESP Flash Download Tool or `esptool.py`.

## Compiling from Source
- **Environment**: Arduino IDE with ESP32‑S3 board support.
- **Dependencies**: None beyond the standard ESP32 core.
- **Steps**: Open the `.ino` file, select `esp32-s3-devkitc-1`, and upload.

## Hardware Setup
The F16 board includes an onboard RS485 transceiver. No external module is required.

| Component | Connection |
|-----------|------------|
| RS485 TX  | GPIO16 (UART1 TX) |
| RS485 RX  | GPIO17 (UART1 RX) |
| RS485 A/B | Connect to other RS485 device |

**Note**: The onboard RS485 circuit handles direction control automatically (or uses a transceiver with auto‑direction). No manual direction control pin is used.

## Expected Behavior
- On startup, the RS485 interface is initialized at 9600 baud, 8 data bits, 1 stop bit, no parity.
- Every 3 seconds, the board sends the message: `Hello from FeedCurrent F16!`
- If any data is received on the RS485 bus, it is printed to the Serial Monitor in the format: `Received: [data]`
- The cycle repeats indefinitely.

Example Serial Monitor output:
RS485 Test Start
Received: Hello from FeedCurrent F16!
Received: Hello from FeedCurrent F16!
...

## Important Notes
- **Baud Rate**: 9600 (configurable in code)
- **Serial Monitor**: Set baud rate to **115200**
- This example assumes the RS485 bus is properly terminated and that other devices respond with data to test reception. If no device is connected, only transmission will occur.

## Related Resources
- Pin definition: `../pin_definitions/F16/F16_pin_definition.md`