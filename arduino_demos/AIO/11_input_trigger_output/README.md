# AIO Hybrid Arduino Example 11: Infrared Receiver (IRremote)

## Description
This example demonstrates how to receive infrared (IR) signals using the IRremote library. It listens on GPIO17 for IR codes and prints decoded protocol information, raw data, and send usage details to the Serial Monitor.

## File Structure
- `src/AIO_11_input_trigger_output.ino` – Arduino source code.
- `precompiled/AIO_11_input_trigger_output.bin` – Precompiled firmware binary for ESP32‑S3 (to be added).

## Using the Precompiled Binary
1. Download the `.bin` file from the `precompiled/` folder.
2. Use the official **ESP Flash Download Tool** or `esptool.py` to flash it to the AIO Hybrid controller.
3. **Flash Address**: `0x0` (as indicated in the forum post).

## Compiling from Source
1. **Environment**: Install Arduino IDE and add ESP32‑S3 board support (via Boards Manager).
2. **Dependencies**:
   - `IRremote.hpp` – Install via Library Manager (search for "IRremote" by Armin Joachimsmeyer).
3. **Steps**:
   - Open `src/AIO_11_input_trigger_output.ino` in Arduino IDE.
   - Select the correct board (`esp32-s3-devkitc-1`) and port.
   - Compile and upload.

## Expected Behavior
After uploading, open the Serial Monitor at **115200 baud**. Point an IR remote control at the IR receiver (connected to GPIO17) and press buttons. For known protocols (e.g., NEC, Sony), the output will show decoded information:
recv data
Protocol=NEC Address=0x00 Command=0x45 Raw-Data=0x45FF00
Send with: sendNEC(0x00, 0x45, <number of repeats>);

For unknown protocols, raw timing data will be printed.

## Important Notes
- **IR receiver pin**: GPIO17 (as defined by `receiver_pin`). Ensure your IR receiver module is connected to this pin with appropriate pull‑up (often 10kΩ) and a 100µF capacitor for noise filtering.
- **Library**: The example uses the [IRremote library](https://github.com/Arduino-IRremote/Arduino-IRremote). Make sure to install it before compiling.
- **Known protocols**: By default, all common protocols (NEC, Sony, RC5, RC6, etc.) are enabled. To restrict to a specific protocol, uncomment the appropriate define in `IRremote.hpp` or use the `IrReceiver.enableIRIn()` variant.
- **No data**: The `loop()` prints nothing when no signal is received. Uncomment the `Serial.println("no data");` line to see a heartbeat.
- **Raw data**: For unknown protocols, the sketch prints raw timing data, which can be used to create custom decoders.

## Related Resources
- Pin definition: `../pin_definitions/AIO/AIO_pin_definition.md`
- [IRremote library documentation](https://github.com/Arduino-IRremote/Arduino-IRremote)