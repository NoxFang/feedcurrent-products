# FeedCurrent B24M Controller Arduino Example 08: Ethernet TCP Server

## Description
This example demonstrates how to use the W5500 Ethernet module on the B24M board as a TCP server. It listens on port 4196 and echoes back any string received from a client.

## File Structure
- `src/B24M_08_ethernet_tcp_server.ino` – Arduino source code.
- `precompiled/B24M_08_ethernet_tcp_server.bin` – Precompiled firmware binary for ESP32-S3.

## Using the Precompiled Binary
Flash `precompiled/B24M_08_ethernet_tcp_server.bin` to address `0x0` using ESP Flash Download Tool or `esptool.py`.

## Compiling from Source
- **Environment**: Arduino IDE with ESP32-S3 board support.
- **Dependencies**: Install `Ethernet` library (built-in).
- **Steps**: Open the `.ino` file, select `esp32-s3-devkitc-1`, and upload.

## Expected Behavior
The device starts as a TCP server on port 4196. When a client connects and sends data, the server echoes it back.

## Important Notes
- **Ethernet pins** (W5500):
  - CLK: GPIO1
  - MOSI: GPIO2
  - MISO: GPIO41
  - CS: GPIO42
  - RST: GPIO44
  - INT: GPIO43
- **Default IP**: 192.168.3.55 (configurable in code)
- **Serial Monitor** shows debug messages at 115200 baud.
