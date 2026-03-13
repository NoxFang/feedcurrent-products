# FeedCurrent B16M Controller Arduino Example 06: How to Use SD Card

## Description
This example demonstrates basic SD card operations: mount, read/write/append/delete files, and performance test.

## File Structure
- `src/B16M_06_sd_card.ino` – Arduino source code.
- `precompiled/B16M_06_sd_card.bin` – Precompiled binary.

## Using the Precompiled Binary
Flash `precompiled/B16M_06_sd_card.bin` to `0x0`.

## Compiling from Source
- **Dependencies**: `FS.h`, `SD.h`, `SPI.h` (built-in).
- **Steps**: Compile and upload.

## Expected Output (example)
SD Card Type: SDHC
SD Card Size: 3817MB
...

## Important Notes
- **SPI pins**: MOSI=10, MISO=12, SCK=11, CS=9 (standard for B16M).
- SD card must be formatted as FAT16/FAT32.