# DM4 ESP32-S3 I/O Pin Definition

## Product Overview

The DM4 Dimmer is a multi-function I/O controller based on ESP32-S3.
It features 4 digital inputs (PCF8574), 4-channel 12-bit DAC output (MCP4728),
4-channel ADC (ADS1115), 4 x 1-Wire buses, DS3231 RTC, 24C02 EEPROM,
W5500 Ethernet, RS485, SD card, Tuya WiFi module, and SSD1306 OLED display.

## Hardware Specifications

| Parameter | Value |
|-----------|-------|
| MCU | ESP32-S3 |
| Digital Input Expander | PCF8574 (I2C 0x24), 4 channels |
| DAC Output | MCP4728 (I2C 0x60), 4 channels, 12-bit |
| ADC Input | ADS1115 (I2C 0x48), 4 channels |
| RTC | DS3231 (I2C 0x68) |
| EEPROM | 24C02 (I2C 0x50) |
| 1-Wire Buses | 4 buses (with pull-up resistors on PCB) |
| Ethernet | W5500 SPI |
| Communication | RS485, Tuya WiFi module |
| Storage | MicroSD (SPI) |
| Display | SSD1306 128×64 OLED (I2C 0x3C) |
| Free GPIO | GPIO13, GPIO14, GPIO21 |

## GPIO Pin Assignments

### I2C Bus

| Signal | GPIO |
|--------|------|
| SDA    | GPIO8 |
| SCL    | GPIO18 |

### 1-Wire Buses (PCB pull-up resistors fitted)

| Bus | GPIO |
|-----|------|
| 1-Wire1 | GPIO47 |
| 1-Wire2 | GPIO48 |
| 1-Wire3 | GPIO17 |
| 1-Wire4 | GPIO40 |

### Free GPIO (No Pull Resistors)

| GPIO   | Description |
|--------|-------------|
| GPIO13 | Free digital I/O |
| GPIO14 | Free digital I/O |
| GPIO21 | Free digital I/O |

### Ethernet (W5500)

| Signal | GPIO |
|--------|------|
| CLK    | GPIO1 |
| MOSI   | GPIO2 |
| MISO   | GPIO41 |
| CS     | GPIO42 |
| INT    | GPIO43 |
| RST    | GPIO44 |

### RS485

| Signal | GPIO |
|--------|------|
| RXD    | GPIO38 |
| TXD    | GPIO39 |

### Tuya WiFi Module

| Signal       | GPIO / Pin |
|--------------|------------|
| RXD          | GPIO15 |
| TXD          | GPIO16 |
| Network Button | Tuya P28 |
| Network LED  | Tuya P16 |

### SD Card (SPI)

| Signal | GPIO |
|--------|------|
| MOSI   | GPIO10 |
| SCK    | GPIO11 |
| MISO   | GPIO12 |
| CS     | GPIO9 |
| CD (detect) | GPIO5 |

## I2C Device Address Map

| Device | Address | Description |
|--------|---------|-------------|
| PCF8574 | 0x24 | 4-channel digital input expander |
| ADS1115 | 0x48 | 4-channel 16-bit ADC |
| MCP4728 | 0x60 | 4-channel 12-bit DAC |
| DS3231  | 0x68 | Real-time clock |
| 24C02   | 0x50 | 256-byte EEPROM |
| SSD1306 | 0x3C | 128×64 OLED display |

## PCF8574 Digital Input Mapping

| PCF8574 Pin | Input Channel |
|-------------|---------------|
| P0 | Input 1 |
| P1 | Input 2 |
| P2 | Input 3 |
| P3 | Input 4 |

## ADS1115 Analog Input Configuration

| Channel | Range | Signal Type |
|---------|-------|-------------|
| A0 (A1) | 0–5 V DC | Voltage input |
| A1 (A2) | 0–5 V DC | Voltage input |
| A2 (A3) | 4–20 mA | Current input |
| A3 (A4) | 4–20 mA | Current input |

## MCP4728 DAC Output Channels

| Channel | Description |
|---------|-------------|
| A | DAC output 1 (0–5 V, 12-bit) |
| B | DAC output 2 (0–5 V, 12-bit) |
| C | DAC output 3 (0–5 V, 12-bit) |
| D | DAC output 4 (0–5 V, 12-bit) |

