# Example 04: RS485 Communication Test

## Description

This example tests RS485 serial communication on the FeedCurrent DM4 controller
(ESP32-S3). It sends a test message every 3 seconds and prints any received reply
to the serial monitor.

## Hardware Requirements

### Key Hardware
- FeedCurrent DM4 controller (ESP32-S3)
- RS485 transceiver (on-board)
- External RS485 device or loopback connector for testing

### Pin Definitions

| Signal | GPIO |
|--------|------|
| RS485 RXD | GPIO38 |
| RS485 TXD | GPIO39 |

**Communication Parameters:** 9600 baud, 8N1

## Software Requirements

### Dependencies
- Arduino IDE with ESP32-S3 board support
- No additional libraries required (uses HardwareSerial)

### Key Code

```cpp
HardwareSerial rs485Serial(1);
rs485Serial.begin(9600, SERIAL_8N1, 38, 39);  // RX=38, TX=39
rs485Serial.println("Hello from KinCony DM4!");
```

## Usage

1. Open `src/DM4_04_rs485_test.ino` in Arduino IDE
2. Select board: **ESP32S3 Dev Module**
3. Upload to the DM4 controller
4. Open Serial Monitor at **115200 baud**
5. Connect another RS485 device or use loopback for reply testing

## Precompiled Firmware

The `precompiled/` directory is reserved for precompiled `.bin` firmware files.

