# FeedCurrent B16M Controller Arduino Example 07: How to Use DS3231 RTC Clock

## Description
This example shows how to read and set the DS3231 RTC via serial commands. It initializes the RTC over I2C and responds to commands entered in the Serial Monitor.

## File Structure
- `src/B16M_07_ds3231_rtc.ino` – Arduino source code.
- `precompiled/B16M_07_ds3231_rtc.bin` – Precompiled binary for ESP32-S3.

## Using the Precompiled Binary
Flash `precompiled/B16M_07_ds3231_rtc.bin` to address `0x0` using ESP Flash Download Tool or `esptool.py`.

## Compiling from Source
- **Environment**: Arduino IDE with ESP32-S3 board support.
- **Dependencies**: Install `DS3231` library (e.g., by Eric Ayars) via Library Manager.
- **Steps**: Open the `.ino` file, select `esp32-s3-devkitc-1`, and upload.

## Serial Commands
- `current time` – prints current date/time.
- `DYYYY-MM-DDTHH:MM:SS` – sets RTC (e.g., `D2025-09-27T10:30:00`).

## Expected Output
On startup, the current time is printed:
Current time is: 2025-01-01 00:00:10
After sending `current time`, the same format is displayed.

## Important Notes
- **I2C pins**: SDA=GPIO38, SCL=GPIO39 (⚠️ critical for B16M – different from many other models).
- RTC address: `0x68`.
- The constants like `OPEN_RLY_DATA` are unused and can be ignored.
- Ensure the DS3231 has a backup battery (e.g., CR2032) to retain time when main power is off.
- Command format is case-sensitive and must be exactly 20 characters long (e.g., `D2025-09-27T10:30:00`).