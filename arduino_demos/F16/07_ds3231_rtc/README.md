# F16 Arduino Example 07: DS3231 Real‑Time Clock

## Description
This example demonstrates how to read and set the time on the DS3231 RTC module using simple serial commands. The board's I2C interface is used to communicate with the RTC.

- **Commands**:
  - `current time` – Prints the current date and time from the RTC.
  - `DYYYY-MM-DDTHH:MM:SS` – Sets the RTC to the specified date and time.  
    Example: `D2025-03-19T14:30:45`
- On startup, the current time is automatically printed.

## File Structure
- `src/F16_07_ds3231_rtc.ino` – Arduino source code.
- `precompiled/F16_07_ds3231_rtc.bin` – Precompiled firmware binary for ESP32‑S3.

## Using the Precompiled Binary
Flash `precompiled/F16_07_ds3231_rtc.bin` to address `0x0` using ESP Flash Download Tool or `esptool.py`.

## Compiling from Source
- **Environment**: Arduino IDE with ESP32‑S3 board support.
- **Dependencies**:
  - `Wire` library (included)
  - `DS3231` library – this example uses a custom `DS3231.h` (not the Adafruit RTClib). The library must be installed in your Arduino libraries folder.
- **Steps**: Open the `.ino` file, select `esp32-s3-devkitc-1`, and upload.

## Hardware Setup
The F16 board includes an onboard DS3231 RTC module. No external wiring is required.

| Component | Connection |
|-----------|------------|
| SDA       | GPIO8      |
| SCL       | GPIO18     |

Ensure a CR2032 battery is installed on the RTC module to maintain time when the main power is off.

## Expected Behavior
1. After reset, the Serial Monitor shows the current RTC time:
Current time is: 2025-3-19 14:30:45
2. You can send commands via the Serial Monitor (115200 baud):
- **Set time**: Enter `D2025-03-19T14:30:45` and press Enter.  
  The board will respond with `Setting time...` and `Time set.`
- **Query time**: Enter `current time` and press Enter.  
  The board will print the current RTC time.
3. If an invalid command is entered, the board prints the received string (for debugging) and ignores it.

## Important Notes
- **Serial Monitor**: Set baud rate to **115200**.
- The RTC is set to **24‑hour mode**.
- The command string must be exactly 20 characters long and follow the format `DYYYY-MM-DDTHH:MM:SS`. Any deviation will be ignored.
- This example does not include alarm, temperature, or battery monitoring features.

## Related Resources
- Pin definition: `../pin_definitions/F16/F16_pin_definition.md`