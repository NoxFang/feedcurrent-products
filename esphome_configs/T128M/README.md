# T128M ESPHome Configuration

## Overview
This directory contains the ESPHome YAML configuration for the T128M 128-channel digital I/O controller.

## Files

| File | Description |
|------|-------------|
| `T128M_esphome.yaml` | Main ESPHome configuration for Home Assistant integration |

## Hardware Requirements

- T128M ESP32-S3 controller
- 12–24V DC power supply
- Ethernet cable (W5500 onboard)

## Key Configuration Details

| Parameter | Value |
|-----------|-------|
| Board | ESP32-S3 |
| Framework | esp-idf |
| Network | W5500 Ethernet |
| I2C Bus A (Outputs) | SDA=GPIO48, SCL=GPIO47 |
| I2C Bus B (Inputs) | SDA=GPIO12, SCL=GPIO11 |
| Output chips | 8× PCF8575 @ 0x20–0x27 on Bus A |
| Input chips | 8× PCF8575 @ 0x20–0x27 on Bus B |
| Output channels | 128 (inverted logic) |
| Input channels | 128 (inverted logic) |
| Analog inputs | A1 (GPIO7, 0–5V), A2 (GPIO6, 0–5V), A3 (GPIO5, 4–20mA), A4 (GPIO4, 4–20mA) |

## Usage

1. Copy `T128M_esphome.yaml` to your ESPHome configuration directory.
2. Update the `api:` section with your encryption key if needed.
3. Flash via USB or OTA.
4. Add the device in Home Assistant → ESPHome integration.

## Precompiled Firmware

The `precompiled/` directory is reserved for compiled `.bin` firmware files.
