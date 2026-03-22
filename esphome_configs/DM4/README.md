# DM4 ESPHome Configuration

## Overview

This directory contains the ESPHome YAML configuration for the KinCony DM4
multi-function I/O controller (without Tuya cloud integration).

## Files

| File | Description |
|------|-------------|
| `DM4_esphome.yaml` | ESPHome config — Home Assistant local, no Tuya |

## Hardware Covered

| Component | Details |
|-----------|---------|
| Ethernet | W5500 (CLK=1, MOSI=2, MISO=41, CS=42, INT=43, RST=44); DHCP by default |
| I2C Bus | SDA=GPIO8, SCL=GPIO18 |
| Digital Inputs | PCF8574 @ 0x24, 4 channels (P0–P3) |
| Analog Inputs | ADS1115 @ 0x48, 4 channels (A0–A3) |
| DAC Outputs | MCP4728 @ 0x60, 4 channels (A–D), 12‑bit |
| OLED Display | SSD1306 128×64 @ 0x3C (displays IP address) |
| RS485 | UART: TX=GPIO38, RX=GPIO39, 9600 baud (with test button) |
| 1‑Wire / GPIOs | See pin definition file for exact mapping |
| Free GPIO | GPIO0, GPIO13, GPIO14, GPIO21 (no pull‑up) |

## Setup Instructions

1. Install ESPHome (pip install esphome or via Home Assistant Add-on)
2. (Optional) To use static IP, add a `manual_ip` section under `ethernet:`.
3. Flash via USB first time, then OTA updates.
4. After flashing, the device will show its IP address on the OLED.

## Related Resources

- [FeedCurrent Official Website](https://www.feedcurrent.com)
- Pin Definition: `pin_definitions/DM4/DM4_pin_definition.md`