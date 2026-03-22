# ESPHome Configurations for Kincony Controllers

This directory contains ESPHome YAML configuration files for various Kincony smart controllers. Each product has its own subfolder with the necessary YAML files and a `README.md` providing model‑specific details.

## Structure

- Each product is organized in a separate subfolder named after the model (e.g., `B4/`, `F8/`, `DM16/`).
- Inside each folder you will find:
  - One or more `.yaml` configuration files (e.g., `B4_esphome_with_tuya.yaml`, `B4_esphome_without_tuya.yaml`).
  - A `README.md` describing hardware features, pin assignments, and usage notes.

## Available Configurations

### B Series (Relay / MOSFET Controllers)
| Model | Subfolder | Description |
|-------|-----------|-------------|
| B4 | `B4/` | 8‑channel relay controller with 4 inputs, ADS1115, 1‑Wire |
| B4M | `B4M/` | 8‑channel relay controller (variant) |
| B8 | `B8/` | 8‑channel relay controller with 8 inputs, PCF8575, Ethernet |
| B8M | `B8M/` | 8‑channel MOSFET controller with 8 inputs, PCF8575, Ethernet |
| B16 | `B16/` | 16‑channel relay controller with 16 inputs, dual PCF8575, Ethernet |
| B24 | `B24/` | 24‑channel relay controller with 24 inputs, triple PCF8575, Ethernet |
| B24M | `B24M/` | 24‑channel relay controller (variant) |

### F Series (Relay Controllers with Digital Inputs)
| Model | Subfolder | Description |
|-------|-----------|-------------|
| F4 | `F4/` | 4‑channel relay controller with 4 inputs, analog inputs, Ethernet |
| F8 | `F8/` | 8‑channel relay controller with 8 inputs, PCF8575, Ethernet |
| F16 | `F16/` | 16‑channel relay controller with 16 inputs, dual PCF8575, Ethernet |
| F24 | `F24/` | 24‑channel relay controller with 24 inputs, triple PCF8575, Ethernet |
| F32 | `F32/` | 32‑channel relay controller with 32 inputs, quad PCF8575, Ethernet |

### DM Series (DAC / Analog Output Controllers)
| Model | Subfolder | Description |
|-------|-----------|-------------|
| DM4 | `DM4/` | 4‑channel DAC controller with digital inputs, 1‑Wire, Ethernet |
| DM8 | `DM8/` | 8‑channel DAC controller with digital inputs, 1‑Wire, Ethernet |
| DM16 | `DM16/` | 16‑channel DAC controller with 16 inputs, 1‑Wire, Ethernet |
| DM32 | `DM32/` | 32‑channel DAC controller with 32 inputs, 1‑Wire, Ethernet |

### N Series (Energy Monitoring Controllers)
| Model | Subfolder | Description |
|-------|-----------|-------------|
| N10 | `N10/` | 10‑channel energy monitor with ARM CPU, Ethernet, LoRa, SD card |
| N20 | `N20/` | 20‑channel energy monitor with dual BL0910 chips, Ethernet, LoRa, SD card |
| N30 | `N30/` | 30‑channel energy monitor with three BL0910 chips, Ethernet, LoRa, SD card |
| N60 | `N60/` | 60‑channel energy monitor with six BL0910 chips, Ethernet, LoRa, SD card |

### T Series (Relay Controllers with Multiple Input Groups)
| Model | Subfolder | Description |
|-------|-----------|-------------|
| T16M | `T16M/` | 16‑channel relay controller with 16 inputs, dual PCF8575, 1‑Wire, Ethernet |
| T32M | `T32M/` | 32‑channel relay controller with 32 inputs, quad PCF8575, 1‑Wire, Ethernet |
| T64M | `T64M/` | 64‑channel relay controller with 64 inputs, octuple PCF8575, two I2C buses |
| T128M | `T128M/` | 128‑channel relay controller with 128 inputs, 16× PCF8575, two I2C buses |

### Special / Industrial Controllers
| Model | Subfolder | Description |
|-------|-----------|-------------|
| G1 | `G1/` | Industrial gateway with 4G (SIM7600), Ethernet, RS485, 1‑Wire |
| AIO Hybrid | `AIO/` | Multi‑function controller with relay outputs, digital inputs, Zigbee, RF433, IR, DAC |
| TA | `TA/` | 12‑channel digital input + 2‑relay controller with Ethernet, RS485, 1‑Wire, RF433 |

## Usage

1. Navigate to the folder of your product.
2. Choose the appropriate YAML file (e.g., `with_tuya` or `without_tuya`) based on your hardware and cloud requirements.
3. Copy the YAML to your ESPHome configuration directory.
4. Modify network settings (static IP, DHCP) and, if needed, API encryption keys.
5. Compile and flash using the ESPHome dashboard or command line.

For detailed instructions, refer to the `README.md` inside each product folder.

## Adding New Models

When adding a new product, create a subfolder with the model name and place the YAML files and a `README.md` following the same format as existing ones. Then update this README accordingly.