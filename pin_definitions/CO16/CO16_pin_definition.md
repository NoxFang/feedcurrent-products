IIC Bus:

SDA:GPIO8
SCL:GPIO18

PCF8575: (relay1-16): i2c address:0x22

XL9555: (input1-16): i2c address:0x24

24C02 EPROM i2c address: 0x50
DS3231 RTC i2c address: 0x68

ST7789 SPI display:

  SCK: GPIO11
  MOSI: GPIO10
  MISO: GPIO12
  CS: GPIO4
  DC: GPIO0
  RESET: GPIO5
  Back light: GPIO40

ADC (DC 0-10v/4-20mA set by jumper):
jumper: short UP: set for DC 0-10V signal.
jumper: short DOWN: set for DC 4-20mA signal.

ADS1115-1 (U35) adc CH1-CH4: i2c address:0x48
ADS1115-2 (U7): adc CH5-CH8:i2c address:0x49
ADS1115-3 (U15): adc CH9-CH12:i2c address:0x4B
ADS1115-4 (U19): adc CH13-CH16:i2c address:0x4A

------------------

NX3L4051:

S1:GPIO7
S2:GPIO21

------------------
SPI bus for MAX31865

SPI-MOSI: GPIO10
SPI-SCK: GPIO11
SPI-MISO: GPIO12
PTC_CS: GPIO14
PTC_RDY: GPIO21
-----------------
LoRa_RST: GPIO5
LoRa_INT: GPIO40
LoRa_CS:GPIO13
-----------------

Ethernet (W5500) I/O define:

clk_pin: GPIO1
mosi_pin: GPIO2
miso_pin: GPIO41
cs_pin: GPIO42

interrupt_pin: GPIO43
reset_pin: GPIO44

--------------------
RS485:
RXD:GPIO38
TXD:GPIO39

Tuya module:
RXD:GPIO17
TXD:GPIO16

Tuya network button: Tuya module's P28
Tuya network LED: Tuya module's P16
--------------------
SD Card:
SPI-MOSI:GPIO10
SPI-SCK:GPIO11
SPI-MISO:GPIO12
SD-CS:GPIO9

--------------------

433MHz RF receiver: GPIO6

4G SIM7600/KNX RXD: GPIO47
4G SIM7600/KNX TXD: GPIO48