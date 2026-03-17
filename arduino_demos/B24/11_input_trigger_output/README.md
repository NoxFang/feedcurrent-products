# FeedCurrent B24 Controller Arduino Example 11: Digital Input Trigger Output

## Description
This example links the 24 digital inputs to the 24 relay outputs on the B24 board. When an input is triggered (connected to GND), the corresponding relay activates.

## File Structure
- `src/B24_11_input_trigger_output.ino` – Arduino source code.
- `precompiled/B24_11_input_trigger_output.bin` – Precompiled firmware binary for ESP32-S3.

## Using the Precompiled Binary
Flash `precompiled/B24_11_input_trigger_output.bin` to address `0x0` using ESP Flash Download Tool or `esptool.py`.

## Compiling from Source
- **Environment**: Arduino IDE with ESP32-S3 board support.
- **Dependencies**: Install `PCF8575` library (e.g., by Rob Tillaart) via Library Manager.
- **Steps**: Open the `.ino` file, select `esp32-s3-devkitc-1`, and upload.

## Expected Behavior
- Input 1 (PCF8575 input pin 0) → Relay 1 (PCF8575 output pin 0), and so on.
- Connecting an input to GND will activate its corresponding relay.
- Inputs have pull-up resistors (active LOW).

## Important Notes
- **Output PCF8575 chips**: addresses `0x22`, `0x24`, `0x25`, pins 0-23.
- **Input PCF8575 chips**: addresses `0x22`, `0x25`, pins 0-23.
- **I2C pins**: SDA=GPIO8, SCL=GPIO18.
- **Serial Monitor** shows debug messages at 115200 baud.
