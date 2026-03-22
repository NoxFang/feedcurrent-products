# DM32 Example 01: 32‑Channel DAC Output by Digital Input Buttons

## Description
This example demonstrates how to control 32‑channel DAC output using digital input buttons connected to two PCF8575 I/O expanders. A **long press** on a button gradually increases the corresponding DAC output value. Short presses are detected but do not trigger any action.

## Hardware Connections
- **I2C Bus**: SDA=GPIO8, SCL=GPIO18, 100kHz
- **PCF8575 #1**: Address `0x22`, inputs 1‑16
- **PCF8575 #2**: Address `0x24`, inputs 17‑32
- **DAC Modbus UART**: RX=GPIO4, TX=GPIO6, baud rate 115200
- **Modbus Device Address**: 1

## Button Wiring
- Each button connects the corresponding PCF8575 pin to GND.
- Internal pull‑up resistors are enabled; button press = LOW (active‑low).

## Operation
- **Short press** (< detection time): Detected but **no action**.
- **Long press** (≥ 50 ms, continues while held): The DAC value for the corresponding channel increases by **100 every 100 ms**, starting from 0. The increment continues until the button is released or the value reaches approximately 4000.

## DAC Channels
| Channel | Modbus Register Address |
|---------|-------------------------|
| CH1     | 4000 (0x0FA0) |
| CH2     | 4001 (0x0FA1) |
| ...     | ... |
| CH32    | 4031 (0x0FBF) |

## Serial Output
After uploading, open the Serial Monitor at **115200 baud**. When a button is pressed, you will see:

key 01 # is pressed!
key_long_press_time = 100, current_light = 100
key_long_press_time = 200, current_light = 200
...
key is released!

## Usage
1. Connect 32 buttons to the PCF8575 inputs (active‑low).
2. Upload the sketch to the DM32 board.
3. Open the Serial Monitor at 115200 baud.
4. Press and hold a button to increase the corresponding DAC output.
5. Release to stop the increase.

## Notes
- The DAC output value does **not** reset to zero on release; it stays at the last set value.
- Short presses do not toggle the output; only long‑press ramping is implemented.
- The example uses two PCF8575 chips. For DM16, change `DM_NUMS` to 16 (and optionally remove the second chip).
- The code includes a simple debounce delay (10 ms) and a 100 ms increment interval.

## Dependencies
- `Adafruit_PCF8575` library
- `HardwareSerial` (built‑in)

## Related Resources
- DM32 Pin Definition: `../pin_definitions/DM32/DM32_pin_definition.md`