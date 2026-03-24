# F8 Arduino Example 11: Digital Input Trigger Output Directly

## Description
This example links the 8 digital inputs directly to the 8 relay outputs using a single **PCF8575** I/O expander (address `0x24`). When an input pin (P0–P7) is **LOW**, the corresponding output pin (P8–P15) is set to **LOW** (relay ON). When the input is **HIGH**, the output is set to **HIGH** (relay OFF). The mapping is real‑time and the program prints the input states to the Serial Monitor every 500 ms.

## File Structure
- `src/F8_11_input_trigger_output.ino` – Arduino source code.
- `precompiled/F8_11_input_trigger_output.bin` – Precompiled firmware binary for ESP32‑S3.

## Using the Precompiled Binary
Flash `precompiled/F8_11_input_trigger_output.bin` to address `0x0` using ESP Flash Download Tool or `esptool.py`.

## Compiling from Source
- **Environment**: Arduino IDE with ESP32‑S3 board support.
- **Dependencies**: Install `PCF8575` library via Library Manager.
- **Steps**: Open the `.ino` file, select `esp32-s3-devkitc-1`, and upload.

## Hardware Connections
- **I2C pins**: SDA=GPIO8, SCL=GPIO18
- **PCF8575**: I2C address `0x24`
  - **Inputs**: P0 – P7 (digital inputs 1‑8, active‑LOW)
  - **Outputs**: P8 – P15 (relay outputs 1‑8, active‑LOW)

## Input‑Output Mapping
| Input | Output | Behavior |
|-------|--------|----------|
| P0 (Input 1) | P8 (Relay 1) | Input LOW → Relay ON (LOW)<br>Input HIGH → Relay OFF (HIGH) |
| P1 (Input 2) | P9 (Relay 2) | Same |
| ... | ... | ... |
| P7 (Input 8) | P15 (Relay 8) | Same |

## Serial Output
After uploading, open the Serial Monitor at **115200 baud**. You will see a line every 500 ms listing the state of each input:

DI1 State: LOW
DI2 State: HIGH
...
DI8 State: LOW

## Important Notes
- The example uses a single PCF8575 chip for both inputs and outputs.
- Inputs have internal pull‑up resistors (active‑LOW logic).
- Relays are active‑LOW (LOW = ON, HIGH = OFF).
- The loop reads the 16‑bit state from the PCF8575 and updates the outputs accordingly.
- The Serial Monitor output is for debugging and can be commented out if not needed.

## Related Resources
- Pin definition: `../pin_definitions/F8/F8_pin_definition.md`