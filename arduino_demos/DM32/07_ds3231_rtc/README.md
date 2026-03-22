# DM32 Example 07: DS3231 RTC Clock

## Overview

This example demonstrates DS3231 real-time clock usage with Arduino (ESP32-S3).

**Features**:
- Initialize DS3231 RTC
- Read current date and time
- Set RTC time via serial command
- 24-hour format

---

## Hardware Requirements

### DS3231 RTC
- **I2C Address**: 0x68
- **SDA Pin**: GPIO8
- **SCL Pin**: GPIO18
- **Frequency**: 40kHz

---

## Library Dependencies

- `DS3231.h` - For DS3231 RTC control
- `Wire.h` - Built-in I2C library

---

## Serial Commands

### Set Time Command
**Format**: `DYYYY-MM-DDTHH:MM:SS`

**Examples**:
- `D2024-09-19T11:50:22` - Set date and time
- `D2025-03-20T15:30:00` - Set to March 20, 2025, 3:30 PM

### Query Time Command
**Command**: `current time`

**Output Example**:
```
Current time is: 2025-3-20 15:30:00
```

---

## Important Notes

- **Serial Baud Rate**: 115200
- **I2C Frequency**: 40kHz for DS3231 communication
- **Time Format**: 24-hour mode
- **Command Validation**: Only accepts exact format `DYYYY-MM-DDTHH:MM:SS`.
- **Year Century**: Library adds 2000 automatically (enter last 2 digits).