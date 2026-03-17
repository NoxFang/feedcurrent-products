/*
 * Made by FeedCurrent IoT: https://www.feedcurrent.com
 *
 * GPIO Status Monitoring
 *
 * This program monitors the status (high or low) of multiple GPIO pins on the ESP32-S3.
 * It prints the status of the pins to the serial monitor whenever a change is detected.
 *
 * GPIO Pins Monitored:
 * - GPIO 13
 * - GPIO 14
 * - GPIO 21
 * - GPIO 40
 * - GPIO 48
 * - GPIO 47
 * - GPIO 7
 *
 * Hardware Requirements:
 * - Connect the pins to appropriate devices or pull them to HIGH/LOW for testing
 */

// Define the GPIO pins to be monitored
#define GPIO_PIN_13 13
#define GPIO_PIN_14 14
#define GPIO_PIN_21 21
#define GPIO_PIN_40 40
#define GPIO_PIN_48 48
#define GPIO_PIN_47 47
#define GPIO_PIN_7   7

// Create an array to hold the GPIO pin numbers
const int monitoredPins[] = {
  GPIO_PIN_13,
  GPIO_PIN_14,
  GPIO_PIN_21,
  GPIO_PIN_40,
  GPIO_PIN_48,
  GPIO_PIN_47,
  GPIO_PIN_7
};

const int pinCount = sizeof(monitoredPins) / sizeof(monitoredPins[0]);

// Store the previous state of the GPIO pins
bool prevState[pinCount] = {false};

void setup() {
  Serial.begin(115200);      // Initialize the serial monitor
  while (!Serial);           // Wait for serial monitor to open

  // Set each monitored pin as input
  for (int i = 0; i < pinCount; i++) {
    pinMode(monitoredPins[i], INPUT);
  }

  Serial.println("GPIO Status Monitoring Started");
}

void loop() {
  for (int i = 0; i < pinCount; i++) {
    bool currentState = digitalRead(monitoredPins[i]);
    if (currentState != prevState[i]) {
      Serial.print("GPIO ");
      Serial.print(monitoredPins[i]);
      Serial.print(" changed to ");
      Serial.println(currentState ? "HIGH" : "LOW");
      prevState[i] = currentState;
    }
  }
  delay(100); // Delay to reduce serial flooding
}
