# B2 Arduino Example 10: Print Text on SSD1306 OLED Display

## Description
This example demonstrates how to display text on the onboard SSD1306 128×64 OLED display using the U8g2 library. It shows two lines:

- **"FEEDCURRENT"** in a larger font (Times Roman 18)
- **"www.feedcurrent.com"** in a smaller font (Times Roman 12)

The display is connected via **software I2C** with SCL=GPIO18, SDA=GPIO8, address 0x3C.

## File Structure
- `src/B2_10_oled_ssd1306.ino` – Arduino source code.
- `precompiled/B2_10_oled_ssd1306.bin` – Precompiled firmware binary for ESP32‑S3.

## Using the Precompiled Binary (.bin)
1. Download the `.bin` file from the `precompiled/` folder.
2. Use the official **ESP Flash Download Tool** or `esptool.py` to flash it to the B2 controller.
3. **Flash Address**: `0x0`.

## Compiling from Source
1. **Environment**: Install Arduino IDE and add ESP32‑S3 board support (via Boards Manager).
2. **Dependencies**:
   - `Wire.h` (built‑in)
   - `U8g2lib.h` – Install via Library Manager (search for “U8g2” by olikraus).
3. **Steps**: Open `src/B2_10_oled_ssd1306.ino` in Arduino IDE, select the board `esp32-s3-devkitc-1` and the correct port, then compile and upload.

## Hardware Connections
| Signal | GPIO |
|--------|------|
| SCL    | GPIO18 |
| SDA    | GPIO8 |
| OLED I2C Address | 0x3C |

**Note**: The B2 board includes an onboard SSD1306 OLED display; no external wiring is required.

## Expected Behavior
After flashing, the OLED screen will show:
`FEEDCURRENT`
`www.feedcurrent.com`
The content is static and continuously refreshed in the `loop()`.

## Important Notes
- **Software I2C**: The display is initialized with `U8G2_SSD1306_128X64_NONAME_F_SW_I2C` (software I2C). This is flexible but slightly slower than hardware I2C. To switch to hardware I2C, change the constructor and ensure `Wire` is initialized with the correct pins.
- **I2C Address**: The display address is `0x3C`. In the code it is set using `u8g2.setI2CAddress(0x3C*2)` because the U8g2 library expects the 8‑bit shifted address (0x78). Do not change unless your display uses a different address.
- **Fonts**: The example uses Times Roman fonts (`u8g2_font_timR18_tf` and `u8g2_font_timR12_tf`). U8g2 includes many built‑in fonts; replace these identifiers to change the appearance.
- **UTF‑8 Support**: `u8g2.enableUTF8Print()` is called to allow printing UTF‑8 characters. Useful for special symbols or non‑ASCII text.
- **Code Comment vs. Actual Output**: The header comment mentions “KINCONY” but the code actually prints **“FEEDCURRENT”**. Always trust the code (`u8g2.print(...)`) over the comments.

## Related Resources
- Pin definition: `../pin_definitions/B2/B2_pin_definition.md`
- U8g2 library documentation: [https://github.com/olikraus/u8g2](https://github.com/olikraus/u8g2)