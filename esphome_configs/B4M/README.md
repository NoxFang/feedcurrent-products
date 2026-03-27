# B4M ESPHome Configuration

## Overview
This directory contains ESPHome YAML configurations for the **FeedCurrent B4M** controller.  
The B4M is based on ESP32‑S3 and features:

- 4‑channel MOSFET outputs (via PCF8574 @ 0x24, pins 4‑7)
- 4‑channel digital inputs (via same PCF8574, pins 0‑3)
- 4‑channel analog inputs (ADS1115, 0‑10V or 4‑20mA)
- RS485, Ethernet (W5500), and I2C OLED display

Two configuration variants are provided:

| File | Description |
|------|-------------|
| `B4M_esphome_with_tuya.yaml` | Includes Tuya WiFi module integration (cloud control via Tuya Smart app). |
| `B4M_esphome_without_tuya.yaml` | Pure local ESPHome version (no Tuya). |

## Hardware Requirements
- FeedCurrent B4M controller (ESP32‑S3)
- W5500 Ethernet module (on‑board)
- I2C OLED display (SSD1306, address 0x3C)
- ADS1115 ADC module (address 0x48)
- CT clamps or voltage sensors for analog inputs (optional)
- Tuya WiFi module (required only for `with_tuya` version)

## Pin / I2C Summary

| Component | GPIO / Address | Notes |
|-----------|----------------|-------|
| Ethernet W5500 | CLK=GPIO1, MOSI=GPIO2, MISO=GPIO41, CS=GPIO42, INT=GPIO43, RST=GPIO44 | |
| I2C bus | SDA=GPIO8, SCL=GPIO18 | Used for PCF8574, OLED, ADS1115 |
| PCF8574 | Address 0x24 | Pins 0‑3: digital inputs; pins 4‑7: MOSFET outputs (active‑LOW) |
| ADS1115 | Address 0x48 | 4 channels: A0‑A3 (single‑ended) |
| RS485 | TX=GPIO38, RX=GPIO39 | UART1 |
| Tuya UART (with_tuya only) | TX=GPIO15, RX=GPIO16 | Baud rate 9600 |
| Free GPIOs | See YAML for details | Various inputs with/without pull‑up |

## Configuration Features

### Both Versions
- **Ethernet** with static IP (DHCP can be enabled)
- **4‑channel MOSFET output control** via GPIO switch platform
- **4‑channel digital input monitoring** via binary_sensor
- **4‑channel analog input** via ADS1115 (0‑5V range, gain 6.144V)
- **RS485** test switch (optional)
- **Web server** on port 80
- **OLED display** shows “B4 Controller”

### With Tuya Version
- Integrates Tuya WiFi module (`tuya_wifi_mcu` component)
- Binds ESPHome GPIO switches / binary sensors to Tuya DP IDs (1‑4 for outputs, 111‑114 for inputs)
- Allows remote control via Tuya Smart app and cloud automation

## Usage

1. **Choose the appropriate YAML file** based on whether you use Tuya.
2. **Modify network settings** if needed (static IP or DHCP). By default Ethernet uses static IP `192.168.3.55`; to use DHCP, remove the manual IP block or add `use_address`.
3. **Adjust ADC gain** if your sensor range differs.
4. **Flash** the configuration using ESPHome dashboard or CLI:
   ```bash
   esphome run B4M_esphome_with_tuya.yaml
   ```
5. **For Tuya version**: After flashing, the device will appear in Tuya Smart app (need to pair via Tuya module). Ensure the Tuya module is connected and powered.

## Important Notes
- The PCF8574 chip controls both inputs and outputs; output pins are **active‑LOW** (MOSFET ON when pin is LOW).
- Analog inputs use `A0_GND`, `A1_GND`, etc. The ADS1115 is configured for single‑ended measurement with gain ±6.144V (max input ~6.144V). For 0‑10V inputs, use a voltage divider.
- The `with_tuya` version requires the `esphome-tuya-wifi-mcu` external component (automatically fetched from GitHub). Internet access is needed during compilation.
- The `without_tuya` version logs via USB‑JTAG (`hardware_uart: USB_SERIAL_JTAG`). To see logs, ensure your USB connection supports this.

## Troubleshooting
- **No Ethernet connection**: Check the W5500 pin assignments; the YAML uses non‑standard pins (GPIO1/2/41‑44). Verify against your board’s schematic.
- **Tuya not pairing:** Ensure the Tuya module is correctly wired (TX→GPIO15, RX→GPIO16) and that the product ID matches your module.
- **OLED blank**: Confirm I2C address is 0x3C and bus is correct.

## Related Resources
- Pin definition: `../../pin_definitions/B4M/B4M_pin_definition.md`
- Arduino examples: `../../arduino_demos/B4M/`
- Tuya external component: esphome-tuya-wifi-mcu