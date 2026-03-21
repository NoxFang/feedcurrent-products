# N30 (ESP32-S3) Pin Definitions

## Overview

The **N30** is an ESP32-S3 based energy monitoring controller. It communicates with two BL0910 energy measurement chips via an internal ARM CPU using UART, providing 20 channels of current/energy monitoring. The board includes Ethernet, I2C OLED, LoRa radio interface, SD card slot, and two free GPIOs.

## ESP32-S3 Pin Assignments

### Ethernet (W5500 SPI)
| Pin | Function | Description |
|-----|----------|-------------|
| GPIO42 | CLK | SPI Clock |
| GPIO43 | MOSI | SPI MOSI |
| GPIO44 | MISO | SPI MISO |
| GPIO41 | CS | W5500 Chip Select |
| GPIO2 | INT | W5500 Interrupt |
| GPIO1 | RST | W5500 Reset |

### I2C Bus (OLED Display)
| Pin | Function | Description |
|-----|----------|-------------|
| GPIO18 | SDA | I2C Data |
| GPIO17 | SCL | I2C Clock |

| Device | I²C Address | Description |
|--------|-------------|-------------|
| SSD1306 | 0x3C | 128x64 OLED display |

### LoRa Radio Interface (SPI)
| Pin | Function | Description |
|-----|----------|-------------|
| GPIO13 | SCK | SPI Clock |
| GPIO12 | MOSI | SPI MOSI |
| GPIO11 | MISO | SPI MISO |
| GPIO14 | CS | Chip Select |
| GPIO21 | RST | Reset |
| GPIO47 | DIO0 | Interrupt / DIO0 |

### ARM CPU UART (Energy Measurement)
This UART connects the ESP32‑S3 to the ARM CPU that interfaces with the BL0910 energy chips.
| Pin | Function | Description |
|-----|----------|-------------|
| GPIO9 | TXD | ESP32 transmit to ARM CPU |
| GPIO10 | RXD | ESP32 receive from ARM CPU |
| *Baud rate: 38400, Modbus RTU* |

### SD Card (SPI)
| Pin | Function | Description |
|-----|----------|-------------|
| GPIO40 | MOSI | SPI MOSI |
| GPIO39 | SCK | SPI Clock |
| GPIO38 | MISO | SPI MISO |
| GPIO48 | CS | Chip Select |
| GPIO8 | CD | Card Detect |

### Free GPIOs (without pull‑up resistance)
| Pin | Description |
|-----|-------------|
| GPIO15 | Digital input / free GPIO |
| GPIO16 | Digital input / free GPIO |

## Important Notes

- The board **does not** include a separate RS485 transceiver; all Modbus communication is handled internally via the ARM CPU UART.
- The LoRa SPI pins are shared with other functions only if the LoRa module is not populated.
- I2C bus is dedicated to the OLED display.
- GPIO0 is not used on the N30 – avoid using it in your firmware.
- Energy measurement uses two BL0910 chips (Modbus addresses 1 and 2) on the internal RS485 bus connected to the ARM CPU.