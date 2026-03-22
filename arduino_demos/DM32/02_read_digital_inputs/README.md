# DM32 Example 02: Read Digital Input Ports State

## Overview

This example demonstrates how to read 32 digital input ports from DM32 using two PCF8575 GPIO expanders.

**Features**:
- Read all 32 digital input states
- Display input status on Serial Monitor (0=ON, 1=OFF)
- Update rate: 500ms

---

## Hardware Requirements

### PCF8575 GPIO Expanders (x2)
- **PCF8575 #1**: I2C Address 0x22, Controls Inputs 1-16
- **PCF8575 #2**: I2C Address 0x24, Controls Inputs 17-32

### I2C Bus
- **SDA Pin**: GPIO8
- **SCL Pin**: GPIO18

---

## Digital Input Mapping

### PCF8575 #1 (I2C 0x22) - Inputs 1-16
| Physical Input | PCF8575 Pin | Description |
|--------------|---------------|-------------|
| DI1 | P8 | Digital input 1 |
| DI2 | P9 | Digital input 2 |
| DI3 | P10 | Digital input 3 |
| DI4 | P11 | Digital input 4 |
| DI5 | P12 | Digital input 5 |
| DI6 | P13 | Digital input 6 |
| DI7 | P14 | Digital input 7 |
| DI8 | P15 | Digital input 8 |
| DI9 | P0 | Digital input 9 |
| DI10 | P1 | Digital input 10 |
| DI11 | P2 | Digital input 11 |
| DI12 | P3 | Digital input 12 |
| DI13 | P4 | Digital input 13 |
| DI14 | P5 | Digital input 14 |
| DI15 | P6 | Digital input 15 |
| DI16 | P7 | Digital input 16 |

### PCF8575 #2 (I2C 0x24) - Inputs 17-32
| Physical Input | PCF8575 Pin | Description |
|--------------|---------------|-------------|
| DI17 | P0 | Digital input 17 |
| DI18 | P1 | Digital input 18 |
| DI19 | P2 | Digital input 19 |
| DI20 | P3 | Digital input 20 |
| DI21 | P4 | Digital input 21 |
| DI22 | P5 | Digital input 22 |
| DI23 | P6 | Digital input 23 |
| DI24 | P7 | Digital input 24 |
| DI25 | P8 | Digital input 25 |
| DI26 | P9 | Digital input 26 |
| DI27 | P10 | Digital input 27 |
| DI28 | P11 | Digital input 28 |
| DI29 | P12 | Digital input 29 |
| DI30 | P13 | Digital input 30 |
| DI31 | P14 | Digital input 31 |
| DI32 | P15 | Digital input 32 |

---

## Library Dependencies

- `Wire.h` - Built-in I2C library
- `PCF8575.h` - For PCF8575 GPIO control

---

## Serial Monitor Output

```
DI1-DI32: 0 1 1 0 1 1 0 1 1 0 1 1 1 1 1 0 1 1 1 1 0 1 1 0 1 1
```

Each number represents input state:
- `0` = ON (active-low, button pressed)
- `1` = OFF (inactive, button released)

---

## Important Notes

- **Input Logic**: The PCF8575 uses active-low logic (0=ON, 1=OFF) with built-in pull-up resistors.
- **Update Rate**: Input states are read and displayed every 500ms.
- **Pin Mapping**: Each PCF8575 has a specific pin order to match the physical input numbers.
- **Two I2C Devices**: DM32 uses two PCF8575 chips (0x22 and 0x24) to provide 32 inputs.

