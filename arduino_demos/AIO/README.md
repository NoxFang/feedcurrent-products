# AIO Hybrid Arduino Examples

## Overview
This directory contains 13 Arduino example programs for the AIO Hybrid smart home controller. Each example demonstrates a specific functionality of the AIO Hybrid hardware.

## Example List

### Example 01: RF433MHz Receiver
- **Description**: Receive RF433MHz signals from remote controls
- **Hardware**: RF433 receiver module
- **GPIO**: RX = GPIO16

### Example 02: DAC Analog Output
- **Description**: Control 4-channel DAC for analog voltage output
- **Hardware**: MCP4728 DAC via I2C
- **I2C Address**: 0x60

### Example 03: IR Infrared Transceiver
- **Description**: Send and receive IR signals
- **Hardware**: IR receiver and transmitter
- **GPIO**: RX = GPIO17, TX = GPIO21

### Example 04: OLED Display
- **Description**: Display text and graphics on SSD1306 OLED
- **Hardware**: SSD1306 OLED via I2C
- **I2C Address**: 0x3C

### Example 05: Zigbee Communication
- **Description**: Communicate with Tuya Zigbee devices
- **Hardware**: Tuya Zigbee module via UART
- **GPIO**: TX = GPIO6, RX = GPIO5

### Example 06: Ethernet TCP Server
- **Description**: Create TCP server using W5500 Ethernet
- **Hardware**: W5500 Ethernet module via SPI
- **SPI Pins**: SCK=42, MOSI=43, MISO=44, CS=41

### Example 07: RTC Clock
- **Description**: Read and set time using DS3231 RTC
- **Hardware**: DS3231 RTC via I2C
- **I2C Address**: 0x68

### Example 08: SD Card File System
- **Description**: Read/write files to SD card
- **Hardware**: SD card module via SPI
- **SPI Pins**: SCK=39, MISO=38, MOSI=40, CS=48

### Example 09: RS485 Modbus Communication
- **Description**: Communicate via RS485 Modbus protocol
- **Hardware**: RS485 transceiver
- **GPIO**: TX = GPIO9, RX = GPIO10, DE = GPIO8

### Example 10: Analog Input Reading
- **Description**: Read analog voltages using ADS1115 ADC
- **Hardware**: ADS1115 ADC via I2C
- **I2C Address**: 0x48

### Example 11: Digital Input Reading
- **Description**: Read digital input states using PCF8574
- **Hardware**: PCF8574 I/O expander via I2C
- **I2C Address**: 0x20

### Example 12: Relay Control
- **Description**: Control 4 relay outputs
- **Hardware**: Relay outputs
- **GPIO**: GPIO36, GPIO37, GPIO45, GPIO46

### Example 13: RF433MHz Transmitter
- **Description**: Transmit RF433MHz signals
- **Hardware**: RF433 transmitter module
- **GPIO**: TX = GPIO15

## Hardware Requirements

### Required Hardware
1. AIO Hybrid controller board
2. ESP32-S3 development board
3. 12V DC power supply
4. USB cable for programming

### Optional Hardware
1. RF433 remote control
2. IR remote control
3. Zigbee devices
4. Modbus slave devices
5. Analog sensors (0-10V)
6. Relay loads (lights, motors, etc.)

## Software Requirements

### Arduino IDE
1. Install Arduino IDE 2.0 or later
2. Add ESP32 board support:
   - Add URL: https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json
3. Install required libraries:
   - Wire (I2C)
   - SPI
   - Adafruit_SSD1306
   - Adafruit_GFX
   - RTClib
   - Adafruit_MCP4728
   - Adafruit_ADS1X15
   - PCF8574

### PlatformIO (Alternative)
1. Install VSCode with PlatformIO extension
2. Create new project with ESP32-S3 board
3. Add required libraries via PlatformIO library manager

## Pin Configuration

### I2C Bus
- **SDA**: GPIO8
- **SCL**: GPIO18

### SPI Bus (SD Card)
- **SCK**: GPIO39
- **MISO**: GPIO38
- **MOSI**: GPIO40
- **CS**: GPIO48

### SPI Bus (Ethernet)
- **SCK**: GPIO42
- **MOSI**: GPIO43
- **MISO**: GPIO44
- **CS**: GPIO41
- **RST**: GPIO1
- **INT**: GPIO2

### Communication
- **RS485**: TX=GPIO9, RX=GPIO10, DE=GPIO8
- **RF433**: RX=GPIO16, TX=GPIO15
- **IR**: RX=GPIO17, TX=GPIO21
- **Zigbee**: TX=GPIO6, RX=GPIO5

### Control
- **Relays**: GPIO36, GPIO37, GPIO45, GPIO46
- **Digital Inputs**: PCF8574 P0-P3
- **Status LED**: GPIO7

## Getting Started

### Step 1: Hardware Setup
1. Connect 12V power to AIO Hybrid
2. Connect USB cable to ESP32-S3
3. Verify all modules are properly connected

### Step 2: Software Setup
1. Open Arduino IDE
2. Select board: ESP32-S3 Dev Module
3. Set Flash Mode: QIO
4. Set Partition Scheme: Default 16MB

### Step 3: Run Examples
1. Open desired example from File → Examples
2. Verify and upload to board
3. Open Serial Monitor (115200 baud)

## Example Details

### Example Structure
Each example directory contains:
1. `src/` - Arduino source code (.ino file)
2. `precompiled/` - Compiled binary files (if available)
3. `README.md` - Example-specific documentation

### Code Organization
- All examples use consistent pin mapping
- Error handling included
- Serial debug output enabled
- Modular function design

## Troubleshooting

### Common Issues
1. **I2C devices not found**: Check connections and addresses
2. **SPI communication failed**: Verify pin assignments
3. **Serial communication errors**: Check baud rate settings
4. **RF433 not working**: Adjust timing parameters

### Debugging
1. Enable Serial debugging (115200 baud)
2. Check power supply (12V DC required)
3. Verify module connections
4. Update library versions

## TID Source Information
All examples are adapted from official KinCony forum posts with TID range: 9019-9031
