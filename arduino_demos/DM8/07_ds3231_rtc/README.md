# DM8 Arduino Demo 07 - DS3231 RTC Clock

## Overview

This example demonstrates how to use the DS3231 RTC module to read and set the current date and time via serial commands.

## Features

- Initialize DS3231 RTC in 24-hour mode
- Read current date and time
- Set date/time via serial command
- Print current time on demand

## Hardware Connections

| Pin | Function |
|-----|----------|
| GPIO8 | I2C SDA |
| GPIO18 | I2C SCL |

### I2C Configuration

| Parameter | Value |
|-----------|-------|
| I2C Address | 0x68 |
| I2C Frequency | 40KHz |
| Time Format | 24-hour |

## Required Libraries

- `DS3231` by NorthernWidget
- `Wire` - Built-in

## Serial Commands

| Command | Format | Example |
|---------|--------|---------|
| Set time | `DYYYY-MM-DDTHH:MM:SS` | `D2026-03-20T22:00:00` |
| Read time | `current time` | - |

## Usage

1. Upload the sketch to DM8
2. Open Serial Monitor (115200 baud)
3. Type `current time` to display current RTC time
4. Type `D2026-03-20T22:00:00` to set time

## Notes

- Time is set in 24-hour format
- Year stored as 2-digit offset from 2000
- RTC retains time when board is powered off (battery required)
