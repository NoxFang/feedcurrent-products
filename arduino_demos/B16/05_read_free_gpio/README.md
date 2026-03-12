# FeedCurrent B16 Arduino Example 05: Read Free GPIO State

## Description
This example monitors the state of 8 free GPIO pins (40,7,48,47,13,14,21,0) and prints any change to the Serial Monitor.

## File Structure
- `src/B16_05_read_free_gpio.ino` – Arduino source code.
- `precompiled/B16_05_read_free_gpio.bin` – Precompiled binary.

## Using the Precompiled Binary
Flash `precompiled/B16_05_read_free_gpio.bin` to `0x0`.

## Compiling from Source
- No extra libraries needed.
- Compile and upload.

## Expected Output
When a pin changes, you'll see messages like:
GPIO 40 changed to HIGH
GPIO 13 changed to LOW

## Important Notes
- **Pin list**: GPIO40,7,48,47,13,14,21,0. The first four have pull-up resistors on PCB (suitable for 1-Wire), the last four do not.
- GPIO0 should not be pulled LOW during reset.