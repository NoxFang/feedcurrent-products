# FeedCurrent B8M Arduino Example 11: Digital Input Trigger Output Directly

## Description
This example links the 8 digital inputs to the 8 MOSFET outputs via the PCF8575. When an input (P8-P15) is LOW, the corresponding output (P0-P7) is set LOW (output ON).

## File Structure
- `src/B8M_11_input_trigger_output.ino` – Arduino source code.
- `precompiled/B8M_11_input_trigger_output.bin` – Precompiled binary.

## Using the Precompiled Binary
Flash `precompiled/B8M_11_input_trigger_output.bin` to `0x0`.

## Compiling from Source
- **Dependencies**: `PCF8575` library.
- **Steps**: Compile and upload.

## Expected Behavior
- Connecting an input pin to GND will activate its corresponding output.
- Mapping: Input 1 (P8) → Output 1 (P0), ..., Input 8 (P15) → Output 8 (P7).

## Important Notes
- I2C address `0x22`, SDA/SCL as before.
- Inputs have pull-up resistors; no external pull-up needed.
- Output active LOW.