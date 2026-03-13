# FeedCurrent B16M Controller Arduino Example 03: Read ADS1115 Analog Input Ports Value

## Description
This example reads voltage from all four ADS1115 channels (A0-A3) and prints the values in millivolts to the Serial Monitor.

## File Structure
- `src/B16M_03_read_ads1115.ino` – Arduino source code.
- `precompiled/B16M_03_read_ads1115.bin` – Precompiled binary.

## Using the Precompiled Binary
Flash `precompiled/B16M_03_read_ads1115.bin` to `0x0`.

## Compiling from Source
- **Dependencies**: Install `DFRobot_ADS1115` library via Library Manager.
- **Steps**: Compile and upload.

## Expected Output
A0:1234mV, A1:5678mV, A2:910mV, A3:112mV

## Important Notes
- ADS1115 I2C address: `0x48` (default). The code sets gain to ±6.144V.
- **I2C pins**: SDA=GPIO38, SCL=GPIO39.