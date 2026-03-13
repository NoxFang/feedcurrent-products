# FeedCurrent B16M ESPHome Configuration (With Tuya)

## Description
This ESPHome YAML configuration is for the **FeedCurrent B16M** controller. It enables integration with Home Assistant via Ethernet. The B16M features **16 relay outputs** and **16 digital inputs** using two separate PCF8575 I/O expanders.

## Key Features
- **Core**: ESP32-S3 with **ESP-IDF framework** (not Arduino).
- **Connectivity**: Ethernet (W5500) with static IP configuration (user-defined).
- **I2C Devices** (using **GPIO38 (SDA) and GPIO39 (SCL)** – ⚠️ different from other models):
  - **PCF8575 (Outputs)**: Address `0x25`, controls 16 relays (P0-P15, active LOW).
  - **PCF8575 (Inputs)**: Address `0x24`, reads 16 dry contact inputs (P0-P15, active LOW).
  - ADS1115 (`0x48`): 4-channel analog inputs.
  - SSD1306 (`0x3C`): Display.
  - DS3231 (`0x68`): RTC clock.
- **1-Wire / Free GPIOs**: 8 GPIOs configured as binary sensors (4 with pull-ups: GPIO40,15,48,47; 4 without: GPIO13,14,21).
- **RS485**: UART interface with a test button. **Pins: TX=GPIO18, RX=GPIO8** (⚠️ opposite to many other models).
- **Web Server**: Enabled on port 80 for diagnostics.

## Important Notes & Modifications Required
1.  **I2C Pins**: This configuration uses **SDA=GPIO38, SCL=GPIO39**. This is critical – using the wrong pins will prevent all I2C devices from working.
2.  **Dual PCF8575 Chips**: Note the two different I2C addresses:
    *   **Outputs**: `pcf8574_hub_out_1` at `0x25` (pins 0-15 → relays 1-16)
    *   **Inputs**: `pcf8574_hub_in_1` at `0x24` (pins 0-15 → inputs 1-16)
    Both use `pcf8575: true` as they are 16-bit chips.
3.  **ESP-IDF Framework**: This config uses the ESP-IDF framework instead of Arduino. Ensure your ESPHome environment supports it (it is included by default).
4.  **API Encryption**: The configuration includes a pre-generated `api.encryption.key`. **You must replace this** with your own key or remove it if you don't need encryption.
5.  **Network Configuration**: Add your network settings under the `ethernet:` section (e.g., `manual_ip` for a static IP). The current config uses DHCP by default.
6.  **RS485 Pins**: Verified pins are **TX=GPIO18, RX=GPIO8**. This matches the B16M pin definition but is opposite to many other FeedCurrent models.
7.  **Tuya Integration**: **Note: This configuration does NOT include the `tuya_wifi_mcu` component**. If you need Tuya cloud control, you will need to add it separately (refer to B16 examples for integration pattern).
8.  **USB Flashing Note**: Forum user reports indicate that enabling the UART (RS485) section may interfere with subsequent USB flashing. If you encounter issues, follow the recovery procedure:
    *   Power off the board.
    *   Hold the **Download (DW) button**.
    *   Power on while holding the button.
    *   Release the button – the board should enter bootloader mode for flashing.

## Flashing Instructions
1.  Install ESPHome (`pip install esphome`).
2.  Place this YAML file in your ESPHome configuration directory.
3.  Run `esphome run B16M_esphome.yaml` to compile and flash the firmware to your B16M board (connected via USB).

## Entity List
The configuration creates the following entities in Home Assistant:
*   **16 Switches**: `b16m-output01` to `b16m-output16` (relays).
*   **16 Binary Sensors**: `b16m-input01` to `b16m-input16` (digital inputs).
*   **4 Analog Sensors**: ADS1115 channels A0-GND to A3-GND.
*   **8 GPIO Binary Sensors**: For free GPIOs (e.g., `b16m-W1-io40`, `b16m-W1-io13`).
*   **1 RS485 Test Button**: `RS485 Button`.