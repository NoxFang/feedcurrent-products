# FeedCurrent B32M Controller Arduino Example 01: Turn ON/OFF OUTPUT

## Description
This example demonstrates how to control the 32 MOSFET outputs on the B32M board via the **PCF8575 output chips** (addresses `0x26`, `0x25`, `0x24`). It sequentially turns on each output (pins 0-31) and then turns them off in a loop.

## File Structure
- `src/B32M_01_turn_on_off_output.ino` – Arduino source code.
- `precompiled/B32M_01_turn_on_off_output.bin` – Precompiled firmware binary for ESP32-S3.

## Using the Precompiled Binary
Flash `precompiled/B32M_01_turn_on_off_output.bin` to address `0x0` using ESP Flash Download Tool or `esptool.py`.

## Compiling from Source
- **Environment**: Arduino IDE with ESP32-S3 board support.
- **Dependencies**: Install `PCF8575` library (e.g., by Rob Tillaart) via Library Manager.
- **Steps**: Open the `.ino` file, select `esp32-s3-devkitc-1`, and upload.

## Expected Behavior
Outputs 1-32 will turn on sequentially (200ms delay), then turn off sequentially, repeating in a loop.

## Important Notes
- **PCF8575 (Output)**: I2C addresses `0x26` (outputs 1-8, 25-32), `0x25` (outputs 9-16), `0x24` (outputs 17-24), outputs are active LOW.
- **I2C pins**: SDA=GPIO8, SCL=GPIO18.
- **Serial Monitor** (optional) shows debug messages at 115200 baud.
