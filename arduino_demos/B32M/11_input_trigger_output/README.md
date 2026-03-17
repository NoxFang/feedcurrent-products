# FeedCurrent B32M Controller Arduino Example 11: Digital Input Trigger Output

## Description
This example links the 32 digital inputs to the 32 MOSFET outputs on the B32M board. When an input is triggered (connected to GND), the corresponding output activates.

## File Structure
- `src/B32M_11_input_trigger_output.ino` – Arduino source code.
- `precompiled/B32M_11_input_trigger_output.bin` – Precompiled firmware binary for ESP32-S3.

## Using the Precompiled Binary
Flash `precompiled/B32M_11_input_trigger_output.bin` to address `0x0` using ESP Flash Download Tool or `esptool.py`.

## Compiling from Source
- **Environment**: Arduino IDE with ESP32-S3 board support.
- **Dependencies**: Install `PCF8575` library (e.g., by Rob Tillaart) via Library Manager.
- **Steps**: Open the `.ino` file, select `esp32-s3-devkitc-1`, and upload.

## Expected Behavior
- Input 1 (PCF8575 input pin 0) → Output 1 (PCF8575 output pin), and so on.
- Connecting an input to GND will activate its corresponding output.
- Inputs have pull-up resistors (active LOW).

## Important Notes
- **Output PCF8575 chips**: addresses `0x26` (outputs 1-8, 25-32), `0x25` (outputs 9-16), `0x24` (outputs 17-24).
- **Input PCF8575 chips**: addresses `0x22` (inputs 1-16), `0x25` (inputs 17-24), `0x26` (inputs 25-32).
- **I2C pins**: SDA=GPIO8, SCL=GPIO18.
- **Serial Monitor** shows debug messages at 115200 baud.
