# DM8 Arduino Demo 08 - Ethernet W5500 TCP Server

## Overview

This example sets up a TCP server on port 4196 using W5500 Ethernet module. It echoes back all received data to the client.

## Features

- W5500 SPI Ethernet module
- TCP server on port 4196
- Echo server (sends back received data)
- Static IP configuration

## Hardware Connections

| Pin | Function |
|-----|----------|
| GPIO1 | W5500 CLK |
| GPIO2 | W5500 MOSI |
| GPIO41 | W5500 MISO |
| GPIO42 | W5500 CS |
| GPIO43 | W5500 INT |
| GPIO44 | W5500 RST |

## Default Network Configuration

| Parameter | Value |
|-----------|-------|
| IP Address | 192.168.3.55 |
| Subnet | 255.255.255.0 |
| Gateway | 192.168.3.1 |
| DNS | 192.168.3.1 |
| Server Port | 4196 |

## Required Libraries

- `Ethernet` (W5500 compatible, e.g., Ethernet by Arduino)
- `SPI` - Built-in

## Usage

1. Adjust IP address in sketch to match your network
2. Upload the sketch to DM8
3. Open Serial Monitor (115200 baud)
4. Connect via TCP client to 192.168.3.55:4196
5. Send text - it will be echoed back

## Testing

Use netcat: `nc 192.168.3.55 4196`
Or telnet: `telnet 192.168.3.55 4196`

## Notes

- MAC address must be unique on the network
- W5500 is reset at startup
- Each client connection is handled sequentially
