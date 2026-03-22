# TA Example 02: Read Digital Input Ports State

## Overview
This example reads the state of all 12 digital input channels on the KinCony TA via the PCF8575 I/O expander and prints the results to the Serial Monitor in binary format every 500ms.

## Hardware
| Component | Description |
|-----------|-------------|
| PCF8575   | I2C I/O expander @ 0x22 |
| Inputs    | PCF8575 pins P0–P11 (CH1–CH12) |

### Key Pins
| Signal  | GPIO   |
|---------|--------|
| I2C SDA | GPIO8  |
| I2C SCL | GPIO18 |

## Input Channel Mapping
| Channel | PCF8575 Pin |
|---------|-------------|
| IN-CH1  | P0 |
| IN-CH2  | P1 |
| ...     | ... |
| IN-CH12 | P11 |

> Input logic: **0 = ON (triggered)**, **1 = OFF (idle)**

## Dependencies
- `PCF8575.h` - PCF8575 I/O expander library

## Usage
1. Upload the sketch to TA
2. Open Serial Monitor at **115200 baud**
3. Connect a switch to any input channel (CH1–CH12)
4. Observe state changes printed in binary format

## Key Code
```cpp
for (int pin = 0; pin < 12; pin++) {
    if (pcf8575_IN1.read(pin)) {
        state |= (1 << pin);
    }
}
Serial.println(state, BIN);
```

## Precompiled Firmware
The `precompiled/` folder is reserved for pre-built `.bin` firmware files.

## Related Resources
- Pin Definition: `../../../pin_definitions/TA/TA_pin_definition.md`
