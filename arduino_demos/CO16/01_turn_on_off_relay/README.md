# CO16 Arduino Example 01: Turn ON/OFF Relay

## Description
This example demonstrates sequential control of the 16 relay outputs on the CO16 board using a PCF8575 I/O expander.  
The sequence:
1. Turn on relays 1‑16 one by one (200 ms interval).
2. Turn off relays 1‑16 one by one (200 ms interval).
3. Repeat indefinitely.

## File Structure
- `src/CO16_01_turn_on_off_relay.ino` – Arduino source code.
- `precompiled/CO16_01_turn_on_off_relay.bin` – Precompiled firmware binary for ESP32‑S3.

## Using the Precompiled Binary (.bin)
1. Download the `.bin` file from the `precompiled/` folder.
2. Use the official **ESP Flash Download Tool** or `esptool.py` to flash it to the CO16 controller.
3. **Flash Address**: `0x0`.

## Compiling from Source
1. **Environment**: Install Arduino IDE and add ESP32‑S3 board support (via Boards Manager).
2. **Dependencies**: Install the `PCF8575` library via Library Manager.
3. **Steps**: Open `src/CO16_01_turn_on_off_relay.ino` in Arduino IDE, select the board `esp32-s3-devkitc-1` and the correct port, then compile and upload.

## Hardware Connections
| Signal | GPIO |
|--------|------|
| SDA    | GPIO8 |
| SCL    | GPIO18 |
| PCF8575 I2C Address | 0x22 |

**Note**: The CO16 board includes an onboard PCF8575 expander for relay control. No external wiring is required for the I2C bus.

## Expected Behavior
- On startup, the Serial Monitor (115200 baud) displays: `PCF8575 Relay Control: Starting...`
- All relays are initially turned off.
- Relays 1‑16 turn on sequentially (200 ms delay between each).
- Relays 1‑16 turn off sequentially (200 ms delay between each).
- The cycle repeats continuously.

## Important Notes
- Relays are **active‑LOW**: `LOW` turns the relay ON, `HIGH` turns it OFF.
- The I2C bus runs at standard speed (100 kHz).
- The delay time is set to 200 ms via `DELAY_TIME`; adjust as needed.

## Related Resources
- Pin definition: `../pin_definitions/CO16/CO16_pin_definition.md`