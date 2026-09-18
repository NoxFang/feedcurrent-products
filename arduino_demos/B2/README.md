# B4 Arduino Examples

This directory contains 11 Arduino example sketches for the **KinCony B4** controller - a 4-channel relay controller based on ESP32-S3.

## B4 Hardware Overview

- **MCU**: ESP32-S3-WROOM-1U
- **Outputs**: 4 Channel Relay (via PCF8575 I2C expander)
- **Inputs**: 4 Channel Digital Input (via PCF8575 I2C expander)
- **ADC**: 4-Channel 16-bit ADS1115
- **Communication**: Ethernet (W5500), RS485, I2C, UART
- **Storage**: SD Card (SPI)
- **Display**: SSD1306 128x64 OLED
- **RTC**: DS3231 Real-Time Clock
- **WiFi**: Tuya WiFi Module support
- **Free GPIOs**: 8 pins (4 with pull-up, 4 without)

## Example List

### 01. Sequential ON/OFF
**Directory**: `01_sequential_on_off/`

Demonstrates sequential control of all 4 relay outputs.

---

### 02. Read Digital Inputs
**Directory**: `02_read_digital_inputs/`

Reads the state of all 4 digital inputs.

---

### 03. Read ADS1115 ADC
**Directory**: `03_read_ads1115/`

Reads analog voltage from 4 ADC channels.

---

### 04. RS485 Communication Test
**Directory**: `04_rs485_communication_test/`

Tests RS485 communication.

---

### 05. Read Free GPIO State
**Directory**: `05_read_free_gpio/`

Monitors 8 free GPIO pins.

---

### 06. SD Card Operations
**Directory**: `06_sd_card_operations/`

SD card read/write operations.

---

### 07. DS3231 RTC
**Directory**: `07_ds3231_rtc/`

Real-time clock interface.

---

### 08. Ethernet TCP Server
**Directory**: `08_ethernet_tcp_server/`

W5500 TCP server setup.

---

### 09. Tuya Communication
**Directory**: `09_tuya_communication/`

Tuya WiFi module communication.

---

### 10. OLED SSD1306
**Directory**: `10_oled_ssd1306/`

OLED display control.

---

### 11. Input Trigger Output
**Directory**: `11_input_trigger_output/`

Direct input-to-output linking.

## Directory Structure

```
example_name/
├── src/
│   └── B4_XX_example_name.ino
├── precompiled/
│   └── B4_XX_example_name.bin
└── README.md
```

## Quick Start

### Using Precompiled Binary
Flash `.bin` from `precompiled/` to address `0x0`.

### Compiling from Source
1. Open `.ino` in Arduino IDE
2. Install libraries
3. Select `ESP32-S3 DevKitC-1`
4. Compile and upload

## Required Libraries

- PCF8575, DFRobot_ADS1115, DS3231, Ethernet, U8g2, SD

## Hardware Connections

- I2C: SDA=GPIO8, SCL=GPIO18
- PCF8575 Input: 0x22, Output: 0x24
- ADS1115: 0x48, OLED: 0x3C, RTC: 0x68

## Notes

- PCF8575 uses **active LOW** logic
- GPIO0: do not pull LOW during boot
- Serial baud: 115200
