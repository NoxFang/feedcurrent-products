# FeedCurrent B24 Controller Arduino Example 05: Read Free GPIO State

## Description
This example monitors the state of free GPIO pins on the B24 board and prints any change to the Serial Monitor.

## File Structure
- `src/B24_05_read_free_gpio.ino` – Arduino source code.
- `precompiled/B24_05_read_free_gpio.bin` – Precompiled firmware binary for ESP32-S3.

## Using the Precompiled Binary
Flash `precompiled/B24_05_read_free_gpio.bin` to address `0x0` using ESP Flash Download Tool or `esptool.py`.

## Compiling from Source
- **Environment**: Arduino IDE with ESP32-S3 board support.
- **Dependencies**: None (built-in Arduino functions).
- **Steps**: Open the `.ino` file, select `esp32-s3-devkitc-1`, and upload.

## Expected Output
When a pin changes, you'll see messages like:
```
GPIO 40 changed to HIGH
GPIO 13 changed to LOW
```

## Important Notes
- **Free GPIO pins**: GPIO40, GPIO7, GPIO48, GPIO47, GPIO13, GPIO14, GPIO21, GPIO0.
- Some pins have pull-up resistors on PCB (suitable for 1-Wire).
- GPIO0 should not be pulled LOW during reset.
- **Serial Monitor** shows debug messages at 115200 baud.
