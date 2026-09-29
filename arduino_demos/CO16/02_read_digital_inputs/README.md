# CO16 Arduino Example 02: Read Digital Inputs

## Description
This example demonstrates how to read the state of the 16 digital input channels on the CO16 board using an XL9535 I/O expander (PCA9555 compatible, I2C address `0x24`).  
The combined 16‑bit input state is printed as a binary value to the Serial Monitor every second.

## File Structure
- `src/CO16_02_read_digital_inputs.ino` – Arduino source code.
- `precompiled/CO16_02_read_digital_inputs.bin` – Precompiled firmware binary for ESP32‑S3.

## Using the Precompiled Binary (.bin)
1. Download the `.bin` file from the `precompiled/` folder.
2. Use the official **ESP Flash Download Tool** or `esptool.py` to flash it to the CO16 controller.
3. **Flash Address**: `0x0`.

## Compiling from Source
1. **Environment**: Install Arduino IDE and add ESP32‑S3 board support (via Boards Manager).
2. **Dependencies**: Install the `PCA95x5` library via Library Manager (search for “PCA95x5” by Renzo Mischianti or similar).
3. **Steps**: Open `src/CO16_02_read_digital_inputs.ino` in Arduino IDE, select the board `esp32-s3-devkitc-1` and the correct port, then compile and upload.

## Hardware Connections
| Signal | GPIO |
|--------|------|
| I2C SDA | GPIO8 |
| I2C SCL | GPIO18 |
| XL9535 I2C Address | 0x24 |

**Note**: The CO16 board includes an onboard XL9535 expander for digital inputs. No external wiring is required for the I2C bus.

## Expected Behavior
- On startup, the Serial Monitor (115200 baud) begins printing after a 2‑second delay.
- Every 1 second, a line is printed:
```
1-16 input states: 0000000000000000
```
The binary value represents the state of all 16 inputs.  
A `0` indicates the input is **ON** (active‑LOW), a `1` indicates **OFF** (active‑HIGH). Refer to the pin definition for logic level details.

## Important Notes
- **I2C Frequency**: 40 kHz (configured via `Wire.begin(8, 18, 40000)`).
- **Polarity**: Set to original (no inversion) using `ioex1.polarity(PCA95x5::Polarity::ORIGINAL_ALL)`.
- **Direction**: All 16 pins configured as inputs.
- The code comment mentions three expander chips, but this implementation only uses one XL9535 at address `0x24` (channels 1‑16).
- No debouncing is implemented; for noisy inputs, consider adding hardware filtering or software delay.

## Related Resources
- Pin definition: `../pin_definitions/CO16/CO16_pin_definition.md`