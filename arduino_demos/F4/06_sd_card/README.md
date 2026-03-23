# F4 Arduino Example 06: How to Use SD Card

## Description
This example demonstrates basic file operations on an SD card using the ESP32‑S3 SPI interface. It initializes the SD card, performs file write, append, read, delete, and a read/write performance test, then prints results to the Serial Monitor.

## File Structure
- `src/F4_06_sd_card.ino` – Arduino source code.
- `precompiled/F4_06_sd_card.bin` – Precompiled firmware binary for ESP32‑S3.

## Using the Precompiled Binary
Flash `precompiled/F4_06_sd_card.bin` to address `0x0` using ESP Flash Download Tool or `esptool.py`.

## Compiling from Source
- **Environment**: Arduino IDE with ESP32‑S3 board support.
- **Dependencies**: Built‑in libraries: `FS.h`, `SD.h`, `SPI.h`.
- **Steps**: Open the `.ino` file, select `esp32-s3-devkitc-1`, and upload.

## Hardware Connections
| Signal | GPIO |
|--------|------|
| SCK    | GPIO11 |
| MISO   | GPIO12 |
| MOSI   | GPIO10 |
| CS     | GPIO9 |

- **SPI Bus**: HSPI (Hardware SPI)
- **SPI Frequency**: 80 MHz

## Hardware Requirements
- F4 board with on‑board SD card slot
- MicroSD card formatted as **FAT32**

## Serial Output
After uploading, open the Serial Monitor at **115200 baud**. You will see output similar to:
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

The performance test prints the number of bytes read/written and the time taken.

## Usage
1. Insert a FAT32‑formatted MicroSD card into the F4 SD card slot.
2. Upload the sketch to the F4 board.
3. Open the Serial Monitor at 115200 baud.
4. Observe the operations and results.

## Notes
- The code creates and deletes two files: `hello.txt` (for basic operations) and `test.txt` (for performance test).
- The performance test writes 1,048,576 bytes (2048 × 512) and reads the same amount.
- Ensure the SD card is properly seated and has sufficient power.

## Related Resources
- Pin definition: `../pin_definitions/F4/F4_pin_definition.md`
