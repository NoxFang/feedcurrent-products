# N60 Arduino Example 01: Read Digital Inputs

## Description
This example reads the state of two free digital input ports on the N60 board (GPIO15 and GPIO16) and prints their status to the Serial Monitor every 500 ms.

## File Structure
- `src/N60_01_read_digital_inputs.ino` – Arduino source code.
- `precompiled/N60_01_read_digital_inputs.bin` – Precompiled firmware binary for ESP32‑S3.

## Using the Precompiled Binary
Flash `precompiled/N60_01_read_digital_inputs.bin` to address `0x0` using ESP Flash Download Tool or `esptool.py`.

## Compiling from Source
- **Environment**: Arduino IDE with ESP32‑S3 board support.
- **Dependencies**: None beyond the standard ESP32 core.
- **Steps**: Open the `.ino` file, select `esp32-s3-devkitc-1`, and upload.

## Hardware Connections
| Pin | GPIO | Description |
|-----|------|-------------|
| DI1 | 15   | Digital Input 1 (no internal pull‑up) |
| DI2 | 16   | Digital Input 2 (no internal pull‑up) |

**Note**: GPIO15 and GPIO16 have no internal pull‑up resistors. Connect an appropriate external pull‑up or pull‑down resistor for reliable readings.

## Expected Behavior
- On startup, the Serial Monitor (115200 baud) displays: `ESP32 GPIO15 and GPIO16 State Monitor`
- Every 500 ms, the states of both GPIOs are printed, e.g.:
  ```cpp
  GPIO15: HIGH | GPIO16: LOW
  GPIO15: LOW | GPIO16: LOW
  ```

## Important Notes
- **Serial Monitor**: Set baud rate to **115200**.
- The example reads only two GPIOs (15 and 16). For other free GPIOs, refer to the pin definition file or modify the code.
- Inputs are read as floating unless externally pulled.

## Related Resources
- Pin definition: `../pin_definitions/N60/N60_pin_definition.md`