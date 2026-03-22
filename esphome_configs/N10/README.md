# N10 ESPHome Configuration

## Overview
This directory contains the ESPHome YAML configuration for the KinCony N10
10‑channel energy monitoring controller.

## File Description

| File | Description |
|------|-------------|
| `N10_esphome.yaml` | Complete ESPHome configuration with Modbus energy monitoring |

## Hardware Requirements
- KinCony N10 controller (ESP32‑S3)
- W5500 Ethernet module (built‑in)
- SSD1306 128×64 OLED display (built‑in)
- CT clamps for each monitored circuit (up to 10)

## Configuration Features
- **10‑channel energy monitoring** via Modbus RTU
- **Per‑channel sensors**: current (A), power (W), energy (kWh)
- **Common sensors**: voltage (V), frequency (Hz), temperature (°C)
- **OLED display**: shows device IP address (DHCP)
- **W5500 Ethernet**: wired network connection (DHCP by default)
- **2× digital inputs** (GPIO15, GPIO16) – hardware capability; not configured in this YAML

## Usage
1. Copy `N10_esphome.yaml` to your ESPHome configuration directory
2. Update the API key and OTA password if needed
3. Flash via ESPHome dashboard or CLI:
`esphome run N10_esphome.yaml`


## Modbus Communication
- Protocol: Modbus RTU
- Baud rate: 115200 (UART to ARM CPU)
- Energy chip baud rate: 38400
- Device address: 0x01

## Important Notes
- The OLED displays the IP address obtained via Ethernet. To change the displayed content, modify the `display` lambda.
- The configuration does **not** include power factor sensors; if needed, they must be added manually.
- Digital inputs (GPIO15, GPIO16) are not used in this YAML but can be added by extending the `binary_sensor` section.

## Related Resources
- Pin definition: `../../pin_definitions/N10/N10_pin_definition.md`
- Arduino examples: `../../arduino_demos/N10/`