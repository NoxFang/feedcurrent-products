// Made by KinCony IoT: https://www.kincony.com

#include <Wire.h>
#include <PCF8575.h>

#define SDA_PIN 8
#define SCL_PIN 18

#define RELAY1 14        // Relay 1 on PCF8575 pin 14 (CH15)
#define RELAY2 15        // Relay 2 on PCF8575 pin 15 (CH16)

#define I2C_ADDRESS 0x22 // PCF8575 I2C address

PCF8575 pcf8575(I2C_ADDRESS);

void setup() {
    Wire.begin(SDA_PIN, SCL_PIN);
    Serial.begin(115200);
    Serial.println("PCF8575 Relay Control: Starting...");

    pcf8575.begin();

    // Initialize relays to OFF state (HIGH = OFF for active-LOW relay)
    pcf8575.write(RELAY1, HIGH);
    pcf8575.write(RELAY2, HIGH);
    Serial.println("All relays are OFF");
}

void loop() {
    Serial.println("Turning Relay 1 ON");
    pcf8575.write(RELAY1, LOW);
    delay(2000);
    Serial.println("Turning Relay 1 OFF");
    pcf8575.write(RELAY1, HIGH);
    delay(2000);

    Serial.println("Turning Relay 2 ON");
    pcf8575.write(RELAY2, LOW);
    delay(2000);
    Serial.println("Turning Relay 2 OFF");
    pcf8575.write(RELAY2, HIGH);
    delay(2000);
}
