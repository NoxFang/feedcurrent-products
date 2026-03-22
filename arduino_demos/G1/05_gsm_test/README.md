# G1 Arduino Example 05: GSM Test (SIM7600)

## Description
This example demonstrates a simple serial bridge between the USB‑UART (Serial Monitor) and the SIM7600 4G module on the G1 controller. It forwards data bidirectionally, allowing you to send AT commands to the module and view its responses.

## File Structure
- `src/G1_05_gsm_test.ino` – Arduino source code.
- `precompiled/G1_05_gsm_test.bin` – Precompiled firmware binary for ESP32‑S3 (to be added).

## Using the Precompiled Binary
1. Download the `.bin` file from the `precompiled/` folder.
2. Use the official **ESP Flash Download Tool** or `esptool.py` to flash it to the G1 controller.
3. **Flash Address**: `0x0` (as indicated in the forum post).

## Compiling from Source
1. **Environment**: Install Arduino IDE and add ESP32‑S3 board support (via Boards Manager).
2. **Dependencies**: None (uses built‑in `HardwareSerial`).
3. **Steps**:
   - Open `src/G1_05_gsm_test.ino` in Arduino IDE.
   - Select the correct board (`esp32-s3-devkitc-1`) and port.
   - Compile and upload.

## Expected Behavior
After uploading, open the Serial Monitor at **115200 baud**. The program acts as a transparent bridge:
- Any characters you type in the Serial Monitor are sent to the SIM7600 module via UART (GPIO9=RX, GPIO10=TX).
- Any response from the SIM7600 is printed to the Serial Monitor.

You can now test AT commands, for example:
AT
You should see a response like `OK`.

## Important Notes
- **SIM7600 UART pins**: RX = GPIO9 (ESP32 receives from module), TX = GPIO10 (ESP32 sends to module). This matches the G1 hardware connection.
- **Baud rate**: 115200 (both the USB Serial and the SIM7600 UART).
- **No AT command parsing**: The code simply forwards raw data; it does not interpret or buffer commands. This is useful for debugging and manual testing.
- **Power**: Ensure the G1 is powered with 12 V DC to supply the SIM7600 module. The module may require a strong power source, especially during network registration.
- **Antenna**: Connect the appropriate antennas (main 4G antenna, GPS antenna if needed) to the SIM7600 module for proper operation.

## Related Resources
- Pin definition: `../pin_definitions/G1/G1_pin_definition.md`
- [SIM7600 AT commands manual](https://www.simcom.com/documents/SIM7600_Series_AT_Command_Manual_V1.07.pdf)