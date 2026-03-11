# FeedCurrent B8 Controller Arduino Example 04: RS485 Communication Test

## Description
This example tests RS485 communication by periodically sending a message and printing any received data.

## File Structure
- `src/B8_04_rs485_test.ino` – Arduino source code.
- `precompiled/B8_04_rs485_test.bin` – Precompiled binary.

## Using the Precompiled Binary
- Flash `precompiled/B8_04_rs485_test.bin` to `0x0`.

## Compiling from Source
- **Dependencies**: `HardwareSerial` (built-in).
- **Steps**: Compile and upload.

## Expected Behavior
- Sends `"Hello from FeedCurrent B8!"` every 3 seconds.
- If data is received, it prints: `Received: <message>`.

## Important Notes
- **Correct pins**: RXD=GPIO38, TXD=GPIO39. Ignore the incorrect comment in the code.
- Baud rate: 9600.