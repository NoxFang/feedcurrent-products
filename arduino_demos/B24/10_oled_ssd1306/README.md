# FeedCurrent B24 Controller Arduino Example 10: SSD1306 OLED Display

## Description
This example displays text on the SSD1306 OLED display on the B24 board using the U8g2 library.

## File Structure
- `src/B24_10_oled_ssd1306.ino` – Arduino source code.
- `precompiled/B24_10_oled_ssd1306.bin` – Precompiled firmware binary for ESP32-S3.

## Using the Precompiled Binary
Flash `precompiled/B24_10_oled_ssd1306.bin` to address `0x0` using ESP Flash Download Tool or `esptool.py`.

## Compiling from Source
- **Environment**: Arduino IDE with ESP32-S3 board support.
- **Dependencies**: Install `U8g2` library via Library Manager.
- **Steps**: Open the `.ino` file, select `esp32-s3-devkitc-1`, and upload.

## Expected Behavior
- Displays "FeedCurrent B24" and other text on the OLED screen.

## Important Notes
- **I2C pins**: SDA=GPIO8, SCL=GPIO18.
- **OLED address**: `0x3C`.
- Uses software I2C; hardware I2C can be used by changing the U8g2 constructor.
