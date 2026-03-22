# DM16 Example 10: SSD1306 OLED Display

This example demonstrates using the SSD1306 OLED display on the DM16 board.

## Features

- Uses SSD1306 128x64 OLED display
- I2C address: 0x3C
- U8g2 library for graphics
- Displays text and simple graphics

## Pin Connections

| Component | Pin | Connection |
|-----------|-----|------------|
| I2C SDA | GPIO8 | ESP32-S3 GPIO8 |
| I2C SCL | GPIO18 | ESP32-S3 GPIO18 |
| OLED Address | 0x3C | I2C address |

## Display Content

The sketch displays:

```
KINCONY
DM16 Board

www.kincony.com
ESP32-S3 Controller

16-Channel DAC
PCF8575 I/O

Ready!
```

## Hardware Requirements

- DM16 board
- No additional components required (SSD1306 onboard)

## Usage

1. Upload the sketch to your DM16 board
2. Observe the display on the OLED screen
3. The display shows product information and status

## Reference

- Forum Thread: https://www.kincony.com/forum/showthread.php?tid=8517
- DM16 Pin Definition: https://www.kincony.com/forum/showthread.php?tid=8499
