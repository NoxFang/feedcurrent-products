# B8 Arduino Examples

This directory contains 11 Arduino example sketches for the **KinCony B8** controller - an 8-channel relay controller based on ESP32-S3.

## B8 Hardware Overview

- **MCU**: ESP32-S3-WROOM-1U
- **Outputs**: 8 Channel Relay (via PCF8575 I2C expander)
- **Inputs**: 8 Channel Digital Input (via PCF8575 I2C expander)
- **ADC**: 4-Channel 16-bit ADS1115
- **Communication**: Ethernet (W5500), RS485, I2C, UART
- **Storage**: SD Card (SPI)
- **Display**: SSD1306 128x64 OLED
- **RTC**: DS3231 Real-Time Clock
- **WiFi**: Tuya WiFi Module support
- **Free GPIOs**: 8 pins (4 with pull-up, 4 without)

## Example List

### 01. Sequential ON/OFF
Sequential control of 8 relay outputs.

### 02. Read Digital Inputs
Read 8 digital inputs.

### 03. Read ADS1115 ADC
Read 4 ADC channels.

### 04. RS485 Communication Test
RS485 communication test.

### 05. Read Free GPIO State
Monitor free GPIO pins.

### 06. SD Card Operations
SD card operations.

### 07. DS3231 RTC
Real-time clock interface.

### 08. Ethernet TCP Server
Ethernet TCP server.

### 09. Tuya Communication
Tuya WiFi communication.

### 10. OLED SSD1306
OLED display control.

### 11. Input Trigger Output
Input-to-output linking.

## Directory Structure

```
example_name/
├── src/
│   └── B8_XX_example_name.ino
├── precompiled/
│   └── B8_XX_example_name.bin
└── README.md
```

## Quick Start

**Precompiled**: Flash `.bin` to `0x0`

**Source**: Open in Arduino IDE, select `ESP32-S3 DevKitC-1`, upload

## Libraries

PCF8575, DFRobot_ADS1115, DS3231, Ethernet, U8g2, SD

## Hardware

- I2C: SDA=GPIO8, SCL=GPIO18
- Input: 0x22, Output: 0x24
- ADC: 0x48, OLED: 0x3C, RTC: 0x68

## Notes

- Active LOW logic
- GPIO0: boot mode pin
- Baud: 115200
