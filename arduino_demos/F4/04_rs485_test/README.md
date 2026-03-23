# F4 Arduino Example 04: RS485 Communication Test

## Description
This example tests RS485 communication on the F4 board. It periodically sends a test message over the RS485 bus and prints any received data to the Serial Monitor.

## File Structure
- `src/F4_04_rs485_test.ino` – Arduino source code.
- `precompiled/F4_04_rs485_test.bin` – Precompiled firmware binary for ESP32‑S3.

## Using the Precompiled Binary
Flash `precompiled/F4_04_rs485_test.bin` to address `0x0` using ESP Flash Download Tool or `esptool.py`.

## Compiling from Source
- **Environment**: Arduino IDE with ESP32‑S3 board support.
- **Dependencies**: None (uses built‑in `HardwareSerial`).
- **Steps**: Open the `.ino` file, select `esp32-s3-devkitc-1`, and upload.

## Expected Behavior
After uploading, open the Serial Monitor at **115200 baud**. You will see:
RS485 Test Start
Every 3 seconds, the board sends the message `"Hello from FeedCurrent F4!"`. If another RS485 device responds, the received message is printed as:
Received: <response>

## Important Notes
- **RS485 pins**: TX=GPIO16, RX=GPIO17.
- **Baud rate**: 9600, 8N1 (8 data bits, no parity, 1 stop bit).
- The example does **not** control the RS485 direction pin (DE/RE) – it assumes the transceiver is always in transmit/receive mode or uses automatic direction control.
- The loop sends a message every 3 seconds (1 second delay after sending, then 2 seconds before the next send).
- To test without another device, connect the RS485 TX and RX pins together (loopback) to see your own messages echoed.

## Related Resources
- Pin definition: `../pin_definitions/F4/F4_pin_definition.md`