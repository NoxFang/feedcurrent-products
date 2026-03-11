# FeedCurrent B8M Arduino Example 02: Read Digital Input Ports State

## Description
This example reads the 8 digital inputs (P8-P15) on the PCF8575 expander and prints their states to the Serial Monitor as a binary number.

## File Structure
- `src/B8M_02_read_digital_input.ino` – Arduino source code.
- `precompiled/B8M_02_read_digital_input.bin` – Precompiled binary.

## Using the Precompiled Binary
Flash `precompiled/B8M_02_read_digital_input.bin` to `0x0`.

## Compiling from Source
- **Dependencies**: `PCF8575` library (same as example 01).
- **Steps**: Compile and upload.

## Expected Output (Serial Monitor at 115200 baud)
Input state: 00000000
Each bit represents an input (bit8 = P8, bit15 = P15). `0` = active (connected to GND), `1` = inactive (with pull-up).

## Important Notes
- Inputs on B8M have pull-up resistors, so they read HIGH when open. Connect to GND to trigger LOW.
- I2C address `0x22`, pins SDA/SCL as above.