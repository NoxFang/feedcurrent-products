# FeedCurrent B32M Controller Arduino Example 08: Ethernet W5500 TCP Server

## Description
This example sets up the W5500 Ethernet module on the B32M board as a TCP server on port 4196, echoing back any received data.

## File Structure
- `src/B32M_08_ethernet_tcp_server.ino` – Arduino source code.
- `precompiled/B32M_08_ethernet_tcp_server.bin` – Precompiled firmware binary for ESP32-S3.

## Using the Precompiled Binary
Flash `precompiled/B32M_08_ethernet_tcp_server.bin` to address `0x0` using ESP Flash Download Tool or `esptool.py`.

## Compiling from Source
- **Environment**: Arduino IDE with ESP32-S3 board support.
- **Dependencies**: `SPI.h`, `Ethernet.h` (built-in).
- **Steps**: Open the `.ino` file, select `esp32-s3-devkitc-1`, and upload.

## Expected Behavior
- Assigns static IP `192.168.1.100` (modify as needed).
- Any TCP client connecting to port 4196 will have its messages echoed back.

## Important Notes
- **Ethernet pins**: CLK=GPIO1, MOSI=GPIO2, MISO=GPIO41, CS=GPIO42, RST=GPIO44, INT=GPIO43.
- **MAC address**: `{0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED}` should be unique on your network.
- **Serial Monitor** shows debug messages at 115200 baud.
