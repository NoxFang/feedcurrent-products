# Example 01: 4‑Channel DAC Initialization

## Description
This example demonstrates how to initialize the MCP4728 4‑channel 12‑bit I2C DAC on the KinCony DM4 controller. It sets each channel to a fixed output value:

- **Channel A**: full scale (4095 → maximum output voltage)
- **Channel B**: half scale (2048)
- **Channel C**: quarter scale (1024)
- **Channel D**: 0 (off)

The outputs remain at these values indefinitely. No button input or dynamic control is included; this is a basic setup example.

## Hardware Requirements

- KinCony DM4 controller (ESP32‑S3)
- MCP4728 DAC (on‑board, I2C address 0x60)

### Pin Definitions
| Interface | GPIO |
|-----------|------|
| I2C SDA   | GPIO8 |
| I2C SCL   | GPIO18 |
| MCP4728   | I2C 0x60 |

## Dependencies

- `Adafruit_MCP4728` – install via Library Manager
- `Wire.h` – built‑in

## Key Code

```cpp
#include <Adafruit_MCP4728.h>
#include <Wire.h>

#define I2C_SDA 8
#define I2C_SCL 18
TwoWire MYI2C = TwoWire(0);

Adafruit_MCP4728 mcp;

void setup() {
  Serial.begin(115200);
  MYI2C.begin(I2C_SDA, I2C_SCL, 100000);
  
  if (!mcp.begin(MCP4728_I2CADDR_DEFAULT, &MYI2C)) {
    Serial.println("Failed to find MCP4728 chip");
    while (1);
  }

  mcp.setChannelValue(MCP4728_CHANNEL_A, 4095);
  mcp.setChannelValue(MCP4728_CHANNEL_B, 2048);
  mcp.setChannelValue(MCP4728_CHANNEL_C, 1024);
  mcp.setChannelValue(MCP4728_CHANNEL_D, 0);
}

void loop() {
  delay(1000);
}

## Usage

1. Open `src/DM4_01_dac_mcp4728.ino` in Arduino IDE.
2. Install the `Adafruit_MCP4728` library via Library Manager.
3. Select board **ESP32S3 Dev Module**.
4. Upload to the DM4 controller.
5. After upload, the DAC outputs will be set to the predefined values. No user interaction is required.

## Expected Output
- Serial Monitor (115200 baud) will display `Adafruit MCP4728 test!` if initialization succeeds.
- DAC output voltages can be measured on the corresponding terminals.

## Precompiled Firmware
The `precompiled/` directory is reserved for pre‑built `.bin` firmware files that can be flashed directly using the ESP32 download tool.
