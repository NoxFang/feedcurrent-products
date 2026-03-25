# T16M Arduino Examples

This directory contains Arduino example sketches for the **FeedCurrent T16M** controller. The T16M is based on the ESP32‑S3 and features 16 relay outputs (PCF8575 @ 0x25), 16 digital inputs (PCF8575 @ 0x24), RS485, Ethernet (W5500), and free GPIO.

## Available Examples

| # | Example Folder | Description |
|---|----------------|-------------|
| 01 | `01_turn_on_off_relay` | Sequentially turns on/off the 16 relay outputs (PCF8575 pins 0‑15) with a 200 ms delay. |
| 02 | `02_read_digital_inputs` | Reads the 16 digital input ports (PCF8575 pins 0‑15) and prints the binary state every 500 ms. |
| 03 | `03_rs485_test` | Simple RS485 communication test: sends a message every 3 s and prints received data. |
| 04 | `04_read_free_gpio` | Monitors 8 free GPIO pins (8,9,10,15,16,17,18,0) for state changes and prints the results. |
| 05 | `05_ethernet_tcp_server` | Sets up W5500 Ethernet as a TCP server (port 4196) that echoes back received data. |
| 06 | `06_input_trigger_output` | Directly links the 16 digital inputs to the 16 relay outputs (active‑LOW logic). |

## Common Hardware Configuration

The T16M uses the following key pins and I2C addresses:

| Function | GPIO / Address |
|----------|----------------|
| I2C SDA | GPIO11 |
| I2C SCL | GPIO12 |
| PCF8575 (inputs) | Address 0x24, pins 0‑15 |
| PCF8575 (outputs) | Address 0x25, pins 0‑15 |
| RS485 | RXD=14, TXD=13 (as used in example 03) |
| Ethernet W5500 | CLK=42, MOSI=43, MISO=44, CS=41, INT=2, RST=1 |
| Free GPIOs | See example 04 for details (GPIO8,9,10,15,16,17,18,0) |

For complete pin definitions, refer to `../pin_definitions/T16M/T16M_pin_definition.md`.

## Usage

1. Open any example folder.
2. Copy the `.ino` file to your Arduino IDE or ESPHome project.
3. Install required libraries as needed (e.g., `PCF8575`).
4. Select the board `esp32-s3-devkitc-1` and upload.

Each example folder contains a `README.md` with specific instructions, dependencies, and expected behavior.

## Precompiled Binaries

If available, each example folder also contains a `precompiled/` subdirectory with ready‑to‑flash `.bin` files. Use the ESP Flash Download Tool or `esptool.py` to flash them at address `0x0`.