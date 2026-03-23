# F4 Arduino Example 01: Turn ON/OFF Relay

## Description
This example demonstrates how to control the 4 relay outputs on the F4 board via the **PCF8574** I/O expander (address `0x24`). It sequentially turns on each relay (pins 4‑7) and then turns them off in a loop.

## File Structure
- `src/F4_01_turn_on_off_relay.ino` – Arduino source code.
- `precompiled/F4_01_turn_on_off_relay.bin` – Precompiled firmware binary for ESP32‑S3.

## Using the Precompiled Binary
Flash `precompiled/F4_01_turn_on_off_relay.bin` to address `0x0` using ESP Flash Download Tool or `esptool.py`.

## Compiling from Source
- **Environment**: Arduino IDE with ESP32‑S3 board support.
- **Dependencies**: Install `PCF8574` library via Library Manager.
- **Steps**: Open the `.ino` file, select `esp32-s3-devkitc-1`, and upload.

## Expected Behavior
- All relays start OFF.
- Relays 1‑4 turn on sequentially (200 ms delay between each).
- All relays remain ON for 200 ms after the last relay turns on.
- Then relays 1‑4 turn off sequentially (200 ms delay between each).
- The cycle repeats indefinitely.

## Important Notes
- **PCF8574**: I2C address `0x24`, outputs connected to pins 4‑7 (active LOW – `LOW` turns relay ON, `HIGH` turns it OFF).
- **I2C pins**: SDA=GPIO8, SCL=GPIO18.
- **Relays**: 16A rated, removable type.
- **Serial Monitor** (optional) shows debug messages at 115200 baud.
