# N10 ESPHome Configuration

## Overview
This directory contains ESPHome YAML configurations for the FeedCurrent N10
10‑channel energy monitoring controller.

## File Description

| File | Description |
|------|-------------|
| `N10_esphome.yaml` | Original configuration with **1 kWh** energy resolution.<br>Requires ARM CPU firmware version < V20_260305SP. |
| `N10_esphome_v2.yaml` | Updated configuration with **0.001 kWh** energy resolution.<br>Requires ARM CPU firmware **≥ V20_260305SP**. |

## Hardware Requirements
- FeedCurrent N10 controller (ESP32‑S3)
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

## Version Differences

| Feature | N10_esphome.yaml | N10_esphome_v2.yaml |
|---------|------------------|---------------------|
| Current resolution | 0.001 A | 0.001 A |
| Power resolution | 0.1 W | 0.1 W |
| Energy resolution | 1 kWh | **0.001 kWh** |
| ARM firmware required | Any | **≥ V20_260305SP** |
| Register format for energy | U_DWORD_R (raw) | FP32_R (IEEE 754) |

> **Important**: The high‑precision version (`_v2`) uses 32‑bit floating‑point registers for energy values and requires the ARM CPU firmware to be updated to version **V20_260305SP** or later.  
> If you are using an older ARM firmware, please use the original `N10_esphome.yaml`.

## Usage
1. Copy the desired YAML file to your ESPHome configuration directory.
2. Update the API key and OTA password if needed.
3. Flash via ESPHome dashboard or CLI:
   ```bash
   esphome run N10_esphome_v2.yaml
   ```
4. If you encounter incorrect energy readings, verify that the ARM firmware meets the version requirement.

## Modbus Communication
- Protocol: Modbus RTU
- Baud rate: 115200 (UART to ARM CPU)
- Energy chip baud rate: 38400
- Device address: 0x01

## Important Notes
- The OLED displays the IP address obtained via Ethernet. To change the displayed content, modify the `display` lambda.
- The configuration does not include power factor sensors; if needed, they must be added manually.
- Digital inputs (GPIO15, GPIO16) are not used in this YAML but can be added by extending the `binary_sensor` section.

## Related Resources
- Pin definition: `../../pin_definitions/N10/N10_pin_definition.md`
- Arduino examples: `../../arduino_demos/N10/`