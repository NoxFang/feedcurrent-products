# F4 (ESP32-S3) Pin Definitions

## Overview

The **F4** is an ESP32-S3 based smart controller with:
- **4 Channel 16A Removable Relay Output** (via PCF8574 I2C expander)
- **4 Channel Digital Input** (via PCF8574 I2C expander)
- **4 Channel ADC** (2 for voltage, 2 for current measurement)
- **Ethernet** (W5500 SPI)
- **RS485** (UART)
- **Tuya Module Interface** (UART)
- **1-Wire Bus** (5 channels, 4 with pull-up, 1 without)
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
| GPIO14 | 1-wire 5 |

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
| CD (Card Detect) | GPIO13 |

## I2C Device Addresses
| Device | I²C Address | Description |
|--------|-------------|-------------|
| PCF8574 | 0x24 | I/O expander for 4 inputs + 4 relays |
| 24C02 EEPROM | 0x50 | Non‑volatile memory |
| DS3231 RTC | 0x68 | Real‑time clock |
| SSD1306 | 0x3C | OLED display |

## PCF8574 Pin Mapping (Address 0x24)

### Inputs (Active LOW)
| Input | PCF8574 Pin | Description |
|-------|-------------|-------------|
| Input 1 | P0 | Digital input 1 |
| Input 2 | P1 | Digital input 2 |
| Input 3 | P2 | Digital input 3 |
| Input 4 | P3 | Digital input 4 |

### Outputs (Active LOW)
| Output | PCF8574 Pin | Description |
|--------|-------------|-------------|
| Relay 1 | P4 | 16A Removable Relay 1 |
| Relay 2 | P5 | 16A Removable Relay 2 |
| Relay 3 | P6 | 16A Removable Relay 3 |
| Relay 4 | P7 | 16A Removable Relay 4 |

## Important Notes

- All PCF8574 I/O pins are **active LOW** (inverted logic)
- I2C bus operates at 400kHz
- RS485 baud rate: 9600
- **GPIO0 is not used** on the F4 hardware – avoid using it in your firmware
- The 4 GPIOs with pull-up (48, 47, 21, 15) are suitable for 1-Wire devices
- ADC pins use ESP32‑S3 internal ADC; for precise measurements, calibration is recommended
- Relays are rated 16A and feature removable terminal blocks
- Tuya module pins (GPIO38/39) are dedicated for the Tuya Wi‑Fi module; they should not be used for other purposes unless the module is absent