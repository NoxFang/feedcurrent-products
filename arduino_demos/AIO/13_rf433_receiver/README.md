# AIO Hybrid Arduino Example 13: RF433 Receiver (rc-switch)

## Description
This example demonstrates how to receive 433 MHz RF signals using the rc‑switch library. It listens on GPIO40 for incoming RF packets and prints the received value, bit length, and protocol number to the Serial Monitor.

## File Structure
- `src/AIO_13_rf433_receiver.ino` – Arduino source code.
- `precompiled/AIO_13_rf433_receiver.bin` – Precompiled firmware binary for ESP32‑S3 (to be added).

## Using the Precompiled Binary
1. Download the `.bin` file from the `precompiled/` folder.
2. Use the official **ESP Flash Download Tool** or `esptool.py` to flash it to the AIO Hybrid controller.
3. **Flash Address**: `0x0` (as indicated in the forum post).

## Compiling from Source
1. **Environment**: Install Arduino IDE and add ESP32‑S3 board support (via Boards Manager).
2. **Dependencies**:
   - `RCSwitch.h` – Install via Library Manager (search for "rc-switch").
3. **Steps**:
   - Open `src/AIO_13_rf433_receiver.ino` in Arduino IDE.
   - Select the correct board (`esp32-s3-devkitc-1`) and port.
   - Compile and upload.

## Expected Output
After uploading, open the Serial Monitor at **9600 baud**. When an RF signal is received, you will see output like:
Received 123456 / 24bit Protocol: 1
- **Received value**: The decoded decimal value of the RF packet.
- **Bit length**: Number of bits in the received packet.
- **Protocol**: The protocol number detected by the library.

The message `"begin test"` is printed once at startup.

## Important Notes
- **RF receiver pin**: GPIO40 (as defined in `enableReceive(digitalPinToInterrupt(40))`). This matches the AIO Hybrid pin definition (GPIO40 is used for RF433 receiver).
- **Baud rate**: Serial monitor must be set to **9600 baud**.
- **Library**: The example uses the [rc-switch library](https://github.com/sui77/rc-switch/), which is commonly used for 433 MHz remote control decoding.
- **Interrupt**: The library uses an interrupt on the receiving pin. Ensure no other code interferes with the same interrupt.
- **No signal**: When no RF signal is present, the loop does nothing – there is no continuous serial output.

## Related Resources
- Pin definition: `../pin_definitions/AIO/AIO_pin_definition.md`
- [rc-switch library documentation](https://github.com/sui77/rc-switch/)