# FeedCurrent B24M Controller Arduino Example 11: Input Trigger Output

## Description
This example demonstrates input-triggered output control on the B24M board. It reads the state of 24 digital inputs from PCF8575 chips and directly controls 24 relay outputs accordingly. When an input is active (LOW), the corresponding relay turns ON.

## File Structure
- `src/B24M_11_input_trigger_output.ino` – Arduino source code.
- `precompiled/B24M_11_input_trigger_output.bin` – Precompiled firmware binary for ESP32-S3.

## Using the Precompiled Binary
Flash `precompiled/B24M_11_input_trigger_output.bin` to address `0x0` using ESP Flash Download Tool or `esptool.py`.

## Compiling from Source
- **Environment**: Arduino IDE with ESP32-S3 board support.
- **Dependencies**: Install `PCF8575` library (e.g., by Rob Tillaart) via Library Manager.
- **Steps**: Open the `.ino` file, select `esp32-s3-devkitc-1`, and upload.

## Expected Behavior
The device reads all 24 digital inputs and controls the corresponding relays in real-time. When input 1 is active, relay 1 turns on, and so on.

## Important Notes
- **PCF8575 (Inputs 1-16)**: I2C address `0x22`, pins P8-P15 → inputs 1-8, P0-P7 → inputs 9-16.
- **PCF8575 (Inputs 17-24 + Outputs 1-8)**: I2C address `0x25`, pins P0-P7 → inputs 17-24, P8-P15 → outputs 1-8.
- **PCF8575 (Outputs 9-24)**: I2C address `0x24`, pins P0-P15.
- **I2C pins**: SDA=GPIO8, SCL=GPIO18.
- **Input type**: Dry contact inputs (active LOW, LOW = ON).
- **Relay control**: Active LOW (LOW = relay ON).
- **Serial Monitor** shows debug messages at 115200 baud.
