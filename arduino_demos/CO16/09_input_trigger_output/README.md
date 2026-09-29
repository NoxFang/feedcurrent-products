# CO16 Arduino Example 09: Digital Input Trigger Output Directly

## Description
This example demonstrates direct linkage between the 16 digital inputs and the 16 relay outputs on the CO16 board.  
- Digital inputs are read via a **PCA9555** I/O expander (I2C address `0x24`).
- Relay outputs are controlled via a **PCF8575** I/O expander (I2C address `0x22`).

**Logic**:
- Input **LOW** → corresponding relay **ON** (output LOW)
- Input **HIGH** → corresponding relay **OFF** (output HIGH)

The state is updated every 100 ms.

## File Structure
- `src/CO16_09_input_trigger_output.ino` – Arduino source code.
- `precompiled/CO16_09_input_trigger_output.bin` – Precompiled firmware binary for ESP32‑S3.

## Using the Precompiled Binary (.bin)
1. Download the `.bin` file from the `precompiled/` folder.
2. Use the official **ESP Flash Download Tool** or `esptool.py` to flash it to the CO16 controller.
3. **Flash Address**: `0x0`.

## Compiling from Source
1. **Environment**: Install Arduino IDE and add ESP32‑S3 board support (via Boards Manager).
2. **Dependencies**:
   - `Wire.h` (built‑in)
   - `PCF8575.h` – Install via Library Manager.
   - `PCA95x5.h` – Install via Library Manager (for PCA9555 input expander).
3. **Steps**: Open `src/CO16_09_input_trigger_output.ino` in Arduino IDE, select the board `esp32-s3-devkitc-1` and the correct port, then compile and upload.

## Hardware Connections
| Signal | GPIO |
|--------|------|
| I2C SDA | GPIO8 |
| I2C SCL | GPIO18 |

| Expander | I2C Address | Function |
|----------|-------------|----------|
| PCA9555  | 0x24        | Digital inputs 1‑16 |
| PCF8575  | 0x22        | Relay outputs 1‑16 |

**Note**: The CO16 board includes both expanders onboard. No external wiring is required for the I2C bus.

## Expected Behavior
- On startup, all relays are turned OFF.
- The board continuously reads all 16 inputs and updates the corresponding relay outputs.
- Input LOW → relay ON; Input HIGH → relay OFF.
- The loop runs every 100 ms.
- No serial output is used in this example.

## Important Notes
- The example uses **active‑LOW** logic for both inputs and relays.
- The PCA9555 inputs are configured as plain inputs (no internal pull‑up enabled in code). If your board does not have external pull‑up resistors, floating inputs may cause unpredictable behavior. Consider adding external pull‑ups or enabling internal pull‑ups if supported.
- To test, connect a jumper wire from an input pin to GND (LOW) to turn on the corresponding relay.
- The code comment mentions “XL9535”, but the actual library used is `PCA95x5` for the PCA9555. Both are register‑compatible.

## Related Resources
- Pin definition: `../pin_definitions/CO16/CO16_pin_definition.md`