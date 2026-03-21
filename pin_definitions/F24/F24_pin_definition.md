# F24 (ESP32-S3) Pin Definitions

## Overview

The **F24** is an ESP32-S3 based smart controller with:
- **24 Channel Relay Output** (using three PCF8575 expanders: outputs 1–8 from `0x26`, outputs 9–24 from `0x25`)
- **24 Channel Digital Input** (using two PCF8575 expanders: inputs 1–16 from `0x24`, inputs 17–24 from `0x26`)
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
| PCF8575 (Outputs 9–24) | 0x25 | 16‑bit I/O expander for relays 9‑24 |
| PCF8575 (Inputs 1–16) | 0x24 | 16‑bit I/O expander for digital inputs 1‑16 |
| PCF8575 (Hybrid) | 0x26 | 16‑bit I/O expander for inputs 17‑24 and relays 1‑8 |
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

### Hybrid Chip (Address `0x26`) – Active LOW
This chip handles inputs 17–24 (P0–P7) and relays 1–8 (P8–P15).

| PCF8575 Pin | Connected Device | Type | Description |
|-------------|------------------|------|-------------|
| P0 | Digital Input 17 | Input | Dry contact (LOW = active) |
| P1 | Digital Input 18 | Input | Dry contact (LOW = active) |
| P2 | Digital Input 19 | Input | Dry contact (LOW = active) |
| P3 | Digital Input 20 | Input | Dry contact (LOW = active) |
| P4 | Digital Input 21 | Input | Dry contact (LOW = active) |
| P5 | Digital Input 22 | Input | Dry contact (LOW = active) |
| P6 | Digital Input 23 | Input | Dry contact (LOW = active) |
| P7 | Digital Input 24 | Input | Dry contact (LOW = active) |
| P8 | Relay 5 | Output | Relay (LOW = ON) |
| P9 | Relay 6 | Output | Relay (LOW = ON) |
| P10 | Relay 7 | Output | Relay (LOW = ON) |
| P11 | Relay 8 | Output | Relay (LOW = ON) |
| P12 | Relay 1 | Output | Relay (LOW = ON) |
| P13 | Relay 2 | Output | Relay (LOW = ON) |
| P14 | Relay 3 | Output | Relay (LOW = ON) |
| P15 | Relay 4 | Output | Relay (LOW = ON) |

### Output Chip (Address `0x25`) – Active LOW
This chip controls relays 9‑24 (16 outputs).

| Output | PCF8575 Pin | Description |
|--------|-------------|-------------|
| Relay 9 | P0 | Relay output 9 |
| Relay 10 | P1 | Relay output 10 |
| Relay 11 | P2 | Relay output 11 |
| Relay 12 | P3 | Relay output 12 |
| Relay 13 | P4 | Relay output 13 |
| Relay 14 | P5 | Relay output 14 |
| Relay 15 | P6 | Relay output 15 |
| Relay 16 | P7 | Relay output 16 |
| Relay 17 | P8 | Relay output 17 |
| Relay 18 | P9 | Relay output 18 |
| Relay 19 | P10 | Relay output 19 |
| Relay 20 | P11 | Relay output 20 |
| Relay 21 | P12 | Relay output 21 |
| Relay 22 | P13 | Relay output 22 |
| Relay 23 | P14 | Relay output 23 |
| Relay 24 | P15 | Relay output 24 |

## Important Notes

- All PCF8575 I/O pins are **active LOW** (inverted logic)
- I2C bus operates at 400kHz
- RS485 baud rate: 9600
- **GPIO0 is not used** on the F24 hardware – avoid using it in your firmware
- ADC pins use ESP32‑S3 internal ADC; for precise measurements, calibration is recommended
- Relays are rated according to the hardware version (consult product label)
- Tuya module pins (GPIO38/39) are dedicated for the Tuya Wi‑Fi module; they should not be used for other purposes unless the module is absent
- The two 1‑Wire pins without pull‑up (GPIO13, GPIO14) require external pull‑up resistors for proper operation
- When configuring in ESPHome, use the pin numbers as listed in the mapping tables above, paying attention to the address and chip assignments for each relay/input group