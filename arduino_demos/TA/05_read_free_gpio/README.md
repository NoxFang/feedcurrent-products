# TA Example 04: RS485 Communication Test

## Overview
This example tests RS485 serial communication on the KinCony TA. It sends a message every 3 seconds and prints any received data to the Serial Monitor.

## Hardware
| Component | Description |
|-----------|-------------|
| RS485 Bus | Half-duplex serial interface |

### Key Pins
| Signal      | GPIO   |
|-------------|--------|
| RS485 RXD   | GPIO38 |
| RS485 TXD   | GPIO39 |

## Dependencies
- `HardwareSerial.h` - Built-in Arduino library

## Usage
1. Connect the RS485 A/B terminals to another RS485 device or loopback
2. Upload the sketch to TA
3. Open Serial Monitor at **115200 baud**
4. Observe `"Hello from KinCony TA!"` sent every 3 seconds
5. Any received RS485 data will be printed

## Key Code
```cpp
HardwareSerial rs485Serial(1);
rs485Serial.begin(9600, SERIAL_8N1, RS485_RXD, RS485_TXD);

rs485Serial.println("Hello from KinCony TA!");
delay(1000);
if (rs485Serial.available()) {
    String msg = "";
    while (rs485Serial.available()) msg += (char)rs485Serial.read();
    Serial.println("Received: " + msg);
}
delay(2000);
**Note: The total loop delay is 3 seconds (1s after send + 2s before next send).

## Wiring for Loopback Test
Connect RS485 A to A and B to B on the same terminal block (short A and B together for echo test, with a 120Ω termination resistor).

## Precompiled Firmware
The `precompiled/` folder is reserved for pre-built `.bin` firmware files.

## Related Resources
- Pin Definition: `../../../pin_definitions/TA/TA_pin_definition.md`