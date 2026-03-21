# T32M (ESP32-S3) Pin Definitions

## Overview

The **T32M** is an ESP32-S3 based smart controller with:
- **32 Channel Relay Output** (via PCF8575 I2C expanders: outputs 1‑16 at `0x20`, outputs 17‑32 at `0x21`)
- **32 Channel Digital Input** (via separate PCF8575 I2C expanders: inputs 1‑16 at `0x24`, inputs 17‑32 at `0x25`)
- **4 Channel ADC** (2 voltage, 2 current, using ESP32 internal ADC)
- **1‑Wire Bus** (4 channels with pull‑up on PCB)
- **3 Free GPIOs** (no pull‑up)
- **Ethernet** (W5500 SPI)
- **RS485** (UART with enable pin)
- **24C02 EEPROM** (I2C)

## ESP32-S3 Pin Assignments

### I2C Bus (400kHz)
| Pin | Function | Description |
|-----|----------|-------------|
| GPIO48 | SDA | I2C Data Line |
| GPIO47 | SCL | I2C Clock Line |

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
| Device | I²C Address | Description |
|--------|-------------|-------------|
| PCF8575 (Outputs 1‑16) | 0x20 | 16‑bit I/O expander for relays 1‑16 |
| PCF8575 (Outputs 17‑32) | 0x21 | 16‑bit I/O expander for relays 17‑32 |
| PCF8575 (Inputs 1‑16) | 0x24 | 16‑bit I/O expander for digital inputs 1‑16 |
| PCF8575 (Inputs 17‑32) | 0x25 | 16‑bit I/O expander for digital inputs 17‑32 |
| 24C02 EEPROM | 0x50 | Non‑volatile memory |

## PCF8575 Pin Mapping

### Output Chip at Address `0x20` – Active LOW
| Output | PCF8575 Pin | Description |
|--------|-------------|-------------|
| Relay 1 | P0 | Relay output 1 |
| Relay 2 | P1 | Relay output 2 |
| ... | ... | ... |
| Relay 16 | P15 | Relay output 16 |

*(All 16 pins of this chip are used for relays 1‑16.)*

### Output Chip at Address `0x21` – Active LOW
| Output | PCF8575 Pin | Description |
|--------|-------------|-------------|
| Relay 17 | P0 | Relay output 17 |
| Relay 18 | P1 | Relay output 18 |
| ... | ... | ... |
| Relay 32 | P15 | Relay output 32 |

*(All 16 pins of this chip are used for relays 17‑32.)*

### Input Chip at Address `0x24` – Active LOW
| Input | PCF8575 Pin | Description |
|-------|-------------|-------------|
| Input 1 | P0 | Digital input 1 |
| Input 2 | P1 | Digital input 2 |
| ... | ... | ... |
| Input 16 | P15 | Digital input 16 |

*(All 16 pins of this chip are used for inputs 1‑16.)*

### Input Chip at Address `0x25` – Active LOW
| Input | PCF8575 Pin | Description |
|-------|-------------|-------------|
| Input 17 | P0 | Digital input 17 |
| Input 18 | P1 | Digital input 18 |
| ... | ... | ... |
| Input 32 | P15 | Digital input 32 |

*(All 16 pins of this chip are used for inputs 17‑32.)*

## Important Notes

- All PCF8575 I/O pins are **active LOW** (inverted logic)
- I2C bus operates at 400kHz
- RS485 baud rate: 9600
- **GPIO0 is not used** on the T32M hardware – avoid using it in your firmware
- ADC pins use ESP32‑S3 internal ADC; for precise measurements, calibration is recommended
- Relays are rated according to the hardware version (consult product label)
- The four 1‑Wire pins have built‑in pull‑up resistors on the PCB
- The three free GPIOs (GPIO8,9,10) have no pull‑up resistors and can be used for general-purpose I/O