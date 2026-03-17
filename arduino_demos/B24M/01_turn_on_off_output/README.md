# FeedCurrent B24M Controller Arduino Example 01: Turn ON/OFF OUTPUT

## Description
This example demonstrates how to control the 24 relay outputs on the B24M board via the **PCF8575 output chips** (addresses `0x25` and `0x24`). It sequentially turns on each output (pins 0-15 on both chips) and then turns them off in a loop.

## File Structure
- `src/B24M_01_turn_on_off_output.ino` – Arduino source code.
- `precompiled/B24M_01_turn_on_off_output.bin` – Precompiled firmware binary for ESP32-S3.

## Using the Precompiled Binary
Flash `precompiled/B24M_01_turn_on_off_output.bin` to address `0x0` using ESP Flash Download Tool or `esptool.py`.

## Compiling from Source
- **Environment**: Arduino IDE with ESP32-S3 board support.
- **Dependencies**: Install `PCF8575` library (e.g., by Rob Tillaart) via Library Manager.
- **Steps**: Open the `.ino` file, select `esp32-s3-devkitc-1`, and upload.

## Expected Behavior
Relays 1-24 will turn on sequentially (200ms delay), then turn off sequentially, repeating in a loop.

## Important Notes
- **PCF8575 (Outputs 1-8)**: I2C address `0x25`, pins P8-P15 (active LOW).
- **PCF8575 (Outputs 9-24)**: I2C address `0x24`, pins P0-P15 (active LOW).
- **I2C pins**: SDA=GPIO8, SCL=GPIO18.
- **Serial Monitor** (optional) shows debug messages at 115200 baud.
