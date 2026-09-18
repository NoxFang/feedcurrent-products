# B2 (ESP32-S3) Pin Definitions

**Main Chip**: ESP32-S3

## 1. I²C Bus
*   **SDA**: `GPIO8`
*   **SCL**: `GPIO18`

### I²C Peripheral Addresses
| Peripheral | I²C Address | Description |
| :--- | :--- | :--- |
| 24C02 EEPROM | `0x50` | EEPROM storage |
| DS3231 RTC | `0x68` | Real-time clock |
| SSD1306 | `0x3C` | Display |
| ADS1115 | `0x48` | 4-channel ADC module |

#### ADS1115 (Address `0x48`) Analog Inputs
| Channel | Signal Type | Range |
| :--- | :--- | :--- |
| A1 | Voltage input | DC 0-5V |
| A2 | Voltage input | DC 0-5V |
| A3 | Current input | 4-20mA |
| A4 | Current input | 4-20mA |

## 2. Digital Inputs
*   **Digital Input 1**: `GPIO6`
*   **Digital Input 2**: `GPIO7`

## 3. Relay Outputs
*   **Relay 1**: `GPIO4`
*   **Relay 2**: `GPIO46`

## 4. 1-Wire Bus
*(Pull-up resistors already integrated on PCB)*
*   **1-wire-1**: `GPIO47`
*   **1-wire-2**: `GPIO48`
*   **1-wire-3**: `GPIO17`
*   **1-wire-4**: `GPIO40`

## 5. Dedicated Peripheral Interfaces

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
*   **RXD**: `GPIO39`
*   **TXD**: `GPIO38`

### Tuya Module
*   **RXD** (Module receive): `GPIO13`
*   **TXD** (Module transmit): `GPIO14`
*   **Network Button**: Tuya module `P28`
*   **Network LED**: Tuya module `P16`

### 4G SIM7600
*   **RXD** (Module receive): `GPIO16`
*   **TXD** (Module transmit): `GPIO15`

### SD Card (SPI Mode)
| Function | GPIO |
| :--- | :--- |
| MOSI | `GPIO10` |
| SCK | `GPIO11` |
| MISO | `GPIO12` |
| CS | `GPIO9` |
| CD (Card Detect) | `GPIO5` |