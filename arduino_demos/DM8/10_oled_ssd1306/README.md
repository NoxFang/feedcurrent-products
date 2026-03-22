# DM8 Arduino Demo 10 - SSD1306 OLED Display

## Overview

This example demonstrates how to display text on the 128x64 SSD1306 OLED display using the U8g2 library.

## Features

- SSD1306 128x64 OLED display
- Displays "FEEDCURRENT" in large font (size 18)
- Displays "www.feedcurrent.com" in small font (size 12)
- Software I2C implementation

## Hardware Connections

| Pin | Function |
|-----|----------|
| GPIO18 | SCL |
| GPIO8 | SDA |

### Display Configuration

| Parameter | Value |
|-----------|-------|
| Resolution | 128x64 |
| I2C Address | 0x3C |
| Rotation | 0° |

## Required Libraries

- `U8g2` by olikraus
- `Wire` - Built-in

## Usage

1. Ensure SSD1306 is connected to I2C pins
2. Upload the sketch to DM8
3. Display shows "FEEDCURRENT" and "www.feedcurrent.com"

## Notes

- Uses software I2C (SCL=18, SDA=8)
- UTF-8 printing enabled
- Display updates continuously via nextPage() loop
- U8G2_R0 = no rotation
