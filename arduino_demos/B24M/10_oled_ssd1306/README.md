# FeedCurrent B24M Controller Arduino Example 10: OLED SSD1306 Display

## Description
This example demonstrates how to display text on an SSD1306 128x64 OLED display using the U8g2 library on the B24M board.

## File Structure
- `src/B24M_10_oled_ssd1306.ino` – Arduino source code.
- `precompiled/B24M_10_oled_ssd1306.bin` – Precompiled firmware binary for ESP32-S3.

## Using the Precompiled Binary
Flash `precompiled/B24M_10_oled_ssd1306.bin` to address `0x0` using ESP Flash Download Tool or `esptool.py`.

## Compiling from Source
- **Environment**: Arduino IDE with ESP32-S3 board support.
- **Dependencies**: Install `U8g2` library via Library Manager.
- **Steps**: Open the `.ino` file, select `esp32-s3-devkitc-1`, and upload.

## Expected Behavior
The OLED display shows "KINCONY" in large text on the first line and "www.kincony.com" on the second line.

## Important Notes
- **SSD1306 I2C Address**: `0x3C`.
- **I2C pins**: SDA=GPIO8, SCL=GPIO18.
