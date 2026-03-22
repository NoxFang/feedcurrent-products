# DM32 ESPHome Configuration

## Overview

This directory contains the ESPHome configuration file for the KinCony DM32 ESP32-S3 dimmer module.  
It provides local Home Assistant integration via Ethernet, without any Tuya cloud dependency.

## Configuration File

### DM32_esphome_without_tuya.yaml

**Description**: Full local control of the DM32 using ESPHome. Network connectivity is provided by the W5500 Ethernet module.

**Features**:
- ✅ W5500 Ethernet connection (DHCP by default)
- ✅ 32‑channel DAC output (Modbus RTU, 0–10V, 0–4095 range)
- ✅ 32‑channel digital input (2× PCF8575 @ 0x22 and 0x24)
- ✅ 4‑channel analog input (ADS1115 @ 0x48)
- ✅ SSD1306 OLED display (128×64 @ 0x3C) showing IP address
- ✅ RS485 test button (UART on GPIO38/39)
- ✅ 1‑Wire / free GPIOs (GPIO47,48,7,40,13,14,21)
- ✅ Home Assistant API integration
- ✅ OTA updates
- ✅ Web server on port 80

---

## Hardware Configuration

### Ethernet (W5500)

| Function | GPIO |
|----------|------|
| CLK      | 1    |
| MOSI     | 2    |
| MISO     | 41   |
| CS       | 42   |
| INT      | 43   |
| RST      | 44   |

**Network**: DHCP is used by default. To set a static IP, add a `manual_ip` section under `ethernet:` in the YAML.

### I2C Bus

| Signal | GPIO |
|--------|------|
| SDA    | 8    |
| SCL    | 18   |

**Frequency**: 400 kHz

**I2C Devices**:

| Device   | Address | Description                |
|----------|---------|----------------------------|
| PCF8575 #1 | 0x22   | Digital inputs 1–16        |
| PCF8575 #2 | 0x24   | Digital inputs 17–32       |
| ADS1115    | 0x48   | 4‑channel analog input     |
| SSD1306    | 0x3C   | OLED display               |

### UART Interfaces

| Function        | RX Pin | TX Pin | Baud Rate |
|-----------------|--------|--------|-----------|
| DAC Modbus      | GPIO4  | GPIO6  | 115200    |
| RS485           | GPIO38 | GPIO39 | 9600      |

- **DAC Modbus**: Controls the 32‑channel 0–10V output via the ARM CPU.
- **RS485**: A test button (`RS485 Button`) is configured to send a fixed packet `[0x11, 0x22, 0x33, 0x44, 0x55]`. You can modify or remove it as needed.

---

## 32‑Channel DAC Output

The DM32 uses Modbus RTU to control 32 DAC channels.  
Each channel is exposed as a **monochromatic light** in Home Assistant, accepting values from 0.0 to 1.0 (mapped to 0–4095 in the Modbus register).

| Channel | Modbus Address (hex) | Modbus Address (dec) | Entity Name |
|---------|----------------------|----------------------|-------------|
| CH1     | 0x0FA0               | 4000                 | DAC CH1     |
| CH2     | 0x0FA1               | 4001                 | DAC CH2     |
| CH3     | 0x0FA2               | 4002                 | DAC CH3     |
| CH4     | 0x0FA3               | 4003                 | DAC CH4     |
| CH5     | 0x0FA4               | 4004                 | DAC CH5     |
| CH6     | 0x0FA5               | 4005                 | DAC CH6     |
| CH7     | 0x0FA6               | 4006                 | DAC CH7     |
| CH8     | 0x0FA7               | 4007                 | DAC CH8     |
| CH9     | 0x0FA8               | 4008                 | DAC CH9     |
| CH10    | 0x0FA9               | 4009                 | DAC CH10    |
| CH11    | 0x0FAA               | 4010                 | DAC CH11    |
| CH12    | 0x0FAB               | 4011                 | DAC CH12    |
| CH13    | 0x0FAC               | 4012                 | DAC CH13    |
| CH14    | 0x0FAD               | 4013                 | DAC CH14    |
| CH15    | 0x0FAE               | 4014                 | DAC CH15    |
| CH16    | 0x0FAF               | 4015                 | DAC CH16    |
| CH17    | 0x0FB0               | 4016                 | DAC CH17    |
| CH18    | 0x0FB1               | 4017                 | DAC CH18    |
| CH19    | 0x0FB2               | 4018                 | DAC CH19    |
| CH20    | 0x0FB3               | 4019                 | DAC CH20    |
| CH21    | 0x0FB4               | 4020                 | DAC CH21    |
| CH22    | 0x0FB5               | 4021                 | DAC CH22    |
| CH23    | 0x0FB6               | 4022                 | DAC CH23    |
| CH24    | 0x0FB7               | 4023                 | DAC CH24    |
| CH25    | 0x0FB8               | 4024                 | DAC CH25    |
| CH26    | 0x0FB9               | 4025                 | DAC CH26    |
| CH27    | 0x0FBA               | 4026                 | DAC CH27    |
| CH28    | 0x0FBB               | 4027                 | DAC CH28    |
| CH29    | 0x0FBC               | 4028                 | DAC CH29    |
| CH30    | 0x0FBD               | 4029                 | DAC CH30    |
| CH31    | 0x0FBE               | 4030                 | DAC CH31    |
| CH32    | 0x0FBF               | 4031                 | DAC CH32    |

**Output Range**: 0–10 V (0 V corresponds to 0, 10 V corresponds to 4095).

---

## 32‑Channel Digital Input

The DM32 uses two PCF8575 16‑bit I/O expanders to read 32 digital inputs.  
All inputs are active‑LOW (connected to GND = ON) and have internal pull‑ups.

| Input Range | PCF8575 Chip | I2C Address | Pin Mapping                              | Entity Names                |
|-------------|--------------|-------------|------------------------------------------|-----------------------------|
| Inputs 1–16 | #1           | 0x22        | P8‑P15 → DI1‑DI8, P0‑P7 → DI9‑DI16       | dm32‑input01 … dm32‑input16 |
| Inputs 17–32| #2           | 0x24        | P0‑P7 → DI17‑DI24, P8‑P15 → DI25‑DI32    | dm32‑input17 … dm32‑input32 |

---

## 4‑Channel Analog Input (ADS1115)

The ADS1115 provides 4 single‑ended analog inputs.  
**Gain**: 6.144 V (full scale)  
**Update interval**: 5 seconds

| Channel | Entity Name                 | Description   |
|---------|-----------------------------|---------------|
| A0‑GND  | ADS1115 Channel A0‑GND      | 0–5 V / 4–20 mA |
| A1‑GND  | ADS1115 Channel A1‑GND      | 0–5 V / 4–20 mA |
| A2‑GND  | ADS1115 Channel A2‑GND      | 0–5 V / 4–20 mA |
| A3‑GND  | ADS1115 Channel A3‑GND      | 0–5 V / 4–20 mA |

---

## OLED Display

The SSD1306 OLED displays the device’s IP address.  
- **Model**: SSD1306 128×64  
- **I2C Address**: 0x3C  
- **Font**: Roboto (15px)

---

## 1‑Wire / Free GPIOs

| GPIO | Entity Name       | Description                              | Pull‑up |
|------|-------------------|------------------------------------------|---------|
| 47   | dm32‑W1‑io47      | 1‑Wire / general‑purpose input           | Yes     |
| 48   | dm32‑W1‑io48      | 1‑Wire / general‑purpose input           | Yes     |
| 7    | dm32‑W1‑io7       | 1‑Wire / general‑purpose input           | Yes     |
| 40   | dm32‑W1‑io40      | 1‑Wire / general‑purpose input           | Yes     |
| 13   | dm32‑W1‑io13      | Free GPIO (no pull‑up)                   | No      |
| 14   | dm32‑W1‑io14      | Free GPIO (no pull‑up)                   | No      |
| 21   | dm32‑W1‑io21      | Free GPIO (no pull‑up)                   | No      |

All of these are exposed as **binary sensors**.  
- 1‑Wire pins have `inverted: true` (active‑LOW).  
- Free GPIOs have `inverted: false`.

---

## RS485 Test Button

A UART test switch is configured on GPIO38/39.  
Pressing the button sends the fixed packet `[0x11, 0x22, 0x33, 0x44, 0x55]` over the RS485 bus.  
You can modify or remove this switch as needed.

---

## Installation

1. Install ESPHome (standalone or as a Home Assistant add‑on).
2. Copy `DM32_esphome_without_tuya.yaml` to your ESPHome configuration directory.
3. (Optional) If you need a static IP, add a `manual_ip` section under `ethernet:`.
4. Compile and upload via USB (first time) or OTA.
5. After flashing, the OLED will display the IP address. Add the device to Home Assistant via the ESPHome integration.

---

## Important Notes

- **No Tuya integration** – this configuration is purely local.
- **Only the without‑Tuya version** is provided; a with‑Tuya version is not available for the DM32 at this time.
- **Modbus DAC** requires the ARM CPU on the DM32 to be properly powered and the UART connection to be correct.
- **RS485** is configured with a test button; you can extend it to implement actual RS485 communication.
- The ADS1115 gain is set to 6.144 V to accommodate 0–5 V signals. Do not exceed 5 V.
- GPIO0 is not used in this configuration.

---

## Reference

- [FeedCurrent Official Website](https://www.feedcurrent.com)
- Pin definition: `pin_definitions/DM32/DM32_pin_definition.md`