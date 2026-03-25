# N20 Arduino Example 05: Collect All Energy Meter Data (Modbus RTU)

## Description
This example demonstrates reading electrical parameters from a 60‑channel energy meter (6 chips × 10 channels) via RS485 Modbus RTU. It collects current, power, energy, voltage, frequency, temperature, and power factor from all chips and prints the data to the Serial Monitor.

- **Modbus protocol**: Reads 68 holding registers per chip
- **Chips**: 6 devices, each with its own register address range (chip_n × 100)
- **Task scheduling**: Uses `TaskScheduler` to run data collection every 200 ms and a heartbeat task every 1 s

## File Structure
- `src/N20_05_collect_all_data.ino` – Arduino source code.
- `precompiled/N20_05_collect_all_data.bin` – Precompiled firmware binary for ESP32‑S3.

## Using the Precompiled Binary
Flash `precompiled/N20_05_collect_all_data.bin` to address `0x0` using ESP Flash Download Tool or `esptool.py`.

## Compiling from Source
- **Environment**: Arduino IDE with ESP32‑S3 board support.
- **Required libraries** (install via Library Manager):
  - `TaskScheduler` by Arkadiusz Chabas
  - `NonBlockingModbusMaster` by Ilya Melnikov
- **Library modification** (critical):
  After installing `NonBlockingModbusMaster`, open its header file (e.g., `NonBlockingModbusMaster.h`) and modify:
  ```cpp
  static const uint8_t maxTXLen = 254;
  static const uint8_t ku8MaxBuffersize = 126;
  ```
This is required to handle the 68‑register (136‑byte) Modbus response.

- Steps: Open the .ino file, select esp32-s3-devkitc-1, and upload.

## Hardware Connections
The N20 board includes an onboard RS485 transceiver. No external module is required.

| Signal | ESP32‑S3 GPIO | Description |
|--------|---------------|-------------|
| RS485 DE (direction control) | GPIO3 (`DE_PIN`) | Controls RS485 transceiver direction (HIGH = transmit) |
| RS485 TX (to meter) | GPIO8 (`TX_PIN`) | Data output from ESP32 to meter |
| RS485 RX (from meter) | GPIO18 (`RX_PIN`) | Data input from meter to ESP32 |

**Note**: The code initializes the hardware serial for Modbus on pins 9 (RX) and 10 (TX) via `collectSerial.begin(115200, SERIAL_8N1, 9, 10);`. Ensure your meter is connected to the correct RS485 terminals (A/B) and that the DE pin is wired to the transceiver’s enable line.

## Expected Behavior
- After upload, open the Serial Monitor (115200 baud).
- The board sends Modbus queries to chips 1‑6 sequentially, each requesting 68 registers.
- Every full cycle (after chip 6), it prints all collected data in a formatted table:
>>chip/socket : 1 Info:
RMS_1:    0.00 A,
RMS_2:    0.00 A,
...
WATT_1:   0.00 W,
...
Energy_1: 0 kWh,
...
RMS_V:    233.58 V,
Period:   49.70 Hz,
Chip_Temp: 25.5 ^C,
PF:       0.0000 .
>>Data Finished!>>
heartbeat task is running.
- Heartbeat messages appear every second.

## Important Notes
- **Modbus addressing**: Chip 1 uses registers starting at address `100`, chip 2 at `200`, …, chip 6 at `600`.
- **Data scaling**:
  - Current (RMS): multiply raw value by 0.001 → Amps
  - Power (WATT): multiply raw value by 0.1 → Watts
  - Energy: raw value → kWh
  - Voltage: multiply raw value by 0.01 → Volts
  - Frequency: multiply raw value by 0.01 → Hz
  - Temperature: raw value × 0.1 → °C
- The example is configured for a **60‑channel meter** (10 channels per chip). Adjust `MAX_U16DATA_LEN` and the number of chips if using a different configuration.
- If communication fails, the Serial Monitor will display error codes and retry.

## Troubleshooting
| Issue | Solution |
|-------|----------|
| No data, timeouts | Check RS485 wiring (A/B polarity, termination). Verify meter address and baud rate (115200, 8N1). |
| Garbled output | Ensure the `NonBlockingModbusMaster` library has the modified buffer sizes (`maxTXLen=254`, `ku8MaxBuffersize=126`). |
| Data shows zero | Confirm the meter is powered and correctly connected. If using a different meter, adjust register mapping. |

## Related Resources
- Pin definition: `../pin_definitions/N20/N20_pin_definition.md`
- [NonBlockingModbusMaster Library](https://github.com/ilyamelnikov/NonBlockingModbusMaster)
- [TaskScheduler Library](https://github.com/arkhipenko/TaskScheduler)