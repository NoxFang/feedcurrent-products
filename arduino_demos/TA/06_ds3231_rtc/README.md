# TA Example 06: DS3231 RTC Clock

## Overview
This example demonstrates how to use the DS3231 Real-Time Clock module on the KinCony TA. It supports reading the current time and setting the time via serial commands.

## Hardware
| Component | I2C Address |
|-----------|-------------|
| DS3231 RTC | 0x68 |

### Key Pins
| Signal  | GPIO   |
|---------|--------|
| I2C SDA | GPIO8  |
| I2C SCL | GPIO18 |

## Dependencies
- `DS3231.h` - DS3231 RTC library
  - Install via Arduino Library Manager: search "DS3231"
- `Wire.h` - Built-in I2C library

## Usage
1. Install the DS3231 library
2. Upload the sketch to TA
3. Open Serial Monitor at **115200 baud**
4. Use serial commands to interact with the RTC

## Serial Commands
| Command | Description | Example |
|---------|-------------|---------|
| `current time` | Print current date and time | `current time` |
| `DYYYY-MM-DDTHH:MM:SS` | Set date and time | `D2024-09-19T11:50:22` |

## Expected Output
Current time is: 2024-9-19 11:50:22

## Key Code
```cpp
// Print current time
static void PrintfCurTime() {
  int year = rtc.getYear() + 2000;
  Serial.print(year);
  Serial.print("-");
  Serial.print(rtc.getMonth(bCentury), DEC);
  Serial.print("-");
  Serial.print(rtc.getDate(), DEC);
  Serial.print(" ");
  Serial.print(rtc.getHour(h12Flag, pmFlag), DEC);
  Serial.print(":");
  Serial.print(rtc.getMinute(), DEC);
  Serial.print(":");
  Serial.println(rtc.getSecond(), DEC);
}

// Set time from serial command
if (serial_cmd_rcv.length() == 20 && serial_cmd_rcv[0] == 'D' && serial_cmd_rcv[11] == 'T') {
    rtc.setYear((byte)serial_cmd_rcv.substring(3, 5).toInt());
    rtc.setMonth((byte)serial_cmd_rcv.substring(6, 8).toInt());
    rtc.setDate((byte)serial_cmd_rcv.substring(9, 11).toInt());
    rtc.setHour((byte)serial_cmd_rcv.substring(12, 14).toInt());
    rtc.setMinute((byte)serial_cmd_rcv.substring(15, 17).toInt());
    rtc.setSecond((byte)serial_cmd_rcv.substring(18).toInt());
    Serial.println("Time set.");
}

## Precompiled Firmware
The `precompiled/` folder is reserved for pre-built `.bin` firmware files.

## Related Resources
Pin Definition: `../../../pin_definitions/TA/TA_pin_definition.md`