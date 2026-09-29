/*
 * FeedCurrent 16-Channel Analog Input Monitor
 *
 * Four ADS1115 ADC modules are used:
 *
 * ADS1115-1 (U35): CH1-CH4   I2C address: 0x48
 * ADS1115-2 (U7):  CH5-CH8   I2C address: 0x49
 * ADS1115-3 (U15): CH9-CH12  I2C address: 0x4B
 * ADS1115-4 (U19): CH13-CH16 I2C address: 0x4A
 *
 * ESPHome equivalent configuration:
 *
 * gain: 4.096
 * filters:
 *   - lambda: 'return x <= 0.0025f ? 0.0f : x;'
 *   - multiply: 5.16696
 *   - clamp:
 *       min_value: 0.0
 *       max_value: 10.0
 *
 * Only channels with an input voltage greater than 0.5V
 * will be printed.
 *
 * Copyright: Made by FeedCurrent IoT: https://www.feedcurrent.com
 */

#include <Wire.h>
#include <DFRobot_ADS1115.h>

// I2C pins
#define SDA_PIN 8
#define SCL_PIN 18

// ADS1115 I2C addresses
#define ADS1115_1_ADDR 0x48
#define ADS1115_2_ADDR 0x49
#define ADS1115_3_ADDR 0x4B
#define ADS1115_4_ADDR 0x4A

// ESPHome calibration multiplier
#define VOLTAGE_MULTIPLIER 5.16696f

// ESPHome zero threshold
#define ADC_ZERO_THRESHOLD 0.0025f

// Print threshold
#define PRINT_THRESHOLD 0.5f

// Maximum input voltage
#define MAX_INPUT_VOLTAGE 10.0f


// Create ADS1115 objects
DFRobot_ADS1115 ads1(&Wire);
DFRobot_ADS1115 ads2(&Wire);
DFRobot_ADS1115 ads3(&Wire);
DFRobot_ADS1115 ads4(&Wire);


/*
 * Read ADS1115 channel and convert to actual input voltage.
 *
 * DFRobot readVoltage() returns voltage in mV.
 *
 * ESPHome:
 *     x <= 0.0025V -> 0V
 *     x * 5.16696
 *     clamp 0~10V
 */
float readInputVoltage(DFRobot_ADS1115 &ads, uint8_t channel)
{
    // Read ADC voltage in mV
    uint16_t adc_mV = ads.readVoltage(channel);

    // Convert mV to V
    float adcVoltage = adc_mV / 1000.0f;

    // ESPHome lambda filter
    if (adcVoltage <= ADC_ZERO_THRESHOLD)
    {
        return 0.0f;
    }

    // ESPHome multiply filter
    float inputVoltage = adcVoltage * VOLTAGE_MULTIPLIER;

    // ESPHome clamp filter
    if (inputVoltage < 0.0f)
    {
        inputVoltage = 0.0f;
    }

    if (inputVoltage > MAX_INPUT_VOLTAGE)
    {
        inputVoltage = MAX_INPUT_VOLTAGE;
    }

    return inputVoltage;
}


/*
 * Check one analog channel.
 *
 * If the actual input voltage is greater than 0.5V,
 * print the channel number and voltage.
 */
void checkChannel(
    DFRobot_ADS1115 &ads,
    uint8_t adcChannel,
    uint8_t channelNumber)
{
    float voltage = readInputVoltage(ads, adcChannel);

    if (voltage > PRINT_THRESHOLD)
    {
        Serial.print("CH");
        Serial.print(channelNumber);
        Serial.print(": ");

        Serial.print(voltage, 2);

        Serial.println(" V");
    }
}


void setup(void)
{
    // Initialize serial communication
    Serial.begin(115200);

    // Initialize I2C
    Wire.begin(SDA_PIN, SCL_PIN);

    /*
     * ADS1115 gain = 4.096V
     *
     * This corresponds to ESPHome:
     *
     * gain: 4.096
     *
     * DFRobot library:
     * eGAIN_ONE = 4.096V
     */

    // ADS1115-1
    ads1.setAddr_ADS1115(ADS1115_1_ADDR);
    ads1.setGain(eGAIN_ONE);
    ads1.setMode(eMODE_SINGLE);
    ads1.setRate(eRATE_128);
    ads1.setOSMode(eOSMODE_SINGLE);
    ads1.init();

    // ADS1115-2
    ads2.setAddr_ADS1115(ADS1115_2_ADDR);
    ads2.setGain(eGAIN_ONE);
    ads2.setMode(eMODE_SINGLE);
    ads2.setRate(eRATE_128);
    ads2.setOSMode(eOSMODE_SINGLE);
    ads2.init();

    // ADS1115-3
    ads3.setAddr_ADS1115(ADS1115_3_ADDR);
    ads3.setGain(eGAIN_ONE);
    ads3.setMode(eMODE_SINGLE);
    ads3.setRate(eRATE_128);
    ads3.setOSMode(eOSMODE_SINGLE);
    ads3.init();

    // ADS1115-4
    ads4.setAddr_ADS1115(ADS1115_4_ADDR);
    ads4.setGain(eGAIN_ONE);
    ads4.setMode(eMODE_SINGLE);
    ads4.setRate(eRATE_128);
    ads4.setOSMode(eOSMODE_SINGLE);
    ads4.init();

    Serial.println();
    Serial.println("FeedCurrent 16-Channel Analog Input Test");
    Serial.println("--------------------------------------");
    Serial.println("ADS1115 Gain: 4.096V");
    Serial.println("Multiplier: 5.16696");
    Serial.println("Print threshold: 0.50V");
    Serial.println();
}


void loop(void)
{
    // ADS1115-1: CH1 ~ CH4
    if (ads1.checkADS1115())
    {
        checkChannel(ads1, 0, 1);
        checkChannel(ads1, 1, 2);
        checkChannel(ads1, 2, 3);
        checkChannel(ads1, 3, 4);
    }
    else
    {
        Serial.println("ADS1115-1 (0x48) Disconnected!");
    }


    // ADS1115-2: CH5 ~ CH8
    if (ads2.checkADS1115())
    {
        checkChannel(ads2, 0, 5);
        checkChannel(ads2, 1, 6);
        checkChannel(ads2, 2, 7);
        checkChannel(ads2, 3, 8);
    }
    else
    {
        Serial.println("ADS1115-2 (0x49) Disconnected!");
    }


    // ADS1115-3: CH9 ~ CH12
    if (ads3.checkADS1115())
    {
        checkChannel(ads3, 0, 9);
        checkChannel(ads3, 1, 10);
        checkChannel(ads3, 2, 11);
        checkChannel(ads3, 3, 12);
    }
    else
    {
        Serial.println("ADS1115-3 (0x4B) Disconnected!");
    }


    // ADS1115-4: CH13 ~ CH16
    if (ads4.checkADS1115())
    {
        checkChannel(ads4, 0, 13);
        checkChannel(ads4, 1, 14);
        checkChannel(ads4, 2, 15);
        checkChannel(ads4, 3, 16);
    }
    else
    {
        Serial.println("ADS1115-4 (0x4A) Disconnected!");
    }


    // Scan every 1 second
    delay(1000);
}