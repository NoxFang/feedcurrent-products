# TA ESP32-S3 Pin Definition

## Overview
- **Product**: KinCony TA
- **MCU**: ESP32-S3
- **I/O Expander**: PCF8575 (16-bit) - 12 inputs + 2 relay outputs
- **Real-Time Clock**: DS3231
- **EEPROM**: 24C02
- **1-Wire Interfaces**: 12 channels
- **Network**: W5500 Ethernet + Tuya WiFi Module
- **Serial**: RS485
- **RF**: 433MHz Receiver
- **Power Supply**: 12-24V DC

---

## I2C Bus

| Signal | GPIO |
|--------|------|
| SDA    | GPIO8 |
| SCL    | GPIO18 |

### I2C Device Addresses

| Device    | Address | Function |
|-----------|---------|----------|
| PCF8575   | 0x22    | 12-channel digital input + 2-relay output |
| DS3231    | 0x68    | Real-Time Clock |
| 24C02     | 0x50    | EEPROM storage |

---

## PCF8575 Channel Mapping (Address: 0x22)

| PCF8575 Pin | Function | Direction | Description |
|-------------|----------|-----------|-------------|
| P0  (bit 0)  | IN-CH1  | INPUT  | Digital Input Channel 1 |
| P1  (bit 1)  | IN-CH2  | INPUT  | Digital Input Channel 2 |
| P2  (bit 2)  | IN-CH3  | INPUT  | Digital Input Channel 3 |
| P3  (bit 3)  | IN-CH4  | INPUT  | Digital Input Channel 4 |
| P4  (bit 4)  | IN-CH5  | INPUT  | Digital Input Channel 5 |
| P5  (bit 5)  | IN-CH6  | INPUT  | Digital Input Channel 6 |
| P6  (bit 6)  | IN-CH7  | INPUT  | Digital Input Channel 7 |
| P7  (bit 7)  | IN-CH8  | INPUT  | Digital Input Channel 8 |
| P8  (bit 8)  | IN-CH9  | INPUT  | Digital Input Channel 9 |
| P9  (bit 9)  | IN-CH10 | INPUT  | Digital Input Channel 10 |
| P10 (bit 10) | IN-CH11 | INPUT  | Digital Input Channel 11 |
| P11 (bit 11) | IN-CH12 | INPUT  | Digital Input Channel 12 |
| P12 (bit 12) | -       | -      | Not used |
| P13 (bit 13) | -       | -      | Not used |
| P14 (bit 14) | OUT-CH1 | OUTPUT | Relay Output Channel 1 (CH15) |
| P15 (bit 15) | OUT-CH2 | OUTPUT | Relay Output Channel 2 (CH16) |

> **Note**: Relay outputs are active-LOW (write LOW to energize relay).

---

## 1-Wire Interfaces (12 channels, pull-up resistors on PCB)

| 1-Wire Channel | GPIO |
|----------------|------|
| 1-Wire 1       | GPIO9  |
| 1-Wire 2       | GPIO11 |
| 1-Wire 3       | GPIO5  |
| 1-Wire 4       | GPIO4  |
| 1-Wire 5       | GPIO7  |
| 1-Wire 6       | GPIO6  |
| 1-Wire 7       | GPIO13 |
| 1-Wire 8       | GPIO40 |
| 1-Wire 9       | GPIO14 |
| 1-Wire 10      | GPIO48 |
| 1-Wire 11      | GPIO21 |
| 1-Wire 12      | GPIO47 |

> Suitable for DS18B20 temperature sensors and other 1-Wire devices.

---

## W5500 Ethernet Interface

| Signal        | GPIO   |
|---------------|--------|
| CLK           | GPIO1  |
| MOSI          | GPIO2  |
| MISO          | GPIO41 |
| CS            | GPIO42 |
| INTERRUPT     | GPIO43 |
| RESET         | GPIO44 |

- **Default IP**: 192.168.3.55
- **Subnet Mask**: 255.255.255.0
- **Gateway**: 192.168.3.1
- **TCP Port**: 4196

---

## RS485 Interface

| Signal | GPIO   |
|--------|--------|
| RXD    | GPIO38 |
| TXD    | GPIO39 |

- **Baud Rate**: 9600 (default)

---

## RF 433MHz Receiver

| Signal | GPIO   |
|--------|--------|
| DATA   | GPIO12 |

> Library: RCSwitch (https://github.com/sui77/rc-switch/)

---

## Tuya WiFi Module Interface

| Signal              | GPIO   |
|---------------------|--------|
| TXD (to Tuya RXD)   | GPIO16 |
| RXD (from Tuya TXD) | GPIO17 |
| Network Button      | Tuya P28 |
| Network LED         | Tuya P16 |

- **Baud Rate**: 9600
- **Protocol**: Tuya Serial Protocol (0x55 0xAA frame format)

---

## DS3231 RTC

- **I2C Address**: 0x68
- **SDA**: GPIO8 (shared I2C bus)
- **SCL**: GPIO18 (shared I2C bus)
- **Time Set Command**: `DYYYY-MM-DDTHH:MM:SS` (e.g., `D2024-09-19T11:50:22`)
- **Query Command**: `current time`

---

## Summary Table

| Function           | GPIO(s)                                       |
|--------------------|-----------------------------------------------|
| I2C SDA            | GPIO8                                         |
| I2C SCL            | GPIO18                                        |
| 1-Wire (12 ch)     | GPIO9,11,5,4,7,6,13,40,14,48,21,47           |
| W5500 CLK          | GPIO1                                         |
| W5500 MOSI         | GPIO2                                         |
| W5500 MISO         | GPIO41                                        |
| W5500 CS           | GPIO42                                        |
| W5500 INT          | GPIO43                                        |
| W5500 RST          | GPIO44                                        |
| RS485 RXD          | GPIO38                                        |
| RS485 TXD          | GPIO39                                        |
| RF433 DATA         | GPIO12                                        |
| Tuya TXD           | GPIO16                                        |
| Tuya RXD           | GPIO17                                        |

---

## Resources
- Product Forum: https://www.kincony.com/forum/forumdisplay.php?fid=76
- ESPHome Config: `TA_esphome.yaml`
