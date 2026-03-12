# B16 Controller (ESP32-S3) Pin Definitions

**Main Chip**: ESP32-S3

## 1. I²C Bus
*   **SDA**: `GPIO8`
*   **SCL**: `GPIO18`

### I²C Peripheral Addresses
| Peripheral | I²C Address | Description |
| :--- | :--- | :--- |
| PCF8575 (Output) | `0x22` | 16-bit I/O expander for 16 relay outputs |
| PCF8575 (Input) | `0x24` | 16-bit I/O expander for 16 digital inputs |
| 24C02 EEPROM | `0x50` | EEPROM storage |
| DS3231 RTC | `0x68` | Real-time clock |
| SSD1306 | `0x3C` | Display |
| ADS1115 | `0x48` | 4-channel ADC module |

#### PCF8575 (Output, Address `0x22`) Pin Mapping
This chip controls the 16 relay outputs (active LOW).
| PCF8575 Pin | Connected Device | Type | Description |
| :--- | :--- | :--- | :--- |
| P0 - P15 | Relay 1 - Relay 16 | Output | 16 relay outputs (LOW = ON) |

#### PCF8575 (Input, Address `0x24`) Pin Mapping
This chip reads the 16 dry contact digital inputs (active LOW).
| PCF8575 Pin | Connected Device | Type | Description |
| :--- | :--- | :--- | :--- |
| P0 - P15 | Digital Input 1 - 16 | Input | 16 digital inputs (LOW = active) |

#### ADS1115 (Address `0x48`) Analog Inputs
| Channel | Signal Type | Range |
| :--- | :--- | :--- |
| A1 | Voltage input | DC 0-5V |
| A2 | Voltage input | DC 0-5V |
| A3 | Current input | 4-20mA |
| A4 | Current input | 4-20mA |

## 2. 1-Wire / Free GPIOs
*(Note: The forum post lists these under "free GPIOs", grouping them by whether pull-up resistors are present.)*

### GPIOs with Pull-up Resistance on PCB
*(Typically used for 1-Wire devices)*
*   `GPIO40`
*   `GPIO48`
*   `GPIO47`
*   `GPIO7`

### GPIOs without Pull-up Resistance on PCB
*   `GPIO13`
*   `GPIO14`
*   `GPIO21`

## 3. Dedicated Peripheral Interfaces

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