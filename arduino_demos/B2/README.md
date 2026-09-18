# B2 Arduino Examples

This directory contains 11 Arduino example sketches for the **FeedCurrent B2** controller – a compact 2-channel relay controller based on ESP32-S3.

## B2 Hardware Overview

- **MCU**: ESP32-S3
- **Outputs**: 2 Channel Relay (direct GPIO control, active‑LOW)
- **Inputs**: 2 Channel Digital Input (direct GPIO, with/without pull‑up)
- **ADC**: 4-Channel 16-bit ADS1115 (I2C)
- **Communication**: Ethernet (W5500), RS485, I2C, UART
- **Storage**: SD Card (SPI)
- **Display**: SSD1306 128×64 OLED (I2C)
- **RTC**: DS3231 Real-Time Clock (I2C)
- **WiFi**: Tuya WiFi Module support (UART)
- **Free GPIOs**: 4 pins (GPIO47, GPIO48, GPIO17, GPIO40)

## Example List

### 01. Turn ON/OFF Relay
**Directory**: `01_turn_on_off_relay/`

Controls the 2 relays sequentially (ON/OFF patterns).

---

### 02. Read Digital Inputs
**Directory**: `02_read_digital_inputs/`

Reads the state of the 2 digital inputs (GPIO6, GPIO7) and prints changes.

---

### 03. Read ADS1115 ADC
**Directory**: `03_read_ads1115/`

Reads analog voltage from 4 ADS1115 channels (A0–A3) in millivolts.

---

### 04. RS485 Communication Test
**Directory**: `04_rs485_test/`

Sends a test message over RS485 and prints any received data.

---

### 05. Read Free GPIO State
**Directory**: `05_read_free_gpio/`

Monitors 4 free GPIO pins (47, 48, 17, 40) for state changes.

---

### 06. SD Card Operations
**Directory**: `06_sd_card/`

Demonstrates SD card file read/write/append/delete and performance test.

---

### 07. DS3231 RTC
**Directory**: `07_ds3231_rtc/`

Reads and sets the DS3231 real-time clock via serial commands.

---

### 08. Ethernet TCP Server
**Directory**: `08_ethernet_tcp_server/`

Configures W5500 Ethernet as a TCP server (port 4196) that echoes received data.

---

### 09. Tuya Communication
**Directory**: `09_tuya_communication/`

Implements UART communication with a Tuya WiFi module (heartbeat, product info, etc.).

---

### 10. OLED SSD1306
**Directory**: `10_oled_ssd1306/`

Displays “FEEDCURRENT” and “www.feedcurrent.com” on the onboard OLED.

---

### 11. Input Trigger Output
**Directory**: `11_input_trigger_output/`

Directly links the 2 digital inputs to the 2 relays (input HIGH → relay ON).

## Directory Structure
```cpp
example_name/
├── src/
│ └── B2_XX_example_name.ino
├── precompiled/
│ └── B2_XX_example_name.bin
└── README.md
```

## Quick Start

### Using Precompiled Binary
Flash the `.bin` file from `precompiled/` to address `0x0` using ESP Flash Download Tool or `esptool.py`.

### Compiling from Source
1. Open the `.ino` file in Arduino IDE.
2. Install the required libraries (see below).
3. Select the board `ESP32-S3-DevKitC-1`.
4. Compile and upload.

## Required Libraries

- `DFRobot_ADS1115` (for example 03)
- `DS3231` (for example 07)
- `Ethernet` (for example 08)
- `U8g2` (for example 10)
- `SD`, `SPI`, `Wire` (built‑in)

## Hardware Connections

| Interface | Pins / Address |
|-----------|----------------|
| I2C (OLED, RTC, ADS1115) | SDA = GPIO8, SCL = GPIO18 |
| ADS1115 | I2C address 0x48 or 0x49 (check module) |
| OLED | I2C address 0x3C |
| RTC (DS3231) | I2C address 0x68 |
| Relays | Relay 1 = GPIO4, Relay 2 = GPIO46 (active‑LOW) |
| Digital Inputs | DI1 = GPIO6, DI2 = GPIO7 |
| RS485 | RX = GPIO39, TX = GPIO38 |
| SD Card | SCK = GPIO11, MISO = GPIO12, MOSI = GPIO10, CS = GPIO9 |
| Ethernet (W5500) | CLK = GPIO1, MOSI = GPIO2, MISO = GPIO41, CS = GPIO42, RST = GPIO44, INT = GPIO43 |
| Tuya Module | TX = GPIO15, RX = GPIO16 |
| Free GPIOs | GPIO47, GPIO48, GPIO17, GPIO40 |

## Notes

- Relays are **active‑LOW** (`LOW` = ON, `HIGH` = OFF).
- Digital inputs (GPIO6, GPIO7) are configured as plain `INPUT`; add external pull‑up/pull‑down or change to `INPUT_PULLUP` as needed.
- GPIO0 is used for boot mode; avoid pulling it LOW during power‑up.
- Serial Monitor baud rate: **115200**.
- Some code comments may mention incorrect pin numbers – always refer to the actual `#define` values in the source.