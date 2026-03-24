# F16 Arduino Example 02: Read Digital Inputs

## Description
This example demonstrates how to read the 16 digital input channels on the F16 board via the **PCF8575** I/O expander (address `0x24`). The status of all inputs is read and printed as a 16‑bit binary value to the Serial Monitor every 500 ms.

## File Structure
- `src/F16_02_read_digital_inputs.ino` – Arduino source code.
- `precompiled/F16_02_read_digital_inputs.bin` – Precompiled firmware binary for ESP32‑S3.

## Using the Precompiled Binary
Flash `precompiled/F16_02_read_digital_inputs.bin` to address `0x0` using ESP Flash Download Tool or `esptool.py`.

## Compiling from Source
- **Environment**: Arduino IDE with ESP32‑S3 board support.
- **Dependencies**: Install `PCF8575` library via Library Manager.
- **Steps**: Open the `.ino` file, select `esp32-s3-devkitc-1`, and upload.

## Expected Behavior
- On startup, Serial Monitor displays:  
  `FeedCurrent F16 16 channel input state 0:ON  1:OFF`
- Every 500 ms, the 16‑bit input state is printed in binary format.
- Each bit corresponds to an input channel (bit 0 = channel 1, bit 15 = channel 16).
- A `0` indicates the input is **ON** (active LOW), `1` indicates **OFF** (active HIGH). Refer to the pin definition for logic level details.

## Important Notes
- **PCF8575**: I2C address `0x24`, inputs connected to pins 0‑15.
- **I2C pins**: SDA = GPIO8, SCL = GPIO18.
- **Serial Monitor**: Set baud rate to **115200**.
- The example reads all 16 inputs in a loop and does not include debouncing.

## Related Resources
- Pin definition: `../pin_definitions/F16/F16_pin_definition.md`