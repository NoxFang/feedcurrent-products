# T128M Arduino Example 01: Turn ON/OFF Output

## Description
This example demonstrates sequential control of 128 outputs on the T128M board using eight PCF8575 I/O expanders.  
- Outputs 1‑16: address `0x27`  
- Outputs 17‑32: address `0x26`  
- Outputs 33‑48: address `0x23`  
- Outputs 49‑64: address `0x22`  
- Outputs 65‑80: address `0x25`  
- Outputs 81‑96: address `0x24`  
- Outputs 97‑112: address `0x21`  
- Outputs 113‑128: address `0x20`  

The sequence:
1. Turn on outputs 1‑128 one by one (50 ms interval).
2. Turn off outputs 128‑1 one by one (50 ms interval).
3. Repeat indefinitely.

## File Structure
- `src/T128M_01_turn_on_off_relay.ino` – Arduino source code.
- `precompiled/T128M_01_turn_on_off_relay.bin` – Precompiled firmware binary for ESP32‑S3.

## Using the Precompiled Binary
Flash `precompiled/T128M_01_turn_on_off_relay.bin` to address `0x0` using ESP Flash Download Tool or `esptool.py`.

## Compiling from Source
- **Environment**: Arduino IDE with ESP32‑S3 board support.
- **Dependencies**: Install `PCF8575` library via Library Manager.
- **Steps**: Open the `.ino` file, select `esp32-s3-devkitc-1`, and upload.

## Hardware Connections
| Signal | GPIO |
|--------|------|
| SDA    | 48   |
| SCL    | 47   |

| PCF8575 | I2C Address | Outputs |
|---------|-------------|---------|
| 1st     | 0x27        | 1‑16    |
| 2nd     | 0x26        | 17‑32   |
| 3rd     | 0x23        | 33‑48   |
| 4th     | 0x22        | 49‑64   |
| 5th     | 0x25        | 65‑80   |
| 6th     | 0x24        | 81‑96   |
| 7th     | 0x21        | 97‑112  |
| 8th     | 0x20        | 113‑128 |

## Expected Behavior
- On startup, all outputs are turned off.
- Outputs 1‑128 turn on sequentially (50 ms delay each).
- Then outputs 128‑1 turn off sequentially.
- Serial Monitor (115200 baud) shows: `PCF8575 128-Channel Output Control Starting...`

## Important Notes
- Outputs are active‑LOW: `LOW` turns the output ON, `HIGH` turns it OFF.
- The I2C bus runs at standard speed (100 kHz).
- Delay between outputs is 50 ms (can be adjusted via `DELAY_TIME`).

## Related Resources
- Pin definition: `../pin_definitions/T128M/T128M_pin_definition.md`