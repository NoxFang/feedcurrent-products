# DM16 Arduino Example 01: 16 Channel DAC Output with Button Control

## Description
This example demonstrates 16‑channel DAC control via Modbus RTU. It reads 16 digital input buttons connected to a PCF8575 I/O expander (address `0x22`). A **long press** on a button increases the corresponding DAC output value. Short presses are detected but do not change the output.

## Hardware Connections
| Function | Pin / Address |
|----------|---------------|
| I2C SDA | GPIO8 |
| I2C SCL | GPIO18 |
| PCF8575 (inputs) | I2C 0x22 |
| Modbus UART RX | GPIO4 |
| Modbus UART TX | GPIO6 |
| Modbus Baud Rate | 115200 |

### DAC Channel Mapping
| Channel | Modbus Register Address |
|---------|-------------------------|
| 1 | 4000 |
| 2 | 4001 |
| ... | ... |
| 16 | 4015 |

The DAC outputs are controlled by an ARM CPU on the DM16 board. The register value range is 0–4095 (12‑bit), but this example only ramps up to approximately 4000.

## Features
- **Button Input**: 16 buttons (active‑LOW) via PCF8575.
- **Long Press**: While a button is held down, the corresponding DAC output value increases by **100 every 100 ms**, starting from 0. The increment continues until the button is released or the value reaches ~4000.
- **Short Press**: Detected but **no action** (no toggle, no reset).
- **Configurable Channel Count**: Set `DM_NUMS` to 16 or 32 to support DM32 with a second PCF8575 at address `0x24`.

## Usage
1. Connect buttons between PCF8575 pins P0–P15 and GND (internal pull‑ups enabled).
2. Upload the sketch to the DM16 board.
3. Open the Serial Monitor at **115200 baud**.
4. Press and hold any button to increase the corresponding DAC output.
5. Serial output shows key presses and the current DAC value.

## Expected Serial Output
Adafruit PCF8575 button read test
Find 1_PCF8575!
Now, starting!
key 01 # is pressed!
key_long_press_time = 100, current_light = 100
key_long_press_time = 200, current_light = 200
...
key is released!

## Notes
- The example does **not** implement short‑press toggling or decreasing values.
- Long‑press increments stop when the button is released; the value stays at the last level.
- For 32‑channel version (DM32), set `DM_NUMS` to `32` and connect a second PCF8575 at address `0x24`.

## Dependencies
- `Adafruit_PCF8575` library
- `Wire` library
- `HardwareSerial` (built‑in)

## Related Resources
- DM16 Pin Definition: `../pin_definitions/DM16/DM16_pin_definition.md`
