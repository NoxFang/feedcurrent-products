# CO16 Arduino Example 05: Read PT100 Temperature Sensor

## Description
This example demonstrates how to read up to four PT100 temperature sensors on the CO16 board using a MAX31865 RTD-to-digital converter and an NX3L4051PW analog multiplexer.  
The code selects each PT100 channel, reads the raw RTD value, calculates resistance and temperature, and prints the results to the Serial Monitor.

- **MAX31865**: SPI interface (software SPI)
- **Multiplexer**: NX3L4051PW, controlled by S1 and S2 (S3 fixed LOW)
- **Channels**: 4 PT100 inputs (CH1–CH4)
- **Wiring**: 3-wire RTD configuration

## File Structure
- `src/CO16_05_read_pt100_temperature.ino` – Arduino source code.
- `precompiled/CO16_05_read_pt100_temperature.bin` – Precompiled firmware binary for ESP32‑S3.

## Using the Precompiled Binary (.bin)
1. Download the `.bin` file from the `precompiled/` folder.
2. Use the official **ESP Flash Download Tool** or `esptool.py` to flash it to the CO16 controller.
3. **Flash Address**: `0x0`.

## Compiling from Source
1. **Environment**: Install Arduino IDE and add ESP32‑S3 board support (via Boards Manager).
2. **Dependencies**: Install the `Adafruit_MAX31865` library via Library Manager.
3. **Steps**: Open `src/CO16_05_read_pt100_temperature.ino` in Arduino IDE, select the board `esp32-s3-devkitc-1` and the correct port, then compile and upload.

## Hardware Connections
| Signal | GPIO | Description |
|--------|------|-------------|
| MAX31865 SCLK | GPIO11 | Software SPI clock |
| MAX31865 MOSI | GPIO10 | Software SPI MOSI |
| MAX31865 MISO | GPIO12 | Software SPI MISO |
| MAX31865 CS   | GPIO14 | Chip select |
| MUX S1        | GPIO7  | Multiplexer channel select |
| MUX S2        | GPIO21 | Multiplexer channel select |

**Note**: The multiplexer S3 pin is fixed LOW on the CO16 board, so only S1 and S2 are used to select channels 1–4.

## Expected Behavior
- On startup, the Serial Monitor (115200 baud) displays:
```
FeedCurrent CO16 four-channel PT100 example
MUX S3=LOW S2=21 S1=7; SPI SCLK=11 MOSI=10 MISO=12 CS=14
```
- Every second, the code cycles through all 4 channels and prints for each:
```
CH1 raw=12345 resistance=150.123 ohm temperature=25.67 C fault=0x0
```
- If a fault is detected, the fault code and description are printed (e.g., `RTD_HIGH_THRESHOLD`, `REFIN_LOW_OR_FORCE_OPEN`).

## Important Notes
- **RTD configuration**: The code initializes the MAX31865 for 3-wire PT100 sensors (`MAX31865_3WIRE`).
- **Reference resistor**: 400 Ω, nominal RTD 100 Ω at 0 °C.
- **50 Hz filter**: Enabled via `pt100.enable50Hz(true)` to reduce mains interference.
- **Multiplexer settling time**: 20 ms delay after channel selection.
- **Fault handling**: Faults are printed and cleared automatically.
- Ensure the PT100 sensors are properly connected to the CO16 terminal block and the MAX31865 is correctly wired to the SPI pins.

## Related Resources
- Pin definition: `../pin_definitions/CO16/CO16_pin_definition.md`
- Adafruit MAX31865 library: [https://github.com/adafruit/Adafruit_MAX31865](https://github.com/adafruit/Adafruit_MAX31865)
