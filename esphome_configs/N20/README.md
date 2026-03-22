# N20 ESPHome Configuration

## Overview
This directory contains the ESPHome YAML configuration for the KinCony N20
20‑channel energy monitoring controller.

## File Description

| File | Description |
|------|-------------|
| `N20_esphome.yaml` | Complete ESPHome configuration with 20‑channel Modbus energy monitoring (two BL0910 chips) |

## Hardware Requirements
- KinCony N20 controller (ESP32‑S3)
- W5500 Ethernet module (built‑in)
- SSD1306 128×64 OLED display (built‑in)
- CT clamps for each monitored circuit (up to 20)

## Configuration Features
- **20‑channel energy monitoring** via two BL0910 chips on a single Modbus bus
- **Per‑channel sensors**: current (A), power (W), energy (kWh)
- **Common sensors per chip**: voltage (V), frequency (Hz), temperature (°C)
- **OLED display**: shows device IP address (DHCP)
- **W5500 Ethernet**: wired network connection (DHCP by default)
- **2× digital inputs** (GPIO15, GPIO16) – hardware capability; not configured in this YAML

## Modbus Architecture
| Chip | Register Address Range | Channels  |
|------|------------------------|-----------|
| BL0910 #1 | 100 – 160 | CH1 – CH10 |
| BL0910 #2 | 200 – 264 | CH11 – CH20 |

All sensors use the same Modbus controller (device address 1). The register base addresses distinguish the two chips.

## Usage
1. Copy `N20_esphome.yaml` to your ESPHome configuration directory
2. Update the API key and OTA password if needed
3. Flash via ESPHome dashboard or CLI:
`esphome run N20_esphome.yaml`

## Important Notes
- The OLED displays the IP address obtained via Ethernet. To change the displayed content, modify the `display` lambda.
- Power factor sensors are **not** included in this configuration; they can be added manually if required.
- Digital inputs (GPIO15, GPIO16) are not used in this YAML but can be added by extending the `binary_sensor` section.

## Related Resources
- Pin definition: `../../pin_definitions/N20/N20_pin_definition.md`
- Arduino examples: `../../arduino_demos/N20/`