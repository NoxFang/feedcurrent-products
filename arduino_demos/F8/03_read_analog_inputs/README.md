# F8 Arduino Example 03: Read Analog Input Ports Value

## Description
This example reads the raw analog values from four analog input pins (A1–A4) using the ESP32‑S3 internal ADC. The values (0–4095, 12‑bit) are printed to the Serial Monitor every 2 seconds.

## File Structure
- `src/F8_03_read_analog_inputs.ino` – Arduino source code.
- `precompiled/F8_03_read_analog_inputs.bin` – Precompiled firmware binary for ESP32‑S3.

## Using the Precompiled Binary
Flash `precompiled/F8_03_read_analog_inputs.bin` to address `0x0` using ESP Flash Download Tool or `esptool.py`.

## Compiling from Source
- **Environment**: Arduino IDE with ESP32‑S3 board support.
- **Dependencies**: None (uses built‑in `analogRead`).
- **Steps**: Open the `.ino` file, select `esp32-s3-devkitc-1`, and upload.

## Expected Output
After uploading, open the Serial Monitor at **115200 baud**. You will see:
A1=1234
A2=2345
A3=3456
A4=4567

The values are raw ADC readings (0–4095). To convert to voltage, multiply by (3.3 V / 4095) if using default attenuation, or adjust based on your voltage divider.

## Important Notes
- **Analog pins**: A1=GPIO5, A2=GPIO7, A3=GPIO6, A4=GPIO4.
- **ADC resolution**: 12‑bit (0–4095).
- **Voltage range**: By default, the ESP32‑S3 ADC has a range of approximately 0–1.1 V. If your input exceeds this, use an external voltage divider or set ADC attenuation (`analogSetAttenuation(ADC_11db)`).
- **No external ADC** is used – this example relies on the built‑in ADC.

## Related Resources
- Pin definition: `../pin_definitions/F8/F8_pin_definition.md`