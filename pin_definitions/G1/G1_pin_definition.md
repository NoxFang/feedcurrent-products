# G1 (KC868-G1) ESP32-S3 Pin Definitions

## Overview

The **G1 (KC868-G1)** is an ESP32-S3 based industrial controller featuring:
- **4G LTE Cellular Module** (SIM7600) via UART
- **Ethernet** (W5500) with hardware TCP/IP stack
- **RS485** industrial communication interface
- **OLED display** (SSD1306, I2C)
- **1-Wire interfaces** (some with on‑board pull‑up resistors)
- **Free GPIOs** (with no ESD protection diodes on‑board)
- **24C02 EEPROM** for non‑volatile storage

## ESP32-S3 Pin Assignments

### I2C Bus
| Pin | Function | Description |
|-----|----------|-------------|
| GPIO12 | SDA | I2C Data |
| GPIO11 | SCL | I2C Clock |

### Ethernet (W5500 SPI)
| Pin | Function | Description |
|-----|----------|-------------|
| GPIO42 | CLK | SPI Clock |
| GPIO43 | MOSI | SPI MOSI |
| GPIO44 | MISO | SPI MISO |
| GPIO41 | CS | W5500 Chip Select |
| GPIO2 | INT | W5500 Interrupt |
| GPIO1 | RST | W5500 Reset |

### RS485 (UART)
| Pin | Function | Description |
|-----|----------|-------------|
| GPIO18 | RXD | RS485 Receive |
| GPIO8 | TXD | RS485 Transmit |

### 4G Module (SIM7600) Interface
| Pin | Function | Description |
|-----|----------|-------------|
| GPIO10 | RXD | Module receive (ESP32 ← SIM7600) |
| GPIO9 | TXD | Module transmit (ESP32 → SIM7600) |

### 1-Wire Bus
#### With On‑board Pull‑up Resistors (ready to use)
| Pin | 1‑Wire Channel |
|-----|----------------|
| GPIO15 | 1-wire 1 |
| GPIO16 | 1-wire 2 |
| GPIO17 | 1-wire 3 |
| GPIO40 | 1-wire 4 |

#### Without On‑board Pull‑up Resistors (require external 4.7kΩ pull‑up)
| Pin | 1‑Wire Channel |
|-----|----------------|
| GPIO13 | 1-wire 5 |
| GPIO14 | 1-wire 6 |
| GPIO21 | 1-wire 7 |

### Free GPIOs (no ESD protection diodes on PCB)
These pins are marked as free but **do not** have on‑board ESD protection. Use external protection when exposed to the environment.
| Pin | Description |
|-----|-------------|
| GPIO4 | Free GPIO (no ESD diode) |
| GPIO5 | Free GPIO (no ESD diode) |
| GPIO6 | Free GPIO (no ESD diode) |
| GPIO7 | Free GPIO (no ESD diode) |

## I2C Device Addresses
| Device | I²C Address | Description |
|--------|-------------|-------------|
| 24C02 EEPROM | 0x50 | Non‑volatile storage |
| SSD1306 | 0x3C | OLED display |

## Important Notes

- **I2C bus** is shared between the EEPROM and OLED display.
- **Ethernet** uses dedicated SPI pins – avoid using them for other SPI devices.
- **1-Wire** channels with on‑board pull‑ups (GPIO15,16,17,40) are ready for DS18B20 sensors. The remaining three channels require external pull‑up resistors.
- **Free GPIOs (GPIO4‑7)** lack on‑board ESD diodes; add external protection if used in exposed applications.
- **4G module (SIM7600)** uses its own UART; ensure power sequencing is handled appropriately.
- **RS485** interface uses GPIO8 (TX) and GPIO18 (RX); no direction control pin is needed as the transceiver is self‑driving.
