# Pi5M8 Pin Definition

> CM5 Resource Pin Assignment Table — Based on the CM5 ALL RESOURCE Pinout Diagram

---

## CM5 GPIO Pin Assignment

### I2C1 (On-board I2C Bus)

| BCM GPIO | Function | Direction | Notes |
|---|---|---|---|
| GPIO2 | I2C1_SDA | Bi-directional | All I2C peripherals (OLED, ADS1115, MCP23017) |
| GPIO3 | I2C1_SCL | Output clock | All I2C peripherals (OLED, ADS1115, MCP23017) |

### UART0 — RS232 (`/dev/ttyAMA0`)

| BCM GPIO | Function | Direction | Notes |
|---|---|---|---|
| GPIO14 | UART0_TX | Output | RS232 TX |
| GPIO15 | UART0_RX | Input | RS232 RX |

### UART2 — RS485 (`/dev/ttyAMA2`)

| BCM GPIO | Function | Direction | Notes |
|---|---|---|---|
| GPIO4 | UART2_TX | Output | RS485 TX |
| GPIO5 | UART2_RX | Input | RS485 RX |

### PWM (2 Channels)

| BCM GPIO | Function | Direction | Notes |
|---|---|---|---|
| GPIO12 | PWM0[0] | Output | PWM output, default 20 kHz |
| GPIO13 | PWM0[1] | Output | PWM output, default 20 kHz |

### Extra GPIO Inputs (via rpi-gpio)

These pins are broken out on the carrier board and monitored directly by CM5 as general-purpose digital inputs.

| BCM GPIO | ALT Function (from CM5 table) | Direction | Notes |
|---|---|---|---|
| GPIO0 | SPI0_SIO[3] / UART1_TX | Input | General DI |
| GPIO1 | SPI0_SIO[2] / UART1_RX | Input | General DI |
| GPIO6 | GPCLK[1] / UART2_CTS | Input | General DI |
| GPIO7 | SPI0_CSn[1] / UART2_RTS | Input | General DI |
| GPIO8 | SPI0_CSn[0] / UART3_TX | Input | General DI |
| GPIO9 | SPI0_SIO[1] / UART3_RX | Input | General DI |
| GPIO10 | SPI0_SIO[0] / UART3_CTS | Input | General DI |
| GPIO11 | SPI0_SCLK / UART3_RTS | Input | General DI |
| GPIO16 | PWM0[3] / UART0_CTS | Input | General DI |
| GPIO17 | SPI1_CSn[0] / UART0_RTS | Input | General DI |
| GPIO18 | SPI1_CLK / I2S0_SCLK | Input | General DI |
| GPIO19 | SPI1_SIO[0] / I2S0_WS | Input | General DI |
| GPIO20 | SPI1_SIO[1] / I2S0_SDIO[0] | Input | General DI |
| GPIO21 | SPI1_SCLK / I2S0_SDO[0] | Input | General DI |
| GPIO22 | SDIO_CLK / I2C3_SDA | Input | General DI |
| GPIO23 | SDIO_CMD / I2C3_SCL | Input | General DI |
| GPIO24 | SDIO_DAT[0] / I2S0_SD[1] | Input | General DI |
| GPIO25 | SDIO_DAT[1] / I2S0_SD[2] | Input | General DI |
| GPIO26 | SDIO_DAT[2] / I2S0_M_CLK | Input | General DI |
| GPIO27 | SDIO_DAT[3] / I2S0_SD[3] | Input | General DI |

---

## I2C Peripheral Address Map

| I2C Address | Chip | Purpose |
|---|---|---|
| `0x20` | MCP23017 #1 | Digital Input channels 1–8 |
| `0x22` | MCP23017 #2 | MOSFET Output channels 1–8 |
| `0x48` | ADS1115 | 4-channel analog acquisition |
| `0x3C` | SSD1306 OLED | 128×64 pixel display |

---

## MCP23017 Channel Mapping

### Digital Inputs (DI) — MCP23017 at `0x20`

| Channel | MCP23017 Pin | Pull-up | Invert | Debounce |
|---|---|---|---|---|
| DI1 | GPA0 (bit 0) | Yes | Yes (active-low) | 200 ms |
| DI2 | GPA1 (bit 1) | Yes | Yes (active-low) | 200 ms |
| DI3 | GPA2 (bit 2) | Yes | Yes (active-low) | 200 ms |
| DI4 | GPA3 (bit 3) | Yes | Yes (active-low) | 200 ms |
| DI5 | GPA4 (bit 4) | Yes | Yes (active-low) | 200 ms |
| DI6 | GPA5 (bit 5) | Yes | Yes (active-low) | 200 ms |
| DI7 | GPA6 (bit 6) | Yes | Yes (active-low) | 200 ms |
| DI8 | GPA7 (bit 7) | Yes | Yes (active-low) | 200 ms |

### MOSFET Outputs (DO) — MCP23017 at `0x22`

| Channel | MCP23017 Pin | Invert |
|---|---|---|
| OUT1 | GPA0 (bit 0) | No |
| OUT2 | GPA1 (bit 1) | Yes |
| OUT3 | GPA2 (bit 2) | Yes |
| OUT4 | GPA3 (bit 3) | Yes |
| OUT5 | GPA4 (bit 4) | Yes |
| OUT6 | GPA5 (bit 5) | Yes |
| OUT7 | GPA6 (bit 6) | Yes |
| OUT8 | GPA7 (bit 7) | Yes |

---

## Analog Inputs (ADS1115 at `0x48`)

| Channel | Physical Quantity | Front-End | Scaling |
|---|---|---|---|
| AI1 (AIN0) | Voltage | Divider Rtop=5.1 kΩ, Rbottom=10 kΩ | `V = V_adc × 1.51` |
| AI2 (AIN1) | Voltage | Divider Rtop=5.1 kΩ, Rbottom=10 kΩ | `V = V_adc × 1.51` |
| AI3 (AIN2) | Current | Shunt Rshunt=150 Ω | `I(mA) = V_adc / 150 × 1000` |
| AI4 (AIN3) | Current | Shunt Rshunt=150 Ω | `I(mA) = V_adc / 150 × 1000` |

---

## Quick Reference Summary

| Function | Pins / Address | Device Path |
|---|---|---|
| I2C1 Bus | GPIO2 (SDA), GPIO3 (SCL) | `/dev/i2c-1` |
| RS232 | GPIO14 (TX), GPIO15 (RX) | `/dev/ttyAMA0` |
| RS485 | GPIO4 (TX), GPIO5 (RX) | `/dev/ttyAMA2` |
| PWM0 | GPIO12 | — |
| PWM1 | GPIO13 | — |
| OLED SSD1306 | I2C 0x3C | — |
| ADS1115 ADC | I2C 0x48 | — |
| MCP23017 DI | I2C 0x20 | — |
| MCP23017 DO (MOSFET) | I2C 0x22 | — |
