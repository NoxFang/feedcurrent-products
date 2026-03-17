# FeedCurrent B24M (ESP32-S3) Pin Definitions

**Source**: [Kincony Forum Post](https://www.kincony.com/forum/showthread.php?tid=8358) (Accessed: 2026-03-17)
**Main Chip**: ESP32-S3

## 1. I²C Bus
*   **SDA**: `GPIO8`
*   **SCL**: `GPIO18`

### I²C Peripheral Addresses
| Peripheral | I²C Address | Description |
| :--- | :--- | :--- |
| PCF8575 (Input 1-16) | `0x22` | 16-bit I/O expander for the first 16 digital inputs |
| PCF8575 (I/O Hybrid) | `0x25` | 16-bit I/O expander for inputs 17-24 and outputs 1-8 |
| PCF8575 (Output 9-24) | `0x24` | 16-bit I/O expander for relay outputs 9-24 |
| DS3231 RTC | `0x68` | Real-time clock |
| SSD1306 | `0x3C` | Display |
| ADS1115 | `0x48` | 4-channel ADC module |
| 24C02 EPROM | `0x50` | EEPROM storage |

#### PCF8575 at Address `0x22` (Inputs 1-16)
This chip reads the first 16 dry contact digital inputs (active LOW).
| PCF8575 Pin | Connected Device | Type | Description |
| :--- | :--- | :--- | :--- |
| P8 | Digital Input 1 | Input | Dry contact (LOW = active) |
| P9 | Digital Input 2 | Input | Dry contact (LOW = active) |
| P10 | Digital Input 3 | Input | Dry contact (LOW = active) |
| P11 | Digital Input 4 | Input | Dry contact (LOW = active) |
| P12 | Digital Input 5 | Input | Dry contact (LOW = active) |
| P13 | Digital Input 6 | Input | Dry contact (LOW = active) |
| P14 | Digital Input 7 | Input | Dry contact (LOW = active) |
| P15 | Digital Input 8 | Input | Dry contact (LOW = active) |
| P0 | Digital Input 9 | Input | Dry contact (LOW = active) |
| P1 | Digital Input 10 | Input | Dry contact (LOW = active) |
| P2 | Digital Input 11 | Input | Dry contact (LOW = active) |
| P3 | Digital Input 12 | Input | Dry contact (LOW = active) |
| P4 | Digital Input 13 | Input | Dry contact (LOW = active) |
| P5 | Digital Input 14 | Input | Dry contact (LOW = active) |
| P6 | Digital Input 15 | Input | Dry contact (LOW = active) |
| P7 | Digital Input 16 | Input | Dry contact (LOW = active) |

#### PCF8575 at Address `0x25` (Inputs 17-24 & Outputs 1-8)
This chip reads inputs 17-24 and controls relay outputs 1-8.
| PCF8575 Pin | Connected Device | Type | Description |
| :--- | :--- | :--- | :--- |
| P0 | Digital Input 17 | Input | Dry contact (LOW = active) |
| P1 | Digital Input 18 | Input | Dry contact (LOW = active) |
| P2 | Digital Input 19 | Input | Dry contact (LOW = active) |
| P3 | Digital Input 20 | Input | Dry contact (LOW = active) |
| P4 | Digital Input 21 | Input | Dry contact (LOW = active) |
| P5 | Digital Input 22 | Input | Dry contact (LOW = active) |
| P6 | Digital Input 23 | Input | Dry contact (LOW = active) |
| P7 | Digital Input 24 | Input | Dry contact (LOW = active) |
| P8 | Relay Output 1 | Output | Relay (LOW = ON) |
| P9 | Relay Output 2 | Output | Relay (LOW = ON) |
| P10 | Relay Output 3 | Output | Relay (LOW = ON) |
| P11 | Relay Output 4 | Output | Relay (LOW = ON) |
| P12 | Relay Output 5 | Output | Relay (LOW = ON) |
| P13 | Relay Output 6 | Output | Relay (LOW = ON) |
| P14 | Relay Output 7 | Output | Relay (LOW = ON) |
| P15 | Relay Output 8 | Output | Relay (LOW = ON) |

#### PCF8575 at Address `0x24` (Outputs 9-24)
This chip controls relay outputs 9-24 (active LOW).
| PCF8575 Pin | Connected Device | Type | Description |
| :--- | :--- | :--- | :--- |
| P0 | Relay Output 9 | Output | Relay (LOW = ON) |
| P1 | Relay Output 10 | Output | Relay (LOW = ON) |
| P2 | Relay Output 11 | Output | Relay (LOW = ON) |
| P3 | Relay Output 12 | Output | Relay (LOW = ON) |
| P4 | Relay Output 13 | Output | Relay (LOW = ON) |
| P5 | Relay Output 14 | Output | Relay (LOW = ON) |
| P6 | Relay Output 15 | Output | Relay (LOW = ON) |
| P7 | Relay Output 16 | Output | Relay (LOW = ON) |
| P8 | Relay Output 17 | Output | Relay (LOW = ON) |
| P9 | Relay Output 18 | Output | Relay (LOW = ON) |
| P10 | Relay Output 19 | Output | Relay (LOW = ON) |
| P11 | Relay Output 20 | Output | Relay (LOW = ON) |
| P12 | Relay Output 21 | Output | Relay (LOW = ON) |
| P13 | Relay Output 22 | Output | Relay (LOW = ON) |
| P14 | Relay Output 23 | Output | Relay (LOW = ON) |
| P15 | Relay Output 24 | Output | Relay (LOW = ON) |

## 2. Analog Input (ADS1115)
| Channel | Range | Description |
| :--- | :--- | :--- |
| A1 | DC 0-5V | Analog input channel 1 |
| A2 | DC 0-5V | Analog input channel 2 |
| A3 | DC 4-20mA | Analog input channel 3 (current loop) |
| A4 | DC 4-20mA | Analog input channel 4 (current loop) |

## 3. Free GPIOs (without pull-up resistance on PCB)
*   `GPIO13`
*   `GPIO14`
*   `GPIO21`

## 4. Free GPIOs (with pull-up resistance on PCB)
*   `GPIO40`
*   `GPIO48`
*   `GPIO47`
*   `GPIO7`

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