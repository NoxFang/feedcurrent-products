# Example 10: Print Text on SSD1306 OLED Display

## Description

This example demonstrates how to display text on the SSD1306 128×64 OLED display
on the FeedCurrent DM4 controller using the U8g2 library.

Two lines are displayed:
- **Line 1**: "FeedCurrent" — large font (Times Roman 18)
- **Line 2**: "www.feedcurrent.com" — small font (Times Roman 12)

## Hardware Requirements

### Key Hardware
- FeedCurrent DM4 controller (ESP32-S3 + SSD1306 OLED on-board)

### Pin Definitions (I2C)

| Signal | GPIO |
|--------|------|
| SCL    | GPIO18 |
| SDA    | GPIO8 |

| Device  | I2C Address |
|---------|-------------|
| SSD1306 | 0x3C |

## Software Requirements

### Dependencies
- Arduino IDE with ESP32-S3 board support
- **U8g2** library — Install via Library Manager
- `Wire` library (built-in)

### Key Code

```cpp
#include <U8g2lib.h>
// SCL=GPIO18, SDA=GPIO8
U8G2_SSD1306_128X64_NONAME_F_SW_I2C u8g2(U8G2_R0, 18, 8, U8X8_PIN_NONE);
u8g2.setI2CAddress(0x3C * 2);
u8g2.begin();
u8g2.firstPage();
do { /* draw */ } while (u8g2.nextPage());
```

## Usage

1. Open `src/DM4_10_oled_ssd1306.ino` in Arduino IDE
2. Install **U8g2** library via Library Manager
3. Select board: **ESP32S3 Dev Module**
4. Upload to the DM4 controller
5. The OLED immediately shows "FEEDCURRENT" and "www.feedcurrent.com"

## Troubleshooting

| Issue | Solution |
|-------|----------|
| Blank screen | Verify I2C address is 0x3C; check GPIO8 (SDA) and GPIO18 (SCL) |
| U8g2 not found | Install via Arduino Library Manager |
| Garbled display | Ensure ESP32-S3 board is selected |

## Precompiled Firmware

The `precompiled/` directory is reserved for precompiled `.bin` firmware files.

