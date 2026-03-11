# FeedCurrent B8 Controller Arduino Example 01: Turn ON/OFF OUTPUT

## Description
This example demonstrates how to control the 8 relays on the B8 board via a PCF8575 I/O expander. It sequentially turns on each relay (P8-P15) and then turns them off in a loop.

## File Structure
- `src/B8_01_turn_on_off.ino` – Arduino source code.
- `precompiled/B8_01_turn_on_off.bin` – Precompiled firmware binary for ESP32-S3.

## Using the Precompiled Binary
1. Download `B8_01_turn_on_off.bin` from the `precompiled/` folder.
2. Flash to address `0x0` using ESP Flash Download Tool or `esptool.py`.

## Compiling from Source
- **Environment**: Arduino IDE with ESP32-S3 board support.
- **Dependencies**: Install `PCF8575` library (e.g., by Rob Tillaart or Renzo Mischianti) via Library Manager.
- **Steps**: Open the `.ino` file, select `esp32-s3-devkitc-1`, and upload.

## Expected Behavior
Relays 1-8 will turn on sequentially (200ms delay), then turn off sequentially, repeating in a loop.

## Important Notes
- **PCF8575**: I2C address `0x22`, relays connected to pins 8-15 (active LOW).
- **I2C pins**: SDA=GPIO8, SCL=GPIO18.
- **Serial Monitor** (optional) shows debug messages at 115200 baud.