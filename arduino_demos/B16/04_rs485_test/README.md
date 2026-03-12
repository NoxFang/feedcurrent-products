# FeedCurrent B16 Arduino Example 04: RS485 Communication Test

## Description
This example tests RS485 communication by periodically sending a message and printing any received data.

## File Structure
- `src/B16_04_rs485_test.ino` – Arduino source code.
- `precompiled/B16_04_rs485_test.bin` – Precompiled binary.

## Using the Precompiled Binary
Flash `precompiled/B16_04_rs485_test.bin` to `0x0`.

## Compiling from Source
- **Dependencies**: `HardwareSerial` (built-in).
- **Steps**: Compile and upload.

## Expected Behavior
- Sends `"Hello from FeedCurrent B16!"` every 3 seconds.
- If data is received, it prints: `Received: <message>`.

## Important Notes
- **Correct pins**: RXD=GPIO38, TXD=GPIO39. Ignore the incorrect comment in the code (which mistakenly mentions GPIO18/8).
- Baud rate: 9600.