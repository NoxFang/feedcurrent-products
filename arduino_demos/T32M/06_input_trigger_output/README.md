# T32M Arduino Example 06: Input Trigger Output

## Description
This example reads 32 digital inputs from two PCF8575 expanders and directly controls 32 relays on two other PCF8575 expanders.  
- Input LOW → corresponding relay turns **ON**  
- Input HIGH → corresponding relay turns **OFF**  

The state is updated every 500 ms.

**I2C Addresses**:
- Inputs 1‑16: `0x24`
- Inputs 17‑32: `0x25`
- Outputs 1‑16: `0x20`
- Outputs 17‑32: `0x21`

## File Structure
- `src/T32M_06_input_trigger_output.ino` – Arduino source code.
- `precompiled/T32M_06_input_trigger_output.bin` – Precompiled firmware binary for ESP32‑S3.

## Using the Precompiled Binary
Flash `precompiled/T32M_06_input_trigger_output.bin` to address `0x0` using ESP Flash Download Tool or `esptool.py`.

## Compiling from Source
- **Environment**: Arduino IDE with ESP32‑S3 board support.
- **Dependencies**: Install `PCF8575` library via Library Manager.
- **Steps**: Open the `.ino` file, select `esp32-s3-devkitc-1`, and upload.

## Hardware Connections
| Signal | GPIO |
|--------|------|
| SDA    | 48   |
| SCL    | 47   |

| PCF8575 | I2C Address | Function |
|---------|-------------|----------|
| Input 1‑16  | 0x24 | Digital inputs 1‑16 |
| Input 17‑32 | 0x25 | Digital inputs 17‑32 |
| Output 1‑16 | 0x20 | Relays 1‑16 |
| Output 17‑32| 0x21 | Relays 17‑32 |

## Expected Behavior
- On startup, all relays are turned OFF.
- The board continuously reads all 32 inputs and updates the corresponding relay outputs.
- Input LOW → relay ON; Input HIGH → relay OFF.
- Serial Monitor (115200 baud) prints: `System started: 32 inputs controlling 32 relays`

## Important Notes
- The example uses **active‑LOW** logic for both inputs and relays.
- To test, connect a jumper wire from an input pin to GND (LOW) to turn on the corresponding relay.

## Related Resources
- Pin definition: `../pin_definitions/T32M/T32M_pin_definition.md`