# CO16 Arduino Example 10: ST7789 TFT Color Display

## Description
This example demonstrates how to drive the onboard ST7789 TFT color display (320×240) on the CO16 board using the ESP32‑S3 native SPI driver (SPI3) and the Adafruit GFX library.  
It displays a static screen with text and color bars, and updates a frame counter every second.

## File Structure
- `src/CO16_10_st7789_tft_display.ino` – Arduino source code.
- `precompiled/CO16_10_st7789_tft_display.bin` – Precompiled firmware binary for ESP32‑S3.

## Using the Precompiled Binary (.bin)
1. Download the `.bin` file from the `precompiled/` folder.
2. Use the official **ESP Flash Download Tool** or `esptool.py` to flash it to the CO16 controller.
3. **Flash Address**: `0x0`.

## Compiling from Source
1. **Environment**: Install Arduino IDE and add ESP32‑S3 board support (via Boards Manager).
2. **Dependencies**:
   - `Adafruit_GFX` – Install via Library Manager (search for “Adafruit GFX Library”).
   - ESP32‑S3 Arduino core (includes the SPI master driver).
3. **Steps**: Open `src/CO16_10_st7789_tft_display.ino` in Arduino IDE, select the board `esp32-s3-devkitc-1` and the correct port, then compile and upload.

## Hardware Connections
The CO16 board includes an onboard ST7789 TFT display. The pin mapping used in the code is:

| ST7789 Signal | ESP32‑S3 GPIO |
|---------------|---------------|
| SCLK          | GPIO11        |
| MOSI          | GPIO10        |
| MISO          | GPIO12        |
| CS            | GPIO4         |
| DC            | GPIO0         |
| RESET         | GPIO5         |
| BACKLIGHT     | GPIO40        |

**Note**: GPIO5 is shared with the optional LoRa module. The code issues a reset pulse before initializing the display, matching the official KCS firmware behavior.

## Expected Behavior
- On startup, the Serial Monitor (115200 baud) prints initialization messages, including the SPI configuration and display resolution.
- The TFT screen shows:
  - Title: “FeedCurrent CO16” (cyan, size 3)
  - Subtitle: “ST7789 display test” (white, size 2)
  - “SPI3 native driver” (white, size 2)
  - Six color bars (red, green, blue, cyan, magenta, yellow) in the middle.
  - “Frame:” label and an incrementing frame counter at the bottom.
- The frame counter updates every second.

## Important Notes
- **SPI Driver**: The example uses the ESP32‑S3 native SPI master driver (`SPI3_HOST`) rather than the Arduino `SPI` library. This provides DMA support and higher performance.
- **Display Inversion**: The initialization sequence enables display inversion (`0x21`), which is required for correct colors on this panel.
- **MADCTL**: Set to `0x68` (MX | MV | BGR) to match the panel orientation.
- **Backlight**: Controlled via GPIO40 (set HIGH to turn on).
- **Memory**: A DMA‑capable buffer is allocated for pixel transfers. If allocation fails, an error is printed.
- **Adafruit_GFX**: The custom `Co16St7789` class inherits from `Adafruit_GFX` and implements the required drawing functions.

## Related Resources
- Pin definition: `../pin_definitions/CO16/CO16_pin_definition.md`
- Adafruit GFX library: [https://github.com/adafruit/Adafruit-GFX-Library](https://github.com/adafruit/Adafruit-GFX-Library)
- ST7789 datasheet: [https://www.buydisplay.com/download/ic/ST7789.pdf](https://www.buydisplay.com/download/ic/ST7789.pdf)