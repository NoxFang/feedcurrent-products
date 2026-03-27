# DM8 ESPHome Configuration

## Overview
This directory contains the ESPHome YAML configuration for the **FeedCurrent DM8** controller.  
The DM8 is based on ESP32‑S3 and is a versatile I/O module featuring:

- **8‑channel digital inputs** (via PCF8574 @ 0x24)
- **4‑channel analog inputs** (ADS1115, 0‑5V / 4‑20mA)
- **8‑channel analog outputs** (via Modbus‑controlled DAC, 0‑5V)
- **RS485** communication
- **Ethernet** (W5500) and **OLED** display

| File | Description |
|------|-------------|
| `DM8_esphome_without_tuya.yaml` | Pure local ESPHome version (no Tuya). |

## Hardware Requirements
- FeedCurrent DM8 controller (ESP32‑S3)
- W5500 Ethernet module (on‑board)
- I2C OLED display (SSD1306, address 0x3C)
- PCF8574 I/O expander (address 0x24)
- ADS1115 ADC module (address 0x48)
- External DAC module (Modbus‑controlled, e.g., from KinCony) for analog outputs
- External sensors / actuators as needed

## Pin / I2C Summary

| Component | GPIO / Address | Notes |
|-----------|----------------|-------|
| Ethernet W5500 | CLK=GPIO1, MOSI=GPIO2, MISO=GPIO41, CS=GPIO42, INT=GPIO43, RST=GPIO44 | |
| I2C bus | SDA=GPIO8, SCL=GPIO18 | Used for PCF8574, ADS1115, OLED |
| PCF8574 | Address 0x24 | Digital inputs on pins 0‑7 (active‑LOW) |
| ADS1115 | Address 0x48 | 4 analog inputs: A0‑A3 (single‑ended) |
| RS485 | TX=GPIO39, RX=GPIO38 | UART1 |
| DAC UART | TX=GPIO6, RX=GPIO4 | Modbus communication to DAC module |
| Free GPIOs | See YAML for details | Additional digital inputs (with/without pull‑up) |

## Configuration Features

- **Ethernet** with static IP (DHCP can be enabled by removing manual IP block)
- **8‑channel digital inputs** via PCF8574 (binary_sensor)
- **4‑channel analog inputs** via ADS1115 (0‑5V range, gain 6.144V)
- **8‑channel analog outputs** via Modbus DAC (mapped to 0‑5V, controlled as monochromatic lights)
- **RS485** test switch (optional)
- **Web server** on port 80
- **OLED display** shows device IP address (obtained via Ethernet)

## Usage

1. **Copy** the YAML file to your ESPHome configuration directory.
2. **Modify network settings** if needed. By default Ethernet uses static IP `192.168.3.55`; to use DHCP, remove the manual IP block or add `use_address`.
3. **Adjust ADC gain** if your sensor range differs.
4. **Flash** the configuration using ESPHome dashboard or CLI:
   ```bash
   esphome run DM8_esphome_without_tuya.yaml
   ```
5. After flashing, the device will be discovered in Home Assistant via the ESPHome integration.

## Important Notes
- Digital inputs are **active‑LOW** (LOW = input active, HIGH = inactive). If your sensor provides a different logic, adjust the `inverted` flag.
- Analog inputs use `A0_GND`, `A1_GND`, etc. The ADS1115 is configured for single‑ended measurement with gain ±6.144V (max input ~6.144V). For 0‑10V inputs, use a voltage divider.
- Analog outputs are controlled via Modbus registers (addresses 0x0FA0 to 0x0FA7). Each output is configured as a monochromatic light (0‑100%), which maps to 0‑5V output (0‑4095 DAC value). Ensure the external DAC module is correctly wired and its Modbus address matches (default 1).
- The RS485 UART is configured with a simple test switch that sends a fixed byte sequence. Replace with your own Modbus or custom protocol as needed.
- The OLED displays the IP address from Ethernet. To change the displayed content, `modify` the display lambda.

## Troubleshooting
- **No Ethernet connection**: Check the W5500 pin assignments; the YAML uses non‑standard pins (GPIO1/2/41‑44). Verify against your board’s schematic.
- **OLED blank**: Confirm I2C address is 0x3C and bus is correct.
- **Digital inputs not reading**: Ensure the PCF8574 is properly connected and that the address is 0x24.
- **Analog outputs not working**: Check that the DAC module is connected to the correct UART pins (TX=GPIO6, RX=GPIO4) and that its - **Modbus address and register mapping match.
- **RS485 test switch**: The included switch sends `[0x11, 0x22, 0x33, 0x44, 0x55]` when pressed; replace with your own protocol.

## Related Resources
- Pin definition: `../../pin_definitions/DM8/DM8_pin_definition.md`
- Arduino examples: `../../arduino_demos/DM8/`
- ESPHome documentation: [ADS1115](https://esphome.io/components/sensor/ads1115/), [Modbus Controller](https://esphome.io/components/modbus_controller/), [PCF8574](https://esphome.io/components/pcf8574/)