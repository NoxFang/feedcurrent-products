/*
   Made by FeedCurrent IoT
   https://www.feedcurrent.com

   Demo: FeedCurrent B2 Relay Control
*/

#define RELAY1_PIN 4
#define RELAY2_PIN 46

// Relay logic (Active LOW)
#define RELAY_ON  LOW
#define RELAY_OFF HIGH

void setup()
{

  pinMode(RELAY1_PIN, OUTPUT);
  pinMode(RELAY2_PIN, OUTPUT);

  // Turn OFF both relays at startup
  digitalWrite(RELAY1_PIN, RELAY_OFF);
  digitalWrite(RELAY2_PIN, RELAY_OFF);
}

void loop()
{
  digitalWrite(RELAY1_PIN, RELAY_ON);
  delay(1000);

  digitalWrite(RELAY1_PIN, RELAY_OFF);
  delay(1000);

  digitalWrite(RELAY2_PIN, RELAY_ON);
  delay(1000);

  Serial.println("Relay 2 OFF");
  digitalWrite(RELAY2_PIN, RELAY_OFF);
  delay(1000);

  digitalWrite(RELAY1_PIN, RELAY_ON);
  digitalWrite(RELAY2_PIN, RELAY_ON);
  delay(1000);

  digitalWrite(RELAY1_PIN, RELAY_OFF);
  digitalWrite(RELAY2_PIN, RELAY_OFF);
  delay(1000);
}