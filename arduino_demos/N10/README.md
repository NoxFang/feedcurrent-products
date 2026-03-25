# N10 Arduino Examples

This directory contains Arduino example sketches for the **FeedCurrent N10** controller. The N10 is based on the ESP32‑S3 and features RS485 Modbus data acquisition (up to 60 channels), SD card, Ethernet (W5500), OLED display, and free digital I/O.

## Example 05 Special Notes (Modbus Data Collection)

- **Library installation**: Before running the code, you must install the `NonBlockingModbusMaster` Arduino library.
- **Library modification**: Before compiling example 05, modify the `NonBlockingModbusMaster` library header to handle large responses:
  ```cpp
  static const uint8_t maxTXLen = 254;
  static const uint8_t ku8MaxBuffersize = 126;
- **Modbus addressing**: Each meter chip occupies 100 holding registers (starting at 100, 200, …, 600). The example reads 68 registers per chip.
- **Data scaling**: See the example’s README for scaling factors (e.g., current × 0.001 → Amps).

## Available Examples

| # | Example Folder | Description |
|---|----------------|-------------|
| 01 | `01_read_digital_inputs` | Reads two free digital inputs (GPIO15, GPIO16) and prints their state every 500 ms. |
| 02 | `02_sd_card` | Demonstrates SD card operations: mount, read/write/append/delete files, and performance test. |
| 03 | `03_ethernet_tcp_server` | Sets up W5500 Ethernet as a TCP server (port 4196) that echoes back received data. |
| 04 | `04_oled_ssd1306` | Displays "FEEDCURRENT" and "www.feedcurrent.com" on the SSD1306 OLED display. |
| 05 | `05_collect_all_data` | Reads electrical parameters (current, power, energy, voltage, frequency, temperature, power factor) from up to 6 energy‑meter chips via RS485 Modbus. |

## Common Hardware Configuration

The N10 uses the following key pins and I2C addresses:

| Function | GPIO / Address |
|----------|----------------|
| Free digital inputs | GPIO15, GPIO16 (example 01) |
| SD Card SPI | SCK=39, MISO=38, MOSI=40, CS=48 |
| Ethernet W5500 | CLK=42, MOSI=43, MISO=44, CS=41, INT=2, RST=1 |
| OLED SSD1306 | SCL=17, SDA=18, I2C address 0x3C |
| RS485 Modbus (DE control) | DE=3, TX=8, RX=18 (direction control) |
| Modbus UART (actual data) | RX=9, TX=10 (UART2, used in example 05) |

For complete pin definitions, refer to `../pin_definitions/N10/N10_pin_definition.md`.

## Usage

1. Open any example folder.
2. Copy the `.ino` file to your Arduino IDE or ESPHome project.
3. Install required libraries as needed:
   - `PCF8575` for relay/input examples (not used in N10 examples)
   - `U8g2` for OLED display (example 04)
   - `TaskScheduler` and `NonBlockingModbusMaster` for Modbus data collection (example 05)
4. Select the board `esp32-s3-devkitc-1` and upload.

Each example folder contains a `README.md` with specific instructions, dependencies, and expected behavior.

## Precompiled Binaries

If available, each example folder also contains a `precompiled/` subdirectory with ready‑to‑flash `.bin` files. Use the ESP Flash Download Tool or `esptool.py` to flash them at address `0x0`.
