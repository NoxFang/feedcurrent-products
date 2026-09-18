# B2 Arduino Example 08: Ethernet W5500 TCP Server

## Description
This example demonstrates how to use the W5500 Ethernet module on the B2 board as a TCP server. The server listens on port **4196** and echoes back any string received from a connected client. It uses a static IP configuration.

## File Structure
- `src/B2_08_ethernet_tcp_server.ino` – Arduino source code.
- `precompiled/B2_08_ethernet_tcp_server.bin` – Precompiled firmware binary for ESP32‑S3.

## Using the Precompiled Binary (.bin)
1. Download the `.bin` file from the `precompiled/` folder.
2. Use the official **ESP Flash Download Tool** or `esptool.py` to flash it to the B2 controller.
3. **Flash Address**: `0x0`.

## Compiling from Source
1. **Environment**: Install Arduino IDE and add ESP32‑S3 board support (via Boards Manager).
2. **Dependencies**:
   - `SPI.h` (built‑in)
   - `Ethernet.h` (built‑in, part of the Arduino Ethernet library)
3. **Steps**: Open `src/B2_08_ethernet_tcp_server.ino` in Arduino IDE, select the board `esp32-s3-devkitc-1` and the correct port, then compile and upload.

## Hardware Connections
The B2 board includes an onboard W5500 Ethernet module. The **actual pin definitions** used in the code are:

| W5500 Signal | ESP32‑S3 GPIO |
|--------------|---------------|
| SCK (CLK)    | GPIO1         |
| MOSI         | GPIO2         |
| MISO         | GPIO41        |
| CS           | GPIO42        |
| RST          | GPIO44        |
| INT          | GPIO43        |

> ⚠️ **Important**: The code comments list a different pin order (CLK=42, MOSI=43, MISO=44, CS=41, RST=1, INT=2). Always refer to the `#define` values above — the comments are incorrect.

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
`IP Address: 192.168.3.55`
2. The server starts listening on port 4196.
3. From any device on the same network, connect to the B2 using a TCP client (e.g., `telnet 192.168.3.55 4196`).
4. Type any text; the server will echo it back.
5. When the client disconnects, the Serial Monitor prints:
`New client connected`
`Client disconnected`

## Important Notes
- **Serial Monitor**: Set baud rate to **115200**.
- The server handles only one client at a time (sequential).
- The code contains a known issue: `server.write(c)` should be `client.write(c)`. If you experience no echo, correct this line.
- Ensure the W5500 module is properly powered and that all SPI connections are secure.
- The MAC address is set to `{0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED}`. Change it if you have multiple devices with the same MAC.

## Troubleshooting
- **No IP address printed**: Check Ethernet cable and network connection.
- **Client cannot connect**: Verify that the IP address is not already in use, and that the network allows connections to port 4196 (firewall rules).
- **No echo**: Correct the `server.write(c)` bug as noted above.

## Related Resources
- Pin definition: `../pin_definitions/B2/B2_pin_definition.md`