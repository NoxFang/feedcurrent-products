# F32 ESPHome Configuration (Without Tuya)

## Overview
This ESPHome YAML configuration is for the **FeedCurrent F32 32‑channel relay controller**, providing local Home Assistant integration via Ethernet. It supports 32 relays, 32 digital inputs, 4 analog inputs, RS485, OLED display, and 1‑Wire/free GPIOs.

**This is a local‑only configuration – no Tuya cloud integration.**

## Hardware Features
- **4 × PCF8575 I/O expanders** (16‑bit, I2C)
- **32 relay outputs** (active‑LOW)
- **32 digital inputs** (active‑LOW)
- **4 analog inputs** (2 voltage, 2 current, ESP32 internal ADC)
- **Ethernet** (W5500 SPI)
- **RS485** (UART with test button)
- **OLED display** (SSD1306, 128×64)
- **1‑Wire / free GPIOs** (6 pins)
- **Web server** (port 80)

## PCF8575 I2C Address Mapping

| Chip | I²C Address | Function |
|------|-------------|----------|
| `pcf8574_hub_in_1` | 0x24 | Digital inputs 1‑16 (pins 0‑15) |
| `pcf8574_hub_out_1` | 0x25 | Relay outputs 17‑32 (pins 0‑15) |
| `pcf8574_hub_out_in_2` | 0x26 | Outputs 9‑16 (pins 8‑15) + Inputs 17‑24 (pins 0‑7) |
| `pcf8574_hub_out_in_3` | 0x27 | Outputs 1‑8 (pins 8‑15) + Inputs 25‑32 (pins 0‑7) |

## GPIO Pin Assignments

| Function | GPIO | Notes |
|----------|------|-------|
| I2C SDA | 8 | |
| I2C SCL | 18 | |
| Ethernet CS | 41 | W5500 SPI chip select |
| Ethernet INT | 2 | W5500 interrupt |
| Ethernet RST | 1 | W5500 reset |
| RS485 TX | 16 | UART transmit |
| RS485 RX | 17 | UART receive |
| Analog A1 (voltage) | 5 | 0‑5V with calibration |
| Analog A2 (voltage) | 7 | 0‑5V with calibration |
| Analog A3 (current) | 6 | 4‑20mA (multiplier 6.6667) |
| Analog A4 (current) | 4 | 4‑20mA (multiplier 6.6667) |

### 1‑Wire / Free GPIOs

| GPIO | Pull‑up | Binary Sensor Name | Notes |
|------|---------|---------------------|-------|
| 48 | Yes | `f32-W1-io48` | Active LOW |
| 47 | Yes | `f32-W1-io47` | Active LOW |
| 21 | Yes | `f32-W1-io21` | Active LOW |
| 15 | Yes | `f32-W1-io15` | Active LOW |
| 13 | No | `f32-W1-io13` | Active HIGH |
| 14 | No | `f32-W1-io14` | Active HIGH |
| 40 | No | `f32-433M` | 433MHz receiver, Active HIGH |

## Flashing Instructions

1. Install ESPHome (standalone or Home Assistant add‑on).
2. Copy `F32_esphome_without_tuya.yaml` to your configuration directory.
3. Compile and upload via USB (first time) or OTA.
4. After flashing, the device will appear in Home Assistant via the ESPHome integration.

## Important Notes

- All relays and digital inputs are **active‑LOW** (connected to GND = ON).
- ADC calibration filters are pre‑configured; adjust if your hardware uses different voltage dividers.
- **Ethernet is the only network interface** – WiFi is not used in this configuration.
- For a static IP, add a `manual_ip` section under `ethernet:`.
- The RS485 test button sends a fixed packet; it can be removed or repurposed.
- **No Tuya components** are included – this is a purely local configuration.

## Reference

- **Pin definitions**: `../pin_definitions/F32/F32_pin_definition.md`
- **FeedCurrent Website**: https://www.feedcurrent.com/