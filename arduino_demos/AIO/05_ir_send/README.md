# AIO Hybrid Arduino Example 05: IR Send (38 kHz Carrier)

## Description
This example demonstrates how to generate a 38 kHz PWM carrier signal using the ESP32‑S3 LEDC hardware peripheral. The output can be used to drive an infrared (IR) LED for transmitting IR remote control signals.

## File Structure
- `src/AIO_05_ir_send.ino` – Arduino source code.
- `precompiled/AIO_05_ir_send.bin` – Precompiled firmware binary for ESP32‑S3 (to be added).

## Using the Precompiled Binary
1. Download the `.bin` file from the `precompiled/` folder.
2. Use the official **ESP Flash Download Tool** or `esptool.py` to flash it to the AIO Hybrid controller.
3. **Flash Address**: `0x0` (as indicated in the forum post).

## Compiling from Source
1. **Environment**: Install Arduino IDE and add ESP32‑S3 board support (via Boards Manager).
2. **Dependencies**: None (uses built‑in ESP32 LEDC driver).
3. **Steps**:
   - Open `src/AIO_05_ir_send.ino` in Arduino IDE.
   - Select the correct board (`esp32-s3-devkitc-1`) and port.
   - Compile and upload.

## Expected Behavior
- After uploading, the IR LED connected to GPIO14 will continuously output a 38 kHz square wave with 50% duty cycle.
- The Serial Monitor (115200 baud) will display `"38kHz PWM started."`.

## Important Notes
- **IR output pin**: GPIO14 (as defined by `IR_SEND_PIN`).
- **Frequency**: 38 kHz – suitable for most consumer IR remote controls (e.g., NEC protocol).
- **Duty cycle**: 50% (128/255).
- **Continuous carrier**: The example outputs the carrier continuously. To send actual IR codes (e.g., NEC, Sony, etc.), you would need to modulate the carrier with the appropriate code patterns (e.g., using `ledc_set_duty()` and `ledc_update_duty()`).
- **Hardware**: The IR LED should be connected to GPIO14 through a current‑limiting resistor (typically 100–150 Ω) and, optionally, a transistor for higher current.
- **LEDC configuration**: The code uses LEDC timer 0, channel 0, with 8‑bit resolution.