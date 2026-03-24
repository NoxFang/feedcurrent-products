# F8 Arduino Example 02: Read Digital Input Ports State

## Description
This example reads the state of the 8 digital input ports on the F8 board using a single **PCF8575** I/O expander (address `0x24`). It prints the binary state of each input to the Serial Monitor every 500 milliseconds.

## File Structure
- `src/F8_02_read_digital_inputs.ino` – Arduino source code.
- `precompiled/F8_02_read_digital_inputs.bin` – Precompiled firmware binary for ESP32‑S3.

## Using the Precompiled Binary
Flash `precompiled/F8_02_read_digital_inputs.bin` to address `0x0` using ESP Flash Download Tool or `esptool.py`.

## Compiling from Source
- **Environment**: Arduino IDE with ESP32‑S3 board support.
- **Dependencies**: Install `PCF8575` library via Library Manager.
- **Steps**: Open the `.ino` file, select `esp32-s3-devkitc-1`, and upload.

## Expected Output
After uploading, open the Serial Monitor at **115200 baud**. You will see a line like this every 500 ms:
Input state: 00000000

Each digit represents the state of the corresponding input (0 = ON, 1 = OFF), in the order Input 1 to Input 8.

## Important Notes
- **I2C pins**: SDA=GPIO8, SCL=GPIO18.
- **PCF8575**: I2C address `0x24`, inputs connected to pins P0‑P7 (active LOW).
- Inputs have pull‑up resistors, so they read HIGH when open. Connect to GND to trigger LOW.
- The example reads only the first 8 inputs (P0‑P7); pins P8‑P15 are not used.

## Related Resources
- Pin definition: `../pin_definitions/F8/F8_pin_definition.md`