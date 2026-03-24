/**
* @brief Example to read multiple digital inputs using ESP32
* @details This program reads the states of GPIO48, GPIO47, GPIO21, GPIO15, GPIO14, and GPIO40
*          and prints the results to the Serial Monitor.
*
* Made by FeedCurrent IoT: https://www.feedcurrent.com
*/

// Define the GPIO pins for digital inputs
#define INPUT1_PIN 48  // GPIO48
#define INPUT2_PIN 47  // GPIO47
#define INPUT3_PIN 21  // GPIO21
#define INPUT4_PIN 15  // GPIO15
#define INPUT5_PIN 14  // GPIO14
#define INPUT6_PIN 40  // GPIO40
#define INPUT7_PIN 0  // GPIO0

void setup() {
    // Initialize the serial communication for debugging
    Serial.begin(115200);
    Serial.println("ESP32 Digital Input Read Example");

    // Set the input pins as INPUT
    pinMode(INPUT1_PIN, INPUT);
    pinMode(INPUT2_PIN, INPUT);
    pinMode(INPUT3_PIN, INPUT);
    pinMode(INPUT4_PIN, INPUT);
    pinMode(INPUT5_PIN, INPUT);
    pinMode(INPUT6_PIN, INPUT);
    pinMode(INPUT7_PIN, INPUT);
}

void loop() {
    // Read the state of the digital inputs
    int state1 = digitalRead(INPUT1_PIN);
    int state2 = digitalRead(INPUT2_PIN);
    int state3 = digitalRead(INPUT3_PIN);
    int state4 = digitalRead(INPUT4_PIN);
    int state5 = digitalRead(INPUT5_PIN);
    int state6 = digitalRead(INPUT6_PIN);
    int state7 = digitalRead(INPUT7_PIN);

    // Print the states to the Serial Monitor
    Serial.print("GPIO48 State: ");
    Serial.println(state1);
    Serial.print("GPIO47 State: ");
    Serial.println(state2);
    Serial.print("GPIO21 State: ");
    Serial.println(state3);
    Serial.print("GPIO15 State: ");
    Serial.println(state4);
    Serial.print("GPIO14 State: ");
    Serial.println(state5);
    Serial.print("GPIO40 State: ");
    Serial.println(state6);
    Serial.print("GPIO0 State: ");
    Serial.println(state7);
    // Wait for 500 milliseconds before reading again
    delay(500);
}