# Kincony B16M (ESP32-S3) Pin Definitions

**Main Chip**: ESP32-S3

## 1. I²C Bus
*   **SDA**: `GPIO38` ⚠️ **Note: Different from other models (such as B16)**
*   **SCL**: `GPIO39` ⚠️ **Note: Different from other models (such as B16)**

### I²C Peripheral Addresses
| Peripheral | I²C Address | Description |
| :--- | :--- | :--- |
| PCF8575 (Output) | `0x25` | 16-bit I/O expander for 16 relay outputs |
| PCF8575 (Input) | `0x24` | 16-bit I/O expander for 16 digital inputs |
| DS3231 RTC | `0x68` | Real-time clock |
| SSD1306 | `0x3C` | Display |
| ADS1115 | `0x48` | 4-channel ADC module |

#### PCF8575 (Output, Address `0x25`) Pin Mapping
This chip controls the 16 relay outputs (active LOW).
| PCF8575 Pin | Connected Device | Type | Description |
| :--- | :--- | :--- | :--- |
| P0 - P15 | Relay 1 - Relay 16 | Output | 16 relay outputs (LOW = ON) |

#### PCF8575 (Input, Address `0x24`) Pin Mapping
This chip reads the 16 dry contact digital inputs (active LOW).
| PCF8575 Pin | Connected Device | Type | Description |
| :--- | :--- | :--- | :--- |
| P0 - P15 | Digital Input 1 - 16 | Input | 16 digital inputs (LOW = active) |

## 2. 1-Wire Bus (with pull-up resistance on PCB)
*   **1-wire-1**: `GPIO40`
*   **1-wire-2**: `GPIO15`
*   **1-wire-3**: `GPIO48`
*   **1-wire-4**: `GPIO47`

## 3. Free GPIOs (without pull-up resistance on PCB)
*   `GPIO13`
*   `GPIO14`
*   `GPIO21`

## 4. Dedicated Peripheral Interfaces

### Ethernet (W5500)
| Function | GPIO |
| :--- | :--- |
| SCK (Clock) | `GPIO42` |
| MOSI | `GPIO43` |
| MISO | `GPIO44` |
| CS (Chip Select) | `GPIO41` |
| INT (Interrupt) | `GPIO2` |
| RST (Reset) | `GPIO1` |

### RS485 ⚠️ **Note: The pins are opposite to those of other commonly used models**
*   **RXD**: `GPIO8`
*   **TXD**: `GPIO18`

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