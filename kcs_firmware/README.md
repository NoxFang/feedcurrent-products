# KCS Firmware System

This directory contains the **KCS firmware** for all FeedCurrent ESP32‑S3 based controllers.  
The same firmware binary works across all supported models.

## Supported Products

- F Series: F4, F8, F16, F24, F32
- DM Series: DM4, DM8, DM16, DM32
- N Series: N10, N20, N30, N60
- T Series: T16M, T32M, T64M, T128M
- B Series: B4, B4M, B8, B8M, B16, B16M, B24, B24M
- Special: G1, TA, AIO Hybrid

## Firmware Files

- `kcs_v3.15.0.bin` – Latest stable release
- Older versions are kept for reference

## Flashing Instructions

### Using ESP Flash Download Tool (Windows)

1. Open ESP Flash Download Tool.
2. Select **ESP32-S3** as the chip type.
3. Add the `.bin` file with address **0x0**.
4. Connect the board via USB, select the correct COM port.
5. Click **START**.

## Version History

| Version | Date       | Notes                         |
|---------|------------|-------------------------------|
| v3.24.2 | 2026-03-25 | Latest unified release        |

## Notes

- Always backup your configuration before flashing.
- After flashing, you may need to reconfigure network settings.

## Related Resources

- [Product Documentation](../README.md)
- [Arduino Examples](../arduino_demos/)
- [ESPHome Configs](../esphome_configs/)