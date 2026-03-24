# F24 Arduino Example 06: SD Card Operations

## Description
This example demonstrates basic SD card file operations on the F24 board using the built‑in SPI interface. It automatically performs the following sequence:
- Delete `/hello.txt` (if exists)
- Write `Hello ` to `/hello.txt`
- Append `World!\n` to `/hello.txt`
- Read and print the file contents
- Test file I/O performance on `/test.txt` (write 2048×512 bytes, then read back)
- Print total and used space on the SD card

## File Structure
- `src/F24_06_sd_card.ino` – Arduino source code.
- `precompiled/F24_06_sd_card.bin` – Precompiled firmware binary for ESP32‑S3.

## Using the Precompiled Binary
Flash `precompiled/F24_06_sd_card.bin` to address `0x0` using ESP Flash Download Tool or `esptool.py`.

## Compiling from Source
- **Environment**: Arduino IDE with ESP32‑S3 board support.
- **Dependencies**: SD.h, SPI.h, FS.h (all included with ESP32 Arduino core).
- **Steps**: Open the `.ino` file, select `esp32-s3-devkitc-1`, and upload.

## Hardware Connections
| SD Card Signal | ESP32‑S3 GPIO |
|----------------|---------------|
| CS             | 9             |
| MOSI           | 10            |
| MISO           | 12            |
| SCK            | 11            |

Insert a micro SD card formatted as FAT32. The board includes a built‑in SD card slot; no external module is required.

## Expected Behavior
After uploading, open the Serial Monitor (115200 baud). You will see output similar to:
SD Card Type: SDHC
SD Card Size: 15504MB
Deleting file: /hello.txt
File deleted
Writing file: /hello.txt
File written
Appending to file: /hello.txt
Message appended
Reading file: /hello.txt
Read from file: Hello World!
[performance test output...]
Total space: 15504MB
Used space: 1MB

If the SD card is not present or not formatted, an error message is printed.

## Important Notes
- **SPI Speed**: 80 MHz (configured in code; reduce if card unstable).
- **Serial Monitor**: Set baud rate to **115200**.
- The example runs only once; to repeat, reset the board.
- File paths use the root directory (e.g., `/hello.txt`).

## Related Resources
- Pin definition: `../pin_definitions/F24/F24_pin_definition.md`