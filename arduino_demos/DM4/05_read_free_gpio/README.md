# Example 05: Read Free GPIO State

## Description

This example monitors the digital state of 8 free GPIO pins on the KinCony DM4 controller (ESP32-S3). Whenever the state of any monitored pin changes, the event is printed to the Serial Monitor.

**Monitored pins:** GPIO40, GPIO7, GPIO48, GPIO47, GPIO13, GPIO14, GPIO21, GPIO0

> **Note:**  
> - GPIO47, GPIO48, and GPIO7 are also 1‑Wire bus pins with on‑board pull‑up resistors.  
> - GPIO0 is the BOOT mode pin; avoid pulling it LOW during startup to prevent entering programming mode.

## Hardware Requirements

### Key Hardware
- KinCony DM4 controller (ESP32-S3)
- Optional: external switches, sensors, or pull resistors on monitored pins

### Pin Definitions

| GPIO | Description |
|------|-------------|
| GPIO40 | 1‑Wire bus 4 / free GPIO (with pull‑up) |
| GPIO7  | 1‑Wire bus 3 / free GPIO (with pull‑up) |
| GPIO48 | 1‑Wire bus 2 / free GPIO (with pull‑up) |
| GPIO47 | 1‑Wire bus 1 / free GPIO (with pull‑up) |
| GPIO13 | Free digital I/O (no pull‑up) |
| GPIO14 | Free digital I/O (no pull‑up) |
| GPIO21 | Free digital I/O (no pull‑up) |
| GPIO0  | Free digital I/O (no pull‑up) – BOOT mode pin |

## Software Requirements

### Dependencies
- Arduino IDE with ESP32-S3 board support
- No additional libraries required

### Key Code

```cpp
#define GPIO_PIN_40 40
#define GPIO_PIN_7  7
#define GPIO_PIN_48 48
#define GPIO_PIN_47 47
#define GPIO_PIN_13 13
#define GPIO_PIN_14 14
#define GPIO_PIN_21 21
#define GPIO_PIN_0  0

pinMode(GPIO_PIN_13, INPUT);
bool state = digitalRead(GPIO_PIN_13);

## Usage

1. Open src/DM4_05_read_free_gpio.ino in Arduino IDE.
2. Select board: ESP32S3 Dev Module.
3. Upload to the DM4 controller.
4. Open Serial Monitor at 115200 baud.
5. Trigger changes on any monitored GPIO (connect to GND or 3.3V) to see state change messages.

## Expected Output
Example output when a pin changes state:
GPIO Status Monitoring Started
GPIO 40 changed to LOW
GPIO 13 changed to HIGH

## Precompiled Firmware
The `precompiled/` directory is reserved for precompiled `.bin` firmware files that can be flashed directly using the ESP32 download tool.