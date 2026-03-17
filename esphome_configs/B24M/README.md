# FeedCurrent B24M ESPHome Configuration

## Description
This ESPHome YAML configuration is for the **FeedCurrent B24M** controller. It enables integration with Home Assistant via Ethernet. The B24M features **24 relay outputs** and **24 digital inputs** using three PCF8575 I/O expanders.

## Available Configurations
- **Without Tuya**: `B24M_esphome_without_tuya.yaml` - Local control only via Home Assistant
- **With Tuya**: `B24M_esphome_with_tuya.yaml` - Includes Tuya Wi-Fi MCU integration for cloud control

## Key Features
- **Core**: ESP32-S3 with **Arduino framework**.
- **Connectivity**: Ethernet (W5500) with DHCP (user-configurable for static IP) + Wi-Fi (via Tuya module, for with_tuya version).
- **I2C Devices** (using **GPIO8 (SDA) and GPIO18 (SCL)**):
  - **PCF8575 (Inputs 1-16)**: Address `0x22`, reads 16 dry contact inputs.
  - **PCF8575 (Inputs 17-24 + Outputs 1-8)**: Address `0x25`, hybrid I/O chip.
  - **PCF8575 (Outputs 9-24)**: Address `0x24`, controls 16 relays.
  - ADS1115 (`0x48`): 4-channel analog inputs (0-5V and 4-20mA).
  - SSD1306 (`0x3C`): Display.
  - DS3231 (`0x68`): RTC clock.
  - 24C02 EPROM (`0x50`): EEPROM storage.
- **Free GPIOs**: 8 GPIOs configured as binary sensors (4 with pull-ups: GPIO0,7,40,47,48; 4 without: GPIO13,14,21).
- **RS485**: UART interface with test button. **Pins: TX=GPIO39, RX=GPIO38**.
- **Tuya Integration** (for with_tuya version): Wi-Fi MCU module for cloud control (product_id: `vyznobv3bahs2pwl`).
- **Web Server**: Enabled on port 80 for diagnostics.
- **Display**: SSD1306 128x64 OLED.

## Important Notes & Modifications Required
1.  **I2C Pins**: This configuration uses **SDA=GPIO8, SCL=GPIO18**. This is specific to B24M – using the wrong pins will prevent all I2C devices from working.
2.  **Triple PCF8575 Chips**: Note the three different I2C addresses:
    *   **Inputs 1-16**: `pcf8574_hub_in_1` at `0x22` (pins P8-P15 → inputs 1-8, P0-P7 → inputs 9-16)
    *   **Inputs 17-24 & Outputs 1-8**: `pcf8574_hub_in_out_1` at `0x25` (P0-P7 → inputs 17-24, P8-P15 → outputs 1-8)
    *   **Outputs 9-24**: `pcf8574_hub_out_1` at `0x24` (pins P0-P15 → outputs 9-24)
    All use `pcf8575: true` as they are 16-bit chips.
3.  **Network Configuration**: The current config uses DHCP by default. For static IP, add `manual_ip:` section under `ethernet:`.
4.  **RS485 Pins**: Verified pins are **TX=GPIO39, RX=GPIO38**.
5.  **Ethernet Pins**: W5500 uses CLK=GPIO1, MOSI=GPIO2, MISO=GPIO41, CS=GPIO42, INT=GPIO43, RST=GPIO44.
6.  **Analog Inputs**: A1-A2 support 0-5V, A3-A4 support 4-20mA current loop.
7.  **USB Flashing Note**: Forum user reports indicate that enabling the UART (RS485) section may interfere with subsequent USB flashing. If you encounter issues, follow the recovery procedure:
    *   Power off the board.
    *   Hold the **Download (BOOT) button**.
    *   Power on while holding the button.
    *   Release the button – the board should enter bootloader mode for flashing.

## Flashing Instructions
1.  Install ESPHome (`pip install esphome`).
2.  Place the YAML file in your ESPHome configuration directory.
3.  Run `esphome run B24M_esphome_without_tuya.yaml` or `esphome run B24M_esphome_with_tuya.yaml` to compile and flash the firmware to your B24M board (connected via USB).

## Entity List
The configuration creates the following entities in Home Assistant:
- **24 Switches**: `b24m-output01` to `b24m-output24` (relays).
- **24 Binary Sensors**: `b24m-input01` to `b24m-input24` (digital inputs).
- **8 GPIO Binary Sensors**: For free GPIOs (e.g., `b24m-W1-io40`, `b24m-W1-io13`).
- **4 Analog Sensors**: ADS1115 channels A0-GND to A3-GND.
- **1 RS485 Test Button**: `RS485 Button`.

Note (for with_tuya version): All Tuya-related entities (dp_id bindings) are set to `internal: true` and are not visible in Home Assistant UI. They are used for syncing state between local control and Tuya cloud.
