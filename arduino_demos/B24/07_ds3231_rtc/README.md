# FeedCurrent B24 Controller Arduino Example 07: DS3231 RTC Clock

## Description
This example demonstrates how to read and set the DS3231 RTC on the B24 board via serial commands.

## File Structure
- `src/B24_07_ds3231_rtc.ino` – Arduino source code.
- `precompiled/B24_07_ds3231_rtc.bin` – Precompiled firmware binary for ESP32-S3.

## Using the Precompiled Binary
Flash `precompiled/B24_07_ds3231_rtc.bin` to address `0x0` using ESP Flash Download Tool or `esptool.py`.

## Compiling from Source
- **Environment**: Arduino IDE with ESP32-S3 board support.
- **Dependencies**: Install `DS3231` library (e.g., by Eric Ayars) via Library Manager.
- **Steps**: Open the `.ino` file, select `esp32-s3-devkitc-1`, and upload.

## Serial Commands
- `current time` – prints current date/time.
- `DYYYY-MM-DDTHH:MM:SS` – sets RTC (e.g., `D2025-06-23T10:30:00`).

## Important Notes
- **I2C pins**: SDA=GPIO8, SCL=GPIO18.
- **RTC address**: `0x68`.
- **Serial Monitor** shows debug messages at 115200 baud.
