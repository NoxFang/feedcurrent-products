# B2 Arduino Example 03: Read ADS1115 Analog Inputs

## Description
This example demonstrates how to read voltage values from all four channels (A0, A1, A2, A3) of the ADS1115 ADC module on the B2 board.  
The readings are printed to the Serial Monitor in millivolts (mV) every second.

## File Structure
- `src/B2_03_read_ads1115.ino` – Arduino source code.
- `precompiled/B2_03_read_ads1115.bin` – Precompiled firmware binary for ESP32‑S3.

## Using the Precompiled Binary
1. Download the `.bin` file from the `precompiled/` folder.
2. Use the official **ESP Flash Download Tool** or `esptool.py` to flash it to the B2 controller.
3. **Flash Address**: `0x0`.

## Compiling from Source
1. **Environment**: Install Arduino IDE and add ESP32‑S3 board support (via Boards Manager).
2. **Dependencies**:
   - `Wire.h` (built‑in)
   - `DFRobot_ADS1115.h` – Install via Library Manager (search for “DFRobot ADS1115”) or download from [DFRobot’s GitHub](https://github.com/DFRobot/DFRobot_ADS1115).
3. **Steps**: Open the `.ino` file inside the `src/` folder, select the board `esp32-s3-devkitc-1` and the correct port, then compile and upload.

## Hardware Connections
| Signal | GPIO |
|--------|------|
| I2C SDA | GPIO8 |
| I2C SCL | GPIO18 |

**ADS1115 I2C Address**: The code uses `ADS1115_IIC_ADDRESS0`. In the DFRobot library this is typically `0x48`, but the code comment says `0x49`. Please verify your module’s actual address (check the ADDR pin connection) and adjust the following line if necessary:
```cpp
ads.setAddr_ADS1115(ADS1115_IIC_ADDRESS0);   // or ADS1115_IIC_ADDRESS1 for 0x49

## Expected Output
After flashing and opening the Serial Monitor (115200 baud), you will see output like:
`A0:1234mV,  A1:5678mV,  A2:910mV,  A3:112mV`
If the ADS1115 is not detected, the message `ADS1115 Disconnected!` is printed.

## Important Notes
- **Gain**: Set to eGAIN_TWOTHIRDS (maximum input ±6.144 V). Adjust if your signal range differs.
- **Mode**: Single‑shot conversion, 128 samples per second.
- Ensure the ADS1115 is properly powered and connected to the I2C bus. The example checks for the device each loop.

## Related Resources
- Pin definition: `../pin_definitions/B2/B2_pin_definition.md`