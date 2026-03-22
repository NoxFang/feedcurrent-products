# DM32 Example 05: Read Free GPIO State

## Description
This example monitors the state of 8 free GPIO pins on the DM32 board. Whenever a pin changes state (HIGH → LOW or LOW → HIGH), the event is printed to the Serial Monitor.

## Monitored GPIO Pins
| GPIO | Description |
|------|-------------|
| GPIO40 | Free GPIO (1‑Wire 4) |
| GPIO7  | Free GPIO (1‑Wire 3) |
| GPIO48 | Free GPIO (1‑Wire 2) |
| GPIO47 | Free GPIO (1‑Wire 1) |
| GPIO13 | Free GPIO (no pull‑up) |
| GPIO14 | Free GPIO (no pull‑up) |
| GPIO21 | Free GPIO (no pull‑up) |
| GPIO0  | Free GPIO – boot mode pin (avoid pulling LOW during startup) |

## Pin Configuration
All monitored pins are configured as digital inputs with **no internal pull‑up**. External pull‑ups may be required for reliable reading on pins without on‑board resistors.

## Serial Output
After uploading, open the Serial Monitor at **115200 baud**. When a pin state changes, you will see a message like:
GPIO 40 changed to HIGH
GPIO 7 changed to LOW

No output is printed when pins remain unchanged.

## Usage
1. Connect external switches or signals to the desired GPIO pins.
2. Upload the sketch to the DM32 board.
3. Open the Serial Monitor at 115200 baud.
4. Change the state of any monitored pin (connect to GND for LOW, leave floating or connect to 3.3V for HIGH) and observe the printed messages.

## Important Notes
- **GPIO0** is the ESP32‑S3 boot mode pin; avoid pulling it LOW during power‑up to prevent entering programming mode.
- Pins **GPIO47, GPIO48, GPIO40, and GPIO7** have on‑board pull‑up resistors for 1‑Wire applications.
- Pins **GPIO13, GPIO14, GPIO21, and GPIO0** have no pull‑up resistors; external pull‑ups may be required for reliable reading.
- The polling delay is set to 100 ms, which can be adjusted in the code.

## Dependencies
- None (uses built‑in `digitalRead` and `Serial`).

## Related Resources
- DM32 Pin Definition: `../pin_definitions/DM32/DM32_pin_definition.md`