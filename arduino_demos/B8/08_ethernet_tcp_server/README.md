# FeedCurrent B8 Controller Arduino Example 08: Ethernet W5500 TCP Server

## Description
This example sets up the W5500 Ethernet module as a TCP server on port 4196, echoing back any received data.

## File Structure
- `src/B8_08_ethernet_tcp_server.ino` – Arduino source code.
- `precompiled/B8_08_ethernet_tcp_server.bin` – Precompiled binary.

## Using the Precompiled Binary
- Flash `precompiled/B8_08_ethernet_tcp_server.bin` to `0x0`.

## Compiling from Source
- **Dependencies**: `SPI.h`, `Ethernet.h` (built-in).
- **Steps**: Compile and upload.

## Expected Behavior
- Assigns static IP `192.168.3.55` (modify as needed).
- Any TCP client connecting to port 4196 will have its messages echoed back.

## Important Notes
- **Pins**: CLK=1, MOSI=2, MISO=41, CS=42, RST=44, INT=43. These are correctly defined in the code.
- MAC address `{0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED}` should be unique on your network.
- Modify IP settings to match your LAN.