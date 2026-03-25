# T16M Arduino Example 06: Input Trigger Output

## Description
This example reads 16 digital inputs from a PCF8575 expander (address `0x24`) and directly controls 16 relays on another PCF8575 expander (address `0x25`).  
- Input LOW → corresponding relay turns **ON**  
- Input HIGH → corresponding relay turns **OFF**  

The state is updated every 500 ms.

## File Structure
- `src/T16M_06_input_trigger_output.ino` – Arduino source code.
- `precompiled/T16M_06_input_trigger_output.bin` – Precompiled firmware binary for ESP32‑S3.

## Using the Precompiled Binary
Flash `precompiled/T16M_06_input_trigger_output.bin` to address `0x0` using ESP Flash Download Tool or `esptool.py`.

## Compiling from Source
- **Environment**: Arduino IDE with ESP32‑S3 board support.
- **Dependencies**: Install `PCF8575` library via Library Manager.
- **Steps**: Open the `.ino` file, select `esp32-s3-devkitc-1`, and upload.

## Hardware Connections
| Signal | GPIO |
|--------|------|
| SDA    | 11   |
| SCL    | 12   |

| PCF8575 | I2C Address | Function |
|---------|-------------|----------|
| Input   | 0x24        | Digital inputs 1‑16 |
| Output  | 0x25        | Relays 1‑16 |

## Expected Behavior
- On startup, all relays are turned OFF.
- The board continuously reads all 16 inputs and updates the corresponding relay outputs.
- Input LOW → relay ON; Input HIGH → relay OFF.
- Serial Monitor (115200 baud) prints: `System started: Input state controlling 16 relays`

## Important Notes
- The example uses **active‑LOW** logic for both inputs and relays.
- To test, connect a jumper wire from an input pin to GND (LOW) to turn on the corresponding relay.

## Related Resources
- Pin definition: `../pin_definitions/T16M/T16M_pin_definition.md`