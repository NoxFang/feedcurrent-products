# AIO Hybrid Arduino Example 07: How to Use DS3231 RTC Clock

## Description
This example demonstrates how to use the DS3231 Real-Time Clock (RTC) module on the AIO Hybrid board. It initializes the RTC over I2C, reads the current date and time, and allows you to set the time via serial commands.

## File Structure
- `src/AIO_07_ds3231_rtc.ino` – Arduino source code.
- `precompiled/AIO_07_ds3231_rtc.bin` – Precompiled firmware binary for ESP32‑S3 (to be added).

## Using the Precompiled Binary
1. Download the `.bin` file from the `precompiled/` folder.
2. Use the official **ESP Flash Download Tool** or `esptool.py` to flash it to the AIO Hybrid controller.
3. **Flash Address**: `0x0` (as indicated in the forum post).

## Compiling from Source
1. **Environment**: Install Arduino IDE and add ESP32‑S3 board support (via Boards Manager).
2. **Dependencies**:
   - `Wire.h` (built‑in)
   - `DS3231.h` – Install via Library Manager (search for "DS3231" by Eric Ayars or similar).
3. **Steps**:
   - Open `src/AIO_07_ds3231_rtc.ino` in Arduino IDE.
   - Select the correct board (`esp32-s3-devkitc-1`) and port.
   - Compile and upload.

## Serial Commands
After uploading, open the Serial Monitor at **115200 baud**. You can use the following commands:

- **`current time`** – Prints the current date and time read from the RTC.
- **`DYYYY-MM-DDTHH:MM:SS`** – Sets the RTC to the specified date and time.  
  Example: `D2025-03-22T14:30:00` sets the time to March 22, 2025, 14:30:00.

## Expected Output
On startup, the current time is printed:
Current time is: 2025-01-01 00:00:10

After sending `current time`, the same format is displayed:
Current time is: 2025-03-22 14:30:00

After sending a set command (e.g., `D2025-03-22T14:30:00`), you will see:
Received length: 20
D index: 0 T index: 11
Setting time...
Time set.

## Important Notes
- **I2C pins**: SDA=GPIO8, SCL=GPIO18 (as defined in the code).
- **RTC address**: `0x68` (hardware default).
- **Command format**: Case‑sensitive; must be exactly 20 characters long (e.g., `D2025-03-22T14:30:00`). The `D` and `T` positions are fixed.
- **24‑hour mode**: The RTC is configured for 24‑hour format.
- **Unused constants**: The `OPEN_RLY_DATA` etc. are not used in this example and can be ignored.
- **Battery backup**: Ensure the DS3231 has a backup battery (CR2032) to retain time when main power is off.

## Related Resources
- Pin definition: `../pin_definitions/AIO/AIO_pin_definition.md`
- Forum source: https://www.kincony.com/forum/showthread.php?tid=8541