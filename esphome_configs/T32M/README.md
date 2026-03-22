# T32M ESPHome Configuration

## Overview
This directory contains the ESPHome YAML configuration for the KinCony T32M 32‑channel relay controller.  
It provides local Home Assistant integration via Ethernet and supports 32 relay outputs, 32 digital inputs, 4 analog inputs, and free GPIOs.

## Hardware Features
- **MCU**: ESP32‑S3 (ESP‑IDF framework)
- **Ethernet**: W5500 SPI (CLK=42, MOSI=43, MISO=44, CS=41, INT=2, RST=1)
- **I2C Bus**: SDA=GPIO48, SCL=GPIO47, 400kHz
- **4 × PCF8575 I/O expanders**:
  - Outputs 1‑16: address `0x21` (pins 0‑15, active LOW)
  - Outputs 17‑32: address `0x20` (pins 0‑15, active LOW)
  - Inputs 1‑16: address `0x25` (pins 0‑15, active LOW)
  - Inputs 17‑32: address `0x24` (pins 0‑15, active LOW)
- **Analog inputs**: 4 channels (ESP32 internal ADC)
  - A1 (GPIO7): 0‑5V voltage (calibrated)
  - A2 (GPIO6): 0‑5V voltage (calibrated)
  - A3 (GPIO5): 4‑20mA current (multiplier 6.6667)
  - A4 (GPIO4): 4‑20mA current (multiplier 6.6667)
- **Free GPIOs** (binary sensors):
  - With pull‑up (active LOW): GPIO15
  - Without pull‑up (active HIGH): GPIO16,17,18,0,8,9,10
- **Web server**: Enabled on port 80

## Pin Assignments

### I2C Bus
| Pin | Function |
|-----|----------|
| GPIO48 | SDA |
| GPIO47 | SCL |

### Ethernet (W5500)
| Function | GPIO |
|----------|------|
| CLK | 42 |
| MOSI | 43 |
| MISO | 44 |
| CS | 41 |
| INT | 2 |
| RST | 1 |

### Analog Inputs
| Pin | Sensor | Type | Calibration |
|-----|--------|------|-------------|
| GPIO7 | A1 Voltage | 0‑5V | Lambda filter (1.60256 / 1.51) |
| GPIO6 | A2 Voltage | 0‑5V | Lambda filter (1.60256 / 1.51) |
| GPIO5 | A3 Current | 4‑20mA | Multiply 6.66666666 |
| GPIO4 | A4 Current | 4‑20mA | Multiply 6.66666666 |

### Free GPIO Binary Sensors
| GPIO | Entity Name | Pull‑up | Active Level |
|------|-------------|---------|--------------|
| 15 | `t32m-W1-io15` | Yes | LOW |
| 16 | `t32m-W1-io16` | No | HIGH |
| 17 | `t32m-W1-io17` | No | HIGH |
| 18 | `t32m-W1-io18` | No | HIGH |
| 0 | `t32m-io0` | No | HIGH |
| 8 | `t32m-io8` | No | HIGH |
| 9 | `t32m-io9` | No | HIGH |
| 10 | `t32m-io10` | No | HIGH |

## I2C Device Addresses
| Device | I²C Address | Description |
|--------|-------------|-------------|
| PCF8575 (Outputs 1‑16) | 0x21 | 16‑bit I/O expander for relays 1‑16 |
| PCF8575 (Outputs 17‑32) | 0x20 | 16‑bit I/O expander for relays 17‑32 |
| PCF8575 (Inputs 1‑16) | 0x25 | 16‑bit I/O expander for inputs 1‑16 |
| PCF8575 (Inputs 17‑32) | 0x24 | 16‑bit I/O expander for inputs 17‑32 |

## Home Assistant Entities
- **32 switches**: `t32m-output01` … `t32m-output32` (relays)
- **32 binary sensors**: `t32m-input01` … `t32m-input32` (digital inputs)
- **8 binary sensors**: free GPIOs (as listed above)
- **4 sensors**: voltage/current readings

## Usage Instructions
1. Install ESPHome (standalone or Home Assistant add‑on).
2. Copy `T32M_esphome.yaml` to your ESPHome configuration directory.
3. (Optional) For a static IP, add a `manual_ip` section under `ethernet:`.
4. Flash the firmware:
   ```bash
   esphome run T32M_esphome.yaml
5. The device will be discovered in Home Assistant via the ESPHome integration.

Important Notes
- **No RS485, WiFi, OTA, or Tuya** – this is a pure local configuration.
- **All relays and digital inputs are active‑LOW** (connected to GND = ON).
- **Analog input calibration** is pre‑configured; adjust if your voltage divider or current sensor differs.
- **GPIO0 is the boot mode pin** – avoid pulling it LOW during startup.
- **I2C pins are GPIO48/47** – this is different from many other Kincony products.

Related Resources
- Pin definition: `../pin_definitions/T32M/T32M_pin_definition.md`
- Arduino examples: `../arduino_demos/T32M/`