# N60 ESPHome Configuration

## Overview
This directory contains the ESPHome YAML configuration for the KinCony N60
60‑channel energy monitoring controller.

## Files

| File | Description |
|------|-------------|
| `N60_esphome.yaml` | Complete ESPHome configuration with 6‑chip, 60‑channel Modbus energy monitoring |

## Hardware Requirements
- FeedCurrent N60 controller (ESP32‑S3)
- W5500 Ethernet module (on‑board)
- 6× BL0910 energy metering chips (on‑board, RS485 Modbus)
- SSD1306 128×64 OLED display (I2C, address 0x3C)

## Configuration Features
- **60‑channel energy monitoring** via 6 BL0910 chips on a single Modbus bus
- **Per‑chip sensors**: 10× current (A), 10× power (W), 10× energy (kWh), plus voltage (V), frequency (Hz), temperature (°C)
- **OLED display**: shows device IP address (DHCP)
- **W5500 Ethernet**: wired network connection (DHCP by default)
- **Web server**: enabled on port 80

## GPIO Pin Summary

| Interface | Pins |
|-----------|------|
| Ethernet (W5500) | CLK=GPIO42, MOSI=GPIO43, MISO=GPIO44, CS=GPIO41, INT=GPIO2, RST=GPIO1 |
| I2C (OLED) | SDA=GPIO18, SCL=GPIO17 |
| RS485 (Modbus) | TX=GPIO9, RX=GPIO10, 115200 baud |

## Modbus Architecture

All six BL0910 chips share the same Modbus controller (address 1). Register base addresses distinguish each chip:

| Chip | Register Base | Channels | Voltage / Freq / Temp |
|------|---------------|----------|------------------------|
| BL0910 #1 | 100 – 164 | CH1–CH10 | 162 (V), 163 (Hz), 164 (°C) |
| BL0910 #2 | 200 – 264 | CH11–CH20 | 262, 263, 264 |
| BL0910 #3 | 300 – 364 | CH21–CH30 | 362, 363, 364 |
| BL0910 #4 | 400 – 464 | CH31–CH40 | 462, 463, 464 |
| BL0910 #5 | 500 – 564 | CH41–CH50 | 562, 563, 564 |
| BL0910 #6 | 600 – 664 | CH51–CH60 | 662, 663, 664 |

Each chip provides:
- **Current**: addresses base+0, +2, … +18 (10 registers, scaled ×0.001)
- **Power**: base+20, +22, … +38 (scaled ×0.1)
- **Energy**: base+40, +42, … +58 (kWh, total‑increasing)
- **Total energy**: base+60 (sum of 10 channels)
- **Voltage**: base+62 (scaled ×0.01)
- **Frequency**: base+63 (scaled ×0.01)
- **Temperature**: base+64 (float, °C)

## Setup Instructions

1. Install ESPHome (pip install esphome or via Home Assistant Add‑on).
2. Replace the `api.encryption.key` and `ota.password` with your own values (or remove if not needed).
3. (Optional) For a static IP, add a `manual_ip` section under `ethernet:`.
4. Flash the firmware via USB or OTA:
   ```bash
   esphome run N60_esphome.yaml
5. The device will be discovered in Home Assistant via the ESPHome integration.

## Important Notes

- The OLED displays the IP address obtained via Ethernet. To change the content, modify the `display` lambda.
- All energy sensors are pre‑configured with the correct scaling factors (current: ×0.001, power: ×0.1, voltage: ×0.01).
- Power factor sensors are not included in this configuration; they can be added manually if needed.
- The YAML is complete – no further sensor extension is required.

## Related Resources

- Pin definition: `../../pin_definitions/N60/N60_pin_definition.md`
- Arduino examples: `../../arduino_demos/N60/`