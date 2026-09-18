# B2 Arduino Example 05: Read Free GPIO State

## Description
This example monitors the digital state (HIGH/LOW) of four free GPIO pins on the B2 board: GPIO47, GPIO48, GPIO17, and GPIO40.  
The program reads the initial states at startup, then continuously checks for changes and prints a message to the Serial Monitor whenever any pin changes.

## File Structure
- `src/B2_05_read_free_gpio.ino` – Arduino source code.
- `precompiled/B2_05_read_free_gpio.bin` – Precompiled firmware binary for ESP32‑S3.

## Using the Precompiled Binary
1. Download the `.bin` file from the `precompiled/` folder.
2. Use the official **ESP Flash Download Tool** or `esptool.py` to flash it to the B2 controller.
3. **Flash Address**: `0x0`.

## Compiling from Source
1. **Environment**: Install Arduino IDE and add ESP32‑S3 board support (via Boards Manager).
2. **Dependencies**: None beyond the standard ESP32 core.
3. **Steps**: Open the `.ino` file inside the `src/` folder, select the board `esp32-s3-devkitc-1` and the correct port, then compile and upload.

## Hardware Connections
| GPIO Pin | Description |
|----------|-------------|
| GPIO47   | Free GPIO (1‑Wire‑1) |
| GPIO48   | Free GPIO (1‑Wire‑2) |
| GPIO17   | Free GPIO (1‑Wire‑3) |
| GPIO40   | Free GPIO (1‑Wire‑4) |

**Note**: These pins are configured as plain inputs (`INPUT`) with **no internal pull‑up or pull‑down**. If a pin is left floating, its state may be unstable. To ensure a defined logic level, either add an external pull‑up/pull‑down resistor or change `INPUT` to `INPUT_PULLUP` in the code.

## Expected Behavior
- On startup, the Serial Monitor (115200 baud) displays the initial state of each pin, e.g.:
`FeedCurrent B2 GPIO State Monitor`
`GPIO47 Initial: 1`
`GPIO48 Initial: 1`
`GPIO17 Initial: 0`
`GPIO40 Initial: 1`
- Whenever a pin changes state, a message is printed, e.g.:
`GPIO47 Changed: 0`
`GPIO17 Changed: 1`
- The program checks for changes every 10 ms.

## Important Notes
- **Serial Monitor**: Set baud rate to **115200**.
- No external hardware is required for basic testing; connect a jumper wire from a monitored GPIO to 3.3V (HIGH) or GND (LOW) to see state changes.
- The pins used here are labelled “1‑Wire‑1” to “1‑Wire‑4” in the B2 pinout, but they can be used as general‑purpose digital inputs when not using 1‑Wire sensors.

## Related Resources
- Pin definition: `../pin_definitions/B2/B2_pin_definition.md`