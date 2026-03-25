/*
  Made by FeedCurrent IoT: https://www.feedcurrent.com

  This program reads the digital state of GPIO15 and GPIO16 on an ESP32
  and prints their state (HIGH or LOW) to the serial monitor every 500ms.
*/

#define PIN_GPIO15 15  // Define GPIO15
#define PIN_GPIO16 16  // Define GPIO16

void setup() {
  Serial.begin(115200);               // Initialize serial communication at 115200 baud
  pinMode(PIN_GPIO15, INPUT);         // Set GPIO15 as input
  pinMode(PIN_GPIO16, INPUT);         // Set GPIO16 as input
  Serial.println("ESP32 GPIO15 and GPIO16 State Monitor");
}

void loop() {
  int state15 = digitalRead(PIN_GPIO15);  // Read state of GPIO15
  int state16 = digitalRead(PIN_GPIO16);  // Read state of GPIO16

  // Print the state to the serial monitor
  Serial.print("GPIO15: ");
  Serial.print(state15 == HIGH ? "HIGH" : "LOW");
  Serial.print("  |  GPIO16: ");
  Serial.println(state16 == HIGH ? "HIGH" : "LOW");

  delay(500);  // Wait for 500 milliseconds before reading again
}