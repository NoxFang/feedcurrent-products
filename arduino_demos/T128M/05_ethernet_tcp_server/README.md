# T128M Example 05: Ethernet W5500 TCP Server

## Overview
This example implements a TCP server on the T128M module using the built-in W5500 Ethernet controller. It allows remote control and monitoring of all 256 I/O channels over Ethernet.

## Hardware Requirements
- T128M with W5500 Ethernet
- Power supply: 12-24V DC
- Ethernet cable
- Router/switch for network connection
- Network configuration (IP, subnet, gateway)

## Network Configuration
- **Default IP**: 192.168.1.100
- **Subnet Mask**: 255.255.255.0
- **Gateway**: 192.168.1.1
- **MAC Address**: From W5500 chip
- **TCP Port**: 4196 (configurable)

## Features
- Multi-client TCP server (up to 8 clients)
- Telnet-style command interface
- Real-time I/O status reporting
- Configurable network parameters
- Connection statistics and monitoring

## Protocol
### Command Format
```
<command> [parameters]
```
### Available Commands
- `help` - Show command list
- `status` - Get device status
- `output on <port>` - Turn output ON
- `output off <port>` - Turn output OFF
- `input read <port>` - Read input state
- `config` - Show configuration
- `reset` - Reset network connection

## Usage
1. Connect Ethernet cable
2. Configure network settings if needed
3. Upload code to T128M
4. Connect via telnet or TCP client
5. Send commands to control I/O

## Testing
- Use `telnet 192.168.1.100 4196`
- Send `help` to see available commands
- Test input/output control
- Verify network stability