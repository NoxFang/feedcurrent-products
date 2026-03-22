# DM16 Arduino Example 02: Read Digital Input Ports State

## Description
This example reads the state of all 16 digital input channels on the DM16 board using a PCF8575 I/O expander. It prints the binary state of each channel (0 = ON, 1 = OFF) to the Serial Monitor every 500 milliseconds.

## Hardware Connections
| Signal | GPIO |
|--------|------|
| I2C SDA | GPIO8 |
| I2C SCL | GPIO18 |
| PCF8575 I2C Address | 0x22 |

## Input Mapping
The PCF8575 pins are mapped to the 16 physical inputs as follows:

| Input | PCF8575 Pin |
|-------|-------------|
| Input 1 | P8 |
| Input 2 | P9 |
| Input 3 | P10 |
| Input 4 | P11 |
| Input 5 | P12 |
| Input 6 | P13 |
| Input 7 | P14 |
| Input 8 | P15 |
| Input 9 | P0 |
| Input 10 | P1 |
| Input 11 | P2 |
| Input 12 | P3 |
| Input 13 | P4 |
| Input 14 | P5 |
| Input 15 | P6 |
| Input 16 | P7 |

## Serial Output
After uploading, open the Serial Monitor at **115200 baud**. You will see a single line repeated every 500 ms:
Input state: 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0

Each digit represents the state of the corresponding input (0 = ON, 1 = OFF), in the order Input 1 to Input 16.

## Usage
1. Connect digital inputs (e.g., buttons or switches) to the DM16 input terminals.
2. Upload the sketch to the DM16 board.
3. Open the Serial Monitor at 115200 baud.
4. Observe the input states changing when you activate the inputs.

## Notes
- The sketch initializes the I2C bus with SDA=GPIO8, SCL=GPIO18.
- PCF8575 pins are configured as inputs with internal pull‑ups (active‑LOW).
- The polling delay is 500 ms (adjustable in the code).

## Dependencies
- `Wire` library (built‑in)
- `PCF8575` library (install via Library Manager)

## Related Resources
- DM16 Pin Definition: `../pin_definitions/DM16/DM16_pin_definition.md`