# G1 Arduino Example 03: Ethernet W5500 TCP Server

## Description
This example sets up the W5500 Ethernet module on the G1 controller as a TCP server. It listens on port **4196** and echoes back any string received from a connected client. A static IP configuration is used.

## File Structure
- `src/G1_03_ethernet_tcp_server.ino` – Arduino source code.
- `precompiled/G1_03_ethernet_tcp_server.bin` – Precompiled firmware binary for ESP32‑S3 (to be added).

## Using the Precompiled Binary
1. Download the `.bin` file from the `precompiled/` folder.
2. Use the official **ESP Flash Download Tool** or `esptool.py` to flash it to the G1 controller.
3. **Flash Address**: `0x0` (as indicated in the forum post).

## Compiling from Source
1. **Environment**: Install Arduino IDE and add ESP32‑S3 board support (via Boards Manager).
2. **Dependencies**:
   - `SPI.h` (built‑in)
   - `Ethernet.h` (built‑in, part of the Arduino Ethernet library)
3. **Steps**:
   - Open `src/G1_03_ethernet_tcp_server.ino` in Arduino IDE.
   - Select the correct board (`esp32-s3-devkitc-1`) and port.
   - Compile and upload.

## Expected Behavior
- After uploading, open the Serial Monitor at **115200 baud**. The device will display its assigned IP address (`192.168.3.55` by default).
- It acts as a TCP server on port **4196**. You can connect to it using a TCP client tool (e.g., PuTTY, telnet, or a Python script).
- Any data sent by the client will be echoed back immediately.

## Important Notes
- **Ethernet pins**: The code uses the following pins for the W5500 module:
  - CLK = GPIO42
  - MOSI = GPIO43
  - MISO = GPIO44
  - CS = GPIO41
  - RST = GPIO1
  - INT = GPIO2
- **Network configuration**: The static IP is set to `192.168.3.55` with gateway `192.168.3.1`. Modify these values in the code (`ip`, `gateway`, etc.) to match your local network.
- **MAC address**: The sample MAC `{0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED}` is used. If multiple devices on your network share the same MAC, change it to a unique one.
- **SPI initialization**: The line `SPI.begin(W5500_CLK_PIN, W5500_MISO_PIN, W5500_MOSI_PIN)` correctly initializes SPI with the defined pins.
- **Ethernet library**: Ensure you are using a version of the Ethernet library compatible with the W5500 and ESP32 (the built‑in library usually works).

## Related Resources
- Pin definition: `../pin_definitions/G1/G1_pin_definition.md`
