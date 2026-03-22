# DM8 Arduino Demo 02 - Read Digital Input Ports State

## Overview

This example demonstrates how to read all 8 digital input channels via the PCF8574 I2C expander. The state of each input is printed to the Serial Monitor when a button is pressed.

## Features

- Reads 8 digital inputs via PCF8574 (I2C 0x24)
- Detects button press (active LOW)
- Polls inputs at 300ms intervals
- Prints pressed button number to Serial

## Hardware Connections

| Pin | Function |
|-----|----------|
| GPIO8 | I2C SDA |
| GPIO18 | I2C SCL |

### PCF8574 Inputs

| Input | Function |
|-------|----------|
| P0 | Digital Input 1 (KEY1) |
| P1 | Digital Input 2 (KEY2) |
| P2 | Digital Input 3 (KEY3) |
| P3 | Digital Input 4 (KEY4) |
| P4 | Digital Input 5 (KEY5) |
| P5 | Digital Input 6 (KEY6) |
| P6 | Digital Input 7 (KEY7) |
| P7 | Digital Input 8 (KEY8) |

## Required Libraries

- `Wire` - Built-in I2C library
- `PCF8574` by Renzo Mischianti

## Usage

1. Connect digital inputs to PCF8574 pins P0-P7
2. Upload the sketch to DM8
3. Open Serial Monitor (115200 baud)
4. Press buttons to see output: "KEY1 PRESSED", etc.

## Notes

- Active LOW: Button press = LOW level
- PCF8574 address: 0x24 (A2=1, A1=0, A0=0)
- Polling interval: 300ms
