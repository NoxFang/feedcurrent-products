# T64M Arduino Example 01: Turn ON/OFF Output

## Description
This example demonstrates sequential control of 64 outputs on the T64M board using four PCF8575 I/O expanders.  
- Outputs 1‑16 are controlled via the first PCF8575 (address `0x25`).  
- Outputs 17‑32 via the second PCF8575 (address `0x24`).  
- Outputs 33‑48 via the third PCF8575 (address `0x21`).  
- Outputs 49‑64 via the fourth PCF8575 (address `0x20`).  

The sequence:
1. Turn on outputs 1‑64 one by one (200 ms interval).
2. Turn off outputs 64‑1 one by one (200 ms interval).
3. Repeat indefinitely.

## File Structure
- `src/T64M_01_turn_on_off_relay.ino` – Arduino source code.
- `precompiled/T64M_01_turn_on_off_relay.bin` – Precompiled firmware binary for ESP32‑S3.

## Using the Precompiled Binary
Flash `precompiled/T64M_01_turn_on_off_relay.bin` to address `0x0` using ESP Flash Download Tool or `esptool.py`.

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
| First   | 0x25        | 1‑16    |
| Second  | 0x24        | 17‑32   |
| Third   | 0x21        | 33‑48   |
| Fourth  | 0x20        | 49‑64   |

## Expected Behavior
- On startup, all outputs are turned off.
- Outputs 1‑64 turn on sequentially (200 ms delay each).
- Then outputs 64‑1 turn off sequentially.
- Serial Monitor (115200 baud) shows: `PCF8575 64-Channel Output Control Starting...`

## Important Notes
- Outputs are active‑LOW: `LOW` turns the output ON, `HIGH` turns it OFF.
- The I2C bus runs at standard speed (100 kHz).

## Related Resources
- Pin definition: `../pin_definitions/T64M/T64M_pin_definition.md`