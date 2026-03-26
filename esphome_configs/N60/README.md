# N60 ESPHome Configuration

## Overview
This directory contains ESPHome YAML configurations for the FeedCurrent N60
60‑channel energy monitoring controller.

## Files

| File | Description |
|------|-------------|
| `N60_esphome.yaml` | Original configuration with **1 kWh** energy resolution.<br>Requires ARM CPU firmware version < V20_260305SP. |
| `N60_esphome_v2.yaml` | Updated configuration with **0.001 kWh** energy resolution.<br>Requires ARM CPU firmware **≥ V20_260305SP**. |

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

## Version Differences

| Feature | N60_esphome.yaml | N60_esphome_v2.yaml |
|---------|------------------|---------------------|
| Current resolution | 0.001 A | 0.001 A |
| Power resolution | 0.1 W | 0.1 W |
| Energy resolution | 1 kWh | **0.001 kWh** |
| ARM firmware required | Any | **≥ V20_260305SP** |
| Register format for energy | U_DWORD_R (raw) | FP32_R (IEEE 754) |

> **Important**: The high‑precision version (`_v2`) uses 32‑bit floating‑point registers for energy values and requires the ARM CPU firmware to be updated to version **V20_260305SP** or later.  
> If you are using an older ARM firmware, please use the original `N60_esphome.yaml`.

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
| BL0910 #1 | 100 – 166 | CH1–CH10 | 162 (V), 163 (Hz), 164 (°C) |
| BL0910 #2 | 200 – 266 | CH11–CH20 | 262, 263, 264 |
| BL0910 #3 | 300 – 366 | CH21–CH30 | 362, 363, 364 |
| BL0910 #4 | 400 – 466 | CH31–CH40 | 462, 463, 464 |
| BL0910 #5 | 500 – 566 | CH41–CH50 | 562, 563, 564 |
| BL0910 #6 | 600 – 666 | CH51–CH60 | 662, 663, 664 |

Each chip provides:
- **Current**: addresses base+0, +2, … +18 (10 registers, scaled ×0.001)
- **Power**: base+20, +22, … +38 (scaled ×0.1)
- **Energy (high precision)**: base+40, +42, … +58 (FP32, kWh)
- **Energy (legacy)**: base+40, +42, … +58 (U_DWORD_R, raw, 1 kWh resolution)
- **Total energy**: base+60 (FP32, kWh)
- **Voltage**: base+62 (scaled ×0.01)
- **Frequency**: base+63 (scaled ×0.01)
- **Temperature**: base+64 (float, °C)
- **Power factor**: base+66 (float)

## Setup Instructions

1. Install ESPHome (pip install esphome or via Home Assistant Add‑on).
2. Copy the desired YAML file to your ESPHome configuration directory.
3. Replace the `api.encryption.key` and `ota.password` with your own values (or remove if not needed).
4. (Optional) For a static IP, add a `manual_ip` section under `ethernet:`.
5. Flash the firmware via USB or OTA:
   ```bash
   esphome run N60_esphome_v2.yaml
   ```
6. If you encounter incorrect energy readings, verify that the ARM firmware meets the version requirement.

## Important Notes
- The OLED displays the IP address obtained via Ethernet. To change the content, modify the `display` lambda.
- All sensors are pre‑configured with the correct scaling factors (current: ×0.001, power: ×0.1, voltage: ×0.01).Power factor - sensors are included in the high‑precision configuration.
- The YAML is complete – no further sensor extension is required.

## Related Resources
- Pin definition: `../../pin_definitions/N60/N60_pin_definition.md`
- Arduino examples: `../../arduino_demos/N60/`