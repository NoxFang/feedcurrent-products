# Arduino Demo Sketches for All Products

This directory contains Arduino example sketches for various KinCony controllers. Each product has its own subfolder, and each example is organized as a standalone Arduino project with source code, precompiled binaries, and a description.

## Directory Structure

- `B32M/` – Examples for the **B32M** model (ESP32-S3, 32CH MOSFET)
- `B32/`  – Examples for the **B32** model (ESP32-S3 Relay) – functionally identical to B32M
- `B24M/` – Examples for the **B24M** model (ESP32-S3, 24CH MOSFET)
- `B24/`  – Examples for the **B24** model (ESP32-S3 Relay) – functionally identical to B24M
- `B16M/` – Examples for the **B16M** model (ESP32-S3, 16CH MOSFET)
- `B16/`  – Examples for the **B16** model (ESP32-S3 Relay) – functionally identical to B16M
- `B8M/`  – Examples for the **B8M** model (ESP32-S3, 8CH MOSFET)
- `B8/`   – Examples for the **B8** model (ESP32-S3 Relay) – functionally identical to B8M
- `B4M/`  – Examples for the **B4M** model (ESP32-S3, 4CH MOSFET)
- `B4/`   – Examples for the **B4** model (ESP32-S3 Relay) – functionally identical to B4M

Within each product folder, examples are numbered and named according to their function (e.g., `01_sequential_on_off`). Every example folder contains:

- `src/` – The Arduino `.ino` source code.
- `precompiled/` – Precompiled `.bin` firmware for quick flashing (using ESP Flash Download Tool at address `0x0`).
- `README.md` – Specific instructions for that example.

## How to Use

1. Navigate to the product and example you're interested in (e.g., `arduino_demos/B4/01_sequential_on_off/`).
2. Read the example's `README.md` for details on functionality, connections, and dependencies.
3. Either open the `.ino` file in Arduino IDE to compile and upload, or flash the precompiled `.bin` file using ESP32 flashing tools.

## Notes

- All examples assume the default hardware configuration as documented in the [pin definitions](../pin_definitions/).
- Make sure to install the required libraries mentioned in each example's README.
- The examples are tested on ESP32-S3 with the Arduino framework.

## Adding New Examples

When adding examples for a new product, please follow the same structure: create a product folder, then numbered example subfolders with the `src/` and `precompiled/` layout, and include a clear README.