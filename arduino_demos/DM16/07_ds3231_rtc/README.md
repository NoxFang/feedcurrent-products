# DM16 Arduino Example 07: DS3231 RTC Clock

## Description
This example demonstrates how to use the DS3231 Real‑Time Clock module on the DM16 board. It initializes the RTC, reads the current date and time, and allows setting the time via serial commands.

## Hardware Connections
| Signal | GPIO |
|--------|------|
| I2C SDA | GPIO8 |
| I2C SCL | GPIO18 |
| DS3231 I2C Address | 0x68 |

**I2C Frequency:** 40 kHz

## Serial Commands
After uploading, open the Serial Monitor at **115200 baud**. Use the following commands:

| Command | Description | Example |
|---------|-------------|---------|
| `current time` | Print the current date and time | `current time` |
| `DYYYY-MM-DDTHH:MM:SS` | Set the RTC date and time | `D2026-03-20T14:30:00` |

## Expected Output
On startup, the sketch prints the current time once:
Current time is: 2026-03-20 14:30:45

After sending `current time`, the same format is displayed again.  
After a set command, it prints:
Setting time...
Time set.

## Usage
1. Upload the sketch to the DM16 board.
2. Open the Serial Monitor at 115200 baud.
3. Type `current time` to read the RTC.
4. Type a set command (e.g., `D2026-03-20T14:30:00`) to update the time.

## Notes
- The RTC is configured in 24‑hour mode.
- The year is stored as a two‑digit offset from 2000 (e.g., 26 → 2026).
- A backup battery (CR2032) is required to retain time when main power is off.

## Dependencies
- `DS3231` library (install via Library Manager)
- `Wire` library (built‑in)

## Related Resources
- DM16 Pin Definition: `../pin_definitions/DM16/DM16_pin_definition.md`
