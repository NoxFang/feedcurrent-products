# F4 Arduino Example 11: Digital Input Trigger Output Directly

## Description
This example links the 4 digital inputs directly to the 4 relay outputs using a single PCF8574 I/O expander. When an input pin is **LOW**, the corresponding relay output is set to **LOW** (relay ON). When the input is **HIGH**, the output is set to **HIGH** (relay OFF). The mapping is real‑time with a short delay between each channel.

## File Structure
- `src/F4_11_input_trigger_output.ino` – Arduino source code.
- `precompiled/F4_11_input_trigger_output.bin` – Precompiled firmware binary for ESP32‑S3.

## Using the Precompiled Binary
Flash `precompiled/F4_11_input_trigger_output.bin` to address `0x0` using ESP Flash Download Tool or `esptool.py`.

## Compiling from Source
- **Environment**: Arduino IDE with ESP32‑S3 board support.
- **Dependencies**: Install `PCF8574` library via Library Manager (e.g., by Renzo Mischianti).
- **Steps**: Open the `.ino` file, select `esp32-s3-devkitc-1`, and upload.

## Hardware Connections
- **I2C pins**: SDA=GPIO8, SCL=GPIO18
- **PCF8574**: I2C address `0x24`
  - **Inputs**: P0 – P3 (digital inputs 1‑4, active‑LOW)
  - **Outputs**: P4 – P7 (relay outputs 1‑4, active‑LOW)

## Input‑Output Mapping
| Input | Output | Behavior |
|-------|--------|----------|
| P0 (Input 1) | P4 (Relay 1) | Input LOW → Relay ON (LOW)<br>Input HIGH → Relay OFF (HIGH) |
| P1 (Input 2) | P5 (Relay 2) | Same |
| P2 (Input 3) | P6 (Relay 3) | Same |
| P3 (Input 4) | P7 (Relay 4) | Same |

## Expected Behavior
- When a digital input is connected to GND (LOW), the corresponding relay turns ON.
- When the input is left floating or pulled HIGH, the relay turns OFF.
- Changes are reflected immediately; each channel is processed with a 50 ms delay between them.

## Important Notes
- **No serial output** is used in this example (the Serial object is initialized but not used).
- Inputs have internal pull‑ups enabled (active‑LOW logic).
- Relays are active‑LOW (LOW = ON, HIGH = OFF).
- The 50 ms delay between channels helps prevent I2C bus contention and provides a simple debounce effect.

## Related Resources
- Pin definition: `../pin_definitions/F4/F4_pin_definition.md`
