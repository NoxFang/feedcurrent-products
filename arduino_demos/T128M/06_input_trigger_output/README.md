# T128M Arduino Example 06: Input Trigger Output

## Description
This example reads 128 digital inputs from eight PCF8575 expanders on I2C Bus‑2 and directly controls 128 relays on eight separate PCF8575 expanders on I2C Bus‑1.  
- Input LOW → corresponding relay turns **ON** (active‑LOW logic)  
- Input HIGH → corresponding relay turns **OFF**  

The state is updated every 200 ms.

**I2C Bus‑1 (Outputs) – SDA=GPIO48, SCL=GPIO47**  
- Outputs 1‑16: address `0x27`  
- Outputs 17‑32: address `0x26`  
- Outputs 33‑48: address `0x23`  
- Outputs 49‑64: address `0x22`  
- Outputs 65‑80: address `0x25`  
- Outputs 81‑96: address `0x24`  
- Outputs 97‑112: address `0x21`  
- Outputs 113‑128: address `0x20`

**I2C Bus‑2 (Inputs) – SDA=GPIO12, SCL=GPIO11**  
- Inputs 1‑16: address `0x27`  
- Inputs 17‑32: address `0x26`  
- Inputs 33‑48: address `0x23`  
- Inputs 49‑64: address `0x22`  
- Inputs 65‑80: address `0x25`  
- Inputs 81‑96: address `0x24`  
- Inputs 97‑112: address `0x21`  
- Inputs 113‑128: address `0x20`

## File Structure
- `src/T128M_06_input_trigger_output.ino` – Arduino source code.
- `precompiled/T128M_06_input_trigger_output.bin` – Precompiled firmware binary for ESP32‑S3.

## Using the Precompiled Binary
Flash `precompiled/T128M_06_input_trigger_output.bin` to address `0x0` using ESP Flash Download Tool or `esptool.py`.

## Compiling from Source
- **Environment**: Arduino IDE with ESP32‑S3 board support.
- **Dependencies**: Install `PCF8575` library via Library Manager.
- **Steps**: Open the `.ino` file, select `esp32-s3-devkitc-1`, and upload.

## Hardware Connections
Two independent I2C buses are used:

| Bus | Signal | GPIO |
|-----|--------|------|
| Output (Bus 1) | SDA | 48 |
| Output (Bus 1) | SCL | 47 |
| Input  (Bus 2) | SDA | 12 |
| Input  (Bus 2) | SCL | 11 |

Refer to the address tables above for each PCF8575 module.

## Expected Behavior
- On startup, all relays are turned OFF.
- The board continuously reads all 128 inputs and updates the corresponding relay outputs.
- Input LOW → relay ON; Input HIGH → relay OFF.
- Serial Monitor (115200 baud) prints: `FeedCurrent 128-Channel Input-Output Mapping Test`

## Important Notes
- The example uses **active‑LOW** logic for both inputs and relays.
- Two separate I2C buses are used to avoid address conflicts and ensure reliable operation.
- To test, connect a jumper wire from an input pin to GND (LOW) to turn on the corresponding relay.

## Related Resources
- Pin definition: `../pin_definitions/T128M/T128M_pin_definition.md`