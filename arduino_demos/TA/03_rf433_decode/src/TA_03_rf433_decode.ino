/*
  Simple example for receiving RF 433MHz signals

  https://github.com/sui77/rc-switch/

  Made by KinCony IoT: https://www.kincony.com
  RF433 DATA pin: GPIO12
*/

#include <RCSwitch.h>

RCSwitch mySwitch = RCSwitch();

void setup() {
  Serial.begin(9600);
  mySwitch.enableReceive(digitalPinToInterrupt(12));  // GPIO12 for RF433 DATA
  Serial.println("RF433MHz receiver started. Waiting for signal...");
  Serial.print("begin test");
}

void loop() {
  if (mySwitch.available()) {

    Serial.print("Received ");
    Serial.print( mySwitch.getReceivedValue() );
    Serial.print(" / ");
    Serial.print( mySwitch.getReceivedBitlength() );
    Serial.print("bit ");
    Serial.print("Protocol: ");
    Serial.println( mySwitch.getReceivedProtocol() );

    mySwitch.resetAvailable();
  }
}
