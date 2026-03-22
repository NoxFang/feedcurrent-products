# DM16 Arduino Example 10: SSD1306 OLED Display

## Description
This example demonstrates how to display text on the SSD1306 128×64 OLED display using the U8g2 library. It shows two lines:

- **First line**: "FEEDCURRENT" in a larger font (Times Roman 18)
- **Second line**: "www.feedcurrent.com" in a smaller font (Times Roman 12)

The display is connected via software I2C with SCL=GPIO18, SDA=GPIO8, address 0x3C.

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

## Usage
1. Upload the sketch to the DM16 board.
2. The OLED display will immediately show the text.
3. No user interaction is required.

## Notes
- The example uses software I2C (`U8G2_SSD1306_128X64_NONAME_F_SW_I2C`). For better performance, you can switch to hardware I2C by changing the constructor.
- UTF‑8 printing is enabled, allowing special characters.
- The display address is set as `0x3C*2` because the U8g2 library expects the 8‑bit shifted address.

## Dependencies
- `U8g2` library (install via Library Manager)
- `Wire` library (built‑in)

## Related Resources
- DM16 Pin Definition: `../pin_definitions/DM16/DM16_pin_definition.md`