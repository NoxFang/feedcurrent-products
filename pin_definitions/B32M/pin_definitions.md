# B32M Pin Definitions

## Overview

The **B32M** is an ESP32-S3 based smart controller with:
- **32 Channel MOSFET Output** (via PCF8575 I2C expanders)
- **32 Channel Digital Input** (via PCF8575 I2C expanders)
- **4 Channel Analog Input** (ADS1115 16-bit ADC)
- **Ethernet** (W5500 SPI)
- **RS485** (UART)
- **OLED Display** (SSD1306 I2C)
- **SD Card** (SPI)
- **RTC** (DS3231 I2C)
- **Free GPIOs** (4 pins with pull-up, 4 pins without)

## ESP32-S3 Pin Assignments

### I2C Bus (400kHz)
| Pin | Function | Description |
|-----|----------|-------------|
| GPIO8 | SDA | I2C Data Line |
| GPIO18 | SCL | I2C Clock Line |

### Ethernet (W5500 SPI)
| Pin | Function | Description |
|-----|----------|-------------|
| GPIO1 | CLK | SPI Clock |
| GPIO2 | MOSI | SPI MOSI |
| GPIO41 | MISO | SPI MISO |
| GPIO42 | CS | W5500 Chip Select |
| GPIO43 | INT | W5500 Interrupt |
| GPIO44 | RST | W5500 Reset |

### RS485 (UART)
| Pin | Function | Description |
|-----|----------|-------------|
| GPIO38 | RX | RS485 Receive |
| GPIO39 | TX | RS485 Transmit |

### SD Card (SPI)
| Pin | Function | Description |
|-----|----------|-------------|
| GPIO9 | CS | SD Card Chip Select |
| GPIO10 | MOSI | SPI MOSI |
| GPIO11 | CLK | SPI Clock |
| GPIO12 | MISO | SPI MISO |

### Free GPIOs (With Pull-up - suitable for 1-Wire)
| Pin | Function | Description |
|-----|----------|-------------|
| GPIO48 | Free GPIO | With pull-up resistor |
| GPIO47 | Free GPIO | With pull-up resistor |
| GPIO40 | Free GPIO | With pull-up resistor |
| GPIO7 | Free GPIO | With pull-up resistor |

### Free GPIOs (Without Pull-up)
| Pin | Function | Description |
|-----|----------|-------------|
| GPIO13 | Free GPIO | No pull-up |
| GPIO14 | Free GPIO | No pull-up |
| GPIO21 | Free GPIO | No pull-up |
| GPIO0 | Free GPIO | No pull-up (boot mode pin) |

### Tuya WiFi Module (UART)
| Pin | Function | Description |
|-----|----------|-------------|
| GPIO16 | TX | Tuya UART TX |
| GPIO17 | RX | Tuya UART RX |

## I2C Device Addresses

| Device | Address | Description |
|--------|---------|-------------|
| PCF8575 | 0x22 | Input 1-16 |
| PCF8575 | 0x25 | Input 17-24 & Output 1-8 |
| PCF8575 | 0x24 | Output 9-24 |
| PCF8575 | 0x26 | Input 25-32 & Output 25-32 |
| ADS1115 | 0x48 | 4-Channel 16-bit ADC |
| SSD1306 | 0x3C | OLED Display |
| DS3231 | 0x68 | Real-Time Clock |

## Output Mapping

| Output | PCF8575 | Pin | Address |
|--------|---------|-----|---------|
| Output 1-8 | pcf8574_hub_in_out_2 | 8-15 | 0x26 |
| Output 9-16 | pcf8574_hub_in_out_1 | 8-15 | 0x25 |
| Output 17-24 | pcf8574_hub_out_1 | 0-7 | 0x24 |
| Output 25-32 | pcf8574_hub_in_out_2 | 0-7 | 0x26 |

## Input Mapping

| Input | PCF8575 | Pin | Address |
|-------|---------|-----|---------|
| Input 1-16 | pcf8574_hub_in_1 | 0-15 | 0x22 |
| Input 17-24 | pcf8574_hub_in_out_1 | 0-7 | 0x25 |
| Input 25-32 | pcf8574_hub_in_out_2 | 0-7 | 0x26 |

## Notes

- All PCF8575 I/O pins are active LOW (inverted logic)
- I2C bus operates at 400kHz
- RS485 baud rate: 9600
- GPIO0 should not be pulled LOW during boot
- The 4 GPIOs with pull-up (48, 47, 40, 7) are suitable for 1-Wire devices
