# AIO Hybrid Arduino Example 06: How to Use SD Card

## Description
This example demonstrates basic file operations on an SD card using the ESP32‑S3 SPI interface. It includes:
- Initializing and testing the SD card
- Reading, writing, appending, and deleting files
- Measuring file read/write performance

## File Structure
- `src/AIO_06_sd_card.ino` – Arduino source code.
- `precompiled/AIO_06_sd_card.bin` – Precompiled firmware binary for ESP32‑S3 (to be added).

## Using the Precompiled Binary
1. Download the `.bin` file from the `precompiled/` folder.
2. Use the official **ESP Flash Download Tool** or `esptool.py` to flash it to the AIO Hybrid controller.
3. **Flash Address**: `0x0` (as indicated in the forum post).

## Compiling from Source
1. **Environment**: Install Arduino IDE and add ESP32‑S3 board support (via Boards Manager).
2. **Dependencies**: None (uses built‑in `FS.h`, `SD.h`, `SPI.h`).
3. **Steps**:
   - Open `src/AIO_06_sd_card.ino` in Arduino IDE.
   - Select the correct board (`esp32-s3-devkitc-1`) and port.
   - Compile and upload.

## Expected Output
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

The exact numbers depend on your SD card.

## Important Notes
- **SPI pins**: SCK=GPIO11, MISO=GPIO12, MOSI=GPIO10, CS=GPIO9. Verify that these match your hardware wiring.
- **SD card format**: The card must be formatted as FAT16 or FAT32.
- **Power supply**: SD cards can draw significant current during writes. Ensure the AIO Hybrid board is powered adequately (12‑24V DC) to avoid corruption.
- **SPI bus**: The code uses the HSPI bus (`SPIClass(HSPI)`) with a frequency of 80 MHz. If you encounter issues, you can lower the frequency (e.g., 40 MHz or 20 MHz).
- **Performance test**: The `testFileIO()` function writes 1,048,576 bytes (1 MB) and reads the same. This may take a few seconds.
- **File operations**: The code creates and deletes files in the root directory. Ensure your SD card does not contain important data before running.