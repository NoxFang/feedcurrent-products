# DM16 Arduino Example 08: Ethernet W5500 TCP Server

## Description
This example sets up the W5500 Ethernet module as a TCP server on port 4196. It listens for incoming connections and echoes back any data received from the client.

## Hardware Connections
| Signal | GPIO |
|--------|------|
| CLK (SCK) | GPIO1 |
| MOSI | GPIO2 |
| MISO | GPIO41 |
| CS | GPIO42 |
| INT | GPIO43 |
| RST | GPIO44 |

- **SPI Bus**: Default SPI (VSPI) – no need to specify bus.
- **MAC Address**: `DE:AD:BE:EF:FE:ED` (modify if needed for your network).

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
1. Connect an Ethernet cable between the DM16 and your router/switch.
2. Upload the sketch to the DM16 board.
3. Open the Serial Monitor at 115200 baud.
4. From a computer on the same network, connect to the DM16 using a TCP client (e.g., `telnet 192.168.3.55 4196` or `nc 192.168.3.55 4196`).
5. Type any text – it will be echoed back.

## Notes
- The example uses static IP configuration; modify the `ip`, `gateway`, etc., in the code if your network uses a different subnet.
- The MAC address is set to a generic value; ensure it is unique on your network.
- The server handles one client at a time; new clients are accepted only after the previous one disconnects.

## Dependencies
- `SPI.h` (built‑in)
- `Ethernet.h` (built‑in, compatible with W5500)

## Related Resources
- DM16 Pin Definition: `../pin_definitions/DM16/DM16_pin_definition.md`