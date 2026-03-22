# Example 06: How to Use SD Card

## Description

This example demonstrates basic SD card file operations on the KinCony DM4
controller (ESP32-S3), including write, append, read, delete, and a
read/write performance benchmark.

## Hardware Requirements

### Key Hardware
- KinCony DM4 controller (ESP32-S3)
- MicroSD card (FAT32 formatted)

### Pin Definitions (SD Card SPI)

| Signal | GPIO |
|--------|------|
| SCK    | GPIO11 |
| MISO   | GPIO12 |
| MOSI   | GPIO10 |
| CS     | GPIO9 |

> **Note:** The SD card detect (CD) pin is not used in this example.

## Software Requirements

### Dependencies
- Arduino IDE with ESP32-S3 board support
- Built-in libraries: `FS`, `SD`, `SPI`

### Key Code

```cpp
SPIClass spi(HSPI);
spi.begin(SCK, MISO, MOSI, CS);
SD.begin(CS, spi, 80000000);

## Usage

1. Format the MicroSD card as FAT32.
2. Insert into the DM4 SD card slot.
3. Open src/DM4_06_sd_card.ino in Arduino IDE.
4. Select board: **ESP32S3 Dev Module**.
5. Upload and open Serial Monitor at **115200 baud**.

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

## Precompiled Firmware
The `precompiled/` directory is reserved for precompiled `.bin` firmware files that can be flashed directly using the ESP32 download tool.