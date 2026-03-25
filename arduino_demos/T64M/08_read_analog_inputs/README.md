# T64M Arduino Example 08: Read Analog Inputs (Built‑in ADC)

## Description
This example reads the four analog input channels (A1–A4) on the T64M board using the ESP32‑S3's built‑in 12‑bit ADC. The raw ADC values (0–4095) are printed to the Serial Monitor every 2 seconds.

## File Structure
- `src/T64M_08_read_analog_inputs.ino` – Arduino source code.
- `precompiled/T64M_08_read_analog_inputs.bin` – Precompiled firmware binary for ESP32‑S3.

## Using the Precompiled Binary
Flash `precompiled/T64M_08_read_analog_inputs.bin` to address `0x0` using ESP Flash Download Tool or `esptool.py`.

## Compiling from Source
- **Environment**: Arduino IDE with ESP32‑S3 board support.
- **Dependencies**: None beyond the standard ESP32 core.
- **Steps**: Open the `.ino` file, select `esp32-s3-devkitc-1`, and upload.

## Hardware Connections
| Analog Input | GPIO |
|--------------|------|
| A1           | 7    |
| A2           | 6    |
| A3           | 5    |
| A4           | 4    |

## Expected Behavior
- On startup, the board initializes the analog pins.
- Every 2 seconds, the raw ADC values for A1–A4 are printed to the Serial Monitor (115200 baud).
- Example output:
  ```cpp
  A1=1234
  A2=567
  A3=890
  A4=3210
  ```

## Important Notes
- The ESP32‑S3 ADC is 12‑bit (0–4095). Voltage can be calculated as `voltage = raw_value * (3.3 / 4095.0)`.
- No external ADC module is required; the board's built‑in ADC is used.
- Input voltage range is 0–3.3V. Do not exceed 3.3V to avoid damage.

## Related Resources
- Pin definition: `../pin_definitions/T64M/T64M_pin_definition.md`