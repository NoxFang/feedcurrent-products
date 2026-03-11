# Kincony B8M Arduino Example 07: How to Use DS3231 RTC Clock

## Description
This example shows how to read and set the DS3231 RTC via serial commands.

## File Structure
- `src/B8M_07_ds3231_rtc.ino` – Arduino source code.
- `precompiled/B8M_07_ds3231_rtc.bin` – Precompiled binary.

## Using the Precompiled Binary
Flash `precompiled/B8M_07_ds3231_rtc.bin` to `0x0`.

## Compiling from Source
- **Dependencies**: Install `DS3231` library (e.g., by Eric Ayars) via Library Manager.
- **Steps**: Compile and upload.

## Serial Commands
- `current time` – prints current date/time.
- `DYYYY-MM-DDTHH:MM:SS` – sets RTC (e.g., `D2025-06-23T10:30:00`).

## Important Notes
- I2C pins: SDA=8, SCL=18.
- RTC address: `0x68`.
- The constants like `OPEN_RLY_DATA` are unused and can be ignored.