# T128M ESP32-S3 IO Pin Definitions

## Overview
The T128M is a 128-channel digital I/O controller based on ESP32-S3, featuring 128 digital inputs and 128 digital outputs via PCF8575 I/O expanders across two independent I2C buses.

---

## Analog Input Pins

| Label | GPIO | Range | Description |
|-------|------|-------|-------------|
| A1 | GPIO7 | 0–5V | Voltage input channel 1 |
| A2 | GPIO6 | 0–5V | Voltage input channel 2 |
| A3 | GPIO5 | 4–20mA | Current input channel 3 |
| A4 | GPIO4 | 4–20mA | Current input channel 4 |

---

## I2C Bus 1 — Output Bus (GPIO48/GPIO47)

| Pin | GPIO |
|-----|------|
| SDA | GPIO48 |
| SCL | GPIO47 |

### PCF8575 Output Chips (128 Output Channels)

| I2C Address | Output Channels | Chip # |
|-------------|-----------------|--------|
| 0x27 | Output 1–16 | OUT Chip 1 |
| 0x26 | Output 17–32 | OUT Chip 2 |
| 0x23 | Output 33–48 | OUT Chip 3 |
| 0x22 | Output 49–64 | OUT Chip 4 |
| 0x25 | Output 65–80 | OUT Chip 5 |
| 0x24 | Output 81–96 | OUT Chip 6 |
| 0x21 | Output 97–112 | OUT Chip 7 |
| 0x20 | Output 113–128 | OUT Chip 8 |

### Other I2C Bus 1 Devices

| Device | I2C Address | Description |
|--------|-------------|-------------|
| 24C02 EEPROM | 0x50 | Non-volatile storage |

---

## I2C Bus 2 — Input Bus (GPIO12/GPIO11)

| Pin | GPIO |
|-----|------|
| SDA | GPIO12 |
| SCL | GPIO11 |

### PCF8575 Input Chips (128 Input Channels)

| I2C Address | Input Channels | Chip # |
|-------------|----------------|--------|
| 0x27 | Input 1–16 | IN Chip 1 |
| 0x26 | Input 17–32 | IN Chip 2 |
| 0x23 | Input 33–48 | IN Chip 3 |
| 0x22 | Input 49–64 | IN Chip 4 |
| 0x25 | Input 65–80 | IN Chip 5 |
| 0x24 | Input 81–96 | IN Chip 6 |
| 0x21 | Input 97–112 | IN Chip 7 |
| 0x20 | Input 113–128 | IN Chip 8 |

---

## RS485 Interface

| Signal | GPIO | Description |
|--------|------|-------------|
| RXD | GPIO21 | RS485 Receive |
| TXD | GPIO13 | RS485 Transmit |
| EN | GPIO14 | Direction control (HIGH=TX, LOW=RX) |

---

## Ethernet (W5500)

| Signal | GPIO | Description |
|--------|------|-------------|
| CLK | GPIO42 | SPI Clock |
| MOSI | GPIO43 | SPI Master Out Slave In |
| MISO | GPIO44 | SPI Master In Slave Out |
| CS | GPIO41 | SPI Chip Select |
| INT | GPIO2 | Interrupt |
| RST | GPIO1 | Reset |

---

## 1-Wire Bus (PCB Pull-up Resistors Installed)

| GPIO | Description |
|------|-------------|
| GPIO15 | 1-Wire bus pin 1 |
| GPIO16 | 1-Wire bus pin 2 |
| GPIO17 | 1-Wire bus pin 3 |
| GPIO18 | 1-Wire bus pin 4 |

---

## Free GPIO Pins

| GPIO | Description |
|------|-------------|
| GPIO8 | General purpose I/O |
| GPIO9 | General purpose I/O |
| GPIO10 | General purpose I/O |

---

## Architecture Summary

```
T128M ESP32-S3
│
├── I2C Bus 1 (SDA=GPIO48, SCL=GPIO47)
│   ├── PCF8575 @ 0x27  →  Output  1–16
│   ├── PCF8575 @ 0x26  →  Output 17–32
│   ├── PCF8575 @ 0x23  →  Output 33–48
│   ├── PCF8575 @ 0x22  →  Output 49–64
│   ├── PCF8575 @ 0x25  →  Output 65–80
│   ├── PCF8575 @ 0x24  →  Output 81–96
│   ├── PCF8575 @ 0x21  →  Output 97–112
│   ├── PCF8575 @ 0x20  →  Output 113–128
│   └── 24C02 EEPROM @ 0x50
│
├── I2C Bus 2 (SDA=GPIO12, SCL=GPIO11)
│   ├── PCF8575 @ 0x27  →  Input  1–16
│   ├── PCF8575 @ 0x26  →  Input 17–32
│   ├── PCF8575 @ 0x23  →  Input 33–48
│   ├── PCF8575 @ 0x22  →  Input 49–64
│   ├── PCF8575 @ 0x25  →  Input 65–80
│   ├── PCF8575 @ 0x24  →  Input 81–96
│   ├── PCF8575 @ 0x21  →  Input 97–112
│   └── PCF8575 @ 0x20  →  Input 113–128
│
├── Ethernet W5500 (SPI: CLK=42, MOSI=43, MISO=44, CS=41, INT=2, RST=1)
├── RS485 (RXD=21, TXD=13, EN=14)
├── Analog Inputs (A1=GPIO7, A2=GPIO6, A3=GPIO5, A4=GPIO4)
├── 1-Wire (GPIO15, GPIO16, GPIO17, GPIO18)
└── Free GPIO (GPIO8, GPIO9, GPIO10, GPIO0)
```
