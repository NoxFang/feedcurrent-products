# AIO Hybrid Arduino Example 01: Turn ON/OFF Relay

## Description
This example demonstrates how to control the 5 relay outputs on the AIO Hybrid board using the PCF8574 I/O expander (address `0x26`). It sequentially turns on each relay and then turns them off in a loop.

## File Structure
- `src/AIO_01_turn_on_off_relay.ino` – Arduino source code.
- `precompiled/AIO_01_turn_on_off_relay.bin` – Precompiled firmware binary for ESP32‑S3 (to be added).

## Using the Precompiled Binary
1. Download the `.bin` file from the `precompiled/` folder.
2. Use the official **ESP Flash Download Tool** or `esptool.py` to flash it to the AIO Hybrid controller.
3. **Flash Address**: `0x0` (as indicated in the forum post).

## Compiling from Source
1. **Environment**: Install Arduino IDE and add ESP32‑S3 board support (via Boards Manager).
2. **Dependencies**:
   - `Wire.h` (built‑in)
   - `PCF8574.h` – Install via Library Manager (search for "PCF8574" by Renzo Mischianti or similar).
3. **Steps**:
   - Open `src/AIO_01_turn_on_off_relay.ino` in Arduino IDE.
   - Select the correct board (`esp32-s3-devkitc-1`) and port.
   - Compile and upload.

## Expected Behavior
- After startup, all relays are OFF.
- The program then turns ON each relay (P3 → P4 → P5 → P6 → P7) with a 500ms delay between each.
- All relays remain ON for 1 second.
- Then all relays are turned OFF and remain OFF for 1 second.
- The cycle repeats indefinitely.

## Important Notes
- **PCF8574**: I2C address `0x26`, relays connected to pins P3–P7 (active **HIGH** – `digitalWrite(pin, HIGH)` turns the relay ON, `LOW` turns it OFF). This matches the AIO Hybrid hardware design.
- **I2C pins**: SDA=GPIO8, SCL=GPIO18.
- **Serial Monitor** (optional) shows debug messages at 115200 baud.
- Ensure the correct I2C address (`0x26`) is used – the AIO Hybrid uses this address for the relay expander.