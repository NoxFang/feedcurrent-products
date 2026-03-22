# G1 Arduino Examples

This directory contains Arduino example sketches for the **FeedCurrent G1 (KC868-G1)** industrial gateway controller. The G1 is based on the ESP32‑S3 and features Ethernet, RS485, 4G (SIM7600), OLED display, digital inputs via PCF8575, and multiple free GPIOs.

## Available Examples

| # | Example Folder | Description |
|---|----------------|-------------|
| 01 | `01_read_digital_inputs` | Reads 16 digital inputs via PCF8575 (I2C address 0x24) and prints the state to the Serial Monitor in binary format. |
| 02 | `02_read_free_gpio` | Monitors 11 free GPIO pins (15,16,17,40,13,14,21,4,5,6,7) for state changes and prints the results. |
| 03 | `03_ethernet_tcp_server` | Sets up the W5500 Ethernet module as a TCP server (port 4196) that echoes back any received data. |
| 04 | `04_rs485_test` | Simple RS485 communication test: sends a message periodically and prints any received data. |
| 05 | `05_gsm_test` | Bidirectional serial bridge between USB (Serial Monitor) and the SIM7600 4G module for AT command testing. |
| 06 | `06_oled_ssd1306` | Displays "FEEDCURRENT" and "www.feedcurrent.com" on the SSD1306 OLED (I2C address 0x3C). |

## Common Hardware Configuration

The G1 uses the following key pins:

| Function | GPIO |
|----------|------|
| I2C SDA (OLED, PCF8575) | GPIO12 |
| I2C SCL (OLED, PCF8575) | GPIO11 |
| Ethernet W5500 CLK | GPIO42 |
| Ethernet W5500 MOSI | GPIO43 |
| Ethernet W5500 MISO | GPIO44 |
| Ethernet W5500 CS | GPIO41 |
| Ethernet W5500 INT | GPIO2 |
| Ethernet W5500 RST | GPIO1 |
| RS485 RXD | GPIO18 |
| RS485 TXD | GPIO8 |
| SIM7600 RXD | GPIO9 |
| SIM7600 TXD | GPIO10 |
| Free GPIO / 1‑Wire | See example 02 for details |

For complete pin definitions, refer to `../pin_definitions/G1/G1_pin_definition.md`.

## Usage

1. Open any example folder.
2. Copy the `.ino` file to your Arduino IDE or ESPHome project.
3. Install required libraries (e.g., `PCF8575` for example 01, `U8g2` for example 06).
4. Select the board `esp32-s3-devkitc-1` and upload.

Each example folder contains a `README.md` with specific instructions, dependencies, and expected behavior.

## Precompiled Binaries

If available, each example folder also contains a `precompiled/` subdirectory with ready‑to‑flash `.bin` files. Use the ESP Flash Download Tool or `esptool.py` to flash them at address `0x0`.


*Last updated: 2026‑03‑22*