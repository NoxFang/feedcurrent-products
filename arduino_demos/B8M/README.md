# B8M Arduino Examples

This directory contains 11 Arduino example sketches for the **KinCony B8M** controller - an 8-channel relay controller based on ESP32-S3.

## B8M Hardware Overview

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
**Directory**: `01_sequential_on_off/`

Sequential control of 8 relay outputs.

---

### 02. Read Digital Inputs
**Directory**: `02_read_digital_inputs/`

Read 8 digital inputs.

---

### 03. Read ADS1115 ADC
**Directory**: `03_read_ads1115/`

Read 4 ADC channels.

---

### 04. RS485 Communication Test
**Directory**: `04_rs485_communication_test/`

RS485 communication test.

---

### 05. Read Free GPIO State
**Directory**: `05_read_free_gpio/`

Monitor free GPIO pins.

---

### 06. SD Card Operations
**Directory**: `06_sd_card_operations/`

SD card operations.

---

### 07. DS3231 RTC
**Directory**: `07_ds3231_rtc/`

Real-time clock interface.

---

### 08. Ethernet TCP Server
**Directory**: `08_ethernet_tcp_server/`

Ethernet TCP server.

---

### 09. Tuya Communication
**Directory**: `09_tuya_communication/`

Tuya WiFi communication.

---

### 10. OLED SSD1306
**Directory**: `10_oled_ssd1306/`

OLED display control.

---

### 11. Input Trigger Output
**Directory**: `11_input_trigger_output/`

Input-to-output linking.

## Directory Structure

```
example_name/
├── src/
│   └── B8M_XX_example_name.ino
├── precompiled/
│   └── B8M_XX_example_name.bin
└── README.md
```

## Quick Start

### Precompiled Binary
Flash `.bin` to address `0x0`.

### From Source
1. Open in Arduino IDE
2. Install libraries
3. Select `ESP32-S3 DevKitC-1`
4. Upload

## Required Libraries

PCF8575, DFRobot_ADS1115, DS3231, Ethernet, U8g2, SD

## Hardware

- I2C: SDA=GPIO8, SCL=GPIO18
- Input: 0x22, Output: 0x24
- ADC: 0x48, OLED: 0x3C, RTC: 0x68

## Notes

- Active LOW logic
- GPIO0: boot mode pin
- Baud: 115200
