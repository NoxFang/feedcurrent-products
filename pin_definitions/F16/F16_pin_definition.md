# F16 (ESP32-S3) Pin Definitions

## Overview

The **F16** is an ESP32-S3 based smart controller with:
- **16 Channel Relay Output** (via PCF8575 I2C expander, address `0x25`)
- **16 Channel Digital Input** (via separate PCF8575 I2C expander, address `0x24`)
- **4 Channel ADC** (2 voltage, 2 current, using ESP32 internal ADC)
- **Ethernet** (W5500 SPI)
- **RS485** (UART)
- **Tuya Module Interface** (UART)
- **1-Wire Bus** (4 channels with pull-up, 2 without)
- **RF433 Wireless Receiver** (GPIO40)
- **SD Card Slot** (SPI)
- **OLED Display** (SSD1306 I2C)
- **24C02 EEPROM** (I2C)
- **DS3231 RTC** (I2C)

## ESP32-S3 Pin Assignments

### I2C Bus (400kHz)
| Pin | Function | Description |
|-----|----------|-------------|
| GPIO8 | SDA | I2C Data Line |
| GPIO18 | SCL | I2C Clock Line |

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
| GPIO17 | RX | RS485 Receive |
| GPIO16 | TX | RS485 Transmit |
| *Baud rate: 9600* |

### Tuya Module Interface
| Pin | Function | Description |
|-----|----------|-------------|
| GPIO38 | RX | Tuya module receive |
| GPIO39 | TX | Tuya module transmit |
| P28 (on module) | Network Button | Tuya module's button |
| P16 (on module) | Network LED | Tuya module's LED |

### Analog Inputs (Direct ESP32 ADC)
| Pin | Function | Range | Description |
|-----|----------|-------|-------------|
| GPIO5 | A1 | 0–5V | Voltage measurement channel 1 |
| GPIO7 | A2 | 0–5V | Voltage measurement channel 2 |
| GPIO6 | A3 | 4–20mA | Current measurement channel 1 |
| GPIO4 | A4 | 4–20mA | Current measurement channel 2 |

### 1-Wire Bus
#### With Pull-up Resistance (on PCB)
| Pin | 1-Wire Channel |
|-----|----------------|
| GPIO48 | 1-wire 1 |
| GPIO47 | 1-wire 2 |
| GPIO21 | 1-wire 3 |
| GPIO15 | 1-wire 4 |

#### Without Pull-up Resistance
| Pin | 1-Wire Channel |
|-----|----------------|
| GPIO13 | 1-wire 5 |
| GPIO14 | 1-wire 6 |

### RF433 Wireless Receiver
| Pin | Function |
|-----|----------|
| GPIO40 | RF433 receiver input |

### SD Card (SPI Mode)
| Function | GPIO |
|----------|------|
| MOSI | GPIO10 |
| SCK | GPIO11 |
| MISO | GPIO12 |
| CS | GPIO9 |

## I2C Device Addresses
| Device | I²C Address | Description |
|--------|-------------|-------------|
| PCF8575 (Output) | 0x25 | 16‑bit I/O expander for 16 relay outputs |
| PCF8575 (Input) | 0x24 | 16‑bit I/O expander for 16 digital inputs |
| 24C02 EEPROM | 0x50 | Non‑volatile memory |
| DS3231 RTC | 0x68 | Real‑time clock |
| SSD1306 | 0x3C | OLED display |

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
- **GPIO0 is not used** on the F16 hardware – avoid using it in your firmware
- ADC pins use ESP32‑S3 internal ADC; for precise measurements, calibration is recommended
- Relays are rated according to the hardware version (consult product label)
- Tuya module pins (GPIO38/39) are dedicated for the Tuya Wi‑Fi module; they should not be used for other purposes unless the module is absent
- The two 1‑Wire pins without pull‑up (GPIO13, GPIO14) require external pull‑up resistors for proper operation