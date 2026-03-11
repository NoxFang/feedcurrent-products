# FeedCurrent B8 Controller Arduino Example 10: Print Text on SSD1306 OLED Display

## Description
This example displays "FEEDCURRENT" and "www.feedcurrent.com" on the onboard SSD1306 OLED using the U8g2 library.

## File Structure
- `src/B8_10_oled_ssd1306.ino` – Arduino source code.
- `precompiled/B8_10_oled_ssd1306.bin` – Precompiled binary.

## Using the Precompiled Binary
- Flash `precompiled/B8_10_oled_ssd1306.bin` to `0x0`.

## Compiling from Source
- **Dependencies**: Install `U8g2` library by oliver via Library Manager.
- **Steps**: Compile and upload.

## Expected Behavior
The OLED shows:
FEEDCURRENT
www.feedcurrent.com

## Important Notes
- **I2C**: Software I2C with SCL=18, SDA=8. Address `0x3C` (set as `0x3C*2` in code).
- Uses software I2C; for better performance, hardware I2C can be used by changing the U8g2 constructor.