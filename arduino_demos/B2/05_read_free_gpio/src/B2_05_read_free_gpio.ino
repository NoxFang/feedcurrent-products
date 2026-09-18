/*
   Made by FeedCurrent IoT
   https://www.feedcurrent.com

   Demo: KinCony B2 GPIO State Monitor
   Board: KinCony B2 (ESP32)

   1-Wire-1 -> GPIO47
   1-Wire-2 -> GPIO48
   1-Wire-3 -> GPIO17
   1-Wire-4 -> GPIO40
*/

#define GPIO1_PIN 47
#define GPIO2_PIN 48
#define GPIO3_PIN 17
#define GPIO4_PIN 40

// Store previous GPIO states
int lastState1;
int lastState2;
int lastState3;
int lastState4;

void setup()
{
  // Initialize serial monitor
  Serial.begin(115200);
  Serial.println("FeedCurrent B2 GPIO State Monitor");

  // Configure GPIOs as inputs
  // Change INPUT to INPUT_PULLUP if required by your hardware
  pinMode(GPIO1_PIN, INPUT);
  pinMode(GPIO2_PIN, INPUT);
  pinMode(GPIO3_PIN, INPUT);
  pinMode(GPIO4_PIN, INPUT);

  // Read initial states
  lastState1 = digitalRead(GPIO1_PIN);
  lastState2 = digitalRead(GPIO2_PIN);
  lastState3 = digitalRead(GPIO3_PIN);
  lastState4 = digitalRead(GPIO4_PIN);

  // Print initial states
  Serial.printf("GPIO47 Initial: %d\n", lastState1);
  Serial.printf("GPIO48 Initial: %d\n", lastState2);
  Serial.printf("GPIO17 Initial: %d\n", lastState3);
  Serial.printf("GPIO40 Initial: %d\n", lastState4);
}

void loop()
{
  int state;

  // Check GPIO47
  state = digitalRead(GPIO1_PIN);
  if (state != lastState1)
  {
    lastState1 = state;
    Serial.printf("GPIO47 Changed: %d\n", state);
  }

  // Check GPIO48
  state = digitalRead(GPIO2_PIN);
  if (state != lastState2)
  {
    lastState2 = state;
    Serial.printf("GPIO48 Changed: %d\n", state);
  }

  // Check GPIO17
  state = digitalRead(GPIO3_PIN);
  if (state != lastState3)
  {
    lastState3 = state;
    Serial.printf("GPIO17 Changed: %d\n", state);
  }

  // Check GPIO40
  state = digitalRead(GPIO4_PIN);
  if (state != lastState4)
  {
    lastState4 = state;
    Serial.printf("GPIO40 Changed: %d\n", state);
  }

  // Small delay for stability
  delay(10);
}