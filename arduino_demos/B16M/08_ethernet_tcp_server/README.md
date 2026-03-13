# FeedCurrent B16M Controller Arduino Example 08: Ethernet W5500 TCP Server

## Description
This example sets up the W5500 Ethernet module as a TCP server on port 4196, echoing back any received data.

## File Structure
- `src/B16M_08_ethernet_tcp_server.ino` – Arduino source code.
- `precompiled/B16M_08_ethernet_tcp_server.bin` – Precompiled binary.

## Using the Precompiled Binary
Flash `precompiled/B16M_08_ethernet_tcp_server.bin` to `0x0`.

## Compiling from Source
- **Dependencies**: `SPI.h`, `Ethernet.h` (built-in).
- **Steps**: Compile and upload.

## Expected Behavior
- Assigns static IP `192.168.3.55` (modify as needed).
- Any TCP client connecting to port 4196 will have its messages echoed back.

## Important Notes
- **Ethernet pins**: CLK=42, MOSI=43, MISO=44, CS=41, RST=1, INT=2 (verify with B16M pin definition).
- MAC address `{0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED}` should be unique on your network.