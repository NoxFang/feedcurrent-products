/*
* Made by FeedCurrent IoT: https://www.feedcurrent.com
*
* GPIO Status Monitoring
*
* This program monitors the status (high or low) of multiple GPIO pins on the ESP32-S3.
* It prints the status of the pins to the serial monitor whenever a change is detected.
*
* GPIO Pins Monitored:
* - GPIO 8
* - GPIO 9
* - GPIO 10
* - GPIO 15
* - GPIO 16
* - GPIO 17
* - GPIO 18
* - GPIO 0
*
* Hardware Requirements:
* - Connect the pins to appropriate devices or pull them to HIGH/LOW for testing
*/

#define GPIO_PIN_8 8
#define GPIO_PIN_9 9
#define GPIO_PIN_10 10
#define GPIO_PIN_15 15
#define GPIO_PIN_16 16
#define GPIO_PIN_17 17
#define GPIO_PIN_18 18
#define GPIO_PIN_0 0

// Store the previous state of the GPIO pins
bool prevState[8] = {false, false, false, false, false, false, false, false};

void setup() {
  // Initialize serial communication for debugging purposes
  Serial.begin(115200); // Initialize the serial monitor at 115200 baud
  while (!Serial);      // Wait for the serial monitor to open

  // Initialize GPIO pins as inputs
  pinMode(GPIO_PIN_8, INPUT);
  pinMode(GPIO_PIN_9, INPUT);
  pinMode(GPIO_PIN_10, INPUT);
  pinMode(GPIO_PIN_15, INPUT);
  pinMode(GPIO_PIN_16, INPUT);
  pinMode(GPIO_PIN_17, INPUT);
  pinMode(GPIO_PIN_18, INPUT);
  pinMode(GPIO_PIN_0, INPUT);

  Serial.println("GPIO Status Monitoring Started");
}

void loop() {
  // Read the current state of each GPIO pin
  bool currentState[8];
  currentState[0] = digitalRead(GPIO_PIN_8);
  currentState[1] = digitalRead(GPIO_PIN_9);
  currentState[2] = digitalRead(GPIO_PIN_10);
  currentState[3] = digitalRead(GPIO_PIN_15);
  currentState[4] = digitalRead(GPIO_PIN_16);
  currentState[5] = digitalRead(GPIO_PIN_17);
  currentState[6] = digitalRead(GPIO_PIN_18);
  currentState[7] = digitalRead(GPIO_PIN_0);

  // Check for changes in GPIO pin states
  for (int i = 0; i < 8; i++) {
    if (currentState[i] != prevState[i]) {
      // Print the pin number and its new state if it has changed
      Serial.print("GPIO ");
      Serial.print(i == 0 ? GPIO_PIN_8 :
                   i == 1 ? GPIO_PIN_9 :
                   i == 2 ? GPIO_PIN_10 :
                   i == 3 ? GPIO_PIN_15 :
                   i == 4 ? GPIO_PIN_16 :
                   i == 5 ? GPIO_PIN_17 :
                   i == 6 ? GPIO_PIN_18 : GPIO_PIN_0);
      Serial.print(" changed to ");
      Serial.println(currentState[i] ? "HIGH" : "LOW");
      // Update the previous state
      prevState[i] = currentState[i];
    }
  }

  // Delay to avoid flooding the serial monitor
  delay(100); // Adjust the delay as needed
}