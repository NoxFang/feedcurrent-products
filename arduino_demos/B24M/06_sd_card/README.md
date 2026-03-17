# FeedCurrent B24M Controller Arduino Example 06: SD Card Operations

## Description
This example demonstrates basic file operations on an SD card using the ESP32-S3 on the B24M board. It includes initializing the SD card, reading, writing, appending, and deleting files, as well as measuring read/write performance.

## File Structure
- `src/B24M_06_sd_card.ino` – Arduino source code.
- `precompiled/B24M_06_sd_card.bin` – Precompiled firmware binary for ESP32-S3.

## Using the Precompiled Binary
Flash `precompiled/B24M_06_sd_card.bin` to address `0x0` using ESP Flash Download Tool or `esptool.py`.

## Compiling from Source
- **Environment**: Arduino IDE with ESP32-S3 board support.
- **Dependencies**: None (uses built-in FS, SD, SPI libraries).
- **Steps**: Open the `.ino` file, select `esp32-s3-devkitc-1`, and upload.

## Expected Behavior
The device initializes the SD card, performs file operations (write, read, append, delete), and displays card information and performance test results on the Serial Monitor.

## Important Notes
- **SD Card pins** (SPI mode):
  - SCK: GPIO11
  - MISO: GPIO12
  - MOSI: GPIO10
  - CS: GPIO9
- **Serial Monitor** shows debug messages at 115200 baud.
