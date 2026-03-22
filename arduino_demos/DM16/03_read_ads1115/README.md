# DM16 Arduino Example 03: Read ADS1115 Analog Input

## Description
This example reads the 4‑channel analog input from the ADS1115 16‑bit ADC on the DM16 board. It prints the voltage values in millivolts to the Serial Monitor every second.

## Hardware Connections
| Signal | GPIO |
|--------|------|
| I2C SDA | GPIO8 |
| I2C SCL | GPIO18 |
| ADS1115 I2C Address | 0x48 |

## Configuration
- **Gain**: ±6.144 V (set to `eGAIN_TWOTHIRDS`, suitable for 0–5 V inputs)
- **Mode**: Single‑shot conversion
- **Sample Rate**: 128 samples per second (SPS)
- **Update Interval**: 1 second

## Input Channels
| Channel | Description |
|---------|-------------|
| A0 | Analog input 0 (voltage) |
| A1 | Analog input 1 (voltage) |
| A2 | Analog input 2 (current, with appropriate shunt resistor) |
| A3 | Analog input 3 (current, with appropriate shunt resistor) |

## Serial Output
After uploading, open the Serial Monitor at **115200 baud**. You will see a line like this every second:
A0:1234mV, A1:5678mV, A2:910mV, A3:112mV

The values represent the measured voltage in millivolts on each channel.

## Usage
1. Connect analog sensors to the DM16 analog input terminals.
2. Upload the sketch to the DM16 board.
3. Open the Serial Monitor at 115200 baud.
4. Observe the readings.

## Dependencies
- `Wire` library (built‑in)
- `DFRobot_ADS1115` library (install via Library Manager)

## Related Resources
- DM16 Pin Definition: `../pin_definitions/DM16/DM16_pin_definition.md`
