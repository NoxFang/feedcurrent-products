# F16 Arduino Example 09: Tuya Module Communication (UART)

## Description
This example demonstrates communication between the ESP32‑S3 and a Tuya Wi‑Fi module (e.g., WB3S) via UART. The board listens for specific packets from the Tuya module and responds with pre‑defined data.

**Supported interactions**:
- Heartbeat request → sends heartbeat response
- Product information request → sends product info (JSON)
- Work mode request → sends work mode data
- Network status request → sends network status

This is the foundation for integrating the F16 with Tuya IoT cloud using an external Tuya module.

## File Structure
- `src/F16_09_tuya_communication.ino` – Arduino source code.
- `precompiled/F16_09_tuya_communication.bin` – Precompiled firmware binary for ESP32‑S3.

## Using the Precompiled Binary
Flash `precompiled/F16_09_tuya_communication.bin` to address `0x0` using ESP Flash Download Tool or `esptool.py`.

## Compiling from Source
- **Environment**: Arduino IDE with ESP32‑S3 board support.
- **Dependencies**: None beyond the standard ESP32 core.
- **Steps**: Open the `.ino` file, select `esp32-s3-devkitc-1`, and upload.

## Hardware Setup
Connect a Tuya Wi‑Fi module (e.g., WB3S) to the F16 board using the following pins:

| Tuya Module | ESP32‑S3 GPIO |
|-------------|---------------|
| TXD         | 39            |
| RXD         | 38            |
| VCC         | 3.3V          |
| GND         | GND           |

**Note**: The Tuya module’s TXD connects to ESP32’s RXD (GPIO38), and its RXD connects to ESP32’s TXD (GPIO39). Ensure the module is powered with 3.3V.

## Communication Protocol
The Tuya module sends 7‑byte packets with the following format:
[0x55, 0xAA, command, ...]
The ESP32‑S3 responds with pre‑defined packets based on the command.

### Supported Requests and Responses

| Request (hex)                              | Response (hex)                              |
|---------------------------------------------|---------------------------------------------|
| `55 AA 00 00 00 00 FF` (heartbeat)          | `55 AA 03 00 00 01 00 03`                   |
| `55 AA 00 01 00 00 00` (product info)       | `55 AA 03 01 00 2A 7B 22 70 ... AA` (JSON)  |
| `55 AA 00 02 00 00 01` (work mode)          | `55 AA 03 02 00 03 10 1C 14 47`             |
| `55 AA 00 03 00 01 00 03` (network status)  | `55 AA 03 03 00 00 05`                      |

Subsequent heartbeats receive a different response (`55 AA 03 00 00 01 01 04`).

## Expected Behavior
1. Open the Serial Monitor (115200 baud).
2. The ESP32‑S3 initializes UART communication with the Tuya module.
3. When the Tuya module sends a valid packet, the ESP32‑S3:
   - Prints the received packet in hex.
   - Sends the corresponding response packet.
   - Prints the sent packet.
4. Example Serial Monitor output:

ESP32-Tuya serial communication initialized.
Received packet: 55 AA 00 00 00 00 FF
Heartbeat received.
Sent packet: 55 AA 03 00 00 01 00 03
Received packet: 55 AA 00 01 00 00 00
Product info request received.
Sent packet: 55 AA 03 01 00 2A 7B 22 70 22 3A 22 63 68 6D 7A 6C 67 6A 70 61 64 70 71 78 64 6B 6F 22 2C 22 76 22 3A 22 31 2E 30 2E 30 22 2C 22 6D 22 3A 30 7D AA
...

## Important Notes
- **Serial Monitor**: Set baud rate to **115200**.
- The Tuya module’s baud rate is **9600** (configured in code).
- This example only handles the packets shown above. For full Tuya integration (DP control, status reporting, etc.), you must extend the code to parse and respond to DP commands as defined by the Tuya MCU protocol.
- The product info response contains a JSON payload with placeholders; modify it to match your actual product.

## Troubleshooting
- **No communication**: Check wiring and that the Tuya module is powered (3.3V). Verify that TX/RX are not swapped.
- **Incomplete packet errors**: Ensure the Tuya module is sending correctly sized packets. The code expects 7‑byte packets.
- **Invalid header**: Check that the module is sending packets starting with `0x55 0xAA`.

## Related Resources
- Pin definition: `../pin_definitions/F16/F16_pin_definition.md`
- Tuya MCU protocol specification (if extending)
