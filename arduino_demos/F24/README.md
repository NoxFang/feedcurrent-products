# F24 Arduino Examples

This directory contains Arduino example sketches for the **FeedCurrent F24** controller. The F24 is based on the ESP32‑S3 and features 24 relay outputs (two PCF8575 expanders), 24 digital inputs (two PCF8575 expanders), 4 analog inputs (ESP32 internal ADC), Ethernet (W5500), RS485, RTC (DS3231), SD card, OLED display, and Tuya WiFi module.

## Available Examples

| # | Example Folder | Description |
|---|----------------|-------------|
| 01 | `01_turn_on_off_relay` | Sequentially turns on/off all 24 relays (first relays 1‑8, then 9‑24) with a 200 ms delay. |
| 02 | `02_read_digital_inputs` | Reads the 24 digital input ports (inputs 1‑16 @ 0x24, inputs 17‑24 @ 0x26) and prints the binary state every 500 ms. |
| 03 | `03_read_analog_inputs` | Reads the 4 analog inputs (GPIO5,7,6,4) using the ESP32‑S3 internal ADC and prints raw values every 2 s. |
| 04 | `04_rs485_test` | Simple RS485 communication test: sends a message every 3 s and prints received data. |
| 05 | `05_read_free_gpio` | Monitors 8 free GPIO pins (48,47,21,15,14,13,12,40) for state changes and prints the results. |
| 06 | `06_sd_card` | Demonstrates basic SD card operations: mount, read/write/append/delete files, and performance test. |
| 07 | `07_ds3231_rtc` | Reads and sets the DS3231 RTC via serial commands (`current time` and `DYYYY-MM-DDTHH:MM:SS`). |
| 08 | `08_ethernet_tcp_server` | Sets up W5500 Ethernet as a TCP server (port 4196) that echoes back received data. |
| 09 | `09_tuya_communication` | Implements UART communication with the Tuya WiFi module (handles heartbeat, product info, etc.). |
| 10 | `10_oled_ssd1306` | Displays "FEEDCURRENT" and "www.feedcurrent.com" on the SSD1306 OLED display. |
| 11 | `11_input_trigger_output` | Directly links the 24 digital inputs to the 24 relay outputs (active‑LOW logic). |
| 12 | `12_control_single_relay` | Toggles relay 24 every 2 s to demonstrate individual relay control. |

## Common Hardware Configuration

The F24 uses the following key pins and I2C addresses:

| Function | GPIO / Address |
|----------|----------------|
| I2C SDA | GPIO8 |
| I2C SCL | GPIO18 |
| PCF8575 (inputs 1‑16) | Address 0x24, pins 0‑15 |
| PCF8575 (inputs 17‑24) | Address 0x26, pins 8‑15 |
| PCF8575 (relays 1‑8) | Address 0x26, pins 0‑7 |
| PCF8575 (relays 9‑24) | Address 0x25, pins 0‑15 |
| Analog inputs (ESP32 ADC) | A1=GPIO5, A2=GPIO7, A3=GPIO6, A4=GPIO4 |
| Ethernet W5500 | CLK=42, MOSI=43, MISO=44, CS=41, INT=2, RST=1 |
| RS485 | RXD=17, TXD=16 (as used in example 04) |
| RTC (DS3231) | Address 0x68 |
| SD Card SPI | SCK=11, MISO=12, MOSI=10, CS=9 |
| OLED SSD1306 | Address 0x3C |
| Tuya WiFi | TX=39, RX=38 (as used in example 09) |
| Free GPIOs | See example 05 for details |

For complete pin definitions, refer to `../pin_definitions/F24/F24_pin_definition.md`.

## Usage

1. Open any example folder.
2. Copy the `.ino` file to your Arduino IDE or ESPHome project.
3. Install required libraries as needed (e.g., `PCF8575`, `U8g2`, `DS3231`, etc.).
4. Select the board `esp32-s3-devkitc-1` and upload.

Each example folder contains a `README.md` with specific instructions, dependencies, and expected behavior.

## Precompiled Binaries

If available, each example folder also contains a `precompiled/` subdirectory with ready‑to‑flash `.bin` files. Use the ESP Flash Download Tool or `esptool.py` to flash them at address `0x0`.