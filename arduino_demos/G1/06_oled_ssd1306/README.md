# G1 Arduino Example 06: Print Text on SSD1306 OLED Display

## Description
This example demonstrates how to display text on the onboard SSD1306 128×64 OLED display using the U8g2 library. It draws two lines:
- `"FEEDCURRENT"` in a larger font
- `"www.feedcurrent.com"` in a smaller font

The display is connected via I2C (software implementation) with SCL=GPIO11, SDA=GPIO12, address `0x3C`.

## File Structure
- `src/G1_06_oled_ssd1306.ino` – Arduino source code.
- `precompiled/G1_06_oled_ssd1306.bin` – Precompiled firmware binary for ESP32‑S3 (to be added).

## Using the Precompiled Binary
1. Download the `.bin` file from the `precompiled/` folder.
2. Use the official **ESP Flash Download Tool** or `esptool.py` to flash it to the G1 controller.
3. **Flash Address**: `0x0` (as indicated in the forum post).

## Compiling from Source
1. **Environment**: Install Arduino IDE and add ESP32‑S3 board support (via Boards Manager).
2. **Dependencies**:
   - `Wire.h` (built‑in)
   - `U8g2lib.h` – Install via Library Manager (search for "U8g2" by oliver).
3. **Steps**:
   - Open `src/G1_06_oled_ssd1306.ino` in Arduino IDE.
   - Select the correct board (`esp32-s3-devkitc-1`) and port.
   - Compile and upload.

## Expected Behavior
After flashing, the OLED display will show:
FEEDCURRENT
www.feedcurrent.com

The content is static and continuously refreshed by the `loop()` function.

## Important Notes
- **I2C pins**: SCL=GPIO11, SDA=GPIO12 (software I2C implementation). This matches the G1 hardware.
- **I2C address**: The display address is `0x3C`. In the code, it is set using `u8g2.setI2CAddress(0x3C*2)` because the U8g2 library expects the 8‑bit shifted address (`0x78`).
- **Software I2C**: The constructor `U8G2_SSD1306_128X64_NONAME_F_SW_I2C` uses software I2C. For better performance, you can switch to hardware I2C by changing the constructor and ensuring `Wire` is properly initialized.
- **Fonts**: The example uses Times Roman fonts (`u8g2_font_timR18_tf` and `u8g2_font_timR12_tf`). Many built‑in fonts are available in U8g2.
- **UTF‑8 support**: `u8g2.enableUTF8Print()` is called to allow printing UTF‑8 characters.

## Related Resources
- Pin definition: `../pin_definitions/G1/G1_pin_definition.md`
- U8g2 library documentation (available in the library manager)