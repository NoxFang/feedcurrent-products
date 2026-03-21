# DM16 Pin Definition

## Overview

| Item | Specification |
|------|----------------|
| Model | KinCony DM16 |
| MCU | ESP32-S3-WROOM-1U (N16R8) |
| DAC Outputs | 16 channels (via Modbus to ARM CPU, DC 0-10V) |
| Digital Inputs | 16 channels (via PCF8575 I2C expander) |
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
| PCF8575 | 0x22 | Digital Input Expander (16 channels) |
| ADS1115 | 0x48 | 16-bit ADC (4 channels) |
| 24C02 | 0x50 | EEPROM |
| DS3231 | 0x68 | Real-Time Clock |
| SSD1306 | 0x3C | OLED Display |

---

## Digital Input (PCF8575 @ 0x22)

The DM16 uses a PCF8575 I2C expander for 16 digital inputs.

| PCF8575 Pin | Input | Function |
|-------------|-------|----------|
| P8 | Input 1 | Digital Input 1 |
| P9 | Input 2 | Digital Input 2 |
| P10 | Input 3 | Digital Input 3 |
| P11 | Input 4 | Digital Input 4 |
| P12 | Input 5 | Digital Input 5 |
| P13 | Input 6 | Digital Input 6 |
| P14 | Input 7 | Digital Input 7 |
| P15 | Input 8 | Digital Input 8 |
| P0 | Input 9 | Digital Input 9 |
| P1 | Input 10 | Digital Input 10 |
| P2 | Input 11 | Digital Input 11 |
| P3 | Input 12 | Digital Input 12 |
| P4 | Input 13 | Digital Input 13 |
| P5 | Input 14 | Digital Input 14 |
| P6 | Input 15 | Digital Input 15 |
| P7 | Input 16 | Digital Input 16 |

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
| GPIO7 | 1-Wire 3 |
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
| GPIO17 | RXD |
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
