# F4 Arduino Example 08: Ethernet W5500 TCP Server

## Description
This example sets up the W5500 Ethernet module as a TCP server on port 4196. It listens for incoming connections and echoes back any data received from the client.

## File Structure
- `src/F4_08_ethernet_tcp_server.ino` – Arduino source code.
- `precompiled/F4_08_ethernet_tcp_server.bin` – Precompiled firmware binary for ESP32‑S3.

## Using the Precompiled Binary
Flash `precompiled/F4_08_ethernet_tcp_server.bin` to address `0x0` using ESP Flash Download Tool or `esptool.py`.

## Compiling from Source
- **Environment**: Arduino IDE with ESP32‑S3 board support.
- **Dependencies**: `SPI.h` (built‑in), `Ethernet.h` (built‑in, compatible with W5500).
- **Steps**: Open the `.ino` file, select `esp32-s3-devkitc-1`, and upload.

## Hardware Connections
| Signal | GPIO |
|--------|------|
| CLK (SCK) | GPIO42 |
| MOSI | GPIO43 |
| MISO | GPIO44 |
| CS | GPIO41 |
| INT | GPIO2 |
| RST | GPIO1 |

- **SPI Bus**: Default SPI (VSPI)
- **MAC Address**: `DE:AD:BE:EF:FE:ED` (modify if needed for your network)

## Network Configuration
| Parameter | Value |
|-----------|-------|
| IP Address | 192.168.3.55 |
| Subnet Mask | 255.255.255.0 |
| Gateway | 192.168.3.1 |
| DNS Server | 192.168.3.1 |
| TCP Port | 4196 |

> **Note:** Adjust these IP settings to match your local network.

## Serial Output
After uploading, open the Serial Monitor at **115200 baud**. You will see:
IP Address: 192.168.3.55

When a client connects, the server prints:
New client connected
When the client disconnects:
Client disconnected

## Usage
1. Connect an Ethernet cable between the F4 and your router/switch.
2. Upload the sketch to the F4 board.
3. Open the Serial Monitor at 115200 baud.
4. From a computer on the same network, connect to the F4 using a TCP client (e.g., `telnet 192.168.3.55 4196` or `nc 192.168.3.55 4196`).
5. Type any text – it will be echoed back.

## Important Notes
- The example uses static IP configuration; modify the `ip`, `gateway`, etc., in the code if your network uses a different subnet.
- The MAC address is set to a generic value; ensure it is unique on your network.
- The server handles one client at a time; new clients are accepted only after the previous one disconnects.

## Related Resources
- Pin definition: `../pin_definitions/F4/F4_pin_definition.md`