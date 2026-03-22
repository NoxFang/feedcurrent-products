/*
* Made by FeedCurrent IoT: https://www.feedcurrent.com
*
* GPIO Status Monitoring with Change Detection
*
* This program monitors the status (high or low) of multiple GPIO pins on the ESP32-S3.
* It prints the status of the pins to the serial monitor whenever a change is detected.
*
* Additional Functionality:
* - The program now monitors 11 GPIO pins, not just the previously listed ones.
* - GPIO pins include: GPIO 15, 16, 17, 40, 13, 14, 21, 4, 5, 6, 7.
* - For each pin, whenever its state changes (from HIGH to LOW or vice versa), the new state is printed to the serial monitor.
*
* GPIO Pins Monitored:
* - GPIO 15
* - GPIO 16
* - GPIO 17
* - GPIO 40
* - GPIO 13
* - GPIO 14
* - GPIO 21
* - GPIO 4
* - GPIO 5
* - GPIO 6
* - GPIO 7
*
* Hardware Requirements:
* - Connect the pins to appropriate devices or pull them to HIGH/LOW for testing.
* - Ensure that the ESP32-S3 is powered and connected to a serial monitor to observe the output.
*
* How it works:
* - The setup function initializes the serial communication and configures the GPIO pins as inputs.
* - The loop function continuously checks the state of each GPIO pin.
* - If a pin's state changes, the new state is printed to the serial monitor, along with the corresponding pin number.
* - The program uses a delay to prevent excessive serial prints, which can be adjusted as necessary.
*/


#define GPIO_PIN_15 15
#define GPIO_PIN_16 16
#define GPIO_PIN_17 17
#define GPIO_PIN_40 40
#define GPIO_PIN_13 13
#define GPIO_PIN_14 14
#define GPIO_PIN_21 21
#define GPIO_PIN_4 4
#define GPIO_PIN_5 5
#define GPIO_PIN_6 6
#define GPIO_PIN_7 7

// Store the previous state of the GPIO pins
bool prevState[11] = {false, false, false, false, false, false, false, false, false, false, false};

void setup() {
  // Initialize serial communication for debugging purposes
  Serial.begin(115200); // Initialize the serial monitor at 115200 baud
  while (!Serial);      // Wait for the serial monitor to open

  // Initialize GPIO pins as inputs
  pinMode(GPIO_PIN_15, INPUT);
  pinMode(GPIO_PIN_16, INPUT);
  pinMode(GPIO_PIN_17, INPUT);
  pinMode(GPIO_PIN_40, INPUT);
  pinMode(GPIO_PIN_13, INPUT);
  pinMode(GPIO_PIN_14, INPUT);
  pinMode(GPIO_PIN_21, INPUT);
  pinMode(GPIO_PIN_4, INPUT);
  pinMode(GPIO_PIN_5, INPUT);
  pinMode(GPIO_PIN_6, INPUT);
  pinMode(GPIO_PIN_7, INPUT);

  Serial.println("GPIO Status Monitoring Started");
}

void loop() {
  // Read the current state of each GPIO pin
  bool currentState[11];
  currentState[0] = digitalRead(GPIO_PIN_15);
  currentState[1] = digitalRead(GPIO_PIN_16);
  currentState[2] = digitalRead(GPIO_PIN_17);
  currentState[3] = digitalRead(GPIO_PIN_40);
  currentState[4] = digitalRead(GPIO_PIN_13);
  currentState[5] = digitalRead(GPIO_PIN_14);
  currentState[6] = digitalRead(GPIO_PIN_21);
  currentState[7] = digitalRead(GPIO_PIN_4);
  currentState[8] = digitalRead(GPIO_PIN_5);
  currentState[9] = digitalRead(GPIO_PIN_6);
  currentState[10] = digitalRead(GPIO_PIN_7); 

  // Check for changes in GPIO pin states
  for (int i = 0; i < 11; i++) {
    if (currentState[i] != prevState[i]) {
      // Print the pin number and its new state if it has changed
      Serial.print("GPIO ");
      Serial.print(i == 0 ? GPIO_PIN_15 :
                   i == 1 ? GPIO_PIN_16 :
                   i == 2 ? GPIO_PIN_17 :
                   i == 3 ? GPIO_PIN_40 :
                   i == 4 ? GPIO_PIN_13 :
                   i == 5 ? GPIO_PIN_14 :
                   i == 6 ? GPIO_PIN_21 :
                   i == 7 ? GPIO_PIN_4 :
                   i == 8 ? GPIO_PIN_5 :                                                           
                   i == 9 ? GPIO_PIN_6 : GPIO_PIN_7);
      Serial.print(" changed to ");
      Serial.println(currentState[i] ? "HIGH" : "LOW");
      // Update the previous state
      prevState[i] = currentState[i];
    }
  }

  // Delay to avoid flooding the serial monitor
  delay(100); // Adjust the delay as needed
}