# TA Example 07: Ethernet W5500 TCP Server

## Overview
This example sets up the FeedCurrent TA as a TCP echo server using the W5500 Ethernet module. It listens on port **4196** and echoes back any data received from a TCP client.

## Hardware
| Component | Description |
|-----------|-------------|
| W5500     | SPI Ethernet controller |

### W5500 Pin Connections
| Signal | GPIO   |
|--------|--------|
| CLK    | GPIO1  |
| MOSI   | GPIO2  |
| MISO   | GPIO41 |
| CS     | GPIO42 |
| INT    | GPIO43 |
| RST    | GPIO44 |

## Network Configuration
| Parameter    | Default Value    |
|--------------|-----------------|
| IP Address   | 192.168.3.55    |
| Subnet Mask  | 255.255.255.0   |
| Gateway      | 192.168.3.1     |
| DNS          | 192.168.3.1     |
| TCP Port     | 4196            |

> Modify the IP configuration in the sketch to match your network.

## Dependencies
- `SPI.h` - Built-in SPI library
- `Ethernet.h` - Arduino Ethernet library (supports W5500)

## Usage
1. Connect Ethernet cable to the TA
2. Modify IP address in code if needed
3. Upload the sketch
4. Open Serial Monitor at **115200 baud**
5. Test with Telnet or any TCP client:
   ```
   telnet 192.168.3.55 4196
   ```
6. Type any text — it will be echoed back

## Key Code
```cpp
EthernetServer server(4196);
server.begin();

EthernetClient client = server.available();
if (client) {
    while (client.connected()) {
        if (client.available()) {
            char c = client.read();
            server.write(c);  // Echo back
        }
    }
    client.stop();
}
```

## Precompiled Firmware
The `precompiled/` folder is reserved for pre-built `.bin` firmware files.

## Related Resources
- Pin Definition: `../../../pin_definitions/TA/TA_pin_definition.md`
- ESPHome Config (with Ethernet): `../../../esphome_configs/TA/TA_esphome.yaml`
