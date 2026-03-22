# Example 02: Read Free GPIO State

## Function Description
This example demonstrates how to monitor the state of 11 free GPIO pins on the G1 controller with change detection. The program continuously checks GPIO pins and reports state changes to the Serial Monitor.

## Hardware Requirements
### Monitored GPIO Pins
The following 11 GPIO pins are monitored:
1. **GPIO 15** - 1-Wire interface (with pull-up resistor)
2. **GPIO 16** - 1-Wire interface (with pull-up resistor)
3. **GPIO 17** - 1-Wire interface (with pull-up resistor)
4. **GPIO 40** - 1-Wire interface (with pull-up resistor)
5. **GPIO 13** - 1-Wire interface (no pull-up resistor)
6. **GPIO 14** - 1-Wire interface (no pull-up resistor)
7. **GPIO 21** - 1-Wire interface (no pull-up resistor)
8. **GPIO 4** - Free GPIO (no ESD protection)
9. **GPIO 5** - Free GPIO (no ESD protection)
10. **GPIO 6** - Free GPIO (no ESD protection)
11. **GPIO 7** - Free GPIO (no ESD protection)

## Software Requirements
### Dependencies
- **Arduino Core:** ESP32-S3 board support
- **No external libraries required**

## Key Code
```cpp
#define GPIO_PIN_15 15
#define GPIO_PIN_16 16
// ... other pin definitions

bool prevState[11] = {false, false, false, false, false, false, false, false, false, false, false};

void setup() {
  Serial.begin(115200);
  while (!Serial);
  
  pinMode(GPIO_PIN_15, INPUT);
  // ... other pinMode calls
  
  Serial.println("GPIO Status Monitoring Started");
}

void loop() {
  bool currentState[11];
  currentState[0] = digitalRead(GPIO_PIN_15);
  // ... other digitalRead calls
  
  for (int i = 0; i < 11; i++) {
    if (currentState[i] != prevState[i]) {
      Serial.print("GPIO ");
      Serial.print(/* pin number based on index */);
      Serial.print(" changed to ");
      Serial.println(currentState[i] ? "HIGH" : "LOW");
      prevState[i] = currentState[i];
    }
  }
  delay(100);
}
```

## Usage Instructions
1. **Upload Code:** Compile and upload to G1 controller
2. **Open Serial Monitor:** Set baud rate to 115200
3. **Monitor Changes:** Connect devices to monitored GPIO pins
4. **Observe Output:** State changes will be displayed in Serial Monitor

## Technical Notes
- **Change Detection:** Only reports when pin state changes
- **Debouncing:** 100ms delay prevents excessive serial output
- **Input Mode:** All pins configured as digital inputs
- **ESD Warning:** GPIO 4-7 have no on-board ESD protection

## Source Information
- **Thread ID:** 7177
- **Posted:** December 6, 2024
- **Attachments:** 6590 (INO), 6591 (BIN)