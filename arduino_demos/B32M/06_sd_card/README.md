# FeedCurrent B32M Controller Arduino Example 06: SD Card Operations

## Description
This example demonstrates basic SD card operations on the B32M board: mount, read/write files, and list files.

## File Structure
- `src/B32M_06_sd_card.ino` – Arduino source code.
- `precompiled/B32M_06_sd_card.bin` – Precompiled firmware binary for ESP32-S3.

## Using the Precompiled Binary
Flash `precompiled/B32M_06_sd_card.bin` to address `0x0` using ESP Flash Download Tool or `esptool.py`.

## Compiling from Source
- **Environment**: Arduino IDE with ESP32-S3 board support.
- **Dependencies**: `SD_MMC` library (built-in) or `SD` library.
- **Steps**: Open the `.ino` file, select `esp32-s3-devkitc-1`, and upload.

## Expected Behavior
- Mounts the SD card
- Creates and writes to a test file
- Reads and displays file contents
- Lists files on the SD card

## Important Notes
- **SPI pins**: MOSI=GPIO10, MISO=GPIO12, SCK=GPIO11, CS=GPIO9.
- SD card must be formatted as FAT16/FAT32.
- **Serial Monitor** shows debug messages at 115200 baud.
