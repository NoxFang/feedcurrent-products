# FeedCurrent B8M Arduino Example 05: Read Free GPIO State

## Description
This example reads the state of several free GPIO pins (13,40,14,48,0,47,7,21) and prints them to the Serial Monitor.

## File Structure
- `src/B8M_05_read_free_gpio.ino` – Arduino source code.
- `precompiled/B8M_05_read_free_gpio.bin` – Precompiled binary.

## Using the Precompiled Binary
Flash `precompiled/B8M_05_read_free_gpio.bin` to `0x0`.

## Compiling from Source
- No extra libraries needed.
- Compile and upload.

## Expected Output
GPIO13: 1, GPIO40: 0, GPIO14: 1, GPIO48: 0, GPIO0: 1, GPIO47: 0, GPIO7: 1, GPIO21: 0

## Important Notes
- GPIO7 is used as a 1-Wire pin (with pull-up). Ensure no conflict.
- GPIO0 should not be pulled LOW during reset.