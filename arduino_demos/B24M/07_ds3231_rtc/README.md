# FeedCurrent B24M Controller Arduino Example 07: DS3231 RTC Clock

## Description
This example demonstrates how to use the DS3231 RTC (Real-Time Clock) module with the B24M board. It reads the current date and time and allows setting the RTC via serial commands.

## File Structure
- `src/B24M_07_ds3231_rtc.ino` – Arduino source code.
- `precompiled/B24M_07_ds3231_rtc.bin` – Precompiled firmware binary for ESP32-S3.

## Using the Precompiled Binary
Flash `precompiled/B24M_07_ds3231_rtc.bin` to address `0x0` using ESP Flash Download Tool or `esptool.py`.

## Compiling from Source
- **Environment**: Arduino IDE with ESP32-S3 board support.
- **Dependencies**: Install `DS3231` library via Library Manager.
- **Steps**: Open the `.ino` file, select `esp32-s3-devkitc-1`, and upload.

## Expected Behavior
The device displays the current time on the Serial Monitor. Use serial command `DYYYY-MM-DDTHH:MM:SS` to set the time.

## Important Notes
- **DS3231 I2C Address**: `0x68`.
- **I2C pins**: SDA=GPIO8, SCL=GPIO18.
- **Serial Monitor** shows debug messages at 115200 baud.
