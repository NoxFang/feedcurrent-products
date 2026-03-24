# F24 Arduino Example 12: Control Single Relay (Relay 24 Toggle)

## Description
This example demonstrates individual control of a specific relay (Relay 24) on the F24 board. The relay toggles ON/OFF every 2 seconds, and its state is printed to the Serial Monitor.

- Relay 24 is controlled via the first PCF8575 (address `0x25`), pin 15.
- Relays 1‑8 are controlled via the second PCF8575 (address `0x26`), pins 0‑7.

## File Structure
- `src/F24_12_control_single_relay.ino` – Arduino source code.
- `precompiled/F24_12_control_single_relay.bin` – Precompiled firmware binary for ESP32‑S3.

## Using the Precompiled Binary
Flash `precompiled/F24_12_control_single_relay.bin` to address `0x0` using ESP Flash Download Tool or `esptool.py`.

## Compiling from Source
- **Environment**: Arduino IDE with ESP32‑S3 board support.
- **Dependencies**: Install `PCF8575` library via Library Manager.
- **Steps**: Open the `.ino` file, select `esp32-s3-devkitc-1`, and upload.

## Hardware Connections
| Signal | GPIO |
|--------|------|
| SDA    | 8    |
| SCL    | 18   |

| PCF8575 | I2C Address | Relays |
|---------|-------------|--------|
| First   | 0x25        | 9‑24   |
| Second  | 0x26        | 1‑8    |

## Expected Behavior
- On startup, all relays are turned off.
- Relay 24 toggles every 2 seconds: ON → OFF → ON → OFF ...
- Serial Monitor (115200 baud) prints:
PCF8575 Relay 24 Toggle Program: Starting...
Relay 24 is ON
Relay 24 is OFF
Relay 24 is ON
...

## Important Notes
- Relays are active‑LOW: `LOW` turns the relay ON, `HIGH` turns it OFF.
- To control other relays individually, modify the `pcf8575_R1.write(pin, state)` or `pcf8575_R2.write(pin, state)` lines accordingly.
- This example is a simple demonstration; for interactive control, extend the code with serial commands.

## Related Resources
- Pin definition: `../pin_definitions/F24/F24_pin_definition.md`