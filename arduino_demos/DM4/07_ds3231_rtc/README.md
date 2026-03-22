# Example 07: DS3231 RTC Clock

## Description

This example demonstrates how to use the DS3231 Real-Time Clock module on the
FeedCurrent DM4 controller. It reads and prints the current date/time and supports
setting the time via serial commands.

## Hardware Requirements

### Key Hardware
- FeedCurrent DM4 controller (ESP32-S3)
- DS3231 RTC (on-board, I2C 0x68)
- CR2032 coin cell battery (for RTC backup power)

### Pin Definitions

| Interface | GPIO / Address |
|-----------|----------------|
| I2C SDA   | GPIO8 |
| I2C SCL   | GPIO18 |
| DS3231    | I2C 0x68 |

## Software Requirements

### Dependencies
- Arduino IDE with ESP32-S3 board support
- **DS3231** library — Install via Library Manager

### Key Code

```cpp
#include <DS3231.h>
DS3231 rtc;
Wire.begin(8, 18, 40000);
rtc.setClockMode(false);  // 24-hour
Serial.print(rtc.getYear() + 2000);
```

## Serial Commands

| Command | Description |
|---------|-------------|
| `current time` | Print current date and time |
| `DYYYY-MM-DDTHH:MM:SS` | Set date and time |

**Set time example:** `D2026-03-20T21:00:00`

## Usage

1. Open `src/DM4_07_ds3231_rtc.ino` in Arduino IDE
2. Install **DS3231** library via Library Manager
3. Select board: **ESP32S3 Dev Module**
4. Upload and open Serial Monitor at **115200 baud**
5. Type `current time` to read the clock
6. Type `D2026-03-20T21:00:00` to set the time

## Precompiled Firmware

The `precompiled/` directory is reserved for precompiled `.bin` firmware files.
