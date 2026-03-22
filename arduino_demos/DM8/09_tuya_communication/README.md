# DM8 Arduino Demo 09 - Tuya WiFi Module Communication

## Overview

This example implements UART communication with the Tuya WiFi module, handling the Tuya protocol handshake and basic command responses.

## Features

- UART communication with Tuya WiFi module
- Responds to Tuya heartbeat packets
- Handles product info, work mode, network status queries
- Tuya protocol frame parsing

## Hardware Connections

| Pin | Function |
|-----|----------|
| GPIO17 | UART RXD (Tuya TXD) |
| GPIO16 | UART TXD (Tuya RXD) |

**Note**: Forum pin definition states RXD=GPIO15, but example code uses RXD=GPIO17. Pin GPIO17 is used in this example.

## Required Libraries

- `HardwareSerial` - Built-in

## Protocol Overview

| Command Received | Response |
|-----------------|----------|
| `55 AA 00 00 00 00 FF` | Heartbeat ACK |
| `55 AA 00 01 00 00 00` | Product info JSON |
| `55 AA 00 02 00 00 01` | Work mode response |
| `55 AA 00 03 00 01 00 03` | Net status + 2nd heartbeat |

## Usage

1. Connect Tuya WiFi module to UART pins
2. Upload the sketch to DM8
3. Open Serial Monitor (115200 baud)
4. Power on - Tuya module will begin initialization handshake
5. Monitor received packets and sent responses

## Notes

- Baud rate: 9600
- HardwareSerial port 1
- Tuya module connects via GPIO16/17
- This is a minimal example for testing protocol communication
