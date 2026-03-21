# AIO Hybrid (ESP32-S3) Pin Definitions

## Overview

The **AIO Hybrid** is a highly integrated smart home controller based on ESP32-S3. It provides multiple interfaces including Ethernet, RS485, Tuya WiFi/Zigbee modules, RF433 receiver, IR transceiver, digital inputs via PCF8575, relay outputs via PCF8574, SD card slot, and I2C peripherals (OLED, RTC, DAC, EEPROM).

## ESP32-S3 Pin Assignments

### I2C Bus (400kHz)
| Pin | Function | Description |
|-----|----------|-------------|
| GPIO8 | SDA | I2C Data Line |
| GPIO18 | SCL | I2C Clock Line |

### I2C Device Addresses
| Device | I²C Address | Description |
|--------|-------------|-------------|
| PCF8575 | 0x24 | 16‑bit I/O expander for 12 digital inputs |
| PCF8574 | 0x26 | 8‑bit I/O expander for 5 relay outputs |
| SSD1306 | 0x3C | OLED display |
| DS3231 | 0x68 | Real‑time clock |
| MCP4728 | 0x60 | 4‑channel DAC (0‑10V) |
| 24C02 | 0x50 | EEPROM |

### PCF8575 (Address `0x24`) – Digital Inputs (12 channels, active LOW)
| PCF8575 Pin | Input Channel |
|-------------|---------------|
| P0 | Digital Input 1 |
| P1 | Digital Input 2 |
| P2 | Digital Input 3 |
| P3 | Digital Input 4 |
| P4 | Digital Input 5 |
| P5 | Digital Input 6 |
| P6 | Digital Input 7 |
| P7 | Digital Input 8 |
| P8 | Digital Input 9 |
| P9 | Digital Input 10 |
| P10 | Digital Input 11 |
| P11 | Digital Input 12 |

### PCF8574 (Address `0x26`) – Relay Outputs (5 channels, active LOW)
| PCF8574 Pin | Relay Channel |
|-------------|---------------|
| P3 | Relay 1 |
| P4 | Relay 2 |
| P5 | Relay 3 |
| P6 | Relay 4 |
| P7 | Relay 5 |

### Analog Inputs (Direct ESP32 ADC)
| Pin | Function | Range | Description |
|-----|----------|-------|-------------|
| GPIO5 | A1 | 0–5V | Voltage measurement channel 1 |
| GPIO7 | A2 | 0–5V | Voltage measurement channel 2 |
| GPIO6 | A3 | 4–20mA | Current measurement channel 1 |
| GPIO4 | A4 | 4–20mA | Current measurement channel 2 |

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
| GPIO47 | RXD | RS485 Receive |
| GPIO3 | TXD | RS485 Transmit |
| *Baud rate: 9600* |

### Tuya WiFi Module
| Pin | Function | Description |
|-----|----------|-------------|
| GPIO38 | RXD | Tuya module receive |
| GPIO39 | TXD | Tuya module transmit |
| P28 (on module) | Network Button | Tuya module's button |
| P16 (on module) | Network LED | Tuya module's LED |

### Tuya Zigbee Module
| Pin | Function | Description |
|-----|----------|-------------|
| GPIO48 | RXD | Zigbee module receive |
| GPIO15 | TXD | Zigbee module transmit |

### RF433 Wireless Receiver
| Pin | Function |
|-----|----------|
| GPIO40 | RF433 receiver input |

### IR Transceiver
| Pin | Function |
|-----|----------|
| GPIO14 | IR Transmit |
| GPIO17 | IR Receive |

### SD Card (SPI Mode)
| Function | GPIO |
|----------|------|
| MOSI | GPIO10 |
| SCK | GPIO11 |
| MISO | GPIO12 |
| CS | GPIO9 |
| CD (Card Detect) | GPIO13 |

## Important Notes

- All PCF857x I/O pins are **active LOW** (inverted logic)
- I2C bus operates at 400kHz
- RS485 baud rate: 9600
- GPIO0 is not used on the AIO Hybrid – avoid using it in your firmware
- The DAC (MCP4728) provides 4 channels of 0‑10V analog output
- The digital inputs are opto‑isolated
- Relay outputs are rated 10A @ 250V AC