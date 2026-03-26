# N30 ESPHome Configuration

## Overview
This directory contains ESPHome YAML configurations for the FeedCurrent N30
30‑channel energy monitoring controller.

## File Description

| File | Description |
|------|-------------|
| `N30_esphome.yaml` | Original configuration with **1 kWh** energy resolution.<br>Requires ARM CPU firmware version < V20_260305SP. |
| `N30_esphome_v2.yaml` | Updated configuration with **0.001 kWh** energy resolution.<br>Requires ARM CPU firmware **≥ V20_260305SP**. |

## Hardware Requirements
- FeedCurrent N30 controller (ESP32‑S3)
- W5500 Ethernet module (built‑in)
- SSD1306 128×64 OLED display (built‑in)
- CT clamps for each monitored circuit (up to 30)

## Configuration Features
- **30‑channel energy monitoring** via three BL0910 chips on a single Modbus bus
- **Per‑channel sensors**: current (A), power (W), energy (kWh)
- **Common sensors per chip**: voltage (V), frequency (Hz), temperature (°C)
- **OLED display**: shows device IP address (DHCP)
- **W5500 Ethernet**: wired network connection (DHCP by default)
- **2× digital inputs** (GPIO15, GPIO16) – hardware capability; not configured in this YAML

## Modbus Architecture
| Chip | Register Address Range | Channels  |
|------|------------------------|-----------|
| BL0910 #1 | 100 – 166 | CH1 – CH10 |
| BL0910 #2 | 200 – 266 | CH11 – CH20 |
| BL0910 #3 | 300 – 366 | CH21 – CH30 |

All sensors use the same Modbus controller (device address 1). The register base addresses distinguish the three chips.

## Version Differences

| Feature | N30_esphome.yaml | N30_esphome_v2.yaml |
|---------|------------------|---------------------|
| Current resolution | 0.001 A | 0.001 A |
| Power resolution | 0.1 W | 0.1 W |
| Energy resolution | 1 kWh | **0.001 kWh** |
| ARM firmware required | Any | **≥ V20_260305SP** |
| Register format for energy | U_DWORD_R (raw) | FP32_R (IEEE 754) |

> **Important**: The high‑precision version (`_v2`) uses 32‑bit floating‑point registers for energy values and requires the ARM CPU firmware to be updated to version **V20_260305SP** or later.  
> If you are using an older ARM firmware, please use the original `N30_esphome.yaml`.

## GPIO Pin Summary (N60 Layout)
| Interface | Pins |
|-----------|------|
| W5500 Ethernet | CLK=GPIO42, MOSI=GPIO43, MISO=GPIO44, CS=GPIO41, INT=GPIO2, RST=GPIO1 |
| OLED I2C | SDA=GPIO18, SCL=GPIO17 |
| RS485 UART | RX=GPIO9, TX=GPIO10 |

## Usage
1. Copy the desired YAML file to your ESPHome configuration directory.
2. Update the API key and OTA password if needed.
3. Flash via ESPHome dashboard or CLI:
   ```bash
   esphome run N30_esphome_v2.yaml
   ```
4. If you encounter incorrect energy readings, verify that the ARM firmware meets the version requirement.

## Important Notes
- The OLED displays the IP address obtained via Ethernet. To change the displayed content, modify the `display` lambda.
- Power factor sensors are not included in this configuration; they can be added manually if required.
- Digital inputs (GPIO15, GPIO16) are not used in this YAML but can be added by extending the `binary_sensor` section.

## Related Resources
- Pin definition: `../../pin_definitions/N30/N30_pin_definition.md`
- Arduino examples: `../../arduino_demos/N30/`