# B32M Arduino Examples

This directory contains 11 Arduino example sketches for the **KinCony B32M** controller - a 32-channel MOSFET controller based on ESP32-S3.

## B32M Hardware Overview

- **MCU**: ESP32-S3-WROOM-1U (N16R8)
- **Outputs**: 32 Channel MOSFET (via PCF8575 I2C expanders)
- **Inputs**: 32 Channel Digital Input (via PCF8575 I2C expanders)
- **ADC**: 4-Channel 16-bit ADS1115
- **Communication**: Ethernet (W5500), RS485, I2C, UART
- **Storage**: SD Card (SPI)
- **Display**: SSD1306 128x64 OLED
- **RTC**: DS3231 Real-Time Clock
- **WiFi**: Tuya WiFi Module support
- **Free GPIOs**: 8 pins (4 with pull-up, 4 without)

## Example List

### 01. Turn ON/OFF OUTPUT
**Directory**: `01_turn_on_off_output/`

Demonstrates sequential control of all 32 MOSFET outputs. Each output turns on for 200ms in sequence, then all turn off in sequence.

**Key Features**:
- PCF8575 output control (addresses 0x24, 0x25, 0x26)
- Active LOW logic
- Sequential relay operation

---

### 02. Read Digital Input
**Directory**: `02_read_digital_input/`

Reads the state of all 32 digital inputs and displays them on the Serial Monitor.

**Key Features**:
- PCF8575 input reading (addresses 0x22, 0x25, 0x26)
- Real-time input monitoring
- Serial output at 115200 baud

---

### 03. Read ADS1115 ADC
**Directory**: `03_read_ads1115/`

Reads analog voltage from all 4 ADS1115 ADC channels (A0-A3) and displays values in millivolts.

**Key Features**:
- 16-bit ADC resolution
- ±6.144V input range
- I2C address 0x48

---

### 04. RS485 Communication Test
**Directory**: `04_rs485_test/`

Tests RS485 communication by sending periodic messages and echoing received data.

**Key Features**:
- UART1 for RS485 (GPIO38=RX, GPIO39=TX)
- 9600 baud rate
- Bidirectional communication test

---

### 05. Read Free GPIO State
**Directory**: `05_read_free_gpio/`

Monitors the state of 8 free GPIO pins and reports changes.

**Key Features**:
- GPIO with pull-up: 48, 47, 40, 7 (suitable for 1-Wire)
- GPIO without pull-up: 13, 14, 21, 0
- State change detection

---

### 06. SD Card Operations
**Directory**: `06_sd_card/`

Demonstrates SD card read/write operations including file creation, reading, appending, and directory listing.

**Key Features**:
- SPI interface (GPIO9=CS, GPIO10=MOSI, GPIO11=CLK, GPIO12=MISO)
- FAT16/FAT32 support
- File management operations

---

### 07. DS3231 RTC Clock
**Directory**: `07_ds3231_rtc/`

Interface with the DS3231 real-time clock for time reading and setting.

**Key Features**:
- I2C address 0x68
- Serial commands for time setting
- Temperature reading

---

### 08. Ethernet TCP Server
**Directory**: `08_ethernet_tcp_server/`

Sets up the W5500 Ethernet module as a TCP server that echoes back received data.

**Key Features**:
- Static IP configuration (default: 192.168.1.100)
- TCP port 4196
- W5500 SPI interface

---

### 09. Tuya WiFi Communication
**Directory**: `09_tuya_communication/`

Implements UART communication protocol with the Tuya WiFi module.

**Key Features**:
- UART2 for Tuya (GPIO16=TX, GPIO17=RX)
- 9600 baud rate
- Basic Tuya protocol handling

---

### 10. OLED SSD1306 Display
**Directory**: `10_oled_ssd1306/`

Displays text and graphics on the 128x64 SSD1306 OLED display.

**Key Features**:
- I2C address 0x3C
- U8g2 library support
- Multiple display pages

---

### 11. Input Trigger Output
**Directory**: `11_input_trigger_output/`

Directly links digital inputs to outputs - when an input is triggered (GND), the corresponding output activates.

**Key Features**:
- Input-to-output mapping (1:1)
- Active LOW logic
- Real-time response

## Directory Structure

Each example folder contains:

```
example_name/
├── src/
│   └── B32M_XX_example_name.ino    # Arduino source code
├── precompiled/
│   └── B32M_XX_example_name.bin    # Precompiled binary
└── README.md                        # Example documentation
```

## Quick Start

### Using Precompiled Binary

1. Navigate to the example folder (e.g., `01_turn_on_off_output/`)
2. Flash the `.bin` file from `precompiled/` directory to address `0x0` using:
   - ESP Flash Download Tool
   - `esptool.py`: `esptool.py write_flash 0x0 B32M_01_turn_on_off_output.bin`

### Compiling from Source

1. Open the `.ino` file in Arduino IDE
2. Install required libraries (see individual README files)
3. Select board: `ESP32-S3 DevKitC-1`
4. Compile and upload

## Required Libraries

Most examples require these libraries:
- **PCF8575** by Rob Tillaart (for I/O expander control)
- **DFRobot_ADS1115** (for ADC examples)
- **DS3231** by Eric Ayars (for RTC example)
- **Ethernet** by Arduino (for Ethernet example)
- **U8g2** by olikraus (for OLED example)
- **SD** or **SD_MMC** (built-in, for SD card example)

## Hardware Connections

### I2C Bus (All I2C devices)
- SDA: GPIO8
- SCL: GPIO18
- Frequency: 400kHz

### I2C Device Addresses
| Device | Address | Purpose |
|--------|---------|---------|
| PCF8575 | 0x22 | Input 1-16 |
| PCF8575 | 0x25 | Input 17-24, Output 9-16 |
| PCF8575 | 0x24 | Output 17-24 |
| PCF8575 | 0x26 | Input 25-32, Output 1-8, 25-32 |
| ADS1115 | 0x48 | 4-Channel ADC |
| SSD1306 | 0x3C | OLED Display |
| DS3231 | 0x68 | Real-Time Clock |

### Other Interfaces
- **Ethernet**: SPI (GPIO1=CLK, GPIO2=MOSI, GPIO41=MISO, GPIO42=CS)
- **RS485**: UART1 (GPIO38=RX, GPIO39=TX)
- **SD Card**: SPI (GPIO9=CS, GPIO10=MOSI, GPIO11=CLK, GPIO12=MISO)
- **Tuya**: UART2 (GPIO16=TX, GPIO17=RX)

## Notes

- All PCF8575 I/O pins use **active LOW** logic
- GPIO0 should not be pulled LOW during boot (boot mode pin)
- Default serial baud rate: 115200
- All examples tested on ESP32-S3 with Arduino framework