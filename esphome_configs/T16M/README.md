# T16M ESPHome Configuration

## Overview
This directory contains the ESPHome YAML configuration for the KinCony T16M 16‑channel relay controller.  
It provides local Home Assistant integration via Ethernet and supports 16 relay outputs, 16 digital inputs, RS485 communication, and 1‑Wire / free GPIOs.

## Hardware Features
- **MCU**: ESP32‑S3 (Arduino framework)
- **Ethernet**: W5500 SPI (CLK=42, MOSI=43, MISO=44, CS=41, INT=2, RST=1)
- **I2C Bus**: SDA=GPIO11, SCL=GPIO12, 400kHz
- **PCF8575 (Outputs)**: Address `0x25`, 16‑bit I/O expander for 16 relay outputs (pins 0‑15, active LOW)
- **PCF8575 (Inputs)**: Address `0x24`, 16‑bit I/O expander for 16 digital inputs (pins 0‑15, active LOW)
- **RS485**: UART TX=GPIO13, RX=GPIO14, 9600 baud (with test button)
- **1‑Wire / Free GPIOs**:
  - With on‑board pull‑up (active LOW): GPIO8, GPIO9, GPIO10, GPIO15
  - Without pull‑up (active HIGH): GPIO16, GPIO17, GPIO18, GPIO0
- **Web Server**: Enabled on port 80

## Pin Assignments

### I2C Bus
| Pin | Function |
|-----|----------|
| GPIO11 | SDA |
| GPIO12 | SCL |

### Ethernet (W5500)
| Function | GPIO |
|----------|------|
| CLK | 42 |
| MOSI | 43 |
| MISO | 44 |
| CS | 41 |
| INT | 2 |
| RST | 1 |

### RS485
| Pin | Function |
|-----|----------|
| GPIO13 | TX |
| GPIO14 | RX |

### 1‑Wire / Free GPIOs
| GPIO | Pull‑up | Binary Sensor Name | Notes |
|------|---------|---------------------|-------|
| 8 | Yes | `t16m-W1-io8` | Active LOW |
| 9 | Yes | `t16m-W1-io9` | Active LOW |
| 10 | Yes | `t16m-W1-io10` | Active LOW |
| 15 | Yes | `t16m-W1-io15` | Active LOW |
| 16 | No | `t16m-W1-io16` | Active HIGH |
| 17 | No | `t16m-W1-io17` | Active HIGH |
| 18 | No | `t16m-W1-io18` | Active HIGH |
| 0 | No | `t16m-io0` | Boot mode pin – avoid pulling LOW during reset |

## I2C Device Addresses
| Device | I²C Address | Description |
|--------|-------------|-------------|
| PCF8575 (Outputs) | 0x25 | 16‑bit I/O expander for relays 1‑16 |
| PCF8575 (Inputs) | 0x24 | 16‑bit I/O expander for digital inputs 1‑16 |

## Home Assistant Entities

### Switches (Relay Outputs)
- `switch.t16m_output01` … `switch.t16m_output16` (16 channels)

### Binary Sensors (Digital Inputs)
- `binary_sensor.t16m_input01` … `binary_sensor.t16m_input16` (16 channels)

### Additional GPIO Binary Sensors
- `binary_sensor.t16m_W1_io8` … `binary_sensor.t16m_W1_io18`, `binary_sensor.t16m_io0`

### RS485 Test Button
- `switch.rs485_button` – sends a fixed packet `[0x11, 0x22, 0x33, 0x44, 0x55]` over RS485

## Usage Instructions

1. **Install ESPHome** (standalone or Home Assistant add‑on).
2. **Copy the YAML file** to your ESPHome configuration directory.
3. **Modify network settings** (optional): By default, Ethernet uses DHCP. For a static IP, add a `manual_ip` section under `ethernet:`.
4. **Flash the firmware**:
   ```bash
   esphome run T16M_esphome.yaml
5. **Add to Home Assistant**: The device will be discovered automatically via the ESPHome integration.

## Important Notes

- **I2C pins are different** from many other Kincony products (use GPIO11/12 instead of GPIO8/18). Verify your wiring before use.
- **All relays and digital inputs are active‑LOW** (connected to GND = ON).
- **GPIO0 is the boot mode pin** – avoid pulling it LOW during startup.
- **RS485 test button** sends a fixed packet; it can be removed or repurposed for custom communication.
- This configuration is **local‑only** (no Tuya cloud integration).

## Related Resources

- Pin definition: ../pin_definitions/T16M/T16M_pin_definition.md
- Arduino examples: ../arduino_demos/T16M/