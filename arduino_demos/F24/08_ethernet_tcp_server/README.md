# F24 Arduino Example 08: Ethernet TCP Server (W5500)

## Description
This example configures the F24 board with an external W5500 Ethernet module to act as a simple TCP server. The server listens on port **4196** and echoes back any data received from a connected client. This is useful for testing network connectivity and basic bidirectional communication.

## File Structure
- `src/F24_08_ethernet_tcp_server.ino` – Arduino source code.
- `precompiled/F24_08_ethernet_tcp_server.bin` – Precompiled firmware binary for ESP32‑S3.

## Using the Precompiled Binary
Flash `precompiled/F24_08_ethernet_tcp_server.bin` to address `0x0` using ESP Flash Download Tool or `esptool.py`.

## Compiling from Source
- **Environment**: Arduino IDE with ESP32‑S3 board support.
- **Dependencies**: `Ethernet.h`, `SPI.h` (both included with the ESP32 Arduino core).
- **Steps**:
  1. Connect the W5500 module to the F24 board as per the pin table below.
  2. Open the `.ino` file, select `esp32-s3-devkitc-1`, and upload.

## Hardware Connections
Connect a W5500 Ethernet module to the F24 board using the following pins:

| W5500 Pin | ESP32‑S3 GPIO |
|-----------|---------------|
| SCK       | 42            |
| MOSI      | 43            |
| MISO      | 44            |
| CS        | 41            |
| RST       | 1             |
| INT       | 2             |
| VCC       | 3.3V          |
| GND       | GND           |

Connect an Ethernet cable from the W5500 module to your network router/switch.

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
IP Address: 192.168.3.55
2. The server starts listening on port 4196.
3. From any device on the same network, connect to the F24 using a TCP client (e.g., `telnet 192.168.3.55 4196`).
4. Type any text; the server will immediately echo it back.
5. When the client disconnects, the Serial Monitor prints:
New client connected
Client disconnected

## Important Notes
- **Serial Monitor**: Set baud rate to **115200**.
- The server handles only one client at a time (sequential).
- The code contains a known issue: `server.write(c)` should be `client.write(c)`. If you experience no echo, correct this line.
- Ensure the W5500 module is properly powered (3.3V) and that all SPI connections are secure.

## Troubleshooting
- **No IP address printed**: Check wiring and module power. Run an I2C/SPI scanner to verify communication.
- **Client cannot connect**: Verify that the IP address is not already in use, and that the network allows connections to port 4196 (firewall rules).
- **No echo**: Correct the `server.write(c)` bug as noted above.

## Related Resources
- Pin definition: `../pin_definitions/F24/F24_pin_definition.md`