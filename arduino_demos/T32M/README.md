# T32M Arduino Examples

This directory contains Arduino example sketches for the **FeedCurrent T32M** controller. The T32M is based on the ESP32‑S3 and features 32 relay outputs (two PCF8575 expanders), 32 digital inputs (two PCF8575 expanders), 4 analog inputs (ESP32 internal ADC), RS485 with direction control, Ethernet (W5500), and free GPIO.

## Available Examples

| # | Example Folder | Description |
|---|----------------|-------------|
| 01 | `01_turn_on_off_relay` | Sequentially turns on/off all 32 relays (first 1‑16, then 17‑32) with a 200 ms delay. |
| 02 | `02_read_digital_inputs` | Reads the 32 digital input ports (inputs 1‑16 @ 0x24, inputs 17‑32 @ 0x25) and prints the binary state every 500 ms. |
| 03 | `03_rs485_test` | RS485 communication test with direction control: sends a message every 3 s, toggles EN pin, and prints received data. |
| 04 | `04_read_free_gpio` | Monitors 8 free GPIO pins (8,9,10,15,16,17,18,0) for state changes and prints the results. |
| 05 | `05_ethernet_tcp_server` | Sets up W5500 Ethernet as a TCP server (port 4196) that echoes back received data. |
| 06 | `06_input_trigger_output` | Directly links the 32 digital inputs to the 32 relay outputs (active‑LOW logic). |
| 07 | `07_read_analog_inputs` | Reads the 4 analog inputs (GPIO7,6,5,4) using the ESP32‑S3 internal ADC and prints raw values every 2 s. |

## Common Hardware Configuration

The T32M uses the following key pins and I2C addresses:

| Function | GPIO / Address |
|----------|----------------|
| I2C SDA | GPIO48 |
| I2C SCL | GPIO47 |
| PCF8575 (inputs 1‑16) | Address 0x24, pins 0‑15 |
| PCF8575 (inputs 17‑32) | Address 0x25, pins 0‑15 |
| PCF8575 (outputs 1‑16) | Address 0x20, pins 0‑15 |
| PCF8575 (outputs 17‑32) | Address 0x21, pins 0‑15 |
| Analog inputs (ESP32 ADC) | A1=GPIO7, A2=GPIO6, A3=GPIO5, A4=GPIO4 |
| RS485 | TX=13, RX=21, EN=14 (direction control) |
| Ethernet W5500 | CLK=42, MOSI=43, MISO=44, CS=41, INT=2, RST=1 |
| Free GPIOs | See example 04 for details (GPIO8,9,10,15,16,17,18,0) |

For complete pin definitions, refer to `../pin_definitions/T32M/T32M_pin_definition.md`.

## Usage

1. Open any example folder.
2. Copy the `.ino` file to your Arduino IDE or ESPHome project.
3. Install required libraries as needed (e.g., `PCF8575`).
4. Select the board `esp32-s3-devkitc-1` and upload.

Each example folder contains a `README.md` with specific instructions, dependencies, and expected behavior.

## Precompiled Binaries

If available, each example folder also contains a `precompiled/` subdirectory with ready‑to‑flash `.bin` files. Use the ESP Flash Download Tool or `esptool.py` to flash them at address `0x0`.