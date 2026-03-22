# TA Arduino Examples

This directory contains Arduino example sketches for the **FeedCurrent TA** controller. The TA is based on the ESP32‑S3 and features Ethernet, RS485, RF433 receiver, digital inputs via PCF8575, relay outputs, DS3231 RTC, and multiple free GPIOs.

## Available Examples

| # | Example Folder | Description |
|---|----------------|-------------|
| 01 | `01_turn_on_off_relay` | Controls 2 relays (PCF8575 pins 14,15) – alternately turns them ON/OFF every 2 seconds. |
| 02 | `02_read_digital_inputs` | Reads 12 digital inputs (PCF8575 pins 0‑11) and prints the binary state to Serial Monitor. |
| 03 | `03_rf433_decode` | Decodes 433 MHz RF signals using the rc‑switch library (GPIO12 interrupt). |
| 04 | `04_rs485_test` | Simple RS485 communication test: sends a message periodically and prints received data. |
| 05 | `05_read_free_gpio` | Monitors 12 free GPIOs (9,11,5,4,7,6,13,40,14,48,21,47) and prints their states. |
| 06 | `06_ds3231_rtc` | Reads and sets DS3231 RTC via serial commands. |
| 07 | `07_ethernet_tcp_server` | Sets up W5500 Ethernet as a TCP server (port 4196) that echoes back received data. |
| 08 | `08_tuya_communication` | Demonstrates UART communication with Tuya WiFi module (heartbeat, product info, etc.). |

## Common Hardware Configuration

The TA uses the following key pins:

| Function | GPIO |
|----------|------|
| I2C SDA (RTC, PCF8575, etc.) | GPIO8 |
| I2C SCL (RTC, PCF8575, etc.) | GPIO18 |
| PCF8575 I2C Address | 0x22 (inputs 0‑11, relays 14‑15) |
| Ethernet W5500 CLK | GPIO1 |
| Ethernet W5500 MOSI | GPIO2 |
| Ethernet W5500 MISO | GPIO41 |
| Ethernet W5500 CS | GPIO42 |
| Ethernet W5500 INT | GPIO43 |
| Ethernet W5500 RST | GPIO44 |
| RS485 RXD | GPIO38 |
| RS485 TXD | GPIO39 |
| RF433 Receiver | GPIO12 (interrupt) |
| Tuya WiFi Module TX | GPIO16 |
| Tuya WiFi Module RX | GPIO17 |
| Free GPIOs / 1‑Wire | See example 05 for details |

For complete pin definitions, refer to `../pin_definitions/TA/TA_pin_definition.md`.

## Usage

1. Open any example folder.
2. Copy the `.ino` file to your Arduino IDE or ESPHome project.
3. Install required libraries:
   - `PCF8575` for examples 01, 02
   - `RCSwitch` for example 03
   - `DS3231` for example 06
   - `U8g2` (not used in these examples, but if you add display code)
4. Select the board `esp32-s3-devkitc-1` and upload.

Each example folder contains a `README.md` with specific instructions, dependencies, and expected behavior.

