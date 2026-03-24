# F8 Arduino Example 05: Read Free GPIO State

## Description
This example monitors the state of 7 free GPIO pins on the F8 board. It reads the state of each pin every 500 ms and prints the results to the Serial Monitor.

## File Structure
- `src/F8_05_read_free_gpio.ino` – Arduino source code.
- `precompiled/F8_05_read_free_gpio.bin` – Precompiled firmware binary for ESP32‑S3.

## Using the Precompiled Binary
Flash `precompiled/F8_05_read_free_gpio.bin` to address `0x0` using ESP Flash Download Tool or `esptool.py`.

## Compiling from Source
- **Environment**: Arduino IDE with ESP32‑S3 board support.
- **Dependencies**: None (uses built‑in `digitalRead`).
- **Steps**: Open the `.ino` file, select `esp32-s3-devkitc-1`, and upload.

## Monitored GPIO Pins
| GPIO | Description |
|------|-------------|
| GPIO48 | 1‑Wire 2 / free GPIO (with pull‑up) |
| GPIO47 | 1‑Wire 1 / free GPIO (with pull‑up) |
| GPIO21 | 1‑Wire 3 / free GPIO (with pull‑up) |
| GPIO15 | 1‑Wire 4 / free GPIO (with pull‑up) |
| GPIO14 | Free GPIO (no pull‑up) |
| GPIO40 | 1‑Wire / free GPIO (with pull‑up) |
| GPIO0  | Free GPIO – boot mode pin (avoid pulling LOW during startup) |

All pins are configured as digital inputs with **no internal pull‑up** (external pull‑ups may be required for reliable reading on pins without on‑board resistors).

## Expected Output
After uploading, open the Serial Monitor at **115200 baud**. You will see a line like this every 500 ms:
GPIO48 State: 1
GPIO47 State: 1
GPIO21 State: 1
GPIO15 State: 1
GPIO14 State: 0
GPIO40 State: 1
GPIO0 State: 0

## Important Notes
- Pins **GPIO48, GPIO47, GPIO21, GPIO15, GPIO40** have on‑board pull‑up resistors.
- Pin **GPIO14** has no pull‑up; external pull‑up may be required.
- **GPIO0** is the ESP32‑S3 boot mode pin; avoid pulling it LOW during power‑up to prevent entering programming mode.
- The example does **not** include change detection; it prints all states every 500 ms.

## Related Resources
- Pin definition: `../pin_definitions/F8/F8_pin_definition.md`