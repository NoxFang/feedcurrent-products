# B2 Arduino Example 01: Turn ON/OFF Relay

## Description
This example demonstrates how to control the 2 relays on the B2 board directly via GPIO pins (GPIO4 and GPIO46).  
The relays are active‑LOW: `LOW` turns the relay ON, `HIGH` turns it OFF.

The example cycles through several switching patterns:
1. Relay 1 ON → OFF (1 s each)
2. Relay 2 ON → OFF (1 s each)
3. Both relays ON → OFF together (1 s each)
4. Repeats indefinitely

## File Structure
- `src/B2_01_turn_on_off_relay.ino` – Arduino source code.
- `precompiled/B2_01_turn_on_off_relay.bin` – Precompiled firmware binary for ESP32‑S3.

## Using the Precompiled Binary
1. Download the `.bin` file from the `precompiled/` folder.
2. Use the official **ESP Flash Download Tool** or `esptool.py` to flash it to the B2 controller.
3. **Flash Address**: `0x0`.

## Compiling from Source
1. **Environment**: Install Arduino IDE and add ESP32‑S3 board support (via Boards Manager).
2. **Dependencies**: None beyond the standard ESP32 core.
3. **Steps**: Open the `.ino` file inside the `src/` folder, select the board `esp32-s3-devkitc-1` and the correct port, then compile and upload.

## Hardware Connections
| Relay | GPIO |
|-------|------|
| Relay 1 | GPIO4 |
| Relay 2 | GPIO46 |

**Note**: Both relays are active‑LOW. Ensure the relay module is powered correctly and the GPIO pins can drive the relay coils (or use an appropriate driver circuit if needed).

## Expected Behavior
- On startup, both relays are turned OFF.
- The Serial Monitor (115200 baud) prints `Relay 2 OFF` at the corresponding step (optional debug message).
- The relay switching pattern repeats continuously.

## Related Resources
- Pin definition: `../pin_definitions/B2/B2_pin_definition.md`