# FeedCurrent B8M Arduino Example 01: Turn ON/OFF OUTPUT

## Description
This example demonstrates how to control the 8 MOSFET outputs on the B8M board via a PCF8575 I/O expander. It sequentially turns on each output (P0-P7) and then turns them off in a loop.

## File Structure
- `src/B8M_01_sequential_on_off.ino` – Arduino source code.
- `precompiled/B8M_01_sequential_on_off.bin` – Precompiled firmware binary for ESP32-S3.

## Using the Precompiled Binary
Flash `precompiled/B8M_01_sequential_on_off.bin` to address `0x0` using ESP Flash Download Tool or `esptool.py`.

## Compiling from Source
- **Environment**: Arduino IDE with ESP32-S3 board support.
- **Dependencies**: Install `PCF8575` library (e.g., by Rob Tillaart) via Library Manager.
- **Steps**: Open the `.ino` file, select `esp32-s3-devkitc-1`, and upload.

## Expected Behavior
Outputs 1-8 will turn on sequentially (200ms delay), then turn off sequentially, repeating in a loop.

## Important Notes
- **PCF8575**: I2C address `0x22`, outputs connected to pins 0-7 (active LOW).
- **I2C pins**: SDA=GPIO8, SCL=GPIO18.
- **Serial Monitor** (optional) shows debug messages at 115200 baud.