# F24 Arduino Example 02: Read Digital Inputs

## Description
This example reads the status of all 24 digital inputs on the F24 board via two PCF8575 I/O expanders. The combined 24‑bit input state is printed as a binary value to the Serial Monitor every 500 ms.

- Inputs 1‑16: PCF8575 at I2C address `0x24`
- Inputs 17‑24: PCF8575 at I2C address `0x26`

## File Structure
- `src/F24_02_read_digital_inputs.ino` – Arduino source code.
- `precompiled/F24_02_read_digital_inputs.bin` – Precompiled firmware binary for ESP32‑S3.

## Using the Precompiled Binary
Flash `precompiled/F24_02_read_digital_inputs.bin` to address `0x0` using ESP Flash Download Tool or `esptool.py`.

## Compiling from Source
- **Environment**: Arduino IDE with ESP32‑S3 board support.
- **Dependencies**: Install `PCF8575` library via Library Manager.
- **Steps**: Open the `.ino` file, select `esp32-s3-devkitc-1`, and upload.

## Hardware Connections
| Signal | GPIO |
|--------|------|
| SDA    | 8    |
| SCL    | 18   |

| PCF8575 | I2C Address | Input Channels |
|---------|-------------|----------------|
| First   | 0x24        | 1‑16           |
| Second  | 0x26        | 17‑24          |

## Expected Behavior
- On startup, the Serial Monitor (115200 baud) displays:  
  `FeedCurrent F24 24 channel input state 0:ON  1:OFF`
- Every 500 ms, a 24‑bit binary value is printed, e.g.:  
  `Input state: 000000000000000000000000` (all inputs OFF)  
  `Input state: 101010101010101010101010` (alternating pattern)
- A `0` indicates the input is **ON** (active‑LOW), a `1` indicates **OFF** (active‑HIGH). Refer to the pin definition for logic level details.

## Important Notes
- The example reads all 24 inputs and combines them into a single binary string.
- No debouncing is implemented; for noisy inputs, consider adding hardware filtering or software delay.
- Inputs 17‑24 use only the first 8 pins of the second PCF8575 (pins 0‑7).

## Related Resources
- Pin definition: `../pin_definitions/F24/F24_pin_definition.md`