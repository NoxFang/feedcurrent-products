# B2 Arduino Example 11: Digital Input Triggers Output Directly

## Description
This example demonstrates a direct linkage between the two digital inputs and the two relay outputs on the B2 board using GPIO pins.  
It continuously monitors the digital inputs and updates the corresponding relay outputs when a change is detected.

- **Digital Input 1 (GPIO6)** controls **Relay 1 (GPIO4)**
- **Digital Input 2 (GPIO7)** controls **Relay 2 (GPIO46)**

**Logic**:
- Input **HIGH** → Relay **ON** (output LOW)
- Input **LOW**  → Relay **OFF** (output HIGH)

## File Structure
- `src/B2_11_input_trigger_output.ino` – Arduino source code.
- `precompiled/B2_11_input_trigger_output.bin` – Precompiled firmware binary for ESP32‑S3.

## Using the Precompiled Binary (.bin)
1. Download the `.bin` file from the `precompiled/` folder.
2. Use the official **ESP Flash Download Tool** or `esptool.py` to flash it to the B2 controller.
3. **Flash Address**: `0x0`.

## Compiling from Source
1. **Environment**: Install Arduino IDE and add ESP32‑S3 board support (via Boards Manager).
2. **Dependencies**: None beyond the standard ESP32 core.
3. **Steps**: Open `src/B2_11_input_trigger_output.ino` in Arduino IDE, select the board `esp32-s3-devkitc-1` and the correct port, then compile and upload.

## Hardware Connections
| Function | GPIO | Notes |
|----------|------|-------|
| Digital Input 1 | GPIO6 | Configured as `INPUT` (no internal pull‑up) |
| Digital Input 2 | GPIO7 | Configured as `INPUT` (no internal pull‑up) |
| Relay 1 | GPIO4 | Active‑LOW output |
| Relay 2 | GPIO46 | Active‑LOW output |

**Important**: The input pins are configured as plain `INPUT` with **no internal pull‑up or pull‑down**. If left floating, the input state may be unstable. To ensure reliable operation, provide an external pull‑up or pull‑down resistor, or change the code to use `INPUT_PULLUP` (then connect the input to GND to activate).

## Expected Behavior
- On startup, both relays are turned OFF.
- The program reads the initial state of both inputs.
- Whenever an input changes:
  - If the input becomes **HIGH**, the corresponding relay turns **ON**.
  - If the input becomes **LOW**, the corresponding relay turns **OFF**.
- The program checks for changes every 10 ms.
- No serial output is used in this example.

## Important Notes
- **Relay logic**: The relays are active‑LOW (`LOW` = ON, `HIGH` = OFF), matching typical KinCony hardware.
- **Input logic**: Unlike some other examples, here a **HIGH** input activates the relay. This is the opposite of the B4 example (which uses PCF8574 and active‑LOW inputs). Always verify the logic for your specific board.
- **Debouncing**: No software debouncing is implemented. For noisy signals, add a small capacitor across the input or implement a debounce routine.
- **Power supply**: Ensure the B2 board is powered adequately to drive the relay coils.

## Related Resources
- Pin definition: `../pin_definitions/B2/B2_pin_definition.md`