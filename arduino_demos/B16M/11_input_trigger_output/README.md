# FeedCurrent B16M Arduino Example 11: Digital Input Trigger Output Directly

## Description
This example links the 16 digital inputs (via PCF8575 at address `0x24`) directly to the 16 relay outputs (via PCF8575 at address `0x25`). When an input pin is **LOW**, the corresponding output pin is set to **LOW** (relay ON). When the input is **HIGH**, the output is set to **HIGH** (relay OFF). This creates a real-time, direct hardware linkage.

## File Structure
- `src/B16M_11_input_trigger_output.ino` – Arduino source code.
- `precompiled/B16M_11_input_trigger_output.bin` – Precompiled firmware binary for ESP32-S3.

## Using the Precompiled Binary
Flash `precompiled/B16M_11_input_trigger_output.bin` to address `0x0` using ESP Flash Download Tool or `esptool.py`.

## Compiling from Source
- **Environment**: Arduino IDE with ESP32-S3 board support.
- **Dependencies**: Install `PCF8575` library (e.g., by Rob Tillaart) via Library Manager.
- **Steps**: Open the `.ino` file, select `esp32-s3-devkitc-1`, and upload.

## Expected Behavior
- The board continuously reads the 16 digital inputs (connected to the input PCF8575 at `0x24`).
- The state of each input directly controls the corresponding relay output (output PCF8575 at `0x25`):
  - **Input 1 (pin 0) → Output 1 (pin 0)**
  - **Input 2 (pin 1) → Output 2 (pin 1)**
  - ...
  - **Input 16 (pin 15) → Output 16 (pin 15)**
- When an input pin is connected to GND (LOW), its corresponding relay activates (LOW). When the input is floating or HIGH, the relay remains off (HIGH).

## Important Notes
- **I2C pins**: SDA=GPIO38, SCL=GPIO39 (⚠️ critical for B16M – different from many other models).
- **Dual PCF8575 chips**:
  - **Input chip**: Address `0x24`, pins 0-15 connected to digital inputs.
  - **Output chip**: Address `0x25`, pins 0-15 connected to relay outputs.
- Inputs have pull-up resistors, so they read HIGH when no connection is made. To trigger an input, connect it to GND.
- Relays are active-LOW (energized when the pin is LOW), matching typical FeedCurrent hardware.
- The example includes a 500ms delay in the loop. For faster response, you can reduce or remove this delay.
- Serial Monitor output (at 115200 baud) shows a startup message but no continuous output.