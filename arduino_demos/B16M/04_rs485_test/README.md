# FeedCurrent B16M Arduino Example 04: RS485 Communication Test

## Description
This example tests RS485 communication by periodically sending a message and printing any received data.

## File Structure
- `src/B16M_04_rs485_test.ino` – Arduino source code.
- `precompiled/B16M_04_rs485_test.bin` – Precompiled binary.

## Using the Precompiled Binary
Flash `precompiled/B16M_04_rs485_test.bin` to `0x0`.

## Compiling from Source
- **Dependencies**: `HardwareSerial` (built-in).
- **Steps**: Compile and upload.

## Expected Behavior
- Sends `"Hello from FeedCurrent F16!"` every 3 seconds (you may change the message).
- If data is received, it prints: `Received: <message>`.

## Important Notes
- **RS485 pins**: TX=GPIO18, RX=GPIO8 (⚠️ opposite to many other models).
- Baud rate: 9600.