# T64M (ESP32-S3) Pin Definitions

## Overview

The **T64M** is an ESP32-S3 based smart controller with:
- **64 Channel Relay Output** (via 4 PCF8575 I2C expanders on I2C Bus‑1)
- **64 Channel Digital Input** (via 4 PCF8575 I2C expanders on I2C Bus‑2)
- **4 Channel ADC** (2 voltage, 2 current, using ESP32 internal ADC)
- **1‑Wire Bus** (4 channels with pull‑up on PCB)
- **3 Free GPIOs** (no pull‑up)
- **Ethernet** (W5500 SPI)
- **RS485** (UART with enable pin)
- **24C02 EEPROM** (I2C on Bus‑1)

## ESP32-S3 Pin Assignments

### I2C Bus 1 (for Outputs & EEPROM)
| Pin | Function | Description |
|-----|----------|-------------|
| GPIO48 | SDA | I2C Data Line |
| GPIO47 | SCL | I2C Clock Line |

### I2C Bus 2 (for Inputs)
| Pin | Function | Description |
|-----|----------|-------------|
| GPIO12 | SDA | I2C Data Line |
| GPIO11 | SCL | I2C Clock Line |

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
| GPIO21 | RX | RS485 Receive |
| GPIO13 | TX | RS485 Transmit |
| GPIO14 | EN | RS485 Enable (DE/RE control) |
| *Baud rate: 9600* |

### Analog Inputs (Direct ESP32 ADC)
| Pin | Function | Range | Description |
|-----|----------|-------|-------------|
| GPIO7 | A1 | 0–5V | Voltage measurement channel 1 |
| GPIO6 | A2 | 0–5V | Voltage measurement channel 2 |
| GPIO5 | A3 | 4–20mA | Current measurement channel 1 |
| GPIO4 | A4 | 4–20mA | Current measurement channel 2 |

### 1-Wire Bus (with pull-up resistance on PCB)
| Pin | 1-Wire Channel |
|-----|----------------|
| GPIO15 | 1-wire 1 |
| GPIO16 | 1-wire 2 |
| GPIO17 | 1-wire 3 |
| GPIO18 | 1-wire 4 |

### Free GPIOs (without pull-up resistance on PCB)
| Pin | Description |
|-----|-------------|
| GPIO8 | Free GPIO |
| GPIO9 | Free GPIO |
| GPIO10 | Free GPIO |

## I2C Device Addresses

### I2C Bus 1 (Addresses for Outputs & EEPROM)
| Device | I²C Address | Description |
|--------|-------------|-------------|
| PCF8575 (Outputs 1‑16) | 0x25 | 16‑bit I/O expander for relays 1‑16 |
| PCF8575 (Outputs 17‑32) | 0x24 | 16‑bit I/O expander for relays 17‑32 |
| PCF8575 (Outputs 33‑48) | 0x21 | 16‑bit I/O expander for relays 33‑48 |
| PCF8575 (Outputs 49‑64) | 0x20 | 16‑bit I/O expander for relays 49‑64 |
| 24C02 EEPROM | 0x50 | Non‑volatile memory |

### I2C Bus 2 (Addresses for Inputs)
| Device | I²C Address | Description |
|--------|-------------|-------------|
| PCF8575 (Inputs 1‑16) | 0x25 | 16‑bit I/O expander for inputs 1‑16 |
| PCF8575 (Inputs 17‑32) | 0x24 | 16‑bit I/O expander for inputs 17‑32 |
| PCF8575 (Inputs 33‑48) | 0x21 | 16‑bit I/O expander for inputs 33‑48 |
| PCF8575 (Inputs 49‑64) | 0x20 | 16‑bit I/O expander for inputs 49‑64 |

## PCF8575 Pin Mapping

All PCF8575 chips use the same internal pin mapping:
- **P0** corresponds to the first channel of the chip
- **P1** corresponds to the second channel
- ...
- **P15** corresponds to the sixteenth channel

For example, the chip at address `0x25` on Bus‑1 controls relays 1‑16 as follows:
| Output | PCF8575 Pin |
|--------|-------------|
| Relay 1 | P0 |
| Relay 2 | P1 |
| ... | ... |
| Relay 16 | P15 |

Similarly, the chip at address `0x25` on Bus‑2 reads inputs 1‑16:
| Input | PCF8575 Pin |
|-------|-------------|
| Input 1 | P0 |
| Input 2 | P1 |
| ... | ... |
| Input 16 | P15 |

The same pattern applies to all other chips (addresses `0x24`, `0x21`, `0x20` on both buses).

## Important Notes

- All PCF8575 I/O pins are **active LOW** (inverted logic)
- I2C buses operate at 400kHz
- RS485 baud rate: 9600
- **GPIO0 is not used** on the T64M hardware – avoid using it in your firmware
- ADC pins use ESP32‑S3 internal ADC; for precise measurements, calibration is recommended
- Relays are rated according to the hardware version (consult product label)
- The four 1‑Wire pins have built‑in pull‑up resistors on the PCB
- The three free GPIOs (GPIO8,9,10) have no pull‑up resistors and can be used for general-purpose I/O
- When programming, use separate I2C instances for Bus‑1 and Bus‑2 (e.g., `Wire1` for Bus‑2)