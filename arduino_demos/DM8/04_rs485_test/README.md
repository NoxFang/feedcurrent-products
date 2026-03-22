# DM8 Arduino Demo 04 - RS485 Communication Test

## Overview

This example tests RS485 communication by sending a test message and displaying received data.

## Features

- RS485 serial communication at 9600 baud
- Sends "Hello from FeedCurrent DM8!" every 3 seconds
- Displays received data from RS485
- HardwareSerial port 1

## Hardware Connections

| Pin | Function |
|-----|----------|
| GPIO38 | RS485 RXD |
| GPIO39 | RS485 TXD |

## Required Libraries

- `HardwareSerial` - Built-in

## Usage

1. Connect RS485 device to DM8 (GPIO38/39)
2. Upload the sketch to DM8
3. Open Serial Monitor (115200 baud)
4. Observe sent messages and received data

## Notes

- Baud rate: 9600
- Data format: 8N1
- HardwareSerial port 1
