# B2 Arduino Example 02: Read Digital Inputs

## Description
This example demonstrates how to read the state of the two digital input ports on the B2 board (GPIO6 and GPIO7).  
The inputs are configured with internal pull‑ups (`INPUT_PULLUP`), so they read `HIGH` when open and `LOW` when connected to GND.

The program prints the initial state at startup, then monitors both inputs and prints a message whenever a change is detected.

## File Structure
- `src/B2_02_read_digital_inputs.ino` – Arduino source code.
- `precompiled/B2_02_read_digital_inputs.bin` – Precompiled firmware binary for ESP32.

## Using the Precompiled Binary
1. Download the `.bin` file from the `precompiled/` folder.
2. Use the official **ESP Flash Download Tool** or `esptool.py` to flash it to the B2 controller.
3. **Flash Address**: `0x0`.

## Compiling from Source
1. **Environment**: Install Arduino IDE and add ESP32 board support (via Boards Manager).
2. **Dependencies**: None beyond the standard ESP32 core.
3. **Steps**: Open the `.ino` file inside the `src/` folder, select the board `esp32-s3-devkitc-1` (or the correct board for B2) and the correct port, then compile and upload.

## Hardware Connections
| Input | GPIO | Note |
|-------|------|------|
| DI1   | GPIO6 | Internal pull‑up enabled |
| DI2   | GPIO7 | Internal pull‑up enabled |

**Note**: To test, connect a jumper wire from the input pin to GND (LOW) or leave it open (HIGH). The internal pull‑up keeps the pin HIGH when not connected.

## Expected Behavior
- On startup, the Serial Monitor (115200 baud) displays:
`FeedCurrent B2 Digital Input Demo`
`DI1 Initial State: 1`
`DI2 Initial State: 1`
- When an input changes state, a message is printed, e.g.:
`DI1 Changed: 0`
`DI2 Changed: 0`
- The program checks for changes every 10 ms.

## Related Resources
- Pin definition: `../pin_definitions/B2/B2_pin_definition.md`