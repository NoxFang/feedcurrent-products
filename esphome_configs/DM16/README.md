# DM16 ESPHome Configurations

## Overview

This directory contains two ESPHome configuration files for the DM16 ESP32-S3 dimmer module:

- **DM16_esphome_without_tuya.yaml** – local control only, no Tuya cloud dependency
- **DM16_esphome_with_tuya.yaml** – integrates Tuya WiFi MCU for cloud control and state synchronization

Both configurations share the same core hardware support: 16‑channel 0–10 V DAC, 16‑channel digital input, 4‑channel analog input, Ethernet, OLED display, and RS485.

---

## Configuration Files

### DM16_esphome_without_tuya.yaml

**Features**:
- ✅ W5500 Ethernet connection (DHCP by default)
- ✅ 16‑channel DAC output (Modbus RTU, 0–10 V, 0–4095 range)
- ✅ 16‑channel digital input (PCF8575 @ 0x22)
- ✅ 4‑channel analog input (ADS1115 @ 0x48)
- ✅ SSD1306 OLED display (128×64 @ 0x3C) showing IP address
- ✅ RS485 test button (UART on GPIO38/39)
- ✅ 1‑Wire / free GPIOs (GPIO47,48,7,40,13,14,21)
- ✅ Home Assistant API integration
- ✅ OTA updates
- ✅ Web server on port 80

---

### DM16_esphome_with_tuya.yaml

**External Component**: [esphome-tuya-wifi-mcu](https://github.com/hzkincony/esphome-tuya-wifi-mcu) (ref: v1.2.0)

**Features**:
- ✅ All hardware features of the without‑Tuya version
- ✅ Tuya WiFi MCU integration (UART: TX=GPIO16, RX=GPIO17, 9600 baud)
- ✅ Dual light entities for each DAC channel (standard + Tuya, state synchronized)
- ✅ 16 Tuya‑bound lights (DP IDs 2,8,16,101,102,103,104,105,106,107,108,109,110,111,112,113)
- ✅ WiFi reset pin (GPIO28) and WiFi LED pin (GPIO16) for Tuya module
- ✅ Product ID: `qdmpkznox0g9kkvo`

---

## Hardware Configuration (Common to Both Versions)

### Ethernet (W5500)

| Function | GPIO |
|----------|------|
| CLK      | 1    |
| MOSI     | 2    |
| MISO     | 41   |
| CS       | 42   |
| INT      | 43   |
| RST      | 44   |

**Network**: DHCP by default. To use a static IP, add a `manual_ip` section under `ethernet:` in the YAML.

### I2C Bus

| Signal | GPIO |
|--------|------|
| SDA    | 8    |
| SCL    | 18   |

**Frequency**: 400 kHz

**I2C Devices**:

| Device   | Address | Description                |
|----------|---------|----------------------------|
| PCF8575  | 0x22    | 16‑channel digital input   |
| ADS1115  | 0x48    | 4‑channel analog input     |
| SSD1306  | 0x3C    | OLED display               |

### UART Interfaces

| Function        | RX Pin | TX Pin | Baud Rate |
|-----------------|--------|--------|-----------|
| DAC Modbus      | GPIO4  | GPIO6  | 115200    |
| RS485           | GPIO38 | GPIO39 | 9600      |
| Tuya WiFi MCU   | GPIO17 | GPIO16 | 9600      | *(with_tuya only)* |

- **DAC Modbus**: Controls the 16‑channel 0–10 V output via the ARM CPU.
- **RS485**: A test button (`RS485 Button`) is configured to send a fixed packet `[0x11, 0x22, 0x33, 0x44, 0x55]`. Can be modified or removed.
- **Tuya WiFi MCU**: Used only in the with‑Tuya version.

---

## 16‑Channel DAC Output

The DM16 uses Modbus RTU to control 16 DAC channels.  
Each channel is exposed as a **monochromatic light** in Home Assistant.

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

**Output Range**: 0–10 V (0 corresponds to 0, 4095 corresponds to 10 V).

### Tuya Integration (with_tuya version only)

Each DAC channel has a **standard light** (e.g., `light.dac_ch1`) and an **internal Tuya light** (e.g., `light.tuya_dac_ch1`) bound together via `bind_light_id`.  
- State changes in Home Assistant sync to the Tuya app.
- State changes in the Tuya app sync back to Home Assistant.
- Tuya DP IDs are mapped as:

| DAC Channel | Tuya DP ID |
|-------------|------------|
| CH1         | 2          |
| CH2         | 8          |
| CH3         | 16         |
| CH4         | 101        |
| CH5         | 102        |
| CH6         | 103        |
| CH7         | 104        |
| CH8         | 105        |
| CH9         | 106        |
| CH10        | 107        |
| CH11        | 108        |
| CH12        | 109        |
| CH13        | 110        |
| CH14        | 111        |
| CH15        | 112        |
| CH16        | 113        |

---

## 16‑Channel Digital Input

The DM16 uses one PCF8575 16‑bit I/O expander to read 16 digital inputs.  
All inputs are active‑LOW (connected to GND = ON) and have internal pull‑ups.

| Input Range | PCF8575 Chip | I2C Address | Pin Mapping                              | Entity Names                |
|-------------|--------------|-------------|------------------------------------------|-----------------------------|
| Inputs 1–16 | #1           | 0x22        | P8‑P15 → DI1‑DI8, P0‑P7 → DI9‑DI16       | dm16‑input01 … dm16‑input16 |

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
| 47   | dm16‑W1‑io47      | 1‑Wire / general‑purpose input           | Yes     |
| 48   | dm16‑W1‑io48      | 1‑Wire / general‑purpose input           | Yes     |
| 7    | dm16‑W1‑io7       | 1‑Wire / general‑purpose input           | Yes     |
| 40   | dm16‑W1‑io40      | 1‑Wire / general‑purpose input           | Yes     |
| 13   | dm16‑W1‑io13      | Free GPIO (no pull‑up)                   | No      |
| 14   | dm16‑W1‑io14      | Free GPIO (no pull‑up)                   | No      |
| 21   | dm16‑W1‑io21      | Free GPIO (no pull‑up)                   | No      |

All are exposed as **binary sensors**.  
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
2. Copy the desired YAML file (`DM16_esphome_without_tuya.yaml` or `DM16_esphome_with_tuya.yaml`) to your ESPHome configuration directory.
3. (Optional) If you need a static IP, add a `manual_ip` section under `ethernet:`.
4. For the with‑Tuya version, ensure the external component is available (ESPHome will download it automatically).
5. Compile and upload via USB (first time) or OTA.
6. After flashing, the OLED will display the IP address. Add the device to Home Assistant via the ESPHome integration.

---

## Important Notes

- **Both configurations** are fully local except for the Tuya cloud integration in the `with_tuya` version.
- **Modbus DAC** requires the ARM CPU on the DM16 to be properly powered and the UART connection to be correct.
- **RS485** is configured with a test button; you can extend it to implement actual RS485 communication.
- The ADS1115 gain is set to 6.144 V to accommodate 0–5 V signals. Do not exceed 5 V.
- **GPIO0 is not used** in these configurations.
- **With‑Tuya version** requires the Tuya module to be present and properly connected to GPIO16/17.

---

## Related Resources

- [FeedCurrent Official Website](https://www.feedcurrent.com)
- Pin Definition: `pin_definitions/DM16/DM16_pin_definition.md`
- Tuya MCU Component: https://github.com/hzkincony/esphome-tuya-wifi-mcu
- ESPHome Documentation: https://esphome.io/

