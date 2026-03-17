/*
 * Made by FeedCurrent IoT: https://www.feedcurrent.com
 *
 * Description:
 * This Arduino program demonstrates how to read and set the DS3231 RTC
 * on the B32M board via serial commands.
 *
 * Pin Definitions:
 * - SDA: GPIO 8
 * - SCL: GPIO 18
 * - DS3231 I2C Address: 0x68
 */

#include "Arduino.h"
#include "DS3231.h"

// Define I2C pins
#define I2C_SDA 8
#define I2C_SCL 18

// Create DS3231 object
DS3231 rtc;

void setup() {
    Serial.begin(115200);
    delay(1000);
    
    Serial.println("B32M - DS3231 RTC Example");
    Serial.println("Initializing I2C...");
    
    // Initialize I2C communication
    Wire.begin(I2C_SDA, I2C_SCL);
    
    // Initialize RTC
    rtc.begin();
    
    Serial.println("RTC initialized!");
    Serial.println("\nCommands:");
    Serial.println("  'current time' - Display current date/time");
    Serial.println("  'DYYYY-MM-DDTHH:MM:SS' - Set date/time (e.g., D2025-06-23T10:30:00)");
    Serial.println();
}

void loop() {
    // Check for serial commands
    if (Serial.available()) {
        String command = Serial.readStringUntil('\n');
        command.trim();
        
        if (command.equalsIgnoreCase("current time")) {
            printCurrentTime();
        }
        else if (command.startsWith("D")) {
            setDateTime(command);
        }
        else {
            Serial.println("Unknown command. Type 'current time' or use DYYYY-MM-DDTHH:MM:SS format.");
        }
    }
    
    delay(100);
}

void printCurrentTime() {
    DateTime now = rtc.now();
    
    Serial.print("Current time: ");
    Serial.print(now.year(), DEC);
    Serial.print('-');
    if (now.month() < 10) Serial.print('0');
    Serial.print(now.month(), DEC);
    Serial.print('-');
    if (now.day() < 10) Serial.print('0');
    Serial.print(now.day(), DEC);
    Serial.print(' ');
    if (now.hour() < 10) Serial.print('0');
    Serial.print(now.hour(), DEC);
    Serial.print(':');
    if (now.minute() < 10) Serial.print('0');
    Serial.print(now.minute(), DEC);
    Serial.print(':');
    if (now.second() < 10) Serial.print('0');
    Serial.print(now.second(), DEC);
    
    Serial.print(" (");
    switch (now.dayOfTheWeek()) {
        case 0: Serial.print("Sunday"); break;
        case 1: Serial.print("Monday"); break;
        case 2: Serial.print("Tuesday"); break;
        case 3: Serial.print("Wednesday"); break;
        case 4: Serial.print("Thursday"); break;
        case 5: Serial.print("Friday"); break;
        case 6: Serial.print("Saturday"); break;
    }
    Serial.println(")");
    
    // Print temperature
    Serial.print("Temperature: ");
    Serial.print(rtc.getTemperature());
    Serial.println(" C");
}

void setDateTime(String command) {
    // Expected format: DYYYY-MM-DDTHH:MM:SS
    if (command.length() != 20) {
        Serial.println("Invalid format. Use: DYYYY-MM-DDTHH:MM:SS");
        return;
    }
    
    int year = command.substring(1, 5).toInt();
    int month = command.substring(6, 8).toInt();
    int day = command.substring(9, 11).toInt();
    int hour = command.substring(12, 14).toInt();
    int minute = command.substring(15, 17).toInt();
    int second = command.substring(18, 20).toInt();
    
    // Validate values
    if (year < 2000 || year > 2099 || month < 1 || month > 12 || day < 1 || day > 31 ||
        hour < 0 || hour > 23 || minute < 0 || minute > 59 || second < 0 || second > 59) {
        Serial.println("Invalid date/time values.");
        return;
    }
    
    // Set RTC
    rtc.adjust(DateTime(year, month, day, hour, minute, second));
    
    Serial.println("Date and time set successfully!");
    printCurrentTime();
}
