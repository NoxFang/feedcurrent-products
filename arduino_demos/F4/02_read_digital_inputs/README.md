# F4 Arduino Example 02: Read Digital Input Ports State

## Description
This example reads the state of the 4 digital input ports on the F4 board using the PCF8574 I/O expander (address `0x24`). It prints the binary state of each input to the Serial Monitor every 500 milliseconds.

## File Structure
- `src/F4_02_read_digital_inputs.ino` – Arduino source code.
- `precompiled/F4_02_read_digital_inputs.bin` – Precompiled firmware binary for ESP32‑S3.

## Using the Precompiled Binary
Flash `precompiled/F4_02_read_digital_inputs.bin` to address `0x0` using ESP Flash Download Tool or `esptool.py`.

## Compiling from Source
- **Environment**: Arduino IDE with ESP32‑S3 board support.
- **Dependencies**: Install `PCF8574` library via Library Manager.
- **Steps**: Open the `.ino` file, select `esp32-s3-devkitc-1`, and upload.

## Expected Output
After uploading, open the Serial Monitor at **115200 baud**. You will see a line like this every 500 ms:
Input state: 0000

Each digit represents the state of the corresponding input (0 = ON, 1 = OFF), in the order Input 1 to Input 4.

## Important Notes
- **I2C pins**: SDA=GPIO8, SCL=GPIO18.
- **PCF8574**: I2C address `0x24`, inputs connected to pins P0‑P3 (active LOW).
- Inputs have pull‑up resistors, so they read HIGH when open. Connect to GND to trigger LOW.
- The example reads only the first 4 inputs (P0‑P3); pins P4‑P7 are not used.
