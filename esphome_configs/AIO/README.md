# AIO Hybrid ESPHome Configurations

## Overview

This directory contains ESPHome configuration files for the AIO Hybrid smart home controller.  
Two versions are provided:

- **AIO_esphome_with_tuya.yaml** – includes Tuya WiFi MCU integration for cloud control (Arduino framework)
- **AIO_esphome_without_tuya.yaml** – local‑only configuration using ESP‑IDF framework, with additional features (UART Zigbee test, WS2812 LED strip)

Both configurations share the same core hardware interfaces but differ in framework, Tuya integration, and optional peripherals.

---

## Hardware Interfaces (Common to Both Versions)

### Communication
| Interface | Pins / Details |
|-----------|----------------|
| **Ethernet** | W5500 via SPI: CLK=GPIO42, MOSI=GPIO43, MISO=GPIO44, CS=GPIO41, INT=GPIO2, RST=GPIO1 |
| **I2C Bus** | SDA=GPIO8, SCL=GPIO18 (400kHz) |
| **Wi‑Fi** | ESP32‑S3 built‑in (optional fallback) |

### I2C Devices
| Device | Address | Description |
|--------|---------|-------------|
| SSD1306 | 0x3C | 128×64 OLED display |
| MCP4728 | 0x60 | 4‑channel 12‑bit DAC (0‑10V analog outputs) |
| PCF8575 | 0x24 | 12‑bit digital input expander (inputs 1‑12) |
| PCF8574 | 0x26 | 5‑bit relay output expander (outputs 1‑5) |

### Digital Inputs (12 channels) – PCF8575 @ 0x24
All inputs are active‑LOW and have internal pull‑ups.

| Input | PCF8575 Pin |
|-------|-------------|
| Input 1  | P0  | Input 7  | P6  |
| Input 2  | P1  | Input 8  | P7  |
| Input 3  | P2  | Input 9  | P8  |
| Input 4  | P3  | Input 10 | P9  |
| Input 5  | P4  | Input 11 | P10 |
| Input 6  | P5  | Input 12 | P11 |

### Relay Outputs (5 channels) – PCF8574 @ 0x26
Outputs are active‑LOW (LOW = relay ON).

| Output | PCF8574 Pin |
|--------|-------------|
| Relay 1 | P3 |
| Relay 2 | P4 |
| Relay 3 | P5 |
| Relay 4 | P6 |
| Relay 5 | P7 |

### Analog Inputs (4 channels) – Direct ESP32 ADC
| Channel | GPIO | Type | Range | Notes |
|---------|------|------|-------|-------|
| A1 (Voltage) | 5 | Voltage | 0‑5V | Calibration filter applied in YAML |
| A2 (Voltage) | 7 | Voltage | 0‑5V | Calibration filter applied in YAML |
| A3 (Current) | 6 | Current | 4‑20mA | Multiplier filter: x6.66666666 |
| A4 (Current) | 4 | Current | 4‑20mA | Multiplier filter: x6.66666666 |

### Analog Outputs (4 channels) – MCP4728 DAC
| Output | Channel | Description |
|--------|---------|-------------|
| dimmer‑1 | A | 0‑10V analog output |
| dimmer‑2 | B | 0‑10V analog output |
| dimmer‑3 | C | 0‑10V analog output |
| dimmer‑4 | D | 0‑10V analog output |

### Infrared (IR)
| Function | GPIO |
|----------|------|
| Receive | 17 (remote_receiver) |
| Transmit | 14 (remote_transmitter, 50% duty) |

### Additional Digital Inputs
| GPIO | Name in Home Assistant | Notes |
|------|------------------------|-------|
| 40 | `AIO_hybrid-433M` | May be used for 433MHz receiver (raw digital input) |
| 0 | `AIO_hybrid-io0` | General‑purpose input (no pull‑up) |

---

## Configuration Differences

### AIO_esphome_with_tuya.yaml (Tuya Cloud Integration)
- **Framework**: Arduino
- **Tuya WiFi MCU**:
  - UART: TX=GPIO39, RX=GPIO38, baud 9600
  - Product ID: `0x9gs3fuzgggwhi1`
  - DP IDs: outputs 1‑5 bound to local relays
- **Zigbee UART**: commented out (disabled)
- **LED strip**: not present
- **Web server**: enabled (port 80)

### AIO_esphome_without_tuya.yaml (Local‑Only)
- **Framework**: ESP‑IDF
- **Tuya integration**: absent
- **UART Zigbee test**:
  - UART ID `uart_zsu`, TX=GPIO15, RX=GPIO48, baud 115200
  - Switch `UART zigbee` sends a fixed packet for testing
- **WS2812 LED strip**:
  - GPIO21, 20 LEDs, RGB order GRB, name "My Light IO21"
- **No Tuya‑bound switches**
- **Web server**: enabled (port 80)

---

## Installation

### Prerequisites
1. ESPHome installed (either standalone or as Home Assistant add‑on)
2. AIO Hybrid controller powered (12V DC)
3. Network connection (Ethernet recommended, Wi‑Fi optional)

### Steps
1. Copy the desired YAML file to your ESPHome configuration directory.
2. (Optional) Create a `secrets.yaml` with your network credentials if you plan to use Wi‑Fi fallback.  
   *Note: Ethernet is the primary connection in both configurations; Wi‑Fi is not mandatory.*
3. Compile and upload via ESPHome dashboard or command line:
   ```bash
   esphome run AIO_esphome_with_tuya.yaml
4. After flashing, the device will be reachable at http://aio-hybrid.local (or its IP address).

---

## Important Notes

- **I2C addresses** are fixed – do not change unless hardware differs.
- **Ethernet** is the main communication interface; Wi‑Fi is not enabled in these YAML files.
- The **WS2812 LED strip** is only available in the `without_tuya` version.
- The **UART Zigbee switch** in `without_tuya` sends a fixed packet – it is intended as a test and can be modified or removed.
- **Infrared** uses the `pronto` code format – you can replace the example code with your own.
- **Analog inputs** include calibration filters. Adjust these if your sensor readings require different scaling.
- **GPIO0** is used as a digital input; be careful not to pull it LOW during boot (it is the boot mode pin).

---

## Troubleshooting

| Issue | Possible Solution |
|-------|-------------------|
| Ethernet not detected | Check W5500 connections; verify SPI pins (42,43,44,41) are correct. |
| I2C devices missing | Confirm SDA/SCL are GPIO8/18 and pull‑ups are present. |
| ADC readings inaccurate | Adjust the lambda filters in the sensor configuration to match your hardware. |
| IR not sending/receiving | Ensure IR LED and receiver are correctly wired; test with known remote codes. |
| LED strip not working | Verify WS2812 data line is GPIO21 and power supply is adequate. |

---

## Version History

- **v1.0.0** (2026‑03‑22): Initial release based on actual YAML files provided by FeedCurrent.  
  Corrected documentation to reflect real hardware and configuration differences.