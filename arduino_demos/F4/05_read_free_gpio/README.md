# F4 Arduino Example 05: Read Free GPIO State

## Description
This example monitors the state of 8 free GPIO pins on the F4 board. Whenever a pin changes state (HIGH → LOW or LOW → HIGH), the event is printed to the Serial Monitor.

## File Structure
- `src/F4_05_read_free_gpio.ino` – Arduino source code.
- `precompiled/F4_05_read_free_gpio.bin` – Precompiled firmware binary for ESP32‑S3.

## Using the Precompiled Binary
Flash `precompiled/F4_05_read_free_gpio.bin` to address `0x0` using ESP Flash Download Tool or `esptool.py`.

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
| GPIO13 | Free GPIO (no pull‑up) |
| GPIO12 | RF433 receiver / free GPIO (no pull‑up) |
| GPIO40 | 1‑Wire / free GPIO (with pull‑up) |

All pins are configured as digital inputs with **no internal pull‑up**. External pull‑ups may be required for reliable reading on pins without on‑board resistors.

## Expected Output
After uploading, open the Serial Monitor at **115200 baud**. When a pin state changes, you will see a message like:
GPIO 48 changed to HIGH
GPIO 40 changed to LOW

No output is printed when pins remain unchanged.

## Usage
1. Connect external switches or signals to the desired GPIO pins.
2. Upload the sketch to the F4 board.
3. Open the Serial Monitor at 115200 baud.
4. Change the state of any monitored pin (connect to GND for LOW, leave floating or connect to 3.3V for HIGH) and observe the printed messages.

## Important Notes
- Pins **GPIO48, GPIO47, GPIO21, GPIO15, GPIO40** have on‑board pull‑up resistors.
- Pins **GPIO14, GPIO13, GPIO12** have no pull‑up resistors; external pull‑ups may be required for reliable reading.
- GPIO12 is also used for the 433MHz receiver – avoid conflicts if using that module.
- The polling delay is set to 100 ms, which can be adjusted in the code.

## Related Resources
- Pin definition: `../pin_definitions/F4/F4_pin_definition.md`