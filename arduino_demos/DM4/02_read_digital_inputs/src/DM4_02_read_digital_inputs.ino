/*
KeyPressed on PIN1
by Mischianti Renzo <http://www.mischianti.org>

https://www.mischianti.org/2019/01/02/pcf8574-i2c-digital-i-o-expander-fast-easy-usage/
*/

#include "Arduino.h"
#include "PCF8574.h"

// Define I2C pins
#define I2C_SDA 8   // SDA pin
#define I2C_SCL 18  // SCL pin

// Set i2c address
PCF8574 pcf8574(0x24);
unsigned long timeElapsed;
void setup()
{
    Wire.begin(I2C_SDA, I2C_SCL);
    Serial.begin(115200);
    delay(1000);

//    pcf8574.pinMode(P0, OUTPUT);
pcf8574.pinMode(P0, INPUT);
pcf8574.pinMode(P1, INPUT);
pcf8574.pinMode(P2, INPUT);
pcf8574.pinMode(P3, INPUT);


    Serial.print("Init pcf8574...");
    if (pcf8574.begin()){
        Serial.println("OK");
    }else{
        Serial.println("KO");
    }
}

void loop()
{
uint8_t val1 = pcf8574.digitalRead(P0);
uint8_t val2 = pcf8574.digitalRead(P1);
uint8_t val3 = pcf8574.digitalRead(P2);
uint8_t val4 = pcf8574.digitalRead(P3);

if (val1==LOW) Serial.println("KEY1 PRESSED");
if (val2==LOW) Serial.println("KEY2 PRESSED");
if (val3==LOW) Serial.println("KEY3 PRESSED");
if (val4==LOW) Serial.println("KEY4 PRESSED");

    delay(300);
}