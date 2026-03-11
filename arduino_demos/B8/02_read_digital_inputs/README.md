# FeedCurrent B8 Controller Arduino Example 02: Read Digital Input Ports State

## Description
This example reads the 8 digital inputs (P0-P7) on the PCF8575 expander and prints their states to the Serial Monitor as a binary number.

## File Structure
- `src/B8_02_read_digital_inputs.ino` – Arduino source code.
- `precompiled/B8_02_read_digital_inputs.bin` – Precompiled firmware binary.

## Using the Precompiled Binary
- Flash `precompiled/B8_02_read_digital_inputs.bin` to address `0x0`.

## Compiling from Source
- **Dependencies**: `PCF8575` library (same as example 01).
- **Steps**: Compile and upload as usual.

## Expected Output (Serial Monitor at 115200 baud)
Input state: 00000000
Each bit represents an input (bit0 = P0, bit7 = P7). `0` = active (connected to GND), `1` = inactive (with pull-up).

## Important Notes
- Inputs on B8 have pull-up resistors, so they read HIGH when open. Connect to GND to trigger LOW.
- I2C address `0x22`, pins SDA/SCL as above.