# AIO Hybrid Arduino Example 02: Read Digital Input Ports State

## Description
This example demonstrates how to read the 12 digital input ports on the AIO Hybrid board using the PCF8575 I/O expander (address `0x24`). The program reads pins P0 to P11 and prints their combined state as a 12‑bit binary value to the Serial Monitor every 500 milliseconds.

## File Structure
- `src/AIO_02_read_digital_inputs.ino` – Arduino source code.
- `precompiled/AIO_02_read_digital_inputs.bin` – Precompiled firmware binary for ESP32‑S3 (to be added).

## Using the Precompiled Binary
1. Download the `.bin` file from the `precompiled/` folder.
2. Use the official **ESP Flash Download Tool** or `esptool.py` to flash it to the AIO Hybrid controller.
3. **Flash Address**: `0x0` (as indicated in the forum post).

## Compiling from Source
1. **Environment**: Install Arduino IDE and add ESP32‑S3 board support (via Boards Manager).
2. **Dependencies**:
   - `Wire.h` (built‑in)
   - `PCF8575.h` – Install via Library Manager (search for "PCF8575" by Renzo Mischianti or similar).
3. **Steps**:
   - Open `src/AIO_02_read_digital_inputs.ino` in Arduino IDE.
   - Select the correct board (`esp32-s3-devkitc-1`) and port.
   - Compile and upload.

## Expected Output
After uploading, open the Serial Monitor at **115200 baud**. You will see output like:Input state: 0=ON, 1=OFF
Input state: 000000000000
Input state: 000000000001
...
The 12‑bit binary number represents the states of inputs P11 (leftmost) to P0 (rightmost). A `0` indicates the input is active (connected to GND), and `1` indicates inactive (with pull‑up).

## Important Notes
- **PCF8575**: I2C address `0x24`, inputs connected to pins P0–P11 (active **LOW**).
- **I2C pins**: SDA=GPIO8, SCL=GPIO18.
- **Inputs have pull‑up resistors** on the AIO Hybrid board, so they read HIGH when open.
- The example reads only the first 12 inputs (P0–P11); pins P12–P15 are not used.
- The Serial Monitor displays the binary value with the most significant bit (P11) on the left.