/*
* Made by FeedCurrent IoT: https://www.feedcurrent.com
*
* Description:
* This Arduino program reads analog values from four analog input pins (A1, A2, A3, A4)
* and prints the values to the Serial Monitor. The analog inputs are defined with specific
* GPIO pins and the program reads the voltage levels from these pins every 2 seconds.
*
* Pin Definitions:
* - A1: GPIO 7
* - A2: GPIO 6
* - A3: GPIO 5
* - A4: GPIO 4
*/

#define ANALOG_A1   7   // Define GPIO pin for analog input A1
#define ANALOG_A2   6   // Define GPIO pin for analog input A2
#define ANALOG_A3   5   // Define GPIO pin for analog input A3
#define ANALOG_A4   4   // Define GPIO pin for analog input A4

void setup()
{
    Serial.begin(115200); // Initialize serial communication at 115200 baud rate
    delay(500); // Short delay to allow serial communication to start

    pinMode(ANALOG_A1, INPUT); // Set GPIO 5 as an input for analog signal A1
    pinMode(ANALOG_A2, INPUT); // Set GPIO 7 as an input for analog signal A2
    pinMode(ANALOG_A3, INPUT); // Set GPIO 6 as an input for analog signal A3
    pinMode(ANALOG_A4, INPUT); // Set GPIO 4 as an input for analog signal A4
}

void loop()
{
    // Read and print analog values from the defined pins
    Serial.print("A1=");
    Serial.println(analogRead(ANALOG_A1)); // Read and print the value from A1
    Serial.print("A2=");
    Serial.println(analogRead(ANALOG_A2)); // Read and print the value from A2
    Serial.print("A3=");
    Serial.println(analogRead(ANALOG_A3)); // Read and print the value from A3
    Serial.print("A4=");
    Serial.println(analogRead(ANALOG_A4)); // Read and print the value from A4
   
    delay(2000); // Wait for 2 seconds before the next reading
}