# DM8 Arduino Demo 05 - Read Free GPIO State

## Overview

This example monitors the state of 8 GPIO pins and reports changes to the Serial Monitor.

## Features

- Monitors 8 GPIO pins for state changes
- Debounced detection (100ms)
- Reports HIGH/LOW transitions
- Includes 1-Wire and free GPIOs

## Hardware Connections

| GPIO | Function |
|------|----------|
| GPIO40 | 1-Wire 4 |
| GPIO7 | Monitored |
| GPIO48 | 1-Wire 2 |
| GPIO47 | 1-Wire 1 |
| GPIO13 | Free GPIO |
| GPIO14 | Free GPIO |
| GPIO21 | Free GPIO |
| GPIO0 | Boot button / Monitored |

## Required Libraries

- None (built-in GPIO)

## Usage

1. Connect signals to monitored GPIO pins
2. Upload the sketch to DM8
3. Open Serial Monitor (115200 baud)
4. Toggle inputs to see state change messages

## Notes

- Detection interval: 100ms
- Input mode: No pull-up (external required)
- 1-Wire pins have PCB pull-ups (GPIO40/47/48)
