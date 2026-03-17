# FeedCurrent B24 Controller Arduino Example 01: Turn ON/OFF OUTPUT

## Description
This example demonstrates how to control the 24 relay outputs on the B24 board via the **PCF8575 output chips** (addresses `0x22`, `0x24`, `0x25`). It sequentially turns on each output (pins 0-23) and then turns them off in a loop.

## File Structure
- `src/B24_01_turn_on_off_output.ino` – Arduino source code.
- `precompiled/1-relay.ino.merged.bin` – Precompiled firmware binary for ESP32-S3.

## Using the Precompiled Binary
Flash `precompiled/1-relay.ino.merged.bin` to address `0x0` using ESP Flash Download Tool or `esptool.py`.

## Compiling from Source
- **Environment**: Arduino IDE with ESP32-S3 board support.
- **Dependencies**: Install `PCF8575` library (e.g., by Rob Tillaart) via Library Manager.
- **Steps**: Open the `.ino` file, select `esp32-s3-devkitc-1`, and upload.

## Expected Behavior
Relays 1-24 will turn on sequentially (200ms delay), then turn off sequentially, repeating in a loop.

## Important Notes
- **PCF8575 (Output)**: I2C addresses `0x22`, `0x24`, `0x25`, outputs connected to pins 0-23 (active LOW).
- **I2C pins**: SDA=GPIO8, SCL=GPIO18.
- **Serial Monitor** (optional) shows debug messages at 115200 baud.
