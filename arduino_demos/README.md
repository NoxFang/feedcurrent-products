# Arduino Demo Sketches for All Products

This directory contains Arduino example sketches for various FeedCurrent controllers. Each product has its own subfolder, and each example is organized as a standalone Arduino project with source code, precompiled binaries, and a description.

## Directory Structure

### F Series – Relay Controllers
- `F4/`   – 4‑channel relay board
- `F8/`   – 8‑channel relay board
- `F16/`  – 16‑channel relay board
- `F24/`  – 24‑channel relay board
- `F32/`  – 32‑channel relay board

### DM Series – Digital Input Modules
- `DM4/`   – 4‑channel digital input module
- `DM8/`   – 8‑channel digital input module
- `DM16/`  – 16‑channel digital input module
- `DM32/`  – 32‑channel digital input module

### N Series – Energy Meter Controllers
- `N10/`  – 10‑channel energy meter (ESP32‑S3)
- `N20/`  – 20‑channel energy meter
- `N30/`  – 30‑channel energy meter
- `N60/`  – 60‑channel energy meter

### T Series – High‑Density I/O Controllers
- `T16M/`   – 16‑channel relay & input board
- `T32M/`   – 32‑channel relay & input board
- `T64M/`   – 64‑channel relay & input board (dual I2C buses)
- `T128M/`  – 128‑channel relay & input board (dual I2C buses)

### B Series – MOSFET & Relay Boards
- `B4/`     – 4‑channel relay board (functionally identical to B4M)
- `B4M/`    – 4‑channel MOSFET board
- `B8/`     – 8‑channel relay board (functionally identical to B8M)
- `B8M/`    – 8‑channel MOSFET board
- `B16/`    – 16‑channel relay board (functionally identical to B16M)
- `B16M/`   – 16‑channel MOSFET board
- `B24/`    – 24‑channel relay board (functionally identical to B24M)
- `B24M/`   – 24‑channel MOSFET board

### Special / Industrial
- `G1/`        – Gateway controller
- `TA/`        – Thermostat adapter
- `AIO Hybrid/` – All‑in‑one hybrid controller

Within each product folder, examples are numbered and named according to their function (e.g., `01_turn_on_off_relay`). Every example folder contains:

- `src/` – The Arduino `.ino` source code.
- `precompiled/` – Precompiled `.bin` firmware for quick flashing (using ESP Flash Download Tool at address `0x0`).
- `README.md` – Specific instructions for that example.

## How to Use

1. Navigate to the product and example you're interested in (e.g., `arduino_demos/F16/01_turn_on_off_relay/`).
2. Read the example's `README.md` for details on functionality, connections, and dependencies.
3. Either open the `.ino` file in Arduino IDE to compile and upload, or flash the precompiled `.bin` file using ESP32 flashing tools.

## Notes

- All examples assume the default hardware configuration as documented in the [pin definitions](../pin_definitions/).
- Make sure to install the required libraries mentioned in each example's README.
- The examples are tested on ESP32-S3 with the Arduino framework.

## Adding New Examples

When adding examples for a new product, please follow the same structure: create a product folder, then numbered example subfolders with the `src/` and `precompiled/` layout, and include a clear README.