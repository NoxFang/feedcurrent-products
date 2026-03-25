# T16M Arduino Example 02: Read Digital Inputs

## Description
This example reads the status of all 16 digital inputs on the T16M board via a PCF8575 I/O expander (address `0x24`). The combined 16‑bit input state is printed as a binary value to the Serial Monitor every 500 ms.

## File Structure
- `src/T16M_02_read_digital_inputs.ino` – Arduino source code.
- `precompiled/T16M_02_read_digital_inputs.bin` – Precompiled firmware binary for ESP32‑S3.

## Using the Precompiled Binary
Flash `precompiled/T16M_02_read_digital_inputs.bin` to address `0x0` using ESP Flash Download Tool or `esptool.py`.

## Compiling from Source
- **Environment**: Arduino IDE with ESP32‑S3 board support.
- **Dependencies**: Install `PCF8575` library via Library Manager.
- **Steps**: Open the `.ino` file, select `esp32-s3-devkitc-1`, and upload.

## Hardware Connections
| Signal | GPIO |
|--------|------|
| SDA    | 11   |
| SCL    | 12   |
| PCF8575 I2C Address | 0x24 |

## Expected Behavior
- On startup, the Serial Monitor (115200 baud) displays:  
  `FeedCurrent T16M 16 channel input state 0:ON  1:OFF`
- Every 500 ms, a 16‑bit binary value is printed, e.g.:  
  `Input state: 0000000000000000` (all inputs OFF)  
  `Input state: 1010101010101010` (alternating pattern)
- A `0` indicates the input is **ON** (active‑LOW), a `1` indicates **OFF** (active‑HIGH). Refer to the pin definition for logic level details.

## Important Notes
- The example reads all 16 inputs and combines them into a single binary string.
- No debouncing is implemented; for noisy inputs, consider adding hardware filtering or software delay.

## Related Resources
- Pin definition: `../pin_definitions/T16M/T16M_pin_definition.md`