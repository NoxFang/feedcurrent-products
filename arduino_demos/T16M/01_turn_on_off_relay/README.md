# T16M Arduino Example 01: Turn ON/OFF Relay

## Description
This example demonstrates sequential control of the 16 relays on the T16M board using a PCF8575 I/O expander (address `0x25`). The sequence:
1. Turn on relays 1‑16 one by one (200 ms interval).
2. Turn off relays 1‑16 one by one (200 ms interval).
3. Repeat indefinitely.

## File Structure
- `src/T16M_01_turn_on_off_relay.ino` – Arduino source code.
- `precompiled/T16M_01_turn_on_off_relay.bin` – Precompiled firmware binary for ESP32‑S3.

## Using the Precompiled Binary
Flash `precompiled/T16M_01_turn_on_off_relay.bin` to address `0x0` using ESP Flash Download Tool or `esptool.py`.

## Compiling from Source
- **Environment**: Arduino IDE with ESP32‑S3 board support.
- **Dependencies**: Install `PCF8575` library via Library Manager.
- **Steps**: Open the `.ino` file, select `esp32-s3-devkitc-1`, and upload.

## Hardware Connections
| Signal | GPIO |
|--------|------|
| SDA    | 11   |
| SCL    | 12   |
| PCF8575 I2C Address | 0x25 |

## Expected Behavior
- On startup, all relays are turned off.
- Relays 1‑16 turn on sequentially (200 ms delay between each).
- All relays then turn off sequentially (200 ms delay between each).
- The cycle repeats continuously.
- Serial Monitor (115200 baud) shows: `PCF8575 Relay Control: Starting...`

## Important Notes
- Relays are active‑LOW: `LOW` turns the relay ON, `HIGH` turns it OFF.
- The I2C bus runs at standard speed (100 kHz).

## Related Resources
- Pin definition: `../pin_definitions/T16M/T16M_pin_definition.md`