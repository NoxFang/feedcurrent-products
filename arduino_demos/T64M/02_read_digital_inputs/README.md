# T64M Arduino Example 02: Read Digital Inputs

## Description
This example reads the status of all 64 digital inputs on the T64M board using four PCF8575 I/O expanders. The input states are printed to the Serial Monitor every 500 ms, grouped into four 16‑bit binary strings.

- Inputs 1‑16: PCF8575 at I2C address `0x25`
- Inputs 17‑32: PCF8575 at I2C address `0x24`
- Inputs 33‑48: PCF8575 at I2C address `0x21`
- Inputs 49‑64: PCF8575 at I2C address `0x20`

## File Structure
- `src/T64M_02_read_digital_inputs.ino` – Arduino source code.
- `precompiled/T64M_02_read_digital_inputs.bin` – Precompiled firmware binary for ESP32‑S3.

## Using the Precompiled Binary
Flash `precompiled/T64M_02_read_digital_inputs.bin` to address `0x0` using ESP Flash Download Tool or `esptool.py`.

## Compiling from Source
- **Environment**: Arduino IDE with ESP32‑S3 board support.
- **Dependencies**: Install `PCF8575` library via Library Manager.
- **Steps**: Open the `.ino` file, select `esp32-s3-devkitc-1`, and upload.

## Hardware Connections
| Signal | GPIO |
|--------|------|
| SDA    | 12   |
| SCL    | 11   |

| PCF8575 | I2C Address | Input Channels |
|---------|-------------|----------------|
| First   | 0x25        | 1‑16           |
| Second  | 0x24        | 17‑32          |
| Third   | 0x21        | 33‑48          |
| Fourth  | 0x20        | 49‑64          |

## Expected Behavior
- On startup, the Serial Monitor (115200 baud) displays:  
  `KinCony F64 64 channel input state  0:ON  1:OFF`
- Every 500 ms, a header `Reading Inputs...` is printed, followed by four lines each showing a 16‑bit binary string representing the state of inputs in that group:
  ```cpp
  Input 1~16: 0000000000000000
  Input 17~32: 1111111111111111
  Input 33~48: 1010101010101010
  Input 49~64: 0101010101010101
  ```
- A `0` indicates the input is **ON** (active‑LOW), a `1` indicates **OFF** (active‑HIGH). Refer to the pin definition for logic level details.

## Important Notes
- The example reads all 64 inputs and prints them in groups.
- No debouncing is implemented; for noisy inputs, consider adding hardware filtering or software delay.

## Related Resources
- Pin definition: `../pin_definitions/T64M/T64M_pin_definition.md`