# T64M Arduino Example 07: I2C Scanner

## Description
This example scans two independent I2C buses on the T64M board and reports the addresses of all detected devices.  
- **Bus 1**: SDA=GPIO48, SCL=GPIO47 (typically used for output/relay modules)  
- **Bus 2**: SDA=GPIO12, SCL=GPIO11 (typically used for input modules)  

Useful for debugging I2C connections and verifying device addresses.

## File Structure
- `src/T64M_07_i2c_scanner.ino` – Arduino source code.
- `precompiled/T64M_07_i2c_scanner.bin` – Precompiled firmware binary for ESP32‑S3.

## Using the Precompiled Binary
Flash `precompiled/T64M_07_i2c_scanner.bin` to address `0x0` using ESP Flash Download Tool or `esptool.py`.

## Compiling from Source
- **Environment**: Arduino IDE with ESP32‑S3 board support.
- **Dependencies**: `Wire` library (built‑in).
- **Steps**: Open the `.ino` file, select `esp32-s3-devkitc-1`, and upload.

## Hardware Connections
Two independent I2C buses are used:

| Bus 1 (Outputs) | GPIO |
|-----------------|------|
| SDA             | 48   |
| SCL             | 47   |

| Bus 2 (Inputs)  | GPIO |
|-----------------|------|
| SDA             | 12   |
| SCL             | 11   |

## Expected Behavior
- On startup, the Serial Monitor (115200 baud) scans both buses and prints found device addresses.
- Example output:
  ```cpp
  Scanning IIC Bus-1 at 100kHz...
  I2C device found at address 0x20 ✓
  I2C device found at address 0x21 ✓
  Scan completed.

  Scanning IIC Bus-2 at 100kHz...
  I2C device found at address 0x24 ✓
  I2C device found at address 0x25 ✓
  Scan completed.
  ```

## Important Notes
- **Serial Monitor**: Set baud rate to **115200**.
- The scan runs only once; to rescan, reset the board.
- Addresses are printed in hexadecimal format.

## Related Resources
- Pin definition: `../pin_definitions/T64M/T64M_pin_definition.md`