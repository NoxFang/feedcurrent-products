# Pi5M16 — Raspberry Pi 5 Industrial Controller Node-RED Flow

> Target Hardware: **Pi5M16** (Raspberry Pi 5 + 16-channel industrial I/O carrier board)

---

## Overview

The Pi5M16 is an industrial-grade digital I/O expansion platform built on the Raspberry Pi 5. It features two MCP23017 I2C GPIO expander chips providing **16 digital inputs** and **16 digital outputs**, plus an onboard OLED display, 4-channel ADC (voltage/current measurement), dual UART ports (including RS485), PWM outputs, and battery monitoring.

The `flows.json` file in this directory is the official Node-RED reference flow for this hardware. Import it to get started with basic testing and demonstrations of all onboard peripherals.

---

## Hardware Specifications

| Item | Specification |
|---|---|
| Mainboard | Raspberry Pi 5 |
| Digital Inputs (DI) | 16 channels (1 × MCP23017, internal pull-up, active-low) |
| Digital Outputs (DO) | 16 channels (1 × MCP23017, mosfet/transistor outputs) |
| Analog Inputs (AI) | 4 channels (ADS1115, 16-bit ADC, I2C) |
| OLED Display | SSD1306 128×64, I2C 0x3C |
| UART | 2 ports (`/dev/ttyAMA0`, `/dev/ttyAMA2`), 115200 8N1 |
| RS485 | 1 channel (multiplexed on `/dev/ttyAMA2`) |
| PWM | 2 channels (GPIO12 / GPIO13, default 20 kHz) |
| Battery Monitor | Onboard Battery node, drives OLED status display |

---

## I2C Bus Address Map

| Chip | I2C Address | Purpose |
|---|---|---|
| MCP23017 #1 | `0x20` | Digital Input channels 1–16 |
| MCP23017 #2 | `0x22` | Digital Output channels 1–16 |
| ADS1115 | `0x48` | 4-channel analog acquisition |
| SSD1306 OLED | `0x3C` | 128×64 pixel display |

> I2C bus: `/dev/i2c-1` (GPIO2 / GPIO3)

---

## Analog Input Scaling

The ADS1115 is configured in **single-ended** mode with a ±4.096 V full-scale range. Channel 0 samples at 920 SPS; channel 1 at 128 SPS.

| Channel | Measured Quantity | Front-End Circuit | Scaling Formula |
|---|---|---|---|
| AI1 | Voltage | Resistive divider Rtop=5.1 kΩ, Rbottom=10 kΩ | `V = V_adc × 1.51` |
| AI2 | Voltage | Resistive divider Rtop=5.1 kΩ, Rbottom=10 kΩ | `V = V_adc × 1.51` |
| AI3 | Current | Shunt resistor Rshunt=150 Ω | `I(mA) = V_adc / 150 × 1000` |
| AI4 | Current | Shunt resistor Rshunt=150 Ω | `I(mA) = V_adc / 150 × 1000` |

---

## Prerequisites

### 1. System Requirements

- Raspberry Pi OS (Bookworm or newer)
- Node-RED installed and running

### 2. Enable I2C and UART

```bash
sudo raspi-config
# Interface Options → I2C → Yes
# Interface Options → Serial Port → disable login shell, enable serial hardware
```

### 3. Install Node-RED Dependencies

From your Node-RED user directory (typically `~/.node-red`):

```bash
cd ~/.node-red
npm install node-red-node-serialport@2.0.3 \
  node-red-contrib-mcp23017chip@0.1.0 \
  node-red-contrib-oled-i2c@1.1.7 \
  node-red-node-pi-gpio@2.0.6 \
  node-red-contrib-ads1x15_i2c@0.0.14
```

Restart Node-RED after installation:

```bash
node-red-restart
```

---

## Importing the Flow

### Method A — Copy from GitHub (recommended)
1. Open `flows.json` on GitHub.
2. Click **Raw**.
3. Select all and copy.
4. Open Node-RED in your browser: `http://<pi-ip>:1880`
5. Click **Menu → Import**.
6. Choose **Clipboard**, paste the JSON, click **Import**.
7. Click **Deploy**.

### Method B — Download the file
1. Open `flows.json` on GitHub.
2. Click **Download** or right-click **Save as**.
3. In Node-RED, click **Menu → Import → File**.
4. Select the downloaded `flows.json`.
5. Click **Import**, then **Deploy**.

---

## Flow Structure

After import, the flow contains the following functional groups:

### OLED Group
- **SSD1306 OLED** initialization and display rendering
- **Battery node**: monitors battery voltage and outputs to screen
- Auto-refreshes once 1 second after startup

### AI (Analog Input) Group
- **read Analog Input**: manually triggers ADS1115 multi-channel read
- **calculate function node**: converts raw ADC readings to physical voltage/current using the divider and shunt values above
- **debug 4**: outputs scaled results to the debug sidebar

### Digital Outputs (16 MOSFETs)
- Each channel has a paired `ONx` / `OFFx` Inject node for manual mosfet testing
- Channel numbering 1–16, driven by MCP23017 at `0x22`

### Digital Inputs (16 Channels)
- 16 × MCP23017 input nodes, configured with internal pull-up, active-low, and 200 ms debounce
- Driven by MCP23017 at `0x20`
- Emits `true` / `false` messages on level changes

### UART / RS485
- `/dev/ttyAMA0`: general-purpose serial, sends/receives data and prints to debug sidebar
- `/dev/ttyAMA2`: RS485 test channel — send a test string via the `RS485 test` Inject node

### PWM Outputs
- **PWM0 output** (GPIO12) and **PWM1 output** (GPIO13): default duty cycle 30%, frequency 20 kHz

---

## Default Pin Reference

| Function | BCM GPIO | Notes |
|---|---|---|
| PWM0 | GPIO12 | PWM output, 20 kHz |
| PWM1 | GPIO13 | PWM output, 20 kHz |
| Extra GPIO Inputs (via rpi-gpio) | GPIO0,1,6,7,8,9,10,11,16–27 | Monitored directly by CM5, separate from MCP23017 DI |
| UART0 (RS232) | GPIO14 / GPIO15 (ttyAMA0) | RS232 serial communication |
| UART2 (RS485) | GPIO4 / GPIO5 (ttyAMA2) | RS485 communication |
| I2C1 | GPIO2 / GPIO3 | All I2C peripherals |

---

## Quick Verification Checklist

After importing and deploying, verify each subsystem in order:

- [ ] OLED screen lights up and shows battery info
- [ ] Click `read Analog Input` — debug sidebar shows AI1–AI4 values
- [ ] Click `ON1` then `OFF1` — mosfet clicks open/close
- [ ] Short any DI input terminal — corresponding level change appears in debug
- [ ] Click `RS485 test` — remote device receives the test string
- [ ] Adjust `PWM0 output` payload (0–100) — measured pin voltage changes accordingly

---

## Troubleshooting

| Problem | Check |
|---|---|
| MCP23017 not responding | Confirm I2C is enabled and the chip address matches `0x20` (DI) and `0x22` (DO). |
| MOSFET does not switch | Check output mapping and `invert` setting in the MCP23017 output node. |
| RS485 not working | Confirm `dtoverlay=uart3` is added and `/dev/ttyAMA2` exists. |
| OLED blank | Check I2C address `0x3C` and that `node-red-contrib-oled-i2c` is installed. |
| ADS1115 not reading | Check I2C address `0x48` and that `node-red-contrib-ads1x15_i2c` is installed. |

---

## License

This flow file is distributed as part of the [feedcurrent-products](https://github.com/NoxFang/feedcurrent-products) repository. Refer to the repository root for the full license terms.
