# DM16 Arduino Example 04: RS485 Communication Test

## Description
This example tests RS485 communication on the DM16 board. It periodically sends a test message over the RS485 bus and prints any received data to the Serial Monitor.

## Hardware Connections
| Signal | GPIO |
|--------|------|
| RS485 RXD | GPIO38 |
| RS485 TXD | GPIO39 |

**Communication Parameters:**
- Baud rate: 9600
- Data bits: 8
- Parity: None
- Stop bits: 1

## Serial Output
After uploading, open the Serial Monitor at **115200 baud**. You will see:
RS485 Test Start
Every 3 seconds, the board sends the message `"Hello from FeedCurrent B16!"`. If another RS485 device responds, the received message is printed as:
Received: <response>

## Usage
1. Connect the RS485 A/B terminals to another RS485 device or create a loopback for testing.
2. Upload the sketch to the DM16 board.
3. Open the Serial Monitor at 115200 baud.
4. Observe the sent messages and any received replies.

## Notes
- The example does not control the RS485 direction pin (DE) – it assumes the transceiver is always in transmit/receive mode or uses automatic direction control.
- The loop sends a message every 3 seconds (1 second delay after sending, then 2 seconds before the next send).
- To test without another device, connect the RS485 TX and RX pins together (loopback) to see your own messages echoed.

## Dependencies
- `HardwareSerial` (built‑in)

## Related Resources
- DM16 Pin Definition: `../pin_definitions/DM16/DM16_pin_definition.md`