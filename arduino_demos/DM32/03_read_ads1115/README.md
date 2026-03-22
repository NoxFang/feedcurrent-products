# DM32 Example 03: Read ADS1115 Analog Input Ports Value

## Overview

This example demonstrates how to read voltage values from ADS1115 4-channel ADC on all four channels (A0, A1, A2, A3).

**Features**:
- Read all 4 ADS1115 channels
- Display voltage in millivolts (mV)
- Update rate: 1 second
- Gain: 2/3x (±6.144V range)

---

## Hardware Requirements

### ADS1115 ADC
- **I2C Address**: 0x48
- **Channels**: 4 single-ended inputs (A0-GND, A1-GND, A2-GND, A3-GND)
- **Resolution**: 16-bit (65535 levels)
- **Gain Setting**: 2/3x (±6.144V range)

### I2C Bus
- **SDA Pin**: GPIO8
- **SCL Pin**: GPIO18

---

## Channel Configuration

| Channel | Entity Name | Range | Description |
|----------|-------------|-------|-------------|
| A0-GND | ADS1115 Channel A0 | ±6.144V | Analog input 1 (0-5V) |
| A1-GND | ADS1115 Channel A1 | ±6.144V | Analog input 2 (0-5V) |
| A2-GND | ADS1115 Channel A2 | ±6.144V | Analog input 3 (4-20mA) |
| A3-GND | ADS1115 Channel A3 | ±6.144V | Analog input 4 (4-20mA) |

---

## Library Dependencies

- `DFRobot_ADS1115.h` - For ADS1115 ADC control

---

## Serial Monitor Output

```
A0:3250mV,  A1:3320mV,  A2:2480mV,  A3:2510mV
ADS1115 Disconnected!
```

Voltage readings are displayed in millivolts (mV).

---

## Important Notes

- **Gain Setting**: The ADS1115 is configured for 2/3x gain (±6.144V range) for measuring 0-5V and 4-20mA inputs.
- **Update Rate**: Readings are taken every 1 second.
- **Error Handling**: The code checks if ADS1115 is connected and displays "ADS1115 Disconnected!" if not found.
- **Units**: All readings are displayed in millivolts (mV) for precision.

