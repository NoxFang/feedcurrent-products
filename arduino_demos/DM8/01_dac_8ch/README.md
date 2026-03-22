# DM8 Arduino Demo 01 - 8 Channel DAC Output

## Overview

This example demonstrates how to control 8‑channel DAC output using Modbus RTU protocol. The DAC outputs are adjusted by 8 digital input buttons connected via a PCF8574 I2C expander. **Long‑press** on a button gradually increases the corresponding DAC output value.

## Features

- Reads 8 digital input buttons via PCF8574 (I2C address 0x24)
- Controls 8‑channel DAC via Modbus RTU (addresses 0x0FA0–0x0FA7)
- **Long press** (>500 ms): Gradually increases DAC output value (0 → ~4000)
- **Short press**: No action (the example only implements long‑press ramping)
- Output range: 0–4095 (12‑bit DAC), but current implementation ramps up to approximately 4000

## Hardware Connections

| Pin | Function |
|-----|----------|
| GPIO8 | I2C SDA |
| GPIO18 | I2C SCL |
| GPIO4 | ARM CPU TXD (Modbus) |
| GPIO6 | ARM CPU RXD (Modbus) |

### I2C Devices

| Device | Address |
|--------|---------|
| PCF8574 | 0x24 |

### Modbus DAC Channels

| Channel | Modbus Address |
|---------|----------------|
| 1 | 0x0FA0 |
| 2 | 0x0FA1 |
| 3 | 0x0FA2 |
| 4 | 0x0FA3 |
| 5 | 0x0FA4 |
| 6 | 0x0FA5 |
| 7 | 0x0FA6 |
| 8 | 0x0FA7 |

## Required Libraries

- `Wire` - Built‑in I2C library
- `Adafruit_PCF8574` by Adafruit (or similar)
- `HardwareSerial` - Built‑in

## Usage

1. Connect digital input buttons to PCF8574 pins P0–P7 (buttons should connect the pin to GND when pressed; internal pull‑ups are enabled).
2. Upload the sketch to DM8.
3. Open Serial Monitor (115200 baud).
4. Press and hold a button to increase the corresponding DAC output value. The value increments by 100 every 100 ms. Release to stop.

## Expected Behavior

- When a button is pressed and held, the Serial Monitor prints:
key xx # is pressed!
key_long_press_time = <ms>, current_light = <value>
- The DAC output value (0–~4000) increases as long as the button is held.
- Releasing the button stops the increase. There is no separate “short press” toggle action.

## Important Notes

- The Modbus communication runs at 115200 baud.
- The DAC is controlled via an ARM CPU on the DM8 board using Modbus RTU.
- Long press ramping speed: increments by 100 every 100 ms (i.e., 1000 per second).
- The output value does not automatically reset to 0 on release; it remains at the last set value.