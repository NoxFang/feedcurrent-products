# F4 ESPHome Configurations

## Overview
This directory contains two ESPHome configuration files for the F4 controller.

## Files
- `f4_esphome_without_tuya.yaml` – Local‑only version, no Tuya cloud integration.
- `f4_esphome_with_tuya.yaml` – Includes Tuya WiFi MCU support for cloud control.

## Hardware Support (Common to Both Versions)
- 4‑channel relay output (PCF8574 @ 0x24, pins 4‑7, active LOW)
- 4‑channel digital input (PCF8574 @ 0x24, pins 0‑3, active LOW)
- 4‑channel analog input (ESP32 ADC, pins 4,5,6,7)
- Ethernet (W5500 SPI: CLK=42, MOSI=43, MISO=44, CS=41, INT=2, RST=1)
- RS485 test button (UART: TX=16, RX=17, 9600 baud)
- I2C bus (SDA=8, SCL=18) with SSD1306 OLED (0x3C)
- 1‑Wire / free GPIOs (detailed in the YAML)
- Web server on port 80

## Configuration Details
(Include full pin tables, Tuya DP mapping, ADC calibration notes, etc.)

## Reference
- [FeedCurrent Official Website](https://www.feedcurrent.com)
- Pin definition: `pin_definitions/F4/F4_pin_definition.md`