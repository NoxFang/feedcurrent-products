/*
   Made by FeedCurrent IoT
   https://www.feedcurrent.com

   Demo: FeedCurrent B2 DI Control Relay
   Board: FeedCurrent B2 (ESP32)

   Digital Input 1 -> GPIO6
   Digital Input 2 -> GPIO7

   Relay 1 -> GPIO4
   Relay 2 -> GPIO46
*/

// Digital Inputs
#define DI1_PIN 6
#define DI2_PIN 7

// Relay Outputs
#define RELAY1_PIN 4
#define RELAY2_PIN 46

// Relay logic (Active LOW)
#define RELAY_ON  LOW
#define RELAY_OFF HIGH

// Store previous DI states
int lastDI1State;
int lastDI2State;

void setup()
{
  // Configure digital inputs
  pinMode(DI1_PIN, INPUT);
  pinMode(DI2_PIN, INPUT);

  // Configure relay outputs
  pinMode(RELAY1_PIN, OUTPUT);
  pinMode(RELAY2_PIN, OUTPUT);

  // Turn OFF relays at startup
  digitalWrite(RELAY1_PIN, RELAY_OFF);
  digitalWrite(RELAY2_PIN, RELAY_OFF);

  // Read initial input states
  lastDI1State = digitalRead(DI1_PIN);
  lastDI2State = digitalRead(DI2_PIN);

}

void loop()
{
  // Read current DI states
  int di1State = digitalRead(DI1_PIN);
  int di2State = digitalRead(DI2_PIN);

  // DI1 changed
  if (di1State != lastDI1State)
  {
    lastDI1State = di1State;

    if (di1State == HIGH)
    {
      digitalWrite(RELAY1_PIN, RELAY_ON);
    }
    else
    {
      digitalWrite(RELAY1_PIN, RELAY_OFF);
    }
  }

  // DI2 changed
  if (di2State != lastDI2State)
  {
    lastDI2State = di2State;

    if (di2State == HIGH)
    {
      digitalWrite(RELAY2_PIN, RELAY_ON);
    }
    else
    {
      digitalWrite(RELAY2_PIN, RELAY_OFF);
    }
  }

  // Small delay for stability
  delay(10);
}