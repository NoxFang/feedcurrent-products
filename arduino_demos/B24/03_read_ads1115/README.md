# FeedCurrent B24 Controller Arduino Example 03: Read ADS1115 Analog Input

## Description
This example reads voltage from all four ADS1115 channels (A0-A3) on the B24 board and prints the values in millivolts to the Serial Monitor.

## File Structure
- `src/B24_03_read_ads1115.ino` – Arduino source code.
- `precompiled/B24_03_read_ads1115.bin` – Precompiled firmware binary for ESP32-S3.

## Using the Precompiled Binary
Flash `precompiled/B24_03_read_ads1115.bin` to address `0x0` using ESP Flash Download Tool or `esptool.py`.

## Compiling from Source
- **Environment**: Arduino IDE with ESP32-S3 board support.
- **Dependencies**: Install `DFRobot_ADS1115` library via Library Manager.
- **Steps**: Open the `.ino` file, select `esp32-s3-devkitc-1`, and upload.

## Expected Output
A0:1234mV, A1:5678mV, A2:910mV, A3:112mV (example values)

## Important Notes
- **ADS1115**: I2C address `0x48` (default), gain set to ±6.144V.
- **I2C pins**: SDA=GPIO8, SCL=GPIO18.
- **Serial Monitor** shows debug messages at 115200 baud.
