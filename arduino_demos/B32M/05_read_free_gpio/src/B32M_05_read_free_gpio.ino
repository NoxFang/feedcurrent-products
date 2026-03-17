/*
 * Made by FeedCurrent IoT: https://www.feedcurrent.com
 *
 * Description:
 * This Arduino program monitors the state of free GPIO pins on the B32M board
 * and prints any change to the Serial Monitor.
 *
 * Pin Definitions:
 * - GPIO with pull-up: 48, 47, 40, 7
 * - GPIO without pull-up: 13, 14, 21, 0
 */

#include "Arduino.h"

// Define free GPIO pins
const int gpioWithPullup[] = {48, 47, 40, 7};
const int gpioWithoutPullup[] = {13, 14, 21, 0};
const int numGpioWithPullup = sizeof(gpioWithPullup) / sizeof(gpioWithPullup[0]);
const int numGpioWithoutPullup = sizeof(gpioWithoutPullup) / sizeof(gpioWithoutPullup[0]);

// Store previous states
int prevStateWithPullup[4];
int prevStateWithoutPullup[4];

void setup() {
    Serial.begin(115200);
    delay(1000);
    
    Serial.println("B32M - Free GPIO State Monitor");
    Serial.println("Monitoring GPIO pins...\n");
    
    // Initialize GPIOs with pull-up
    Serial.println("GPIOs with pull-up (suitable for 1-Wire):");
    for (int i = 0; i < numGpioWithPullup; i++) {
        pinMode(gpioWithPullup[i], INPUT_PULLUP);
        prevStateWithPullup[i] = digitalRead(gpioWithPullup[i]);
        Serial.print("  GPIO ");
        Serial.print(gpioWithPullup[i]);
        Serial.println(" (INPUT_PULLUP)");
    }
    
    // Initialize GPIOs without pull-up
    Serial.println("\nGPIOs without pull-up:");
    for (int i = 0; i < numGpioWithoutPullup; i++) {
        pinMode(gpioWithoutPullup[i], INPUT);
        prevStateWithoutPullup[i] = digitalRead(gpioWithoutPullup[i]);
        Serial.print("  GPIO ");
        Serial.print(gpioWithoutPullup[i]);
        Serial.println(" (INPUT)");
    }
    
    Serial.println("\nMonitoring started. Connect pins to GND to see changes.");
    Serial.println("Note: GPIO0 should not be pulled LOW during boot!\n");
}

void loop() {
    // Check GPIOs with pull-up
    for (int i = 0; i < numGpioWithPullup; i++) {
        int currentState = digitalRead(gpioWithPullup[i]);
        if (currentState != prevStateWithPullup[i]) {
            prevStateWithPullup[i] = currentState;
            Serial.print("GPIO ");
            Serial.print(gpioWithPullup[i]);
            Serial.print(" changed to ");
            Serial.println(currentState == HIGH ? "HIGH" : "LOW");
        }
    }
    
    // Check GPIOs without pull-up
    for (int i = 0; i < numGpioWithoutPullup; i++) {
        int currentState = digitalRead(gpioWithoutPullup[i]);
        if (currentState != prevStateWithoutPullup[i]) {
            prevStateWithoutPullup[i] = currentState;
            Serial.print("GPIO ");
            Serial.print(gpioWithoutPullup[i]);
            Serial.print(" changed to ");
            Serial.println(currentState == HIGH ? "HIGH" : "LOW");
        }
    }
    
    delay(50);  // Small delay for debounce
}
