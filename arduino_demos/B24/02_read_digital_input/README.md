# FeedCurrent B24 Controller Arduino Example 02: Read Digital Input

## Description
This example demonstrates how to read digital input states from two 16-channel PCF8575 I/O expanders on the B24 board. It reads inputs 1-24 and prints the state to the Serial Monitor.

## File Structure
- `src/B24_02_read_digital_input.ino` – Arduino source code.
- `precompiled/B24_02_read_digital_input.bin` – Precompiled firmware binary for ESP32-S3.

## Using the Precompiled Binary
Flash `precompiled/B24_02_read_digital_input.bin` to address `0x0` using ESP Flash Download Tool or `esptool.py`.

## Compiling from Source
- **Environment**: Arduino IDE with ESP32-S3 board support.
- **Dependencies**: Install `PCF8575` library (e.g., by Rob Tillaart) via Library Manager.
- **Steps**: Open the `.ino` file, select `esp32-s3-devkitc-1`, and upload.

## Expected Behavior
The program continuously reads the state of all 24 digital inputs and prints them to the Serial Monitor at 115200 baud.

## Important Notes
- **PCF8575 (Input)**: I2C addresses `0x22` (inputs 1-16), `0x25` (inputs 17-24).
- **I2C pins**: SDA=GPIO8, SCL=GPIO18.
- **Serial Monitor** shows debug messages at 115200 baud.
