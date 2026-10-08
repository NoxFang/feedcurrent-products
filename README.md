# FeedCurrent Products – Software Resources

This repository contains systematically organized software resources for FeedCurrent ESP32‑S3 based controllers.  
Resources include **pin definitions**, **ESPHome YAML configurations**, **Arduino example sketches**, and **KCS firmware** for each product.

## Repository Structure
```cpp
feedcurrent-products/
├── pin_definitions/ # GPIO pinout tables per product
├── esphome_configs/ # ESPHome YAML files (with/without Tuya)
├── arduino_demos/ # Arduino example sketches
└── kcs_firmware/ # KCS firmware binaries (per model)
```

## Supported Products

### F Series – Relay Controllers
- F4, F8, F16, F24, F32  
  *Relay outputs, digital inputs, analog inputs, RS485, Ethernet, SD card, RTC, OLED, Tuya WiFi.*

### DM Series – Digital Input Modules
- DM4, DM8, DM16, DM32  
  *Dedicated digital input expansion boards.*

### N Series – Energy Meter Controllers
- N10, N20, N30, N60  
  *Multi‑channel energy metering via RS485 Modbus, SD card, Ethernet, OLED.*

### T Series – High‑Density I/O Controllers
- T16M, T32M, T64M, T128M  
  *Large‑scale relay and input boards (up to 128 channels), dual I2C buses, Ethernet, RS485.*

### B Series – MOSFET & Relay Boards
- B4, B4M, B8, B8M, B16, B16M, B24, B24M  
  *Relay and MOSFET variants with same pin layouts.*

### Pi5 Series – Raspberry Pi CM5 Controllers
- Pi5M8, Pi5M16, Pi5M32 – MOSFET output controllers with 8/16/32 channels
- Pi5R8, Pi5R16, Pi5R32 – Relay output controllers with 8/16/32 channels
  *Powered by Raspberry Pi Compute Module 5 (CM5), DIN rail mount, Gigabit Ethernet, RS232/RS485, optocoupler‑isolated inputs, PWM outputs, analog inputs, M.2 PCIe expansion, SSD1306 OLED display, Node‑RED support, and industrial aluminum enclosure.*

### Special / Industrial
- G1 (Gateway), TA (Thermostat Adapter), AIO Hybrid  
  *Specialised controllers with integrated peripherals (RF433, Zigbee, IR, DAC, etc.).*

## Directory Details

### Pin Definitions (`pin_definitions/`)
Each product folder contains a `_pin_definition.md` file listing GPIO assignments, I2C addresses, and hardware‑specific notes.

### ESPHome Configurations (`esphome_configs/`)
For each product, two YAML files are provided:
- `with_tuya.yaml` – includes Tuya cloud integration
- `without_tuya.yaml` – pure local ESPHome setup

### Arduino Examples (`arduino_demos/`)
Each product has numbered example folders (01 to up to 13) with:
- `src/` – Arduino `.ino` source code
- `precompiled/` – ready‑to‑flash `.bin` firmware
- `README.md` – detailed explanation of the example

### Node‑RED Flows (`node_red_flows/`)
Pre‑built Node‑RED flows for the Pi5 series and other supported products.
- Subdirectories are named after the product (e.g., `Pi5M8/`, `Pi5R16/`).
- Each folder contains `.json` flow files that can be imported directly into Node‑RED.
- Ideal for rapid prototyping and visual automation design.

### KCS Firmware (`kcs_firmware/`)
Pre‑compiled KCS system firmware for each product model.  
- Subdirectories are named after the product (e.g., `F16/`, `T64M/`).
- Each folder contains one or more `.bin` files (e.g., `kcs_v3.24.2.bin`).
- Flash at address `0x0` using ESP Flash Download Tool or `esptool.py`.

## Usage

1. **Browse** the product folder you are interested in.
2. **Check** the pin definition for correct wiring.
3. **Choose** either:
   - **ESPHome** for Home Assistant integration
   - **Arduino** for custom programming
   - **Node‑RED** for visual automation (Pi5 series and compatible models)
   - **KCS firmware** for the complete production‑ready system
4. **Flash** the appropriate firmware (precompiled binaries at address `0x0`) or compile from source.

## Requirements

- **Hardware**: Any supported FeedCurrent controller
- **Software**: Arduino IDE (with ESP32‑S3 support), ESPHome, or ESP Flash Download Tool
- **Libraries**: As listed in each example’s README (e.g., `PCF8575`, `U8g2`, `DS3231`)

## Contributing

When adding a new product:
1. Create a subfolder under `pin_definitions/`, `esphome_configs/`, `arduino_demos/`, `node_red_flows/`, and `kcs_firmware/`.
2. Follow the established naming and structure conventions.
3. Provide clear English documentation.
4. Reference the source forum threads (if applicable).

## Version History
- **2026‑10‑08** – Added node_red_flows/ directory with Pi5M8, Pi5M16, Pi5M32, Pi5R8, Pi5R16, Pi5R32 flows; added corresponding pin_definitions/ entries for all Pi5 models.
- **2026‑03‑26** – Added `kcs_firmware/` directory with KCS v3.24.2 firmware for all models.
- **2026‑03‑25** – Added T16M, T32M, T64M, T128M, N10/N20/N30/N60, F24/F32, and all corresponding examples.
- **2026‑03‑21** – Initial AIO Hybrid documentation included.

---

*This repository is maintained for reference and development purposes. Refer to the official product documentation for warranties and support.*