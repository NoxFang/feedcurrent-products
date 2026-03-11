# FeedCurrent B8M (ESP32-S3) Pin Definitions

**Main Chip**: ESP32-S3

## 1. I²C Bus
*   **SDA**: `GPIO8`
*   **SCL**: `GPIO18`

### I²C Peripheral Addresses
| Peripheral | I²C Address | Description |
| :--- | :--- | :--- |
| PCF8575 | `0x22` | 16-bit I/O expander, connects 8 MOSFETs and 8 digital inputs |
| 24C02 EEPROM | `0x50` | EEPROM storage |
| DS3231 RTC | `0x68` | Real-time clock |
| SSD1306 | `0x3C` | Display |
| ADS1115 | `0x48` | 4-channel ADC module |

#### PCF8575 (Address `0x22`) Pin Mapping
| PCF8575 Pin | Connected Device | Type | Description |
| :--- | :--- | :--- | :--- |
| P0 | MOSFET 1 | Output | 10A driver IC |
| P1 | MOSFET 2 | Output | 10A driver IC |
| P2 | MOSFET 3 | Output | 10A driver IC |
| P3 | MOSFET 4 | Output | 10A driver IC |
| P4 | MOSFET 5 | Output | 10A driver IC |
| P5 | MOSFET 6 | Output | 10A driver IC |
| P6 | MOSFET 7 | Output | 10A driver IC |
| P7 | MOSFET 8 | Output | 10A driver IC |
| P8 | Digital Input 1 | Input | Dry contact input |
| P9 | Digital Input 2 | Input | Dry contact input |
| P10 | Digital Input 3 | Input | Dry contact input |
| P11 | Digital Input 4 | Input | Dry contact input |
| P12 | Digital Input 5 | Input | Dry contact input |
| P13 | Digital Input 6 | Input | Dry contact input |
| P14 | Digital Input 7 | Input | Dry contact input |
| P15 | Digital Input 8 | Input | Dry contact input |

#### ADS1115 (Address `0x48`) Analog Inputs
| Channel | Signal Type | Range |
| :--- | :--- | :--- |
| A1 | Voltage input | DC 0-5V |
| A2 | Voltage input | DC 0-5V |
| A3 | Current input | 4-20mA |
| A4 | Current input | 4-20mA |

## 2. 1-Wire Bus
*(Pull-up resistors already integrated on PCB)*
*   **1-wire-1**: `GPIO47`
*   **1-wire-2**: `GPIO48`
*   **1-wire-3**: `GPIO7`
*   **1-wire-4**: `GPIO40`

## 3. Free GPIOs
*(No pull-up resistors on PCB)*
*   `GPIO13`
*   `GPIO14`
*   `GPIO21`

## 4. Dedicated Peripheral Interfaces

### Ethernet (W5500)
| Function | GPIO |
| :--- | :--- |
| SCK (Clock) | `GPIO1` |
| MOSI | `GPIO2` |
| MISO | `GPIO41` |
| CS (Chip Select) | `GPIO42` |
| INT (Interrupt) | `GPIO43` |
| RST (Reset) | `GPIO44` |

### RS485
*   **RXD**: `GPIO38`
*   **TXD**: `GPIO39`

### Tuya Module
*   **RXD** (Module receive): `GPIO17`
*   **TXD** (Module transmit): `GPIO16`
*   **Network Button**: Tuya module `P28`
*   **Network LED**: Tuya module `P16`

### SD Card (SPI Mode)
| Function | GPIO |
| :--- | :--- |
| MOSI | `GPIO10` |
| SCK | `GPIO11` |
| MISO | `GPIO12` |
| CS | `GPIO9` |
| CD (Card Detect) | `GPIO5` |