# Example 08: Ethernet W5500 TCP Server Mode

## Description

This example configures the FeedCurrent DM4 controller (ESP32-S3) with the on-board
W5500 Ethernet chip as a TCP server. It listens on port 4196 and echoes back any
data received from connected clients.

## Hardware Requirements

### Key Hardware
- FeedCurrent DM4 controller (ESP32-S3 + W5500 on-board)
- Ethernet cable connected to a router/switch

### Pin Definitions (W5500)

| Signal | GPIO |
|--------|------|
| CLK    | GPIO1 |
| MOSI   | GPIO2 |
| MISO   | GPIO41 |
| CS     | GPIO42 |
| INT    | GPIO43 |
| RST    | GPIO44 |

## Software Requirements

### Dependencies
- Arduino IDE with ESP32-S3 board support
- **Ethernet** library (W5500 compatible)
- `SPI` library (built-in)

### Key Code

```cpp
SPI.begin(1, 41, 2);    // CLK, MISO, MOSI
Ethernet.init(42);       // CS
Ethernet.begin(mac, ip, dns, gateway, subnet);
EthernetServer server(4196);
server.begin();
```

## Network Configuration

Modify these values to match your network:

```cpp
IPAddress ip(192, 168, 3, 55);       // Change to desired static IP
IPAddress subnet(255, 255, 255, 0);
IPAddress gateway(192, 168, 3, 1);
```

## Usage

1. Connect Ethernet cable to DM4
2. Modify IP settings in the sketch
3. Open `src/DM4_08_ethernet_tcp_server.ino` in Arduino IDE
4. Select board: **ESP32S3 Dev Module**
5. Upload and open Serial Monitor at **115200 baud**
6. Use a TCP client (Netcat, Hercules) to connect to IP:4196

## Precompiled Firmware

The `precompiled/` directory is reserved for precompiled `.bin` firmware files.
