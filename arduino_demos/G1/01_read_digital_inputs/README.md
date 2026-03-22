# Example 01: Read Digital Input Ports State

## Function Description
This example demonstrates how to read the state of digital input ports using a 16-channel PCF8575 I/O expander on the G1 controller. The program reads all 16 input pins and displays their state in binary format on the Serial Monitor.

## Hardware Requirements
### Key Hardware
- **G1 Controller:** KC868-G1 with ESP32-S3
- **PCF8575 I/O Expander:** 16-bit I2C I/O expander (address: 0x24)
- **Input Devices:** Up to 16 digital inputs (buttons, switches, sensors)
- **Power Supply:** 12V DC power source

### Pin Definitions
| Pin | Function | Description |
|-----|----------|-------------|
| GPIO12 | SDA | I2C data line |
| GPIO11 | SCL | I2C clock line |
| PCF8575 | Address 0x24 | 16-channel I/O expander |

**Note:** The actual G1 PCB uses 12 buttons, leaving 4 digital input channels free.

## Software Requirements
### Dependencies
- **PCF8575 Library:** Required for I2C communication with PCF8575 expander
- **Wire Library:** Built-in Arduino I2C communication library
- **Arduino Framework:** ESP32-S3 board support package

### Library Installation
1. Install PCF8575 library via Arduino Library Manager
2. Ensure ESP32 board support is installed
3. Include necessary headers in your sketch

## Key Code
```cpp
#include "PCF8575.h"

// Define I2C pins
#define I2C_SDA 12
#define I2C_SCL 11

// Initialize PCF8575 at address 0x24
PCF8575 pcf8575_IN1(0x24);

void setup() {
    Serial.begin(115200);
    Wire.begin(I2C_SDA, I2C_SCL);
    pcf8575_IN1.begin();
}

void loop() {
    uint16_t state = 0;
    for (int pin = 0; pin < 16; pin++) {
        if (pcf8575_IN1.read(pin)) {
            state |= (1 << pin);
        }
    }
    Serial.print("Input state: ");
    Serial.println(state, BIN);
    delay(500);
}
```

## Usage Instructions
### Step 1: Hardware Connection
1. Connect input devices (buttons, switches) to PCF8575 input pins
2. Ensure proper pull-up/pull-down resistors as needed
3. Connect G1 controller to power (12V DC)

### Step 2: Software Setup
1. Open Arduino IDE
2. Select ESP32S3 Dev Module board
3. Set Flash Size to 16MB
4. Enable PSRAM option

### Step 3: Upload and Test
1. Upload the sketch to G1 controller
2. Open Serial Monitor at 115200 baud
3. Observe input state changes in binary format
4. Press buttons or toggle switches to see state changes

## Precompiled Firmware
The `precompiled/` directory contains precompiled firmware files ready for deployment.

### Available Files
- **Source Code:** `G1_01_read_digital_input_ports.ino` in `src/` directory
- **Precompiled Bin:** (If available) in `precompiled/` directory

### Installation Methods
1. **Arduino IDE:** Upload via serial port
2. **ESP32 Flash Tool:** Use precompiled .bin file
3. **OTA Update:** If OTA is configured

## State Representation
- **Binary Output:** 16-bit binary number representing input states
- **Bit Position:** Each bit corresponds to an input pin (0-15)
- **State Meaning:**
  - `0`: Input ON (active low)
  - `1`: Input OFF (inactive)

**Example Output:** `Input state: 0000000000001111` (pins 0-3 are ON, others OFF)

## Technical Notes
### PCF8575 Configuration
- **I2C Address:** 0x24 (fixed on G1 hardware)
- **Pin Mode:** All pins configured as inputs
- **Pull-up:** Internal pull-up resistors enabled

### ESP32-S3 I2C Settings
- **Clock Speed:** Standard 100kHz I2C
- **SDA Pin:** GPIO12
- **SCL Pin:** GPIO11
- **Wire Library:** Uses TwoWire instance

### Performance Characteristics
- **Sampling Rate:** 2 Hz (500ms delay)
- **Resolution:** 16-bit input state
- **Accuracy:** Limited by I2C communication speed

## Troubleshooting
### Common Issues
1. **No Serial Output:** Check baud rate (115200) and USB connection
2. **I2C Communication Failure:** Verify SDA/SCL connections and address (0x24)
3. **Incorrect Input States:** Check input device connections and pull-up resistors
4. **Library Errors:** Ensure PCF8575 library is properly installed

### Debugging Tips
1. Enable verbose I2C debugging in Wire library
2. Check I2C bus with scanner sketch
3. Verify PCF8575 address using I2C scanner
4. Test individual pins with simple read/write operations

## Related Resources
- **PCF8575 Datasheet:** [Texas Instruments](https://www.ti.com/product/PCF8575)
- **ESP32-S3 Documentation:** [Espressif](https://docs.espressif.com/projects/esp-idf/en/latest/esp32s3/)