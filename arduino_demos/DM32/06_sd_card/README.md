# DM32 Example 06: How to Use SD Card

## Description
This example demonstrates basic file operations on an SD card using the ESP32‑S3 SPI interface. It initializes the SD card, performs file write, append, read, delete, and a read/write performance test, then prints results to the Serial Monitor.

## Hardware Connections
| Signal | GPIO |
|--------|------|
| MOSI   | GPIO10 |
| SCK    | GPIO11 |
| MISO   | GPIO12 |
| CS     | GPIO9 |

- **SPI Bus**: HSPI (Hardware SPI)
- **SPI Frequency**: 80 MHz

## Hardware Requirements
- DM32 board with on‑board SD card slot
- MicroSD card formatted as **FAT32**

## Functions
- **`setup()`**: Initializes serial, SPI, and SD card; checks card type and size; then performs:
  - `deleteFile()`: Removes `/hello.txt` if it exists.
  - `writeFile()`: Writes `"Hello "` to `/hello.txt`.
  - `appendFile()`: Appends `"World!\n"` to the file.
  - `readFile()`: Reads and prints the file content.
  - `testFileIO()`: Reads and writes 1 MB of data to measure performance.
- **`loop()`**: Empty (no repeated operations).

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
1. Insert a FAT32‑formatted MicroSD card into the DM32 SD card slot.
2. Upload the sketch to the DM32 board.
3. Open the Serial Monitor at 115200 baud.
4. Observe the operations and results.

## Notes
- The code creates and deletes two files: `hello.txt` (for basic operations) and `test.txt` (for performance test).
- The performance test writes 1,048,576 bytes (2048 × 512) and reads the same amount.
- Ensure the SD card is properly seated and has sufficient power.

## Dependencies
- Built‑in libraries: `FS.h`, `SD.h`, `SPI.h`

## Related Resources
- DM32 Pin Definition: `../pin_definitions/DM32/DM32_pin_definition.md`