# Example 03: Ethernet W5500 TCP Server Mode

## Description
This example configures the onboard W5500 Ethernet chip on the KinCony N10
as a TCP server. The server listens on port **4196** and echoes any string
received from a connected client back to the sender.

## Hardware Requirements
- KinCony N10 controller (ESP32-S3)
- RJ45 Ethernet cable connected to a router or switch
- A PC or device to act as TCP client (e.g., Hercules, Putty, or netcat)

## Pin Definitions (W5500 SPI)
| Signal | GPIO | Description |
|--------|------|-------------|
| CLK    | GPIO42 | SPI Clock |
| MOSI   | GPIO43 | SPI Master Out Slave In |
| MISO   | GPIO44 | SPI Master In Slave Out |
| CS     | GPIO41 | Chip Select |
| RST    | GPIO1  | Hardware Reset |
| INT    | GPIO2  | Interrupt |

## Software Requirements
### Dependencies
- `Ethernet` library — install via Arduino Library Manager  
  (search: **"Ethernet"** by Arduino)
- `SPI.h` — built-in with ESP32 Arduino core

## Network Configuration
Edit the following in the sketch before uploading:
```cpp
byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };  // Change MAC if needed
IPAddress ip(192, 168, 3, 55);     // Change to an IP in your network
IPAddress gateway(192, 168, 3, 1); // Your router IP
```

## Usage
1. Install the `Ethernet` library in Arduino IDE
2. Adjust the IP address in the sketch to match your network
3. Open `N10_03_ethernet_tcp_server.ino` in Arduino IDE
4. Select board: **ESP32S3 Dev Module**
5. Upload the sketch
6. Open Serial Monitor at **115200 baud** to see server status
7. Connect a TCP client to `192.168.3.55:4196` and send text

## Testing with Netcat
```bash
# Linux / macOS
echo "Hello N10" | nc 192.168.3.55 4196

# Windows PowerShell
"Hello N10" | & nc.exe 192.168.3.55 4196
```

## Expected Serial Output
```
========================================
  KinCony N10 - Ethernet TCP Server Demo
========================================
TCP Server listening on 192.168.3.55:4196
Client connected.
Received: Hello N10
Client disconnected.
```

## Key Code
```cpp
#define W5500_CS  41
#define TCP_PORT  4196

SPI.begin(42, 44, 43, 41);  // CLK, MISO, MOSI, CS
Ethernet.init(W5500_CS);
Ethernet.begin(mac, ip, dns, gateway, subnet);
EthernetServer server(TCP_PORT);
server.begin();
```

## Troubleshooting
| Issue | Solution |
|-------|---------|
| "W5500 hardware not found" | Check SPI wiring; ensure W5500 is powered |
| "Ethernet cable not connected" | Verify RJ45 cable and link LED |
| No client can connect | Confirm IP is in the same subnet |

## Precompiled Firmware
The `precompiled/` directory contains pre-built firmware that can be
flashed directly to the ESP32-S3 at address `0x0`.

## Related Resources
- Pin Definition: `../../../pin_definitions/N10/N10_pin_definition.md`
- Product Page: https://www.kincony.com
