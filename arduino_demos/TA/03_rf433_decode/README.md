# TA Example 03: RF 433MHz Signal Decode

## Overview
This example uses the RCSwitch library to receive and decode RF 433MHz signals via the onboard RF receiver connected to GPIO12.

## Hardware
| Component       | Description |
|-----------------|-------------|
| RF433 Receiver  | Connected to GPIO12 |

### Key Pins
| Signal      | GPIO   |
|-------------|--------|
| RF433 DATA  | GPIO12 |

## Dependencies
- `RCSwitch.h` - RC Switch library
  - Install: Arduino Library Manager → search "rc-switch"
  - GitHub: https://github.com/sui77/rc-switch/

## Usage
1. Install the RCSwitch library
2. Upload the sketch to TA
3. Open Serial Monitor at **9600 baud**
4. Press any 433MHz remote button near the TA
5. Decoded value, bit length, and protocol will be printed

## Expected Output
```
Received 12345678 / 24bit Protocol: 1
```

## Key Code
```cpp
mySwitch.enableReceive(digitalPinToInterrupt(12));

if (mySwitch.available()) {
    Serial.print("Received ");
    Serial.print(mySwitch.getReceivedValue());
    Serial.print(" / ");
    Serial.print(mySwitch.getReceivedBitlength());
    Serial.print("bit Protocol: ");
    Serial.println(mySwitch.getReceivedProtocol());
    mySwitch.resetAvailable();
}
```

## Precompiled Firmware
The `precompiled/` folder is reserved for pre-built `.bin` firmware files.

## Related Resources
- Pin Definition: `../../../pin_definitions/TA/TA_pin_definition.md`
