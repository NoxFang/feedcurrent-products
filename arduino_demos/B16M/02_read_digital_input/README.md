# FeedCurrent B16M Controller Arduino Example 02: Read Digital Input Ports State

## Description
This example reads the 16 digital inputs via the **PCF8575 input chip** (address `0x24`) and prints their states to the Serial Monitor as a 16-bit binary number.

## File Structure
- `src/B16M_02_read_digital_input.ino` – Arduino source code.
- `precompiled/B16M_02_read_digital_input.bin` – Precompiled binary.

## Using the Precompiled Binary
Flash `precompiled/B16M_02_read_digital_input.bin` to `0x0`.

## Compiling from Source
- **Dependencies**: `PCF8575` library (same as example 01).
- **Steps**: Compile and upload.

## Expected Output (Serial Monitor at 115200 baud)
Input state: 0000000000000000
Each bit represents an input (bit0 = input 1, bit15 = input 16). `0` = active (connected to GND), `1` = inactive (with pull-up).

## Important Notes
- **PCF8575 (Input)**: I2C address `0x24`, inputs connected to pins 0-15 (active LOW).
- **I2C pins**: SDA=GPIO38, SCL=GPIO39.
- Inputs have pull-up resistors, so they read HIGH when open.