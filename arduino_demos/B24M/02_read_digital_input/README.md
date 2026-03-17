# FeedCurrent B24M Controller Arduino Example 02: Read Digital Input

## Description
This example demonstrates how to read the state of 24 digital inputs on the B24M board via the **PCF8575 input chips** (addresses `0x22` and `0x25`). It reads all input states and prints them to the Serial Monitor.

## File Structure
- `src/B24M_02_read_digital_input.ino` – Arduino source code.
- `precompiled/B24M_02_read_digital_input.bin` – Precompiled firmware binary for ESP32-S3.

## Using the Precompiled Binary
Flash `precompiled/B24M_02_read_digital_input.bin` to address `0x0` using ESP Flash Download Tool or `esptool.py`.

## Compiling from Source
- **Environment**: Arduino IDE with ESP32-S3 board support.
- **Dependencies**: Install `PCF8575` library (e.g., by Rob Tillaart) via Library Manager.
- **Steps**: Open the `.ino` file, select `esp32-s3-devkitc-1`, and upload.

## Expected Behavior
The Serial Monitor will display the state of all 24 digital inputs (1-24). When an input is active (LOW), it prints "on".

## Important Notes
- **PCF8575 (Inputs 1-16)**: I2C address `0x22`, pins P8-P15 → inputs 1-8, P0-P7 → inputs 9-16.
- **PCF8575 (Inputs 17-24)**: I2C address `0x25`, pins P0-P7.
- **I2C pins**: SDA=GPIO8, SCL=GPIO18.
- **Input type**: Dry contact inputs (active LOW, meaning LOW = ON).
- **Serial Monitor** shows debug messages at 115200 baud.
