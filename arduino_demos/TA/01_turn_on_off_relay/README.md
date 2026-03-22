# TA Example 01: Turn ON/OFF Output (Relay Control)

## Overview
This example demonstrates how to control the 2 relay outputs on the KinCony TA using the PCF8575 I/O expander via I2C. Relays toggle on/off sequentially every 2 seconds.

## Hardware
| Component | Description |
|-----------|-------------|
| PCF8575   | I2C I/O expander @ 0x22 |
| Relay 1   | PCF8575 pin 14 (CH15) |
| Relay 2   | PCF8575 pin 15 (CH16) |

### Key Pins
| Signal | GPIO |
|--------|------|
| I2C SDA | GPIO8 |
| I2C SCL | GPIO18 |

## Dependencies
- `Wire.h` - Arduino I2C library (built-in)
- `PCF8575.h` - PCF8575 I/O expander library

## Usage
1. Install the PCF8575 library via Arduino Library Manager
2. Open `TA_01_turn_on_off_output.ino` in Arduino IDE
3. Select board: **ESP32S3 Dev Module**
4. Upload and open Serial Monitor at **115200 baud**
5. Observe Relay 1 and Relay 2 toggling every 2 seconds

## Key Code
```cpp
#define RELAY1 14  // PCF8575 pin 14
#define RELAY2 15  // PCF8575 pin 15

pcf8575.write(RELAY1, LOW);   // Turn relay ON  (active-LOW)
pcf8575.write(RELAY1, HIGH);  // Turn relay OFF
```

## Precompiled Firmware
The `precompiled/` folder is reserved for pre-built `.bin` firmware files that can be flashed directly using ESP32 Flash Download Tool.

## Related Resources
- Pin Definition: `../../../pin_definitions/TA/TA_pin_definition.md`
- ESPHome Config: `../../../esphome_configs/TA/TA_esphome.yaml`
