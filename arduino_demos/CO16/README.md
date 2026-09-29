# CO16 Arduino Examples

This directory contains Arduino example sketches for the **FeedCurrent CO16** controller. The CO16 is based on the ESP32‑S3 and features 16 relay outputs (PCF8575 @ 0x22), 16 digital inputs (PCA9555 @ 0x24), 16 analog inputs (4× ADS1115), 4 PT100 temperature inputs (MAX31865), Ethernet (W5500), RS485, RTC (DS3231), SD card, ST7789 TFT display, and I2C/SPI/UART communication.

## Available Examples

| # | Example Folder | Description |
|---|----------------|-------------|
| 01 | `01_turn_on_off_relay` | Sequentially turns on/off the 16 relay outputs (PCF8575 pins 0‑15) with a 200 ms delay. |
| 02 | `02_read_digital_inputs` | Reads the 16 digital input ports (PCA9555 @ 0x24) and prints the binary state every second. |
| 03 | `03_read_analog_inputs` | Reads 16 analog channels via four ADS1115 modules (0x48, 0x49, 0x4B, 0x4A). Only voltages >0.5 V are printed. |
| 04 | `04_rs485_test` | Simple RS485 communication test: sends a message every 3 seconds and prints received data. |
| 05 | `05_read_pt100_temperature` | Reads up to four PT100 sensors using MAX31865 and NX3L4051PW multiplexer. Prints raw, resistance, and temperature. |
| 06 | `06_sd_card` | Demonstrates basic SD card operations: mount, read/write/append/delete files, and performance test. |
| 07 | `07_ds3231_rtc` | Reads and sets the DS3231 RTC via serial commands (`current time` and `DYYYY-MM-DDTHH:MM:SS`). |
| 08 | `08_ethernet_tcp_server` | Sets up W5500 Ethernet as a TCP server (port 4196) that echoes back received data. |
| 09 | `09_input_trigger_output` | Directly links the 16 digital inputs (PCA9555) to the 16 relay outputs (PCF8575). Input LOW → relay ON. |
| 10 | `10_st7789_tft_display` | Drives the onboard ST7789 320×240 TFT display via SPI3 and Adafruit GFX. Shows text, color bars, and frame counter. |

## Common Hardware Configuration

The CO16 uses the following key pins:

| Function | GPIO / Address |
|----------|----------------|
| I2C SDA | GPIO8 |
| I2C SCL | GPIO18 |
| PCF8575 (relay outputs) | Address 0x22, pins 0‑15 |
| PCA9555/XL9535 (digital inputs) | Address 0x24, pins 0‑15 |
| ADS1115 #1 (CH1‑CH4) | Address 0x48 |
| ADS1115 #2 (CH5‑CH8) | Address 0x49 |
| ADS1115 #3 (CH9‑CH12) | Address 0x4B |
| ADS1115 #4 (CH13‑CH16) | Address 0x4A |
| DS3231 RTC | Address 0x68 |
| Ethernet W5500 | CLK=1, MOSI=2, MISO=41, CS=42, RST=44, INT=43 |
| RS485 | RX=38, TX=39 |
| SD Card SPI | SCK=11, MISO=12, MOSI=10, CS=9 |
| PT100 (MAX31865) | SCLK=11, MOSI=10, MISO=12, CS=14 |
| PT100 MUX | S1=7, S2=21 (S3 fixed LOW) |
| ST7789 TFT | SCLK=11, MOSI=10, MISO=12, CS=4, DC=0, RST=5, BL=40 |

For complete pin definitions, refer to `../pin_definitions/CO16/CO16_pin_definition.md`.

## Usage

1. Open any example folder.
2. Copy the `.ino` file to your Arduino IDE or ESPHome project.
3. Install required libraries as needed (e.g., `PCF8575`, `PCA95x5`, `DFRobot_ADS1115`, `Adafruit_MAX31865`, `DS3231`, `Ethernet`, `Adafruit_GFX`, etc.).
4. Select the board `esp32-s3-devkitc-1` and upload.

Each example folder contains a `README.md` with specific instructions, dependencies, and expected behavior.

## Precompiled Binaries

If available, each example folder also contains a `precompiled/` subdirectory with ready‑to‑flash `.bin` files. Use the ESP Flash Download Tool or `esptool.py` to flash them at address `0x0`.