# CO16 Arduino Example 06: How to Use SD Card

## Description
This example demonstrates basic file operations on an SD card using the CO16 board.  
It initializes the SD card, performs read/write/append/delete operations, measures file I/O performance, and prints the card capacity and usage to the Serial Monitor.

## File Structure
- `src/CO16_06_sd_card.ino` – Arduino source code.
- `precompiled/CO16_06_sd_card.bin` – Precompiled firmware binary for ESP32‑S3.

## Using the Precompiled Binary (.bin)
1. Download the `.bin` file from the `precompiled/` folder.
2. Use the official **ESP Flash Download Tool** or `esptool.py` to flash it to the CO16 controller.
3. **Flash Address**: `0x0`.

## Compiling from Source
1. **Environment**: Install Arduino IDE and add ESP32‑S3 board support (via Boards Manager).
2. **Dependencies**: `FS.h`, `SD.h`, `SPI.h` (all built‑in with ESP32 core).
3. **Steps**: Open `src/CO16_06_sd_card.ino` in Arduino IDE, select the board `esp32-s3-devkitc-1` and the correct port, then compile and upload.

## Hardware Connections
| SD Card Signal | GPIO |
|----------------|------|
| SCK            | 11   |
| MISO           | 12   |
| MOSI           | 10   |
| CS             | 9    |

Insert a micro SD card formatted as FAT32. The CO16 board includes a built‑in SD card slot; no external module is required.

## Expected Output (Serial Monitor at 115200 baud)
After inserting a formatted SD card and resetting the board, you will see output similar to:
```cpp
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
[performance test output...]
Total space: 3817MB
Used space: 16MB
```

## Important Notes
- **SPI Speed**: 80 MHz (configured in code; reduce if card unstable).
- **Serial Monitor**: Set baud rate to **115200**.
- The example runs only once; to repeat, reset the board.
- File paths use the root directory (e.g., `/hello.txt`).
- Ensure the SD card is formatted as FAT32 and properly inserted.

## Related Resources
- Pin definition: `../pin_definitions/CO16/CO16_pin_definition.md`