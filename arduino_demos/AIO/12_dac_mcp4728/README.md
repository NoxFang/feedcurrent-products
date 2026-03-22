# AIO Hybrid Arduino Example 12: DAC MCP4728 Analog Output

## Description
This example demonstrates how to control the MCP4728 4‑channel 12‑bit DAC (Digital‑to‑Analog Converter) on the AIO Hybrid board. It initializes the DAC over I2C, sets each channel to a different output value, and then idles.

## File Structure
- `src/AIO_12_dac_mcp4728.ino` – Arduino source code.
- `precompiled/AIO_12_dac_mcp4728.bin` – Precompiled firmware binary for ESP32‑S3 (to be added).

## Using the Precompiled Binary
1. Download the `.bin` file from the `precompiled/` folder.
2. Use the official **ESP Flash Download Tool** or `esptool.py` to flash it to the AIO Hybrid controller.
3. **Flash Address**: `0x0` (as indicated in the forum post).

## Compiling from Source
1. **Environment**: Install Arduino IDE and add ESP32‑S3 board support (via Boards Manager).
2. **Dependencies**:
   - `Wire.h` (built‑in)
   - `Adafruit_MCP4728.h` – Install via Library Manager (search for "Adafruit MCP4728").
3. **Steps**:
   - Open `src/AIO_12_dac_mcp4728.ino` in Arduino IDE.
   - Select the correct board (`esp32-s3-devkitc-1`) and port.
   - Compile and upload.

## Expected Behavior
After uploading, open the Serial Monitor at **115200 baud**. You will see:
Adafruit MCP4728 test!

The DAC outputs are set as follows:
- **Channel A**: 4095 (full scale, ≈ 3.3 V if Vref = VDD)
- **Channel B**: 2048 (half scale, ≈ 1.65 V)
- **Channel C**: 1024 (quarter scale, ≈ 0.825 V)
- **Channel D**: 0 (0 V)

The loop does nothing after setup, so the outputs remain at these values until the board is reset or reprogrammed.

## Important Notes
- **I2C pins**: SDA=GPIO8, SCL=GPIO18 (as defined in the code).
- **I2C address**: The MCP4728 uses address `0x60` by default (the library handles this). If your board uses a different address, modify the `mcp.begin()` call.
- **Output range**: The DAC output voltage depends on the reference voltage (`Vref`). By default, the MCP4728 uses the supply voltage (VDD) as reference. On the AIO Hybrid, VDD is typically 3.3 V.
- **Library**: The example uses the Adafruit MCP4728 library. For more advanced features (e.g., updating individual channels, saving to EEPROM), refer to the library documentation.
- **Idle state**: The `loop()` only contains a delay, so the microcontroller consumes minimal power after initialization.

## Related Resources
- Pin definition: `../pin_definitions/AIO/AIO_pin_definition.md`
- Forum source: https://www.kincony.com/forum/showthread.php?tid=8546
- [Adafruit MCP4728 library documentation](https://github.com/adafruit/Adafruit_MCP4728)