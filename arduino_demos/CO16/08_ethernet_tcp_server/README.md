# CO16 Arduino Example 08: Ethernet W5500 TCP Server

## Description
This example configures the CO16 board with an onboard W5500 Ethernet module to act as a TCP server.  
The server listens on port **4196** and echoes back any data received from a connected client. It uses a static IP configuration.

## File Structure
- `src/CO16_08_ethernet_tcp_server.ino` – Arduino source code.
- `precompiled/CO16_08_ethernet_tcp_server.bin` – Precompiled firmware binary for ESP32‑S3.

## Using the Precompiled Binary (.bin)
1. Download the `.bin` file from the `precompiled/` folder.
2. Use the official **ESP Flash Download Tool** or `esptool.py` to flash it to the CO16 controller.
3. **Flash Address**: `0x0`.

## Compiling from Source
1. **Environment**: Install Arduino IDE and add ESP32‑S3 board support (via Boards Manager).
2. **Dependencies**: `SPI.h`, `Ethernet.h` (both built‑in with the ESP32 Arduino core).
3. **Steps**: Open `src/CO16_08_ethernet_tcp_server.ino` in Arduino IDE, select the board `esp32-s3-devkitc-1` and the correct port, then compile and upload.

## Hardware Connections
The CO16 board includes an onboard W5500 Ethernet module. The pin definitions used in the code are:

| W5500 Signal | ESP32‑S3 GPIO |
|--------------|---------------|
| SCK (CLK)    | GPIO1         |
| MOSI         | GPIO2         |
| MISO         | GPIO41        |
| CS           | GPIO42        |
| RST          | GPIO44        |
| INT          | GPIO43        |

Connect an Ethernet cable from the CO16 board to your network router/switch.

## Network Configuration
The example uses a **static IP address**:
- IP: `192.168.3.55`
- Subnet mask: `255.255.255.0`
- Gateway: `192.168.3.1`
- DNS: `192.168.3.1`
- TCP port: **4196**

If your network uses a different subnet, modify the `ip`, `gateway`, `subnet`, and `dns` variables in the code before uploading.

## Expected Behavior
1. After uploading, open the Serial Monitor (115200 baud). You should see:
```
IP Address: 192.168.3.55
```
2. The server starts listening on port 4196.
3. From any device on the same network, connect to the CO16 using a TCP client (e.g., `telnet 192.168.3.55 4196`).
4. Type any text; the server will echo it back.
5. When the client disconnects, the Serial Monitor prints:
```
New client connected
Client disconnected
```

## Important Notes
- **Serial Monitor**: Set baud rate to **115200**.
- The server handles only one client at a time (sequential).
- The code contains a known issue: `server.write(c)` should be `client.write(c)`. If you experience no echo, correct this line.
- Ensure the W5500 module is properly powered and that all SPI connections are secure.
- The MAC address is set to `{0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED}`. Change it if you have multiple devices with the same MAC.

## Related Resources
- Pin definition: `../pin_definitions/CO16/CO16_pin_definition.md`