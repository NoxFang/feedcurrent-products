# F16 ESPHome Configurations

## Overview
This directory contains two ESPHome configuration files for the FeedCurrent F16 16‑channel relay controller:
- `F16_esphome_without_tuya.yaml` – Local‑only version, no Tuya cloud integration.
- `F16_esphome_with_tuya.yaml` – Includes Tuya WiFi MCU support for cloud control.

## Hardware Support (Common to Both Versions)
- **16‑channel relay output** (PCF8575 @ 0x25, pins 0‑15, active LOW)
- **16‑channel digital input** (PCF8575 @ 0x24, pins 0‑15, active LOW)
- **4‑channel analog input** (ESP32 ADC, pins 5,7,6,4)
  - A1 (GPIO5), A2 (GPIO7): 0‑5V voltage with calibration
  - A3 (GPIO6), A4 (GPIO4): 4‑20mA current with multiplier
- **1‑Wire / free GPIO**:
  - With pull‑up: GPIO48,47,21,15 (binary_sensors, active LOW)
  - Without pull‑up: GPIO13,14,40 (binary_sensors, active HIGH)
- **RS485** (UART: TX=16, RX=17, 9600 baud) with test button
- **Ethernet** (W5500 SPI: CLK=42, MOSI=43, MISO=44, CS=41, INT=2, RST=1)
- **I2C** (SDA=8, SCL=18, 400kHz) connecting OLED (0x3C) and PCF8575 chips
- **OLED display**: SSD1306 128×64, shows "FeedCurrent F16"
- **Web server**: enabled on port 80

## Configuration Differences
- **Without Tuya**: standard ESPHome with all local controls.
- **With Tuya**: adds Tuya WiFi MCU (UART TX=39, RX=38, product ID `chmzlgjpadpqxdko`). Tuya DP IDs map to all relays and inputs, enabling state synchronization with Tuya app.

## Flashing Instructions
1. Install ESPHome.
2. Copy the desired YAML file to your configuration directory.
3. Run `esphome run <filename>.yaml` and follow the prompts.
4. After flashing, add the device to Home Assistant via ESPHome integration.

## Important Notes
- All relays and digital inputs are active‑LOW (connected to GND = ON).
- ADC calibration filters are pre‑configured; adjust if your hardware differs.
- For static IP, add a `manual_ip` section under `ethernet:`.
- The RS485 test button sends a fixed packet; it can be removed or repurposed.

## Reference
- [FeedCurrent Official Website](https://www.feedcurrent.com)
- Pin definition: `pin_definitions/F16/F16_pin_definition.md`