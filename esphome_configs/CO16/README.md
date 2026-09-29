# CO16 ESPHome Configurations

## Overview
This directory contains two ESPHome configuration files for the FeedCurrent CO16 16‑channel relay controller:

- `CO16_esphome_without_tuya.yaml` – Local‑only version, no Tuya cloud integration.
- `CO16_esphome_with_tuya.yaml` – Includes Tuya WiFi MCU support for cloud control.

Both configurations use the **ESP-IDF framework** (not Arduino) and require ESPHome **≥ 2026.5.3**.

## Hardware Support (Common to Both Versions)
- **16‑channel relay output** (PCF8575 @ 0x22, pins 0‑15, active LOW)
- **16‑channel digital input** (XL9535 @ 0x24, active LOW)
  - Inputs 1‑8: XL9535 pins 0‑7
  - Inputs 9‑16: XL9535 pins 10‑17 (pins 8‑9 are skipped)
- **16‑channel analog input** via four ADS1115 ADCs:
  - ADS1115‑1 @ 0x48 → CH1‑CH4
  - ADS1115‑2 @ 0x49 → CH5‑CH8
  - ADS1115‑3 @ 0x4B → CH9‑CH12
  - ADS1115‑4 @ 0x4A → CH13‑CH16
  - Default scaling: 0‑10 V (gain 4.096, multiplier 5.16696, clamp 0‑10 V)
  - For 4‑20 mA channels, change filters to `[{multiply: 10.0}]` and unit to `mA` (see comments in YAML).
- **4‑channel PT100 temperature** via MAX31865 + NX3L4051 multiplexer:
  - MUX S1 = GPIO7, S2 = GPIO21, S3 = LOW
  - MAX31865 software SPI: CLK = GPIO11, MOSI = GPIO10, MISO = GPIO12, CS = GPIO14
  - 3‑wire PT100, 400 Ω reference, 50 Hz mains filter
  - Sensors update every 10 s (4 channels sequentially)
- **Ethernet** (W5500 SPI2: CLK=GPIO1, MOSI=GPIO2, MISO=GPIO41, CS=GPIO42, INT=GPIO43, RST=GPIO44, 16 MHz)
- **I2C bus** (SDA=GPIO8, SCL=GPIO18, 100 kHz)
- **Web server** on port 80
- **OTA** updates via ESPHome

> **Note**: The CO16 board also has an ST7789 TFT display, SD card, DS3231 RTC, and RS485 transceiver, but these are **not configured** in the ESPHome YAML files. They can be added manually if needed.

## Configuration Differences
- **Without Tuya**: standard ESPHome with all local controls.  
  Uses `external_components` from `hzkincony/esphome-nx3l4051` (commit `c3b3d5fe…`) for the NX3L4051 multiplexer and MAX31865.
- **With Tuya**: adds Tuya WiFi MCU (UART TX=GPIO16, RX=GPIO17, 9600 baud, product ID `8svouhd9lziyz5py`).  
  All relays and inputs are bound to Tuya DP IDs:
  - Outputs 1‑6: DP 1‑6
  - Outputs 7‑16: DP 101‑110
  - Inputs 1‑8: DP 111‑118
  - Inputs 9‑16: DP 119‑126
  Uses `external_components` from `hzkincony/esphome-tuya-wifi-mcu` (ref v1.4.0 + feat/esp-idf-support) which also provides the NX3L4051 components.
  Additionally defines a **RS485 UART** (`uart_1`: TX=GPIO39, RX=GPIO38, 9600 baud) but no switch is attached by default.

## Flashing Instructions
1. Install ESPHome (version ≥ 2026.5.3).
2. Copy the desired YAML file to your configuration directory.
3. Run `esphome run <filename>.yaml` and follow the prompts.
4. After flashing, add the device to Home Assistant via the ESPHome integration.

## Important Notes
- All relays and digital inputs are **active‑LOW** (connected to GND = ON / triggered).
- The PT100 sensors are read sequentially through the multiplexer; each channel updates every 10 seconds.
- Analog inputs default to 0‑10 V. For 4‑20 mA sensors, modify the `filters` block for the relevant channel as described in the YAML comments.
- The `without_tuya` version explicitly notes that **Ethernet and Wi‑Fi cannot be used simultaneously** in ESPHome. Remove the `ethernet:` block before adding a `wifi:` configuration.
- The `with_tuya` version requires a Tuya WiFi module connected to the specified UART pins.
- `restore_mode: ALWAYS_OFF` is set for all relay outputs, so they default to OFF after power‑on.
- GPIO5 is shared with the optional LoRa module; not used in these YAMLs.

## Reference
- Pin definition: `../../pin_definitions/CO16/CO16_pin_definition.md`
- Arduino examples: `../../arduino_demos/CO16/`
- FeedCurrent Official Website: [https://www.feedcurrent.com](https://www.feedcurrent.com)