# FeedCurrent B24M Controller Arduino Example 05: Read Free GPIO State

## Description
This example demonstrates how to read the state of free GPIO pins on the B24M board. It monitors 7 GPIO pins and prints any state changes to the Serial Monitor.

## File Structure
- `src/B24M_05_read_free_gpio.ino` – Arduino source code.
- `precompiled/B24M_05_read_free_gpio.bin` – Precompiled firmware binary for ESP32-S3.

## Using the Precompiled Binary
Flash `precompiled/B24M_05_read_free_gpio.bin` to address `0x0` using ESP Flash Download Tool or `esptool.py`.

## Compiling from Source
- **Environment**: Arduino IDE with ESP32-S3 board support.
- **Dependencies**: None.
- **Steps**: Open the `.ino` file, select `esp32-s3-devkitc-1`, and upload.

## Expected Behavior
When any of the monitored GPIO pins changes state, the Serial Monitor displays the pin number and its new state (HIGH or LOW).

## Important Notes
- **Free GPIOs monitored**: GPIO7, GPIO13, GPIO14, GPIO21, GPIO40, GPIO47, GPIO48.
- **GPIO with pull-up on PCB**: GPIO7, GPIO40, GPIO47, GPIO48.
- **GPIO without pull-up on PCB**: GPIO13, GPIO14, GPIO21.
- **Serial Monitor** shows debug messages at 115200 baud.
