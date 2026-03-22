# F8 ESPHome Configuration (With Tuya)

## Overview
This configuration is for the FeedCurrent F8 controller with Tuya Wi‑Fi module integration.  
It provides 8 relay outputs, 8 digital inputs, 4 analog inputs, Ethernet, RS485, and an OLED display.

## Hardware Configuration
- **MCU**: ESP32‑S3 (Arduino framework)
- **I2C Bus**: SDA=GPIO8, SCL=GPIO18, 400kHz
- **PCF8575**: Address 0x24, 16‑bit I/O expander
  - Inputs: P0‑P7 (8 channels, active LOW)
  - Outputs: P8‑P15 (8 relays, active LOW)
- **Analog Inputs** (ESP32 ADC):
  - A1 (GPIO5) – Voltage, 0‑5V with calibration
  - A2 (GPIO7) – Voltage, 0‑5V with calibration
  - A3 (GPIO6) – Current, 4‑20mA (multiplier 6.6667)
  - A4 (GPIO4) – Current, 4‑20mA (multiplier 6.6667)
- **1‑Wire / Free GPIO**:
  - With pull‑up: GPIO48,47,21,15
  - Without pull‑up: GPIO14,40,0
- **RS485**: UART TX=16, RX=17, 9600 baud (test button included)
- **Tuya Wi‑Fi Module**: UART TX=39, RX=38, 9600 baud, product ID `gk6ok3aysk6lw1bb`
  - DP mapping: Outputs 1‑8 → DP 1‑6,101,102; Inputs 1‑8 → DP 111‑118
- **Ethernet**: W5500 SPI (CLK=42, MOSI=43, MISO=44, CS=41, INT=2, RST=1)
- **Display**: SSD1306 (0x3C) – shows "FeedCurrent F8"
- **Web Server**: Port 80

## Flashing Instructions
1. Install ESPHome.
2. Copy the YAML file to your configuration directory.
3. Run `esphome run F8_esphome_with_tuya.yaml`.
4. Add to Home Assistant via ESPHome integration.

## Notes
- All relays and inputs are active‑LOW.
- ADC calibration filters are included; adjust if needed.
- For static IP, add `manual_ip` under `ethernet:`.
- The RS485 test button sends a fixed packet; it can be removed or repurposed.

## Reference
- [FeedCurrent Official Website](https://www.feedcurrent.com)
- Pin definition: `pin_definitions/F8/F8_pin_definition.md`