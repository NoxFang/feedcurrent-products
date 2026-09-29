# CO16 Arduino Example 03: Read Analog Inputs

## Description
This example demonstrates how to read the 16 analog input channels on the CO16 board using four ADS1115 16-bit ADC modules.  
Each ADS1115 handles 4 channels, and the measured input voltage is calibrated and printed to the Serial Monitor.

- **ADS1115-1 (U35)**: CH1–CH4, I2C address `0x48`
- **ADS1115-2 (U7)**:  CH5–CH8, I2C address `0x49`
- **ADS1115-3 (U15)**: CH9–CH12, I2C address `0x4B`
- **ADS1115-4 (U19)**: CH13–CH16, I2C address `0x4A`

Only channels with an input voltage greater than **0.5 V** are printed.

## File Structure
- `src/CO16_03_read_analog_inputs.ino` – Arduino source code.
- `precompiled/CO16_03_read_analog_inputs.bin` – Precompiled firmware binary for ESP32‑S3.

## Using the Precompiled Binary (.bin)
1. Download the `.bin` file from the `precompiled/` folder.
2. Use the official **ESP Flash Download Tool** or `esptool.py` to flash it to the CO16 controller.
3. **Flash Address**: `0x0`.

## Compiling from Source
1. **Environment**: Install Arduino IDE and add ESP32‑S3 board support (via Boards Manager).
2. **Dependencies**:
   - `Wire.h` (built‑in)
   - `DFRobot_ADS1115.h` – Install via Library Manager (search for “DFRobot ADS1115”).
3. **Steps**: Open `src/CO16_03_read_analog_inputs.ino` in Arduino IDE, select the board `esp32-s3-devkitc-1` and the correct port, then compile and upload.

## Hardware Connections
| Signal | GPIO |
|--------|------|
| I2C SDA | GPIO8 |
| I2C SCL | GPIO18 |

| ADS1115 Module | I2C Address | Channels |
|----------------|-------------|----------|
| ADS1115-1      | 0x48        | CH1–CH4  |
| ADS1115-2      | 0x49        | CH5–CH8  |
| ADS1115-3      | 0x4B        | CH9–CH12 |
| ADS1115-4      | 0x4A        | CH13–CH16|

**Note**: The CO16 board includes the ADS1115 modules onboard. No external wiring is required for the I2C bus.

## Expected Behavior
- On startup, the Serial Monitor (115200 baud) prints a header and configuration summary.
- Every 1 second, the code reads all 16 channels. For any channel whose calibrated voltage exceeds 0.5 V, a line is printed:
```
CH1: 2.34 V
CH5: 1.08 V
```
- If an ADS1115 module is not detected, an error message is printed, e.g.:
```ADS1115-1 (0x48) Disconnected!

## Calibration Details
The code applies the same calibration as the ESPHome configuration:
- **Gain**: 4.096 V (`eGAIN_ONE`)
- **Zero threshold**: readings ≤ 0.0025 V are treated as 0.
- **Multiplier**: 5.16696 (to convert ADC voltage to actual input voltage).
- **Clamp**: final voltage is limited to 0–10 V.

This means the actual input voltage is calculated as:
```
V_in = clamp( (V_adc ≤ 0.0025 ? 0 : V_adc) × 5.16696 , 0, 10 )
```

## Important Notes
- **Single‑ended mode**: All channels are read as single‑ended inputs.
- **Sample rate**: 128 samples per second (`eRATE_128`).
- **Serial Monitor**: Set baud rate to **115200**.
- The 0.5 V print threshold avoids displaying noise on unused channels.

## Related Resources
- Pin definition: `../pin_definitions/CO16/CO16_pin_definition.md`