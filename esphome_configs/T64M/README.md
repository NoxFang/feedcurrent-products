# T64M ESPHome Configuration

## Overview
This directory contains the ESPHome YAML configuration for the KinCony T64M 64‑channel digital I/O controller.  
It provides local Home Assistant integration via Ethernet and supports 64 relay outputs, 64 digital inputs, 4 analog inputs, and free GPIOs.

## Hardware Features
- **MCU**: ESP32‑S3 (ESP‑IDF framework)
- **Ethernet**: W5500 SPI (CLK=42, MOSI=43, MISO=44, CS=41, INT=2, RST=1)
- **Two independent I2C buses**:
  - **Bus A** (outputs): SDA=GPIO48, SCL=GPIO47, 400kHz
  - **Bus B** (inputs): SDA=GPIO12, SCL=GPIO11, 400kHz
- **8 × PCF8575 I/O expanders** (16‑bit, active LOW):
  - **Outputs** (Bus A):
    - Address `0x25` → outputs 1‑16 (pins 0‑15)
    - Address `0x24` → outputs 17‑32 (pins 0‑15)
    - Address `0x21` → outputs 33‑48 (pins 0‑15)
    - Address `0x20` → outputs 49‑64 (pins 0‑15)
  - **Inputs** (Bus B):
    - Address `0x25` → inputs 1‑16 (pins 0‑15)
    - Address `0x24` → inputs 17‑32 (pins 0‑15)
    - Address `0x21` → inputs 33‑48 (pins 0‑15)
    - Address `0x20` → inputs 49‑64 (pins 0‑15)
- **Analog inputs**: 4 channels (ESP32 internal ADC)
  - A1 (GPIO7): 0‑5V voltage (calibrated)
  - A2 (GPIO6): 0‑5V voltage (calibrated)
  - A3 (GPIO5): 4‑20mA current (multiplier 6.6667)
  - A4 (GPIO4): 4‑20mA current (multiplier 6.6667)
- **Free GPIO binary sensors**:
  - With pull‑up (active LOW): GPIO15
  - Without pull‑up (active HIGH): GPIO16,17,18,0,8,9,10
- **Web server**: Enabled on port 80

## Pin Assignments

### I2C Bus A (Outputs)
| Pin | Function |
|-----|----------|
| GPIO48 | SDA |
| GPIO47 | SCL |

### I2C Bus B (Inputs)
| Pin | Function |
|-----|----------|
| GPIO12 | SDA |
| GPIO11 | SCL |

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
| 15 | `t64m-W1-io15` | Yes | LOW |
| 16 | `t64m-W1-io16` | No | HIGH |
| 17 | `t64m-W1-io17` | No | HIGH |
| 18 | `t64m-W1-io18` | No | HIGH |
| 0 | `t64m-io0` | No | HIGH |
| 8 | `t64m-io8` | No | HIGH |
| 9 | `t64m-io9` | No | HIGH |
| 10 | `t64m-io10` | No | HIGH |

## Home Assistant Entities
- **64 switches**: `t64m-output01` … `t64m-output64` (relays)
- **64 binary sensors**: `t64m-input01` … `t64m-input64` (digital inputs)
- **8 binary sensors**: free GPIOs (as listed above)
- **4 sensors**: voltage/current readings

## Usage Instructions
1. Install ESPHome (standalone or Home Assistant add‑on).
2. Copy `T64M_esphome.yaml` to your ESPHome configuration directory.
3. (Optional) For a static IP, add a `manual_ip` section under `ethernet:`.
4. Flash the firmware:
   ```bash
   esphome run T64M_esphome.yaml
5. The device will be discovered in Home Assistant via the ESPHome integration.

## Important Notes
- **No WiFi, RS485, or Tuya – this is a pure local configuration.
- **All relays and digital inputs are active‑LOW (connected to GND = ON).
- **Analog input calibration is pre‑configured; adjust if your voltage divider or current sensor differs.
- **GPIO0 is the boot mode pin – avoid pulling it LOW during startup.
- **2C buses are independent – verify connections to the correct bus for outputs and inputs.
- **The web server is accessible at the device’s IP address, port 80.

## Related Resources
- Pin definition: ../pin_definitions/T64M/T64M_pin_definition.md
- Arduino examples: ../arduino_demos/T64M/