# FeedCurrent B24M Controller Arduino Example 03: Read ADS1115 Analog Input

## Description
This example demonstrates how to read analog voltage values from the **ADS1115** 4-channel ADC module on the B24M board. It reads all four channels (A0-A3) and prints the values to the Serial Monitor.

## File Structure
- `src/B24M_03_read_ads1115.ino` – Arduino source code.
- `precompiled/B24M_03_read_ads1115.bin` – Precompiled firmware binary for ESP32-S3.

## Using the Precompiled Binary
Flash `precompiled/B24M_03_read_ads1115.bin` to address `0x0` using ESP Flash Download Tool or `esptool.py`.

## Compiling from Source
- **Environment**: Arduino IDE with ESP32-S3 board support.
- **Dependencies**: Install `DFRobot_ADS1115` library via Library Manager.
- **Steps**: Open the `.ino` file, select `esp32-s3-devkitc-1`, and upload.

## Expected Behavior
The Serial Monitor will display voltage readings from all four ADS1115 channels (A0-A3) in millivolts, updated every second.

## Important Notes
- **ADS1115 I2C Address**: `0x48` (default, configured as `ADS1115_IIC_ADDRESS0` in code).
- **I2C pins**: SDA=GPIO8, SCL=GPIO18.
- **Analog Inputs**:
  - A0, A1: DC 0-5V
  - A2, A3: DC 4-20mA (current loop)
- **Serial Monitor** shows debug messages at 115200 baud.
