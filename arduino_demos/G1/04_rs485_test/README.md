# G1 Arduino Example 04: RS485 Communication Test

## Description
This example demonstrates a basic RS485 communication test on the G1 controller. It periodically sends a test message over the RS485 bus and listens for any incoming messages, printing received data to the Serial Monitor.

## File Structure
- `src/G1_04_rs485_test.ino` – Arduino source code.
- `precompiled/G1_04_rs485_test.bin` – Precompiled firmware binary for ESP32‑S3 (to be added).

## Using the Precompiled Binary
1. Download the `.bin` file from the `precompiled/` folder.
2. Use the official **ESP Flash Download Tool** or `esptool.py` to flash it to the G1 controller.
3. **Flash Address**: `0x0` (as indicated in the forum post).

## Compiling from Source
1. **Environment**: Install Arduino IDE and add ESP32‑S3 board support (via Boards Manager).
2. **Dependencies**: None (uses built‑in `HardwareSerial`).
3. **Steps**:
   - Open `src/G1_04_rs485_test.ino` in Arduino IDE.
   - Select the correct board (`esp32-s3-devkitc-1`) and port.
   - Compile and upload.

## Expected Behavior
- After uploading, open the Serial Monitor at **115200 baud**. You will see:
RS485 Test Start、
- Every 3 seconds, the board sends `"Hello from FeedCurrent G1!"` over RS485.
- If another RS485 device is connected and responds, received messages will be printed as:
Received: <response message>

## Important Notes
- **RS485 pins**: RXD = GPIO18, TXD = GPIO8 (as defined in the code). Verify these match your hardware wiring.
- **Baud rate**: 9600, 8N1 (8 data bits, no parity, 1 stop bit).
- **Half‑duplex**: RS485 is half‑duplex; the code does not include explicit direction control (DE/RE). If your transceiver requires direction control, modify the code accordingly.
- **Loopback test**: To test without another device, connect the RS485 TX and RX pins (through a converter or directly) to see your own sent message echoed back.
- **Serial Monitor**: Debug output is printed to the USB Serial at 115200 baud.

## Related Resources
- Pin definition: `../pin_definitions/G1/G1_pin_definition.md`