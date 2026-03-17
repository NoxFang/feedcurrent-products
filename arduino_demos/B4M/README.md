# B4M Arduino Examples

This directory contains 11 Arduino example sketches for the **KinCony B4M** controller - a 4-channel relay controller based on ESP32-S3.

## B4M Hardware Overview

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

**Key Features**:
- PCF8575 output control (address 0x24)
- Active LOW logic
- Sequential relay operation

---

### 02. Read Digital Inputs
**Directory**: `02_read_digital_inputs/`

Reads the state of all 4 digital inputs and displays them on the Serial Monitor.

**Key Features**:
- PCF8575 input reading (address 0x22)
- Real-time input monitoring
- Serial output at 115200 baud

---

### 03. Read ADS1115 ADC
**Directory**: `03_read_ads1115/`

Reads analog voltage from all 4 ADS1115 ADC channels (A0-A3).

**Key Features**:
- 16-bit ADC resolution
- ±6.144V input range
- I2C address 0x48

---

### 04. RS485 Communication Test
**Directory**: `04_rs485_communication_test/`

Tests RS485 communication by sending periodic messages.

**Key Features**:
- UART1 for RS485 (GPIO38=RX, GPIO39=TX)
- 9600 baud rate
- Bidirectional communication

---

### 05. Read Free GPIO State
**Directory**: `05_read_free_gpio/`

Monitors the state of 8 free GPIO pins.

**Key Features**:
- GPIO with pull-up: 48, 47, 40, 7
- GPIO without pull-up: 13, 14, 21, 0
- State change detection

---

### 06. SD Card Operations
**Directory**: `06_sd_card_operations/`

Demonstrates SD card read/write operations.

**Key Features**:
- SPI interface
- FAT16/FAT32 support
- File management

---

### 07. DS3231 RTC
**Directory**: `07_ds3231_rtc/`

Interface with the DS3231 real-time clock.

**Key Features**:
- I2C address 0x68
- Time setting via serial commands
- Temperature reading

---

### 08. Ethernet TCP Server
**Directory**: `08_ethernet_tcp_server/`

Sets up W5500 as a TCP server.

**Key Features**:
- Static IP configuration
- TCP port 4196
- W5500 SPI interface

---

### 09. Tuya Communication
**Directory**: `09_tuya_communication/`

UART communication with Tuya WiFi module.

**Key Features**:
- UART2 for Tuya (GPIO16=TX, GPIO17=RX)
- 9600 baud rate
- Tuya protocol support

---

### 10. OLED SSD1306
**Directory**: `10_oled_ssd1306/`

Displays text on 128x64 OLED.

**Key Features**:
- I2C address 0x3C
- U8g2 library support

---

### 11. Input Trigger Output
**Directory**: `11_input_trigger_output/`

Links inputs to outputs (1:1 mapping).

**Key Features**:
- Direct input-to-output mapping
- Active LOW logic
- Real-time response

## Directory Structure

Each example folder contains:

```
example_name/
├── src/
│   └── B4M_XX_example_name.ino    # Arduino source code
├── precompiled/
│   └── B4M_XX_example_name.bin    # Precompiled binary
└── README.md                       # Example documentation
```

## Quick Start

### Using Precompiled Binary

1. Navigate to the example folder
2. Flash the `.bin` file from `precompiled/` to address `0x0`

### Compiling from Source

1. Open `.ino` in Arduino IDE
2. Install required libraries
3. Select board: `ESP32-S3 DevKitC-1`
4. Compile and upload

## Required Libraries

- **PCF8575** by Rob Tillaart
- **DFRobot_ADS1115**
- **DS3231** by Eric Ayars
- **Ethernet** by Arduino
- **U8g2** by olikraus
- **SD** or **SD_MMC**

## Hardware Connections

### I2C Bus
- SDA: GPIO8
- SCL: GPIO18

### I2C Device Addresses
| Device | Address | Purpose |
|--------|---------|---------|
| PCF8575 | 0x22 | Inputs 1-4 |
| PCF8575 | 0x24 | Outputs 1-4 |
| ADS1115 | 0x48 | 4-Channel ADC |
| SSD1306 | 0x3C | OLED Display |
| DS3231 | 0x68 | Real-Time Clock |

## Notes

- All PCF8575 I/O pins use **active LOW** logic
- GPIO0 should not be pulled LOW during boot
- Default serial baud rate: 115200
