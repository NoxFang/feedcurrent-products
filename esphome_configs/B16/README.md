# FeedCurrent B16 ESPHome Configuration (With Tuya)

## Description
This ESPHome YAML configuration is for the **FeedCurrent B16** controller **with** the Tuya Wi-Fi module. It enables integration with Home Assistant via Ethernet and provides cloud control through the Tuya ecosystem. The B16 features **16 relay outputs** and **16 digital inputs** using two separate PCF8575 I/O expanders.

## Key Features
- **Core**: ESP32-S3 with Arduino framework.
- **Connectivity**: Ethernet (W5500) with static IP configuration (user-defined).
- **I2C Devices**:
  - **PCF8575 (Outputs)**: Address `0x22`, controls 16 relays (P0-P15, active LOW).
  - **PCF8575 (Inputs)**: Address `0x24`, reads 16 dry contact inputs (P0-P15, active LOW).
  - ADS1115 (`0x48`): 4-channel analog inputs.
  - SSD1306 (`0x3C`): Display.
  - DS3231 (`0x68`): RTC clock.
  - 24C02 (`0x50`): EEPROM.
- **Tuya Integration**:
  - Uses `tuya_wifi_mcu` component (external from `hzkincony/esphome-tuya-wifi-mcu` at `v1.1.0`).
  - Binds Tuya DP IDs to local GPIO switches/binary sensors for state sync.
- **1-Wire / Free GPIOs**: 8 GPIOs configured as binary sensors (4 with pull-ups: GPIO48,47,40,7; 4 without: GPIO13,14,21,0).
- **RS485**: UART interface with a test button.
- **Web Server**: Enabled on port 80 for diagnostics.

## Important Notes & Modifications Required
1.  **Dual PCF8575 Chips**: Note the two different I2C addresses:
    *   **Outputs**: `pcf8574_hub_out_1` at `0x22` (pins 0-15 → relays 1-16)
    *   **Inputs**: `pcf8574_hub_in_1` at `0x24` (pins 0-15 → inputs 1-16)
    Both use `pcf8575: true` as they are 16-bit chips.
2.  **API Encryption**: The configuration includes a pre-generated `api.encryption.key`. **You must replace this** with your own key or remove it if you don't need encryption.
3.  **Network Configuration**: Add your network settings under the `ethernet:` section (e.g., `manual_ip` for a static IP). The current config uses DHCP by default.
4.  **Tuya Product ID**: The `product_id: byxtsco8rwt4x8km` must match the product ID of your Tuya module's firmware. Verify or update it as needed.
5.  **External Component**: It uses `https://github.com/hzkincony/esphome-tuya-wifi-mcu` at `v1.1.0`. Forum discussion indicates this compiles without issues on **ESPHome 2025.6.3** and later. A deprecation warning about `switch.SWITCH_SCHEMA` may appear but does not affect functionality (the component author is expected to update it).
6.  **Logging**: The `logger` section is commented out. Uncomment if you need serial logs, but note it may interfere with the Tuya UART.

## Flashing Instructions
1.  Install ESPHome (`pip install esphome`).
2.  Place this YAML file in your ESPHome configuration directory.
3.  Run `esphome run B16_esphome_with_tuya.yaml` to compile and flash the firmware to your B16 board (connected via USB).

## Entity List
The configuration creates the following entities in Home Assistant:
*   **16 Switches**: `b16-output01` to `b16-output16` (relays) and their bound Tuya counterparts.
*   **16 Binary Sensors**: `b16-input01` to `b16-input16` (digital inputs) and their bound Tuya counterparts.
*   **4 Analog Sensors**: ADS1115 channels A0-GND to A3-GND.
*   **8 GPIO Binary Sensors**: For free GPIOs (e.g., `b16-W1-io48`, `b16-io13`).
*   **1 RS485 Test Button**: `RS485 Button`.
*   **Display**: Shows "FeedCurrent B16" on the SSD1306 OLED.