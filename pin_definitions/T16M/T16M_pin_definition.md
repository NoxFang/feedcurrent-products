# T16M (ESP32-S3) Pin Definitions

## Overview

The **T16M** is an ESP32-S3 based smart controller with:
- **16 Channel Relay Output** (via PCF8575 I2C expander, address `0x25`)
- **16 Channel Digital Input** (via separate PCF8575 I2C expander, address `0x24`)
- **1-Wire Bus** (7 channels with pull-up on PCB)
- **Ethernet** (W5500 SPI)
- **RS485** (UART)
- **24C02 EEPROM** (I2C)

## ESP32-S3 Pin Assignments

### I2C Bus (400kHz)
| Pin | Function | Description |
|-----|----------|-------------|
| GPIO11 | SDA | I2C Data Line |
| GPIO12 | SCL | I2C Clock Line |

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
| GPIO14 | RX | RS485 Receive |
| GPIO13 | TX | RS485 Transmit |
| *Baud rate: 9600* |

### 1-Wire Bus (with pull-up resistance on PCB)
| Pin | 1-Wire Channel |
|-----|----------------|
| GPIO8 | 1-wire 1 |
| GPIO9 | 1-wire 2 |
| GPIO10 | 1-wire 3 |
| GPIO15 | 1-wire 4 |
| GPIO16 | 1-wire 5 |
| GPIO17 | 1-wire 6 |
| GPIO18 | 1-wire 7 |

## I2C Device Addresses
| Device | I²C Address | Description |
|--------|-------------|-------------|
| PCF8575 (Output) | 0x25 | 16‑bit I/O expander for 16 relay outputs |
| PCF8575 (Input) | 0x24 | 16‑bit I/O expander for 16 digital inputs |
| 24C02 EEPROM | 0x50 | Non‑volatile memory |

## PCF8575 Pin Mapping

### Input Chip (Address `0x24`) – Active LOW
| Input | PCF8575 Pin | Description |
|-------|-------------|-------------|
| Input 1 | P0 | Digital input 1 |
| Input 2 | P1 | Digital input 2 |
| Input 3 | P2 | Digital input 3 |
| Input 4 | P3 | Digital input 4 |
| Input 5 | P4 | Digital input 5 |
| Input 6 | P5 | Digital input 6 |
| Input 7 | P6 | Digital input 7 |
| Input 8 | P7 | Digital input 8 |
| Input 9 | P8 | Digital input 9 |
| Input 10 | P9 | Digital input 10 |
| Input 11 | P10 | Digital input 11 |
| Input 12 | P11 | Digital input 12 |
| Input 13 | P12 | Digital input 13 |
| Input 14 | P13 | Digital input 14 |
| Input 15 | P14 | Digital input 15 |
| Input 16 | P15 | Digital input 16 |

### Output Chip (Address `0x25`) – Active LOW
| Output | PCF8575 Pin | Description |
|--------|-------------|-------------|
| Relay 1 | P0 | Relay output 1 |
| Relay 2 | P1 | Relay output 2 |
| Relay 3 | P2 | Relay output 3 |
| Relay 4 | P3 | Relay output 4 |
| Relay 5 | P4 | Relay output 5 |
| Relay 6 | P5 | Relay output 6 |
| Relay 7 | P6 | Relay output 7 |
| Relay 8 | P7 | Relay output 8 |
| Relay 9 | P8 | Relay output 9 |
| Relay 10 | P9 | Relay output 10 |
| Relay 11 | P10 | Relay output 11 |
| Relay 12 | P11 | Relay output 12 |
| Relay 13 | P12 | Relay output 13 |
| Relay 14 | P13 | Relay output 14 |
| Relay 15 | P14 | Relay output 15 |
| Relay 16 | P15 | Relay output 16 |

## Important Notes

- All PCF8575 I/O pins are **active LOW** (inverted logic)
- I2C bus operates at 400kHz
- RS485 baud rate: 9600
- The 1‑Wire pins have built‑in pull‑up resistors on the PCB
- GPIO0 is not used on the T16M hardware – avoid using it in your firmware
- Relays are rated according to the hardware version (consult product label)