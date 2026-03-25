# T64M Arduino Examples

This directory contains Arduino example sketches for the **FeedCurrent T64M** controller. The T64M is based on the ESP32‑S3 and features 64 relay outputs (4× PCF8575), 64 digital inputs (4× PCF8575), 4 analog inputs (ESP32 internal ADC), RS485 with direction control, Ethernet (W5500), free GPIO, and an I2C scanner utility.

## Available Examples

| # | Example Folder | Description |
|---|----------------|-------------|
| 01 | `01_turn_on_off_relay` | Sequentially turns on/off all 64 outputs (1‑64) with a 200 ms delay. |
| 02 | `02_read_digital_inputs` | Reads the 64 digital input ports (grouped by 16‑bit blocks) and prints binary state every 500 ms. |
| 03 | `03_rs485_test` | RS485 communication test with direction control: sends a message every 3 s, toggles EN pin, and prints received data. |
| 04 | `04_read_free_gpio` | Monitors 8 free GPIO pins (8,9,10,15,16,17,18,0) for state changes and prints the results. |
| 05 | `05_ethernet_tcp_server` | Sets up W5500 Ethernet as a TCP server (port 4196) that echoes back received data. |
| 06 | `06_input_trigger_output` | Directly links the 64 digital inputs to the 64 relay outputs (active‑LOW logic), using two separate I2C buses. |
| 07 | `07_i2c_scanner` | Scans two independent I2C buses (output bus and input bus) and reports all detected device addresses. |
| 08 | `08_read_analog_inputs` | Reads the 4 analog inputs (GPIO7,6,5,4) using the ESP32‑S3 internal ADC and prints raw values every 2 s. |

## Common Hardware Configuration

The T64M uses two independent I2C buses and the following key pins:

### I2C Bus‑1 (Outputs – Relays)
| Signal | GPIO |
|--------|------|
| SDA    | 48   |
| SCL    | 47   |
| PCF8575 Addresses | Outputs 1‑16: 0x25<br>Outputs 17‑32: 0x24<br>Outputs 33‑48: 0x21<br>Outputs 49‑64: 0x20 |

### I2C Bus‑2 (Inputs)
| Signal | GPIO |
|--------|------|
| SDA    | 12   |
| SCL    | 11   |
| PCF8575 Addresses | Inputs 1‑16: 0x25<br>Inputs 17‑32: 0x24<br>Inputs 33‑48: 0x21<br>Inputs 49‑64: 0x20 |

### Other Peripherals
| Function | GPIO / Address |
|----------|----------------|
| Analog inputs (ESP32 ADC) | A1=GPIO7, A2=GPIO6, A3=GPIO5, A4=GPIO4 |
| RS485 | TX=13, RX=21, EN=14 (direction control) |
| Ethernet W5500 | CLK=42, MOSI=43, MISO=44, CS=41, INT=2, RST=1 |
| Free GPIOs | GPIO8,9,10,15,16,17,18,0 (see example 04) |

For complete pin definitions, refer to `../pin_definitions/T64M/T64M_pin_definition.md`.

## Usage

1. Open any example folder.
2. Copy the `.ino` file to your Arduino IDE or ESPHome project.
3. Install required libraries as needed (e.g., `PCF8575`).
4. Select the board `esp32-s3-devkitc-1` and upload.

Each example folder contains a `README.md` with specific instructions, dependencies, and expected behavior.

## Precompiled Binaries

If available, each example folder also contains a `precompiled/` subdirectory with ready‑to‑flash `.bin` files. Use the ESP Flash Download Tool or `esptool.py` to flash them at address `0x0`.