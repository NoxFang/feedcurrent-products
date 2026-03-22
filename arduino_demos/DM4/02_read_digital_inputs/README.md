# Example 02: Read Digital Input Ports State

## Description

This example reads the state of the 4 digital input channels on the KinCony DM4
using the PCF8574 I2C I/O expander (address 0x24). It prints a message to the
serial monitor whenever an input is detected as LOW (pressed/active).

## Hardware Requirements

### Key Hardware
- KinCony DM4 controller (ESP32-S3)
- PCF8574 I/O expander (on-board, I2C 0x24)

### Pin Definitions

| Interface | GPIO |
|-----------|------|
| I2C SDA   | GPIO8 |
| I2C SCL   | GPIO18 |

| PCF8574 Pin | Input Channel |
|-------------|---------------|
| P0 | Input 1 |
| P1 | Input 2 |
| P2 | Input 3 |
| P3 | Input 4 |

## Software Requirements

### Dependencies
- Arduino IDE with ESP32-S3 board support
- **PCF8574** library — Install via Library Manager

### Key Code

```cpp
#include "PCF8574.h"
PCF8574 pcf8574(0x24);
pcf8574.pinMode(P0, INPUT);
pcf8574.begin();
uint8_t val = pcf8574.digitalRead(P0);  // LOW = active
```

## Usage

1. Open `src/DM4_02_read_digital_input.ino` in Arduino IDE
2. Install **PCF8574** library via Library Manager
3. Select board: **ESP32S3 Dev Module**
4. Upload to the DM4 controller
5. Open Serial Monitor at **115200 baud**
6. Activate any of the 4 digital inputs to see "KEY1–KEY4 PRESSED"

## Precompiled Firmware

The `precompiled/` directory is reserved for precompiled `.bin` firmware files.

