# F4 Arduino Example 07: DS3231 RTC Clock

## Description
This example demonstrates how to use the DS3231 Real‑Time Clock module on the F4 board. It initializes the RTC, reads the current date and time, and allows setting the time via serial commands.

## File Structure
- `src/F4_07_ds3231_rtc.ino` – Arduino source code.
- `precompiled/F4_07_ds3231_rtc.bin` – Precompiled firmware binary for ESP32‑S3.

## Using the Precompiled Binary
Flash `precompiled/F4_07_ds3231_rtc.bin` to address `0x0` using ESP Flash Download Tool or `esptool.py`.

## Compiling from Source
- **Environment**: Arduino IDE with ESP32‑S3 board support.
- **Dependencies**:
  - `DS3231.h` – Install via Library Manager (e.g., “DS3231” by Eric Ayars or NorthernWidget).
  - `Wire.h` (built‑in).
- **Steps**: Open the `.ino` file, select `esp32-s3-devkitc-1`, and upload.

## Hardware Connections
| Signal | GPIO |
|--------|------|
| SDA    | GPIO8 |
| SCL    | GPIO18 |

- **I2C Frequency**: 40 kHz
- **DS3231 I2C Address**: 0x68

## Serial Commands
After uploading, open the Serial Monitor at **115200 baud**. Use the following commands:

| Command | Description | Example |
|---------|-------------|---------|
| `current time` | Print the current date and time | `current time` |
| `DYYYY-MM-DDTHH:MM:SS` | Set the RTC date and time | `D2026-03-23T10:30:00` |

## Expected Output
On startup, the sketch prints the current time once:
Current time is: 2026-03-23 10:30:00

After sending `current time`, the same format is displayed again.  
After a set command, it prints:
Setting time...
Time set.

## Important Notes
- The RTC is configured in **24‑hour mode**.
- The year is stored as a two‑digit offset from 2000 (e.g., 26 → 2026).
- A backup battery (CR2032) is required to retain time when main power is off.
- The constants `OPEN_RLY_DATA`, `OPEN_RLY_MONTH`, etc., are unused in this example and can be ignored.

## Related Resources
- Pin definition: `../pin_definitions/F4/F4_pin_definition.md`