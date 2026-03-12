# Pin Definitions for Kincony Controllers

This directory contains the ESP32-S3 I/O pin definitions for various Kincony controller models. Each model has its own subfolder with a Markdown file detailing the complete pin mappings (I2C, GPIO, relays, inputs, etc.).

## Structure

- Each product is organized in a separate subfolder named after the model (e.g., `B4/`, `B8/`).
- Inside each folder, you will find a Markdown file named `{Model}_pin_definition.md` (e.g., `B4/B4_pin_definition.md`).

## Available Models

| Model | Description | Pin Definition File |
|-------|-------------|---------------------|
| **B4** | 8‑channel relay controller with 4 inputs, ADS1115, 1‑Wire | [`B4/B4_pin_definition.md`](B4/B4_pin_definition.md) |
| **B4M** | 8‑channel relay controller (variant) | [`B4M/B4M_pin_definition.md`](B4M/B4M_pin_definition.md) |
| **B8** | 8‑channel relay controller with 8 inputs, PCF8575, Ethernet | [`B8/B8_pin_definition.md`](B8/B8_pin_definition.md) |
| **B8M** | 8‑channel MOSFET controller with 8 inputs, PCF8575, Ethernet | [`B8M/B8M_pin_definition.md`](B8M/B8M_pin_definition.md) |
| **B16** | 16‑channel relay controller with 16 inputs, dual PCF8575, Ethernet | [`B16/B16_pin_definition.md`](B16/B16_pin_definition.md) |

## Usage

Each Markdown file provides:
- I²C bus pins and peripheral addresses.
- Detailed pin mapping for PCF857x expanders (relays and inputs).
- ADS1115 analog input channels.
- 1‑wire and free GPIOs.
- Ethernet (W5500), RS485, Tuya module, and SD card pin assignments.

Refer to the specific file for the exact hardware configuration of your product.