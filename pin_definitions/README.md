# Pin Definitions for Kincony Controllers

This directory contains the ESP32-S3 I/O pin definitions for various Kincony controller models. Each model has its own subfolder with a Markdown file detailing the complete pin mappings (I2C, GPIO, relays, inputs, etc.).

## Structure

- Each product is organized in a separate subfolder named after the model (e.g., `B4/`, `B8/`).
- Inside each folder, you will find a Markdown file named `{Model}_pin_definition.md` (e.g., `B4/B4_pin_definition.md`).

## Available Models

### B Series (Relay / MOSFET Controllers)

| Model | Description | Pin Definition File |
|-------|-------------|---------------------|
| **B4** | 8‑channel relay controller with 4 inputs, ADS1115, 1‑Wire | [`B4/B4_pin_definition.md`](B4/B4_pin_definition.md) |
| **B4M** | 8‑channel relay controller (variant) | [`B4M/B4M_pin_definition.md`](B4M/B4M_pin_definition.md) |
| **B8** | 8‑channel relay controller with 8 inputs, PCF8575, Ethernet | [`B8/B8_pin_definition.md`](B8/B8_pin_definition.md) |
| **B8M** | 8‑channel MOSFET controller with 8 inputs, PCF8575, Ethernet | [`B8M/B8M_pin_definition.md`](B8M/B8M_pin_definition.md) |
| **B16** | 16‑channel relay controller with 16 inputs, dual PCF8575, Ethernet | [`B16/B16_pin_definition.md`](B16/B16_pin_definition.md) |
| **B24** | 24‑channel relay controller with 24 inputs, triple PCF8575, Ethernet | [`B24/B24_pin_definition.md`](B24/B24_pin_definition.md) |
| **B24M** | 24‑channel relay controller (variant) | [`B24M/B24M_pin_definition.md`](B24M/B24M_pin_definition.md) |

### F Series (Relay Controllers with Digital Inputs)

| Model | Description | Pin Definition File |
|-------|-------------|---------------------|
| **F4** | 4‑channel relay controller with 4 inputs, analog inputs, Ethernet | [`F4/F4_pin_definition.md`](F4/F4_pin_definition.md) |
| **F8** | 8‑channel relay controller with 8 inputs, PCF8575, Ethernet | [`F8/F8_pin_definition.md`](F8/F8_pin_definition.md) |
| **F16** | 16‑channel relay controller with 16 inputs, dual PCF8575, Ethernet | [`F16/F16_pin_definition.md`](F16/F16_pin_definition.md) |
| **F24** | 24‑channel relay controller with 24 inputs, triple PCF8575, Ethernet | [`F24/F24_pin_definition.md`](F24/F24_pin_definition.md) |
| **F32** | 32‑channel relay controller with 32 inputs, quad PCF8575, Ethernet | [`F32/F32_pin_definition.md`](F32/F32_pin_definition.md) |

### T Series (Relay Controllers with Multiple Input Groups)

| Model | Description | Pin Definition File |
|-------|-------------|---------------------|
| **T16M** | 16‑channel relay controller with 16 inputs, dual PCF8575, 1‑Wire, Ethernet | [`T16M/T16M_pin_definition.md`](T16M/T16M_pin_definition.md) |
| **T32M** | 32‑channel relay controller with 32 inputs, quad PCF8575, 1‑Wire, Ethernet | [`T32M/T32M_pin_definition.md`](T32M/T32M_pin_definition.md) |
| **T64M** | 64‑channel relay controller with 64 inputs, octuple PCF8575, two I2C buses | [`T64M/T64M_pin_definition.md`](T64M/T64M_pin_definition.md) |
| **T128M** | 128‑channel relay controller with 128 inputs, 16× PCF8575, two I2C buses | [`T128M/T128M_pin_definition.md`](T128M/T128M_pin_definition.md) |

### N Series (Energy Monitoring Controllers)

| Model | Description | Pin Definition File |
|-------|-------------|---------------------|
| **N10** | 10‑channel energy monitor with ARM CPU, Ethernet, LoRa, SD card | [`N10/N10_pin_definition.md`](N10/N10_pin_definition.md) |
| **N20** | 20‑channel energy monitor with dual BL0910 chips, Ethernet, LoRa, SD card | [`N20/N20_pin_definition.md`](N20/N20_pin_definition.md) |

### DM Series (DAC / Analog Output Controllers)

| Model | Description | Pin Definition File |
|-------|-------------|---------------------|
| **DM4** | 4‑channel DAC controller with digital inputs, 1‑Wire, Ethernet | [`DM4/DM4_pin_definition.md`](DM4/DM4_pin_definition.md) |
| **DM8** | 8‑channel DAC controller with digital inputs, 1‑Wire, Ethernet | [`DM8/DM8_pin_definition.md`](DM8/DM8_pin_definition.md) |
| **DM16** | 16‑channel DAC controller with 16 inputs, 1‑Wire, Ethernet | [`DM16/DM16_pin_definition.md`](DM16/DM16_pin_definition.md) |
| **DM32** | 32‑channel DAC controller with 32 inputs, 1‑Wire, Ethernet | [`DM32/DM32_pin_definition.md`](DM32/DM32_pin_definition.md) |

### Special / Industrial Controllers

| Model | Description | Pin Definition File |
|-------|-------------|---------------------|
| **G1** | Industrial gateway with 4G (SIM7600), Ethernet, RS485, 1‑Wire | [`G1/G1_pin_definition.md`](G1/G1_pin_definition.md) |
| **AIO Hybrid** | Multi‑function controller with relay outputs, digital inputs, Zigbee, RF433, IR, DAC | [`AIO/AIO_pin_definition.md`](AIO/AIO_pin_definition.md) |
| **TA** | 12‑channel digital input + 2‑relay controller with Ethernet, RS485, 1‑Wire, RF433 | [`TA/TA_pin_definition.md`](TA/TA_pin_definition.md) |

## Usage

Each Markdown file provides:
- I²C bus pins and peripheral addresses.
- Detailed pin mapping for PCF857x expanders (relays and inputs).
- ADS1115 analog input channels (where applicable).
- 1‑wire and free GPIOs.
- Ethernet (W5500), RS485, Tuya module, SD card, and other peripheral pin assignments.

Refer to the specific file for the exact hardware configuration of your product.

## Adding New Models

When adding a new product, create a subfolder with the model name and place a `{Model}_pin_definition.md` file inside following the same format as existing ones. Then update this README accordingly.