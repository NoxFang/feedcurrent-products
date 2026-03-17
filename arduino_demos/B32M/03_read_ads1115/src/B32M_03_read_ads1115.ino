/*
 * Made by FeedCurrent IoT: https://www.feedcurrent.com
 *
 * Description:
 * This Arduino program reads voltage from all four ADS1115 channels (A0-A3)
 * on the B32M board and prints the values in millivolts to the Serial Monitor.
 *
 * Pin Definitions:
 * - SDA: GPIO 8
 * - SCL: GPIO 18
 * - ADS1115 I2C Address: 0x48
 */

#include "Arduino.h"
#include "DFRobot_ADS1115.h"

// Define I2C pins
#define I2C_SDA 8
#define I2C_SCL 18

// Create ADS1115 object
DFRobot_ADS1115 ads1115;

void setup() {
    Serial.begin(115200);
    delay(1000);
    
    Serial.println("B32M - ADS1115 ADC Reader");
    Serial.println("Initializing I2C...");
    
    // Initialize I2C communication
    Wire.begin(I2C_SDA, I2C_SCL);
    
    // Initialize ADS1115
    ads1115.setAddr_ADS1115(ADS1115_IIC_ADDRESS0);  // 0x48
    ads1115.setGain(eGain_6_144);  // ±6.144V range
    ads1115.setMode(eMode_Single);
    ads1115.setRate(eRate_128);
    ads1115.setOSMode(eOSMode_Single);
    
    if (!ads1115.init()) {
        Serial.println("Failed to initialize ADS1115!");
        while (1);
    }
    
    Serial.println("ADS1115 initialized successfully!");
    Serial.println("Reading ADC values...\n");
}

void loop() {
    int16_t adc0, adc1, adc2, adc3;
    float voltage0, voltage1, voltage2, voltage3;
    
    // Read all 4 channels
    adc0 = ads1115.readVoltage(0);
    adc1 = ads1115.readVoltage(1);
    adc2 = ads1115.readVoltage(2);
    adc3 = ads1115.readVoltage(3);
    
    // Convert to voltage (for ±6.144V range, 1 bit = 0.1875mV)
    voltage0 = adc0 * 0.1875;
    voltage1 = adc1 * 0.1875;
    voltage2 = adc2 * 0.1875;
    voltage3 = adc3 * 0.1875;
    
    // Print results
    Serial.println("=================================");
    Serial.print("A0: ");
    Serial.print(voltage0, 1);
    Serial.println(" mV");
    
    Serial.print("A1: ");
    Serial.print(voltage1, 1);
    Serial.println(" mV");
    
    Serial.print("A2: ");
    Serial.print(voltage2, 1);
    Serial.println(" mV");
    
    Serial.print("A3: ");
    Serial.print(voltage3, 1);
    Serial.println(" mV");
    Serial.println("=================================\n");
    
    delay(2000);
}
