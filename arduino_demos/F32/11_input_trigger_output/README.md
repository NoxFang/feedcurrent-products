# F32 Arduino Example 11: Input Trigger Output

## Description
This example reads 32 digital inputs from three PCF8575 expanders and directly controls 32 relays based on the input state.  
- Input LOW → corresponding relay turns **ON**  
- Input HIGH → corresponding relay turns **OFF**  

The mapping uses four PCF8575 chips with the following I2C addresses and pin assignments:

| Chip | I2C Address | Function | Pin Usage |
|------|-------------|----------|-----------|
| U23 | 0x24 | Inputs 1‑16 | Pins 0‑15 |
| U49 | 0x26 | Inputs 17‑24 (pins 0‑7)<br>Relays 9‑16 (pins 8‑15) | Pins 8‑11: relays 13‑16<br>Pins 12‑15: relays 9‑12 |
| U27 | 0x25 | Relays 17‑32 | Pins 0‑15 |
| U62 | 0x27 | Inputs 25‑32 (pins 0‑7)<br>Relays 1‑8 (pins 8‑15) | Pins 8‑15: relays 1‑8 |

The state is updated continuously with a 500 ms delay between cycles.

## File Structure
- `src/F32_11_input_trigger_output.ino` – Arduino source code.
- `precompiled/F32_11_input_trigger_output.bin` – Precompiled firmware binary for ESP32‑S3.

## Using the Precompiled Binary
Flash `precompiled/F32_11_input_trigger_output.bin` to address `0x0` using ESP Flash Download Tool or `esptool.py`.

## Compiling from Source
- **Environment**: Arduino IDE with ESP32‑S3 board support.
- **Dependencies**: Install `PCF8575` library via Library Manager.
- **Steps**: Open the `.ino` file, select `esp32-s3-devkitc-1`, and upload.

## Hardware Connections
| Signal | GPIO |
|--------|------|
| SDA    | 8    |
| SCL    | 18   |

Refer to the table above for I2C address and pin mappings.

## Expected Behavior
- On startup, all relays are turned OFF.
- The board continuously reads all 32 inputs and updates the corresponding relay outputs.
- Input LOW → relay ON; Input HIGH → relay OFF.
- The Serial Monitor (115200 baud) prints: `System started: Input state controlling 24 relays`
  (Note: the message says “24 relays” but the example controls 32 relays; the string is a historical artifact.)

## Important Notes
- The example uses **active‑LOW** logic for both inputs and relays.
- Multiple PCF8575 chips share I2C addresses 0x24, 0x25, 0x26, and 0x27.
- Some chips (U49 and U62) combine both input and relay functions on different pin ranges.
- To test, connect a jumper wire from an input pin to GND (LOW) to turn on the corresponding relay.

## Related Resources
- Pin definition: `../pin_definitions/F32/F32_pin_definition.md`