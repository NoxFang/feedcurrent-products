# DM8 Arduino Demo 06 - SD Card

## Overview

This example demonstrates SD card operations including file read, write, append, delete, and I/O performance testing using HSPI.

## Features

- SD card initialization and type detection
- File write, append, read, and delete
- I/O performance test (512-byte blocks, 2048 iterations)
- Reports card type and capacity

## Hardware Connections (HSPI)

| Pin | Function |
|-----|----------|
| GPIO11 | SCK |
| GPIO12 | MISO |
| GPIO10 | MOSI |
| GPIO9 | CS |

> **Note:** The SD card detect (CD) pin is not used in this example.

## Required Libraries

- `FS` - Built-in
- `SD` - Built-in
- `SPI` - Built-in

## Usage

1. Insert MicroSD card into DM8.
2. Upload the sketch to DM8.
3. Open Serial Monitor at **115200 baud**.
4. View operations and performance results.

## Expected Output

SD Card Type: SDHC
SD Card Size: 3817MB
Deleting file: /hello.txt
File deleted
Writing file: /hello.txt
File written
Appending to file: /hello.txt
Message appended
Reading file: /hello.txt
Read from file: Hello World!
... (performance test results)
Total space: 3817MB
Used space: 16MB

## Notes

- SPI frequency: 80 MHz
- Supports MMC, SDSC, SDHC
- Uses HSPI (Hardware SPI)
- Test file: /test.txt (auto-deleted after test)

## Related Resources

- DM8 Pin Definition: `../pin_definitions/DM8/DM8_pin_definition.md`