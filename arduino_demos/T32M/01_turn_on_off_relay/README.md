# T32M Arduino Example 01: Turn ON/OFF Relay

## Description
This example demonstrates sequential control of the 32 relays on the T32M board using two PCF8575 I/O expanders.  
- Relays 1‑16 are controlled via the first PCF8575 (address `0x20`).  
- Relays 17‑32 are controlled via the second PCF8575 (address `0x21`).  

The sequence:
1. Turn on relays 1‑16 one by one (200 ms interval).
2. Turn on relays 17‑32 one by one (200 ms interval).
3. Turn off relays 1‑16 one by one (200 ms interval).
4. Turn off relays 17‑32 one by one (200 ms interval).
5. Repeat indefinitely.

## File Structure
- `src/T32M_01_turn_on_off_relay.ino` – Arduino source code.
- `precompiled/T32M_01_turn_on_off_relay.bin` – Precompiled firmware binary for ESP32‑S3.

## Using the Precompiled Binary
Flash `precompiled/T32M_01_turn_on_off_relay.bin` to address `0x0` using ESP Flash Download Tool or `esptool.py`.

## Compiling from Source
- **Environment**: Arduino IDE with ESP32‑S3 board support.
- **Dependencies**: Install `PCF8575` library via Library Manager.
- **Steps**: Open the `.ino` file, select `esp32-s3-devkitc-1`, and upload.

## Hardware Connections
| Signal | GPIO |
|--------|------|
| SDA    | 48   |
| SCL    | 47   |

| PCF8575 | I2C Address | Relays |
|---------|-------------|--------|
| First   | 0x20        | 1‑16   |
| Second  | 0x21        | 17‑32  |

## Expected Behavior
- On startup, all relays are turned off.
- Relays 1‑16 turn on sequentially (200 ms delay), then relays 17‑32.
- All relays then turn off in the same order.
- Serial Monitor (115200 baud) shows: `PCF8575 32-Channel Relay Control: Starting...`

## Important Notes
- Relays are active‑LOW: `LOW` turns the relay ON, `HIGH` turns it OFF.
- The I2C bus runs at standard speed (100 kHz).

## Related Resources
- Pin definition: `../pin_definitions/T32M/T32M_pin_definition.md`