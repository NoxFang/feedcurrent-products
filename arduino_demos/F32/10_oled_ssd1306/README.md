# F32 Arduino Example 10: Print Text on SSD1306 OLED Display

## Description
This example demonstrates how to display text on the SSD1306 128×64 OLED display using the U8g2 library. It shows two lines:

- **First line**: "FEEDCURRENT" in a larger font (Times Roman 18)
- **Second line**: "www.feedcurrent.com" in a smaller font (Times Roman 12)

The display is connected via software I2C with SCL=GPIO18, SDA=GPIO8, address 0x3C.

## File Structure
- `src/F32_10_oled_ssd1306.ino` – Arduino source code.
- `precompiled/F32_10_oled_ssd1306.bin` – Precompiled firmware binary for ESP32‑S3.

## Using the Precompiled Binary
Flash `precompiled/F32_10_oled_ssd1306.bin` to address `0x0` using ESP Flash Download Tool or `esptool.py`.

## Compiling from Source
- **Environment**: Arduino IDE with ESP32‑S3 board support.
- **Dependencies**:
  - `U8g2` library (install via Library Manager, search “U8g2” by olikraus).
  - `Wire` library (built‑in).
- **Steps**: Open the `.ino` file, select `esp32-s3-devkitc-1`, and upload.

## Hardware Connections
| Signal | GPIO |
|--------|------|
| SCL    | GPIO18 |
| SDA    | GPIO8 |
| OLED I2C Address | 0x3C |

## Display Output
After uploading, the OLED screen will show:
FEEDCURRENT
www.feedcurrent.com

The content is static and continuously refreshed.

## Important Notes
- The example uses software I2C (`U8G2_SSD1306_128X64_NONAME_F_SW_I2C`). For better performance, you can switch to hardware I2C by changing the constructor.
- UTF‑8 printing is enabled, allowing special characters.
- The display address is set as `0x3C*2` because the U8g2 library expects the 8‑bit shifted address.

## Related Resources
- Pin definition: `../pin_definitions/F32/F32_pin_definition.md`