# DM8 Arduino Examples

This directory contains Arduino example sketches for the **FeedCurrent DM8** multi‑function controller. The DM8 is based on the ESP32‑S3 and features 8‑channel DAC (via Modbus to ARM CPU), 8 digital inputs (PCF8574), 4 analog inputs (ADS1115), Ethernet (W5500), RS485, RTC (DS3231), SD card, OLED display, and Tuya WiFi module.

## Available Examples

| # | Example Folder | Description |
|---|----------------|-------------|
| 01 | `01_dac_8ch` | Demonstrates 8‑channel DAC control via Modbus, with button input handling (PCF8574) for adjusting outputs. |
| 02 | `02_read_digital_inputs` | Reads the 8 digital input ports (PCF8574 pins P0–P7) and prints "KEYx PRESSED" when a key is pressed (active‑LOW). |
| 03 | `03_read_ads1115` | Reads voltage from all 4 ADS1115 analog input channels and prints the values in millivolts. |
| 04 | `04_rs485_test` | Simple RS485 communication test: sends a message every 3 seconds and prints any received data. |
| 05 | `05_read_free_gpio` | Monitors 8 free GPIO pins (40,7,48,47,13,14,21,0) for state changes and prints the results. |
| 06 | `06_sd_card` | Demonstrates basic SD card operations: mount, read/write/append/delete files, and performance test. |
| 07 | `07_ds3231_rtc` | Reads and sets the DS3231 RTC via serial commands (`current time` and `DYYYY-MM-DDTHH:MM:SS`). |
| 08 | `08_ethernet_tcp_server` | Sets up W5500 Ethernet as a TCP server (port 4196) that echoes back received data. |
| 09 | `09_tuya_communication` | Implements UART communication with the Tuya WiFi module (handles heartbeat, product info, etc.). |
| 10 | `10_oled_ssd1306` | Displays "FEEDCURRENT" and "www.feedcurrent.com" on the SSD1306 OLED display. |

## Common Hardware Configuration

The DM8 uses the following key pins:

| Function | GPIO / Address |
|----------|----------------|
| I2C SDA | GPIO8 |
| I2C SCL | GPIO18 |
| PCF8574 (inputs) | Address 0x24, pins P0‑P7 |
| ADS1115 ADC | Address 0x48 |
| Ethernet W5500 | CLK=1, MOSI=2, MISO=41, CS=42, INT=43, RST=44 |
| RS485 | RXD=38, TXD=39 |
| RTC (DS3231) | Address 0x68 |
| SD Card SPI | SCK=11, MISO=12, MOSI=10, CS=9 |
| OLED SSD1306 | Address 0x3C |
| Tuya WiFi | TX=16, RX=17 |
| Free GPIOs | See example 05 for details |

For complete pin definitions, refer to `../pin_definitions/DM8/DM8_pin_definition.md`.

## Usage

1. Open any example folder.
2. Copy the `.ino` file to your Arduino IDE or ESPHome project.
3. Install required libraries as needed (e.g., `PCF8574`, `Adafruit_PCF8574`, `DFRobot_ADS1115`, `RTC`, `U8g2`, etc.).
4. Select the board `esp32-s3-devkitc-1` and upload.

Each example folder contains a `README.md` with specific instructions, dependencies, and expected behavior.

## Precompiled Binaries

If available, each example folder also contains a `precompiled/` subdirectory with ready‑to‑flash `.bin` files. Use the ESP Flash Download Tool or `esptool.py` to flash them at address `0x0`.