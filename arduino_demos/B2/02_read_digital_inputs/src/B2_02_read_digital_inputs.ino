/*
   Made by FeedCurrent IoT
   https://www.feedcurrent.com

   Demo: FeedCurrent B2 Digital Input Read
   Board: FeedCurrent B2 (ESP32)

   Digital Input 1 -> GPIO6
   Digital Input 2 -> GPIO7
*/

#define DI1_PIN 6
#define DI2_PIN 7

// Store previous input states
int lastDI1State = HIGH;
int lastDI2State = HIGH;

void setup()
{
  // Initialize serial monitor
  Serial.begin(115200);
  Serial.println("FeedCurrent B2 Digital Input Demo");

  // Configure digital input pins
  // Change INPUT to INPUT_PULLUP if your hardware requires internal pull-up
  pinMode(DI1_PIN, INPUT_PULLUP);
  pinMode(DI2_PIN, INPUT_PULLUP);

  // Read initial states
  lastDI1State = digitalRead(DI1_PIN);
  lastDI2State = digitalRead(DI2_PIN);

  Serial.print("DI1 Initial State: ");
  Serial.println(lastDI1State);

  Serial.print("DI2 Initial State: ");
  Serial.println(lastDI2State);
}

void loop()
{
  // Read current input states
  int di1State = digitalRead(DI1_PIN);
  int di2State = digitalRead(DI2_PIN);

  // Check if DI1 state changed
  if (di1State != lastDI1State)
  {
    lastDI1State = di1State;

    Serial.print("DI1 Changed: ");
    Serial.println(di1State);
  }

  // Check if DI2 state changed
  if (di2State != lastDI2State)
  {
    lastDI2State = di2State;

    Serial.print("DI2 Changed: ");
    Serial.println(di2State);
  }

  // Small delay for stability
  delay(10);
}