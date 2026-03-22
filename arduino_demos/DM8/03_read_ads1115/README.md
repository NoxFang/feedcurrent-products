# DM8 Arduino Demo 03 - Read ADS1115 Analog Input

## Overview

This example reads analog voltage from all 4 channels of the ADS1115 16-bit ADC and displays the values in millivolts via Serial.

## Features

- Reads 4 analog channels via ADS1115 (I2C 0x48)
- 16-bit resolution
- Gain: 2/3x (max 6.144V input)
- Single-shot mode
- Update rate: 1 second

## Hardware Connections

| Pin | Function |
|-----|----------|
| GPIO8 | I2C SDA |
| GPIO18 | I2C SCL |

### ADS1115 Channels

| Channel | Type | Range |
|---------|------|-------|
| A0 | Voltage | DC 0-5V |
| A1 | Voltage | DC 0-5V |
| A2 | Current | DC 4-20mA (with shunt) |
| A3 | Current | DC 4-20mA (with shunt) |

## Required Libraries

- `Wire` - Built-in I2C library
- `DFRobot_ADS1115`

## Usage

1. Connect analog inputs to ADS1115 channels A0-A3
2. Upload the sketch to DM8
3. Open Serial Monitor (115200 baud)
4. View readings: "A0:XXXXmV, A1:XXXXmV, A2:XXXXmV, A3:XXXXmV"

## Notes

- I2C Address: 0x48
- Sample rate: 128 SPS
- Mode: Single-shot conversion
- Voltage output in millivolts (mV)
