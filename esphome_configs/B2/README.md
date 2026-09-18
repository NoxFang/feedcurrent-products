# B2 ESPHome Configuration

## Overview
This directory contains ESPHome YAML configurations for the **FeedCurrent B2** controller.  
The B2 is based on ESP32‑S3 and features:

- 2‑channel relay outputs (GPIO4, GPIO46)
- 2‑channel digital inputs (GPIO6, GPIO7, active‑low)
- 4‑channel analog inputs (ADS1115, 0‑5V or 4‑20mA)
- 4‑channel 1‑Wire GPIOs with on‑board pull‑ups (GPIO47, GPIO48, GPIO17, GPIO40)
- RS485, Ethernet (W5500), and I2C OLED display
- Optional Tuya WiFi module, 4G SIM7600, and SD card interfaces

Two configuration variants are provided:

| File | Description |
|------|-------------|
| `B2_esphome_with_tuya.yaml` | Includes Tuya WiFi module integration (cloud control via Tuya Smart app). |
| `B2_esphome_without_tuya.yaml` | Pure local ESPHome version (no Tuya). |

## Hardware Requirements
- FeedCurrent B2 controller (ESP32‑S3)
- W5500 Ethernet module (on‑board)
- I2C OLED display (SSD1306, address 0x3C)
- ADS1115 ADC module (address 0x48)
- Sensors or voltage/current sources for analog inputs (optional)
- Tuya WiFi module (required only for `with_tuya` version)
- 4G SIM7600 module and SD card (optional, not enabled in current YAML)

## Pin / I2C Summary

| Component | GPIO / Address | Notes |
|-----------|----------------|-------|
| Ethernet W5500 | CLK=GPIO1, MOSI=GPIO2, MISO=GPIO41, CS=GPIO42, INT=GPIO43, RST=GPIO44 | |
| I2C bus | SDA=GPIO8, SCL=GPIO18 | Used for EEPROM, RTC, OLED, ADS1115 |
| ADS1115 | Address 0x48 | 4 channels: A0‑A3 (single‑ended) |
| OLED SSD1306 | Address 0x3C | 128x64 display |
| 24C02 EEPROM | Address 0x50 | |
| DS3231 RTC | Address 0x68 | |
| Relay 1 | GPIO4 | Active‑HIGH (inverted: false) |
| Relay 2 | GPIO46 | Active‑HIGH (inverted: false) |
| Digital Input 1 | GPIO6 | Active‑LOW (inverted: true) |
| Digital Input 2 | GPIO7 | Active‑LOW (inverted: true) |
| 1‑Wire 1 | GPIO47 | On‑board pull‑up |
| 1‑Wire 2 | GPIO48 | On‑board pull‑up |
| 1‑Wire 3 | GPIO17 | On‑board pull‑up |
| 1‑Wire 4 | GPIO40 | On‑board pull‑up |
| RS485 | TX=GPIO38, RX=GPIO39 | UART1 |
| Tuya UART (with_tuya only) | TX=GPIO14, RX=GPIO13 | Baud rate 9600 |
| Tuya Reset Button | Tuya module P28 | |
| Tuya Network LED | Tuya module P16 | |
| 4G SIM7600 (optional) | TX=GPIO15, RX=GPIO16 | Not enabled in YAML |
| SD Card (optional) | MOSI=GPIO10, SCK=GPIO11, MISO=GPIO12, CS=GPIO9, CD=GPIO5 | Not enabled in YAML |

## Configuration Features

### Both Versions
- **Ethernet** via W5500 (DHCP by default)
- **2‑channel relay control** via GPIO switch platform
- **2‑channel digital input monitoring** via binary_sensor (active‑low)
- **4‑channel analog input** via ADS1115 (0‑5V range, gain 6.144V, 16‑bit)
- **4‑channel 1‑Wire GPIO binary sensors** (with on‑board pull‑ups)
- **RS485** test switch (optional)
- **Web server** on port 80
- **OLED display** shows “FeedCurrent B2”

### With Tuya Version
- Integrates Tuya WiFi module (`tuya_wifi_mcu` component v1.3.1)
- Binds ESPHome GPIO switches / binary sensors to Tuya DP IDs:
  - Outputs: DP 1 (Relay 1), DP 2 (Relay 2)
  - Inputs: DP 111 (Input 1), DP 112 (Input 2)
- Allows remote control and monitoring via Tuya Smart app
- Requires `product_id: qk4eefxayleh2x5s` and external component from GitHub

## Usage

1. **Choose the appropriate YAML file** based on whether you use Tuya.
2. **Modify network settings** if needed. Ethernet uses DHCP by default; to set a static IP, add a `manual_ip` block under `ethernet:`.
3. **Adjust ADC gain** if your sensor range differs (default 6.144V for 0‑5V inputs).
4. **Flash** the configuration using ESPHome dashboard or CLI:
   ```bash
   esphome run B2_esphome_with_tuya.yaml
5. **For Tuya version**: After flashing, pair the device in the Tuya Smart app. Ensure the Tuya module is connected and powered.

## Important Notes

- The digital inputs are **active‑LOW** (`inverted: true`), meaning a closed contact to GND triggers the input.
- The relay outputs are **active‑HIGH** (`inverted: false`).
- The ADS1115 is configured for single‑ended measurement with gain ±6.144V (max input ~6.144V). For 0‑10V inputs, use a voltage divider.
- The 1‑Wire GPIOs have on‑board pull‑up resistors; no external resistors are needed.
- The `with_tuya` version requires the `esphome-tuya-wifi-mcu` external component (automatically fetched from GitHub). Internet access is needed during compilation.
- The `without_tuya` version logs via USB‑JTAG (`hardware_uart: USB_SERIAL_JTAG`). To see logs, ensure your USB connection supports this.

## Troubleshooting

- **No Ethernet connection**: Check the W5500 pin assignments; the YAML uses non‑standard pins (GPIO1/2/41‑44). Verify against your board’s schematic.
- **Tuya not pairing**: Ensure the Tuya module is correctly wired (TX→GPIO14, RX→GPIO13) and that the product ID matches your module.
- **OLED blank**: Confirm I2C address is 0x3C and bus is correct.
- **Analog readings inaccurate**: Adjust the `gain` parameter or add a voltage divider for higher voltages.

## Related Resources

- Pin definition: ../../pin_definitions/B2/B2_pin_definition.md
- Arduino examples: ../../arduino_demos/B2/
- Tuya external component: [esphome-tuya-wifi-mcu](https://github.com/hzkincony/esphome-tuya-wifi-mcu)