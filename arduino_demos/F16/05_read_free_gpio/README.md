# F16 Arduino Example 05: Read Free GPIO Status

## Description
This example monitors the state (HIGH/LOW) of eight free GPIO pins on the F16 board. When any pin changes state, the new status is printed to the Serial Monitor. This is useful for detecting switch presses, sensor signals, or general digital input monitoring.

## File Structure
- `src/F16_05_read_free_gpio.ino` – Arduino source code.
- `precompiled/F16_05_read_free_gpio.bin` – Precompiled firmware binary for ESP32‑S3.

## Using the Precompiled Binary
Flash `precompiled/F16_05_read_free_gpio.bin` to address `0x0` using ESP Flash Download Tool or `esptool.py`.

## Compiling from Source
- **Environment**: Arduino IDE with ESP32‑S3 board support.
- **Dependencies**: None beyond the standard ESP32 core.
- **Steps**: Open the `.ino` file, select `esp32-s3-devkitc-1`, and upload.

## Monitored GPIO Pins
| Pin | GPIO Number |
|-----|-------------|
| 1   | 48          |
| 2   | 47          |
| 3   | 21          |
| 4   | 15          |
| 5   | 14          |
| 6   | 13          |
| 7   | 12          |
| 8   | 40          |

**Note**: These pins are free for general‑purpose input usage. They are configured as inputs with no internal pull‑up or pull‑down (high impedance). If you need a defined logic level when the pin is not driven, add an external pull‑up or pull‑down resistor.

## Expected Behavior
- On startup, the Serial Monitor displays: `GPIO Status Monitoring Started`
- The board continuously reads the state of all eight pins.
- When a pin changes state (from LOW to HIGH or HIGH to LOW), a message is printed:
GPIO 48 changed to HIGH
GPIO 47 changed to LOW
- The cycle repeats indefinitely, checking for changes every 100 ms.

## Important Notes
- **Serial Monitor**: Set baud rate to **115200**.
- No external hardware is required to run this example; you can test by connecting a jumper wire from a monitored GPIO to 3.3V (HIGH) or GND (LOW). Always ensure the voltage does not exceed 3.3V.
- The monitoring delay (100 ms) can be adjusted in the code.

## Related Resources
- Pin definition: `../pin_definitions/F16/F16_pin_definition.md`