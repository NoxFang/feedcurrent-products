# DM8 ESPHome Configuration

## Overview

This ESPHome configuration provides full local integration for the KinCony DM8 controller without Tuya cloud services.  
It includes Ethernet connectivity, 8‑channel DAC output via Modbus, 8‑channel digital input via PCF8574, 4‑channel analog input via ADS1115, and an OLED display.

## Hardware Covered

| Component | Details |
|-----------|---------|
| **Ethernet** | W5500 SPI (CLK=1, MOSI=2, MISO=41, CS=42, INT=43, RST=44) – DHCP by default |
| **I2C Bus** | SDA=GPIO8, SCL=GPIO18, 400kHz |
| **DAC Output** | 8 channels via Modbus RTU (addresses 0x0FA0–0x0FA7) |
| **Digital Inputs** | 8 channels via PCF8574 @ 0x24 (P0–P7) |
| **Analog Inputs** | 4 channels via ADS1115 @ 0x48 (A0–A3) |
| **OLED Display** | SSD1306 128×64 @ 0x3C (displays IP address) |
| **RS485** | UART: TX=GPIO39, RX=GPIO38, 9600 baud (test button included) |
| **1‑Wire / Free GPIO** | See pin list below |

## Pin Assignments

| Function | GPIO |
|----------|------|
| I2C SDA | 8 |
| I2C SCL | 18 |
| RS485 TX | 39 |
| RS485 RX | 38 |
| DAC UART TX (ESP32 → DAC) | 6 |
| DAC UART RX (ESP32 ← DAC) | 4 |
| W5500 CLK | 1 |
| W5500 MOSI | 2 |
| W5500 MISO | 41 |
| W5500 CS | 42 |
| W5500 INT | 43 |
| W5500 RST | 44 |
| 1‑Wire / GPIO (pull‑up) | 47, 48, 17, 40 |
| Free GPIO (no pull‑up) | 13, 14, 21 |

## I2C Device Addresses

| Device | Address | Description |
|--------|---------|-------------|
| PCF8574 | 0x24 | 8‑channel digital input |
| ADS1115 | 0x48 | 4‑channel 16‑bit ADC |
| SSD1306 | 0x3C | 128×64 OLED display |

## Network

The configuration uses DHCP by default. To assign a static IP, add a `manual_ip` section under `ethernet:` in the YAML file.

## DAC (Modbus) Channels

The DM8 provides 8 analog output channels via Modbus RTU. Each channel accepts a value from 0.0 to 1.0, which is scaled to 0–4095 (12‑bit) and written to the corresponding Modbus holding register.

| Channel | Modbus Address (hex) | Modbus Address (decimal) |
|---------|---------------------|--------------------------|
| 1 | 0x0FA0 | 4000 |
| 2 | 0x0FA1 | 4001 |
| 3 | 0x0FA2 | 4002 |
| 4 | 0x0FA3 | 4003 |
| 5 | 0x0FA4 | 4004 |
| 6 | 0x0FA5 | 4005 |
| 7 | 0x0FA6 | 4006 |
| 8 | 0x0FA7 | 4007 |

The 8 DAC outputs are exposed as **monochromatic lights** in Home Assistant, allowing smooth dimming control.

## Analog Inputs (ADS1115)

| Channel | Type | Range |
|---------|------|-------|
| A0 | Voltage | 0‑5 V |
| A1 | Voltage | 0‑5 V |
| A2 | Current | 4‑20 mA |
| A3 | Current | 4‑20 mA |

- Gain: 6.144 V (full scale)
- Resolution: 16 bits

## Digital Inputs & GPIO

- **8 dedicated digital inputs** (PCF8574 @ 0x24) – active LOW (connected to GND = ON)
- **4 GPIOs with on‑board pull‑up** (GPIO47,48,17,40) – suitable for 1‑Wire devices (e.g., DS18B20)
- **3 free GPIOs without pull‑up** (GPIO13,14,21) – general purpose I/O

All are exposed as binary sensors in Home Assistant.

## RS485 Test Button

A UART test switch sends a fixed packet `[0x11, 0x22, 0x33, 0x44, 0x55]` over RS485 when pressed. This can be used to verify RS485 communication.

## Web Server

A web server is enabled on port 80, providing a basic status interface.

## Flashing Instructions

1. Install ESPHome (standalone or as Home Assistant add‑on).
2. Copy `DM8_esphome.yaml` to your ESPHome configuration directory.
3. (Optional) If you need static IP, add a `manual_ip` section under `ethernet:`.
4. Compile and upload via USB (first time) or OTA.

## Notes

- This configuration **does not** use the Tuya module – local control only.
- The DAC outputs are controlled via Modbus; ensure the ARM CPU on the DM8 is powered and the UART connection is correct.
- ADS1115 gain is set to 6.144 V to accommodate the 0‑5 V range. Do not apply voltages exceeding 5 V.
- Digital inputs and 1‑Wire pins have on‑board pull‑up resistors where noted; external resistors may be required for the free GPIOs.

## Related Resources

- [FeedCurrent Official Website](https://www.feedcurrent.com)
- Pin definition: `pin_definitions/DM8/DM8_pin_definition.md`