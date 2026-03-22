# AIO Hybrid Arduino Example 03: Read Analog Input Ports Value

## Description
This example demonstrates how to read the four analog input ports on the AIO Hybrid board using the ESP32‑S3 internal ADC. It reads the voltage levels from GPIO5 (A1), GPIO7 (A2), GPIO6 (A3), and GPIO4 (A4) and prints the raw ADC values to the Serial Monitor every 2 seconds.

## File Structure
- `src/AIO_03_read_analog_inputs.ino` – Arduino source code.
- `precompiled/AIO_03_read_analog_inputs.bin` – Precompiled firmware binary for ESP32‑S3 (to be added).

## Using the Precompiled Binary
1. Download the `.bin` file from the `precompiled/` folder.
2. Use the official **ESP Flash Download Tool** or `esptool.py` to flash it to the AIO Hybrid controller.
3. **Flash Address**: `0x0` (as indicated in the forum post).

## Compiling from Source
1. **Environment**: Install Arduino IDE and add ESP32‑S3 board support (via Boards Manager).
2. **Dependencies**: None (uses built‑in ADC functions).
3. **Steps**:
   - Open `src/AIO_03_read_analog_inputs.ino` in Arduino IDE.
   - Select the correct board (`esp32-s3-devkitc-1`) and port.
   - Compile and upload.

## Expected Output
After uploading, open the Serial Monitor at **115200 baud**. You will see output like:
AIO Example 03: Read Analog Input Ports Value
==============================================
Pin Configuration:
A1 -> GPIO 5
A2 -> GPIO 7
A3 -> GPIO 6
A4 -> GPIO 4

A1=1234
A2=2345
A3=3456
A4=4567

The values are raw ADC readings (0–4095, 12‑bit resolution). To convert to voltage, multiply by (3.3V / 4095) if using the default attenuation.

## Important Notes
- **Analog pins**: A1=GPIO5, A2=GPIO7, A3=GPIO6, A4=GPIO4 (as defined in the code).
- **Resolution**: ESP32‑S3 ADC has 12‑bit resolution (0–4095).
- **Attenuation**: The code does not set ADC attenuation; the default attenuation (`ADC_ATTEN_DB_0`) limits the input range to approximately 0–1.1V. If you need a wider range (e.g., 0–3.3V), add `analogSetAttenuation(ADC_11db);` in `setup()`.
- **Voltage divider**: If your analog inputs use external voltage dividers (e.g., for 0–5V), you must scale the raw readings accordingly.
- **Sampling rate**: The loop reads all four channels every 2 seconds. Adjust the `delay()` if faster sampling is needed.

## Related Resources
- Pin definition: `../pin_definitions/AIO/AIO_pin_definition.md`
- Forum source: https://www.kincony.com/forum/showthread.php?tid=8537