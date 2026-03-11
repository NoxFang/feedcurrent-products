# FeedCurrent B8M ESPHome Configuration (With Tuya)

## Description
This ESPHome YAML configuration is for the **FeedCurrent B8M** controller **with** the Tuya Wi-Fi module. It enables integration with Home Assistant via Ethernet and provides cloud control through the Tuya ecosystem.

## Key Features
- **Core**: ESP32-S3 with Arduino framework.
- **Connectivity**: Ethernet (W5500) with static IP configuration (user-defined).
- **I2C Devices**: PCF8575 (address `0x22`), ADS1115 (`0x48`), SSD1306 (`0x3C`).
- **PCF8575 (16-bit)**:
    - **8x MOSFET Outputs** (P0-P7, active LOW)
    - **8x Digital Inputs** (P8-P15, dry contact, active LOW)
- **Tuya Integration**:
    - Uses `tuya_wifi_mcu` component (external from `hzkincony/esphome-tuya-wifi-mcu` at `v1.1.0`).
    - Binds Tuya DP IDs to local GPIO switches/binary sensors for state sync.
- **ADS1115**: 4-channel analog inputs (A0-A3).
- **1-Wire**: 4 GPIOs with pull-ups (GPIO47, 48, 7, 40) as binary sensors.
- **Free GPIOs**: 3 inputs (GPIO13, 14, 21) and GPIO0.
- **RS485**: UART interface with a test button.
- **Display**: SSD1306 shows "FeedCurrent B8M".
- **Web Server**: Enabled on port 80 for diagnostics.

## Important Notes & Modifications Required
1.  **API Encryption**: The configuration includes a pre-generated `api.encryption.key`. **You must replace this** with your own key or remove it if you don't need encryption.
2.  **Network Configuration**: Add your network settings under the `ethernet:` section (e.g., `manual_ip` for a static IP).
3.  **Tuya Product ID**: The `product_id: mje1l6yi62hlljcn` must match the product ID of your Tuya module's firmware. Verify or update it as needed.
4.  **External Component**: It uses `https://github.com/hzkincony/esphome-tuya-wifi-mcu` at `v1.1.0`. Ensure this version is compatible with your ESPHome setup.
5.  **PCF8575 Support**: The `pcf8574` component is used with `pcf8575: true` to support the 16-bit chip. Do not change this.
6.  **Pin Mapping**: Note the specific mapping: Outputs = P0-P7, Inputs = P8-P15. This is opposite to the B8 model.
7.  **Logging**: The `logger` section is commented out. Uncomment if you need serial logs, but note it may interfere with the Tuya UART.

## Flashing Instructions
1.  Install ESPHome (`pip install esphome`).
2.  Place this YAML file in your ESPHome configuration directory.
3.  Run `esphome run B8M_esphome_with_tuya.yaml` to compile and flash.