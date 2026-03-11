# B8 Relay Controller (ESP32-S3) Pin Definitions

**Main Chip**: ESP32-S3

## 1. I²C Bus
*   **SDA**: `GPIO8`
*   **SCL**: `GPIO18`

### I²C Peripheral Addresses
| Peripheral | I²C Address | Description |
| :--- | :--- | :--- |
| PCF8575 | `0x22` | 16-bit I/O expander, connects 8 inputs and 8 relays |
| 24C02 EEPROM | `0x50` | EEPROM storage |
| DS3231 RTC | `0x68` | Real-time clock |
| SSD1306 | `0x3C` | Display |
| ADS1115 | `0x48` | 4-channel ADC module |

#### PCF8575 (Address `0x22`) Pin Mapping
| PCF8575 Pin | Connected Device | Type | Description |
| :--- | :--- | :--- | :--- |
| P0 | Digital Input 1 | Input | Dry contact input |
| P1 | Digital Input 2 | Input | Dry contact input |
| P2 | Digital Input 3 | Input | Dry contact input |
| P3 | Digital Input 4 | Input | Dry contact input |
| P4 | Digital Input 5 | Input | Dry contact input |
| P5 | Digital Input 6 | Input | Dry contact input |
| P6 | Digital Input 7 | Input | Dry contact input |
| P7 | Digital Input 8 | Input | Dry contact input |
| P8 | Relay 1 | Output | Normally open contact |
| P9 | Relay 2 | Output | Normally open contact |
| P10 | Relay 3 | Output | Normally open contact |
| P11 | Relay 4 | Output | Normally open contact |
| P12 | Relay 5 | Output | Normally open contact |
| P13 | Relay 6 | Output | Normally open contact |
| P14 | Relay 7 | Output | Normally open contact |
| P15 | Relay 8 | Output | Normally open contact |

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