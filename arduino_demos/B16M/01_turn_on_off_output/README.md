# FeedCurrent B16M Controller Arduino Example 01: Turn ON/OFF OUTPUT

## Description
This example demonstrates how to control the 16 relay outputs on the B16M board via the **PCF8575 output chip** (address `0x25`). It sequentially turns on each output (pins 0-15) and then turns them off in a loop.

## File Structure
- `src/B16M_01_turn_on_off.ino` – Arduino source code.
- `precompiled/B16M_01_turn_on_off.bin` – Precompiled firmware binary for ESP32-S3.

## Using the Precompiled Binary
Flash `precompiled/B16M_01_turn_on_off.bin` to address `0x0` using ESP Flash Download Tool or `esptool.py`.

## Compiling from Source
- **Environment**: Arduino IDE with ESP32-S3 board support.
- **Dependencies**: Install `PCF8575` library (e.g., by Rob Tillaart) via Library Manager.
- **Steps**: Open the `.ino` file, select `esp32-s3-devkitc-1`, and upload.

## Expected Behavior
Relays 1-16 will turn on sequentially (200ms delay), then turn off sequentially, repeating in a loop.

## Important Notes
- **PCF8575 (Output)**: I2C address `0x25`, outputs connected to pins 0-15 (active LOW).
- **I2C pins**: SDA=GPIO38, SCL=GPIO39 (⚠️ different from many other models).
- **Serial Monitor** (optional) shows debug messages at 115200 baud.