# F24 Arduino Example 11: Input Trigger Output

## Description
This example reads 24 digital inputs from two PCF8575 expanders and directly controls 24 relays based on the input state.  
- Input LOW → corresponding relay turns **ON**  
- Input HIGH → corresponding relay turns **OFF**  

The mapping is:
- Inputs 1‑16 (PCF8575 address `0x24`) control Relays 9‑24 (PCF8575 address `0x25`)
- Inputs 17‑24 (PCF8575 address `0x26`, pins 8‑15) control Relays 1‑8 (same chip `0x26`, pins 0‑7)

The state is updated every 500 ms.

## File Structure
- `src/F24_11_input_trigger_output.ino` – Arduino source code.
- `precompiled/F24_11_input_trigger_output.bin` – Precompiled firmware binary for ESP32‑S3.

## Using the Precompiled Binary
Flash `precompiled/F24_11_input_trigger_output.bin` to address `0x0` using ESP Flash Download Tool or `esptool.py`.

## Compiling from Source
- **Environment**: Arduino IDE with ESP32‑S3 board support.
- **Dependencies**: Install `PCF8575` library via Library Manager.
- **Steps**: Open the `.ino` file, select `esp32-s3-devkitc-1`, and upload.

## Hardware Connections
| Signal | GPIO |
|--------|------|
| SDA    | 8    |
| SCL    | 18   |

| PCF8575 | I2C Address | Function |
|---------|-------------|----------|
| U23 (IN1) | 0x24 | Inputs 1‑16 |
| U49 (IN2/RL) | 0x26 | Inputs 17‑24 (pins 8‑15) + Relays 1‑8 (pins 0‑7) |
| U27 (RL) | 0x25 | Relays 9‑24 |

## Expected Behavior
- On startup, all relays are turned OFF.
- In the main loop, the board continuously reads all 24 inputs.
- For each input:
  - If the input is **LOW** (0V, active), the corresponding relay is turned **ON**.
  - If the input is **HIGH** (3.3V), the corresponding relay is turned **OFF**.
- The state is updated every 500 ms.
- Serial Monitor (115200 baud) prints: `System started: Input state controlling 24 relays`

## Important Notes
- The example uses **active‑LOW** logic for both inputs and relays.
- Inputs 17‑24 and Relays 1‑8 share the same I2C chip (address `0x26`). The chip is configured to read inputs on pins 8‑15 and write outputs on pins 0‑7.
- Relays 9‑24 are controlled by a dedicated chip at address `0x25`.
- To test, connect a jumper wire from an input pin to GND (LOW) to turn on the corresponding relay.

## Related Resources
- Pin definition: `../pin_definitions/F24/F24_pin_definition.md`