# Example 03: Read ADS1115 Analog Input Ports Value

## Description

This example reads voltage values from all four ADS1115 analog input channels
(A0–A3) on the KinCony DM4 and prints the results in millivolts to the serial
monitor every second.

- **A0, A1**: 0–5 V DC voltage inputs
- **A2, A3**: 4–20 mA current inputs (use appropriate shunt resistor)

## Hardware Requirements

### Key Hardware
- KinCony DM4 controller (ESP32-S3)
- ADS1115 ADC (on-board, I2C 0x48)

### Pin Definitions

| Interface | GPIO / Address |
|-----------|----------------|
| I2C SDA   | GPIO8 |
| I2C SCL   | GPIO18 |
| ADS1115   | I2C 0x48 |

## Software Requirements

### Dependencies
- Arduino IDE with ESP32-S3 board support
- **DFRobot_ADS1115** library — Install via Library Manager

### Key Code

```cpp
#include <DFRobot_ADS1115.h>
DFRobot_ADS1115 ads(&Wire);
ads.setAddr_ADS1115(ADS1115_IIC_ADDRESS0);  // 0x48
ads.setGain(eGAIN_TWOTHIRDS);               // ±6.144V range
ads.init();
int16_t mv = ads.readVoltage(0);            // Read channel A0 in mV
```

## Usage

1. Open `src/DM4_03_read_ads1115.ino` in Arduino IDE
2. Install **DFRobot_ADS1115** library via Library Manager
3. Select board: **ESP32S3 Dev Module**
4. Upload to the DM4 controller
5. Open Serial Monitor at **115200 baud**
6. Observe A0–A3 voltage readings printed every second

## Precompiled Firmware

The `precompiled/` directory is reserved for precompiled `.bin` firmware files.