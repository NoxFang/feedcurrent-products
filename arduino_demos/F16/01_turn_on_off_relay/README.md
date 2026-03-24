# F16 Arduino Example 01: Turn ON/OFF Relay

## Description
This example demonstrates how to control the 16 relay outputs on the F16 board via the **PCF8575** I/O expander (address `0x25`). It sequentially turns on each relay (pins 0‑15) and then turns them off in a loop.

## File Structure
- `src/F16_01_turn_on_off_relay.ino` – Arduino source code.
- `precompiled/F16_01_turn_on_off_relay.bin` – Precompiled firmware binary for ESP32‑S3.

## Using the Precompiled Binary
Flash `precompiled/F16_01_turn_on_off_relay.bin` to address `0x0` using ESP Flash Download Tool or `esptool.py`.

## Compiling from Source
- **Environment**: Arduino IDE with ESP32‑S3 board support.
- **Dependencies**: Install `PCF8575` library via Library Manager.
- **Steps**: Open the `.ino` file, select `esp32-s3-devkitc-1`, and upload.

## Expected Behavior
- Relays 1‑16 turn on sequentially (200 ms delay between each).
- Then all relays turn off sequentially (200 ms delay between each).
- The cycle repeats indefinitely.

## Important Notes
- **PCF8575**: I2C address `0x25`, relays connected to pins 0‑15 (active LOW – `LOW` turns relay ON, `HIGH` turns it OFF).
- **I2C pins**: SDA = GPIO8, SCL = GPIO18.
- **Serial Monitor** (optional) shows debug messages at 115200 baud.

## Related Resources
- Pin definition: `../pin_definitions/F16/F16_pin_definition.md`