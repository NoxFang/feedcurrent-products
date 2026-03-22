# F24 ESPHome Configurations

## Overview

This directory contains ESPHome configuration files for the **F24 24‑channel relay controller**.  
Two versions are intended:

- `F24_esphome_with_tuya.yaml` – Full hardware support + Tuya Wi‑Fi MCU cloud integration.
- `F24_esphome_without_tuya.yaml` – **Should be** a local‑only version with full hardware support.  
  ⚠️ **Current file is incorrect** – it contains a KC868‑HAv2 configuration (only 6 channels).  
  A corrected version is described below; replace the existing file with the template provided.

---

## Correct Hardware Description (Based on `with_tuya.yaml`)

The F24 controller uses **three PCF8575 16‑bit I/O expanders** and **ESP32‑S3 internal ADC**.

| Chip | I²C Address | Function |
|------|-------------|----------|
| U23 | `0x24` | Digital inputs 1–16 (pins 0‑15) |
| U27 | `0x25` | Relay outputs 9–24 (pins 0‑15) |
| U49 | `0x26` | Relay outputs 1–8 (pins 8‑15) + Digital inputs 17–24 (pins 0‑7) |

### Pin Assignments

#### Digital Inputs (active‑LOW)
- **Inputs 1–16**: U23, pins 0‑15 → `f24-input01` … `f24-input16`
- **Inputs 17–24**: U49, pins 0‑7 → `f24-input17` … `f24-input24`

#### Relay Outputs (active‑LOW)
- **Outputs 1–8**: U49, pins 8‑15 → `f24-output01` … `f24-output08`  
  (exact mapping: output1=pin12, output2=pin13, output3=pin14, output4=pin15, output5=pin8, output6=pin9, output7=pin10, output8=pin11)
- **Outputs 9–24**: U27, pins 0‑15 → `f24-output09` … `f24-output24`

#### Analog Inputs (ESP32 internal ADC)
| GPIO | Channel | Type | Calibration |
|------|---------|------|-------------|
| 5 | A1 | Voltage (0‑5V) | Lambda filter (1.60256 / 1.51 factor) |
| 7 | A2 | Voltage (0‑5V) | Lambda filter (1.60256 / 1.51 factor) |
| 6 | A3 | Current (4‑20mA) | Multiply by 6.66666666 |
| 4 | A4 | Current (4‑20mA) | Multiply by 6.66666666 |

#### 1‑Wire / Free GPIO
| GPIO | Pull‑up | Binary Sensor Name | Notes |
|------|---------|---------------------|-------|
| 48 | Yes | `f24-W1-io48` | Active LOW |
| 47 | Yes | `f24-W1-io47` | Active LOW |
| 21 | Yes | `f24-W1-io21` | Active LOW |
| 15 | Yes | `f24-W1-io15` | Active LOW |
| 13 | No | `f24-W1-io13` | Active HIGH |
| 14 | No | `f24-W1-io14` | Active HIGH |
| 40 | No | `f24-433M` | 433MHz receiver, Active HIGH |

#### Communication Interfaces
| Interface | Pins | Notes |
|-----------|------|-------|
| Ethernet (W5500) | CLK=42, MOSI=43, MISO=44, CS=41, INT=2, RST=1 | DHCP by default |
| RS485 | TX=16, RX=17, 9600 baud | Includes test button |
| Tuya WiFi MCU (with_tuya) | TX=39, RX=38, 9600 baud | Product ID `cchos3g1j2ucfbyd` |

#### I2C Bus
- **SDA=GPIO8, SCL=GPIO18, 400kHz**  
- Devices: PCF8575 chips (0x24, 0x25, 0x26) and SSD1306 OLED (0x3C)

#### OLED Display
- Displays `"FeedCurrent F24"` using Roboto 20px font.

#### Web Server
- Enabled on port 80.

---

## Flashing Instructions
1. Install ESPHome (standalone or Home Assistant add‑on).
2. Copy the YAML file to your configuration directory.
3. Compile and upload via USB (first time) or OTA.
4. After flashing, the device will appear in Home Assistant via the ESPHome integration.

## Important Notes
- All relays and digital inputs are active‑LOW (connected to GND = ON).
- ADC calibration filters are pre‑configured; adjust if your hardware uses different voltage dividers.
- For static IP, add `manual_ip` under `ethernet:`.
- The RS485 test button sends a fixed packet; it can be removed or repurposed.
- Do not use the current `without_tuya` file – replace it with the template or a corrected version.

## Reference
- [FeedCurrent Official Website](https://www.feedcurrent.com)
- Pin definition: `pin_definitions/F24/F24_pin_definition.md`