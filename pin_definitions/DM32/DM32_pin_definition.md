# DM32 Pin Definition

## Hardware Information

- **Product**: KinCony DM32
- **MCU**: ESP32-S3-WROOM-1U (N16R8)
- **DAC Output**: 32-channel 0-10V (Modbus to ARM CPU)
- **Digital Input**: 32 channels (PCF8575 I2C x2)
- **Analog Input**: 4 channels (ADS1115, 2x0-5V, 2x4-20mA)
- **RTC**: DS3231 (I2C 0x68)
- **1-Wire**: 4 ports with PCB pull-up resistors
- **Network**: W5500 SPI Ethernet
- **Communication**: RS485 + Tuya WiFi (UART)
- **Storage**: MicroSD (SPI HSPI)
- **Display**: SSD1306 128x64 OLED (I2C 0x3C)

---

## GPIO Pin Assignment

### I2C Bus
| Signal | GPIO | Description |
|--------|-------|-------------|
| SDA | 8 | I2C Data |
| SCL | 18 | I2C Clock |

### 1-Wire Bus (with PCB pull-up resistors)
| Signal | GPIO | Description |
|--------|-------|-------------|
| 1-Wire1 | 47 | DS18B20 or other 1-Wire devices |
| 1-Wire2 | 48 | DS18B20 or other 1-Wire devices |
| 1-Wire3 | 7 | DS18B20 or other 1-Wire devices |
| 1-Wire4 | 40 | DS18B20 or other 1-Wire devices |

### Free GPIO (no pull-up on PCB)
| Signal | GPIO | Description |
|--------|-------|-------------|
| Free GPIO 1 | 13 | General purpose I/O |
| Free GPIO 2 | 14 | General purpose I/O |
| Free GPIO 3 | 21 | General purpose I/O |

---

## I2C Device Addresses

| Device | I2C Address | Description |
|---------|--------------|-------------|
| PCF8575 #1 | 0x22 | Digital Input 1-16 (Inputs 1-16) |
| PCF8575 #2 | 0x24 | Digital Input 17-32 (Inputs 17-32) |
| ADS1115 ADC | 0x48 | 4-channel analog-to-digital converter |
| 24C02 EEPROM | 0x50 | 2KB I2C EEPROM |
| DS3231 RTC | 0x68 | Real-time clock |
| SSD1306 OLED | 0x3C | 128x64 OLED display |

---

## UART Serial Configuration

| Interface | TXD Pin | RXD Pin | Description |
|-----------|-----------|-----------|-------------|
| RS485 | GPIO39 | GPIO38 | RS485 communication (9600 baud) |
| Tuya Module | GPIO16 | GPIO17 | Tuya WiFi MCU communication (9600 baud) |
| ARM CPU (DAC) | GPIO4 | GPIO6 | Modbus DAC control (115200 baud) |

---

## SPI Interface Configuration

### SD Card (HSPI)
| Signal | GPIO | Description |
|--------|-------|-------------|
| MOSI | 10 | SPI Data Out |
| SCK | 11 | SPI Clock |
| MISO | 12 | SPI Data In |
| CS | 9 | SPI Chip Select |
| SD-Detect | 5 | SD card detect pin |

### W5500 Ethernet (SPI)
| Signal | GPIO | Description |
|--------|-------|-------------|
| CLK | 1 | SPI Clock |
| MOSI | 2 | SPI Data Out |
| MISO | 41 | SPI Data In |
| CS | 42 | SPI Chip Select |
| INT | 43 | Interrupt pin |
| RST | 44 | Reset pin |

---

## Analog Input (ADS1115)

| Channel | Type | Range | Description |
|----------|-------|--------|-------------|
| A1 | Voltage | 0-5V DC | Analog input 1 |
| A2 | Voltage | 0-5V DC | Analog input 2 |
| A3 | Current | 4-20mA | Analog input 3 |
| A4 | Current | 4-20mA | Analog input 4 |

---

## Modbus DAC Configuration

**DAC Channels**: 32 channels (CH1-CH32)
**DAC Range**: 0-10V (mapped from 0-4095)
**Modbus Device ID**: 1
**Modbus Function Code**: 0x06 (Write Single Register), 0x10 (Write Multiple Registers)

| Channel | Register Address | Description |
|---------|-----------------|-------------|
| CH1 | 0x0FA0 (4000) | DAC output channel 1 |
| CH2 | 0x0FA1 (4001) | DAC output channel 2 |
| CH3 | 0x0FA2 (4002) | DAC output channel 3 |
| CH4 | 0x0FA3 (4003) | DAC output channel 4 |
| CH5 | 0x0FA4 (4004) | DAC output channel 5 |
| CH6 | 0x0FA5 (4005) | DAC output channel 6 |
| CH7 | 0x0FA6 (4006) | DAC output channel 7 |
| CH8 | 0x0FA7 (4007) | DAC output channel 8 |
| CH9 | 0x0FA8 (4008) | DAC output channel 9 |
| CH10 | 0x0FA9 (4009) | DAC output channel 10 |
| CH11 | 0x0FAA (4010) | DAC output channel 11 |
| CH12 | 0x0FAB (4011) | DAC output channel 12 |
| CH13 | 0x0FAC (4012) | DAC output channel 13 |
| CH14 | 0x0FAD (4013) | DAC output channel 14 |
| CH15 | 0x0FAE (4014) | DAC output channel 15 |
| CH16 | 0x0FAF (4015) | DAC output channel 16 |
| CH17 | 0x0FB0 (4016) | DAC output channel 17 |
| CH18 | 0x0FB1 (4017) | DAC output channel 18 |
| CH19 | 0x0FB2 (4018) | DAC output channel 19 |
| CH20 | 0x0FB3 (4019) | DAC output channel 20 |
| CH21 | 0x0FB4 (4020) | DAC output channel 21 |
| CH22 | 0x0FB5 (4021) | DAC output channel 22 |
| CH23 | 0x0FB6 (4022) | DAC output channel 23 |
| CH24 | 0x0FB7 (4023) | DAC output channel 24 |
| CH25 | 0x0FB8 (4024) | DAC output channel 25 |
| CH26 | 0x0FB9 (4025) | DAC output channel 26 |
| CH27 | 0x0FBA (4026) | DAC output channel 27 |
| CH28 | 0x0FBB (4027) | DAC output channel 28 |
| CH29 | 0x0FBC (4028) | DAC output channel 29 |
| CH30 | 0x0FBD (4029) | DAC output channel 30 |
| CH31 | 0x0FBE (4030) | DAC output channel 31 |
| CH32 | 0x0FBF (4031) | DAC output channel 32 |

---

## Digital Input Mapping (PCF8575)

### PCF8575 #1 (I2C 0x22) - Inputs 1-16
| Physical Input | PCF8575 Pin | Description |
|--------------|---------------|-------------|
| DI1 | P8 | Digital input 1 |
| DI2 | P9 | Digital input 2 |
| DI3 | P10 | Digital input 3 |
| DI4 | P11 | Digital input 4 |
| DI5 | P12 | Digital input 5 |
| DI6 | P13 | Digital input 6 |
| DI7 | P14 | Digital input 7 |
| DI8 | P15 | Digital input 8 |
| DI9 | P0 | Digital input 9 |
| DI10 | P1 | Digital input 10 |
| DI11 | P2 | Digital input 11 |
| DI12 | P3 | Digital input 12 |
| DI13 | P4 | Digital input 13 |
| DI14 | P5 | Digital input 14 |
| DI15 | P6 | Digital input 15 |
| DI16 | P7 | Digital input 16 |

### PCF8575 #2 (I2C 0x24) - Inputs 17-32
| Physical Input | PCF8575 Pin | Description |
|--------------|---------------|-------------|
| DI17 | P0 | Digital input 17 |
| DI18 | P1 | Digital input 18 |
| DI19 | P2 | Digital input 19 |
| DI20 | P3 | Digital input 20 |
| DI21 | P4 | Digital input 21 |
| DI22 | P5 | Digital input 22 |
| DI23 | P6 | Digital input 23 |
| DI24 | P7 | Digital input 24 |
| DI25 | P8 | Digital input 25 |
| DI26 | P9 | Digital input 26 |
| DI27 | P10 | Digital input 27 |
| DI28 | P11 | Digital input 28 |
| DI29 | P12 | Digital input 29 |
| DI30 | P13 | Digital input 30 |
| DI31 | P14 | Digital input 31 |
| DI32 | P15 | Digital input 32 |

---

## Tuya Module Control

| Signal | Tuya Pin | Description |
|---------|-----------|-------------|
| Network Button | P28 | Tuya WiFi reset/configure button |
| Network LED | P16 | Tuya WiFi status LED |

---

## Important Notes

- **1-Wire**: All 1-Wire pins (47, 48, 7, 40) have pull-up resistors on PCB. GPIO13, GPIO14, GPIO21 are free GPIO without pull-up.
- **PCF8575**: Two PCF8575 chips are used to expand 32 digital inputs. The first chip (0x22) handles inputs 1-16, and the second chip (0x24) handles inputs 17-32.
- **Modbus DAC**: The DAC is controlled via Modbus RTU protocol at 115200 baud on UART (RX=4, TX=6). The register address range is 0x0FA0-0x0FBF (4000-4031).
- **SD Card**: Uses HSPI bus at 80MHz frequency. The SD-Detect pin is GPIO5.
- **W5500 Ethernet**: Uses SPI bus with interrupt and reset pins. The default IP configuration is 192.168.3.55.
- **DS3231 RTC**: Uses I2C at 40kHz frequency. The I2C address is 0x68.
- **ADS1115 ADC**: Uses I2C address 0x48. The gain can be set to 6.144V range (2/3x gain) for measuring 0-5V or 4-20mA inputs.

---

## Reference

- **Data Source**: https://www.kincony.com/forum/showthread.php?tid=9019
- **Product Page**: https://www.kincony.com/
- **Last Updated**: 2026-03-20
