# AIO Hybrid Arduino Example 09: How to Communicate with Tuya Zigbee Module

## Description
This example demonstrates basic communication with a Tuya Zigbee module connected via UART. It sends a predefined command packet to the module and prints any received response to the Serial Monitor.

## File Structure
- `src/AIO_09_tuya_zigbee.ino` – Arduino source code.
- `precompiled/AIO_09_tuya_zigbee.bin` – Precompiled firmware binary for ESP32‑S3 (to be added).

## Using the Precompiled Binary
1. Download the `.bin` file from the `precompiled/` folder.
2. Use the official **ESP Flash Download Tool** or `esptool.py` to flash it to the AIO Hybrid controller.
3. **Flash Address**: `0x0` (as indicated in the forum post).

## Compiling from Source
1. **Environment**: Install Arduino IDE and add ESP32‑S3 board support (via Boards Manager).
2. **Dependencies**: None (uses built‑in Serial).
3. **Steps**:
   - Open `src/AIO_09_tuya_zigbee.ino` in Arduino IDE.
   - Select the correct board (`esp32-s3-devkitc-1`) and port.
   - Compile and upload.

## Expected Behavior
After uploading, open the Serial Monitor at **115200 baud**. The program will:
- Send a fixed command packet `55 AA 00 00 04 00 00 00 01 00 04` to the Tuya Zigbee module via UART (GPIO15 RX, GPIO48 TX).
- Print the sent data to the Serial Monitor.
- Then, in the loop, it continuously listens for responses from the module and prints any received bytes in hexadecimal format.

Example output:
send data to Tuya module:
55 AA 00 00 04 00 00 00 01 00 04
received from tuya: 55 AA 03 00 ...

## Important Notes
- **Tuya Zigbee pins**: RX = GPIO15 (ESP32 receives from module), TX = GPIO48 (ESP32 sends to module).
- **Baud rate**: 115200, 8N1.
- **Command packet**: The example sends a fixed command (`0x55 0xAA 0x00 0x00 0x04 0x00 0x00 0x00 0x01 0x00 0x04`). This is likely a test or initialization command; refer to the Tuya Zigbee module documentation for actual protocol details.
- **Serial ports**: The code uses `Serial0` (USB CDC) for debug output and `Serial2` for communication with the Zigbee module.
- **Polling**: The loop checks for available data every 100 ms and prints any received bytes.

## Related Resources
- Pin definition: `../pin_definitions/AIO/AIO_pin_definition.md`
- Forum source: https://www.kincony.com/forum/showthread.php?tid=8543