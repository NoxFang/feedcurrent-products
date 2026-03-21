# DM8 Pin Definition

## Overview

| Item | Specification |
|------|----------------|
| Model | KinCony DM8 |
| MCU | ESP32-S3 |
| DAC Outputs | 8 channels (via Modbus to ARM CPU) |
| Digital Inputs | 8 channels (via PCF8574) |
| Analog Inputs | 4 channels (via ADS1115) |

---

## I2C Configuration

| Pin | Function |
|-----|----------|
| GPIO8 | SDA |
| GPIO18 | SCL |

### I2C Device Addresses

| Device | I2C Address | Description |
|--------|-------------|-------------|
| PCF8574 | 0x24 | Digital Input Expander (8 channels) |
| ADS1115 | 0x48 | 16-bit ADC (4 channels) |
| 24C02 | 0x50 | EEPROM |
| DS3231 | 0x68 | Real-Time Clock |
| SSD1306 | 0x3C | OLED Display |

---

## Digital Input (PCF8574 @ 0x24)

| Pin | Function |
|-----|----------|
| P0 | Digital Input 1 |
| P1 | Digital Input 2 |
| P2 | Digital Input 3 |
| P3 | Digital Input 4 |
| P4 | Digital Input 5 |
| P5 | Digital Input 6 |
| P6 | Digital Input 7 |
| P7 | Digital Input 8 |

---

## Analog Input (ADS1115 @ 0x48)

| Channel | Range |
|---------|-------|
| A0 | DC 0-5V |
| A1 | DC 0-5V |
| A2 | DC 4-20mA |
| A3 | DC 4-20mA |

---

## 1-Wire Interface

| Pin | Function |
|-----|----------|
| GPIO47 | 1-Wire 1 |
| GPIO48 | 1-Wire 2 |
| GPIO17 | 1-Wire 3 |
| GPIO40 | 1-Wire 4 |

*Note: Pull-up resistors are included on PCB.*

---

## RS485

| Pin | Function |
|-----|----------|
| GPIO38 | RXD |
| GPIO39 | TXD |

---

## Tuya WiFi Module UART

| Pin | Function |
|-----|----------|
| GPIO15 | RXD |
| GPIO16 | TXD |

---

## ARM CPU DAC UART (Modbus Control)

| Pin | Function |
|-----|----------|
| GPIO4 | TXD |
| GPIO6 | RXD |

*Baud rate: 115200*

---

## Ethernet (W5500)

| Pin | Function |
|-----|----------|
| GPIO1 | CLK |
| GPIO2 | MOSI |
| GPIO41 | MISO |
| GPIO42 | CS |
| GPIO43 | INT |
| GPIO44 | RST |

---

## SD Card (SPI)

| Pin | Function |
|-----|----------|
| GPIO10 | MOSI |
| GPIO11 | SCK |
| GPIO12 | MISO |
| GPIO9 | CS |
| GPIO5 | Card Detect |

---

## Free GPIO

| Pin | Function |
|-----|----------|
| GPIO13 | Free GPIO |
| GPIO14 | Free GPIO |
| GPIO21 | Free GPIO |

---

## Tuya Module (Hardware)

| Function | Connection |
|----------|------------|
| Network Button | Connected to Tuya Module P28 |
| Network LED | Connected to Tuya Module P16 |

---
