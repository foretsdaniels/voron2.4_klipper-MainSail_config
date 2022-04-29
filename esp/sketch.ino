#include "Button2.h"
// We assigned a name LED pin to pin number 22
const int relay1 = 27;
const int relay2 = 14;
// this will assign the name PushButton to pin numer 15
const int trig0 = 22;
const int trig1 = 23;
// This Setup function is used to initialize everything
void setup()
{
  // This statement will declare pin 22 as digital output
  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);
  // This statement will declare pin 15 as digital input
  pinMode(trig0, INPUT_PULLUP); // MIGHT NEED TO CHAGE TO "(TRIGx,INPUT)"
  pinMode(trig1, INPUT_PULLUP); // MIGHT NEED TO CHAGE TO "(TRIGx,INPUT)"
  Serial.begin(9600);
  Serial.println("void setup boot loop Done.");
}
void loop()
{
  // digitalRead function stores the Push button state
  // in variable push_button_state
  int Push_button_state = digitalRead(trig0);
  // if condition checks if push button is pressed
  // if pressed LED will turn on otherwise remain off
  digitalWrite(relay1, HIGH);
  if ( Push_button_state == HIGH )
  {
    digitalWrite(relay1, LOW);
  }
  else
  {
    digitalWrite(relay1, HIGH);
    Serial.println("RELAY HAS CHANGEd");
  }
  // digitalRead function stores the Push button state
  // in variable push_button_state
  int Push_button_state2 = digitalRead(trig1);
  // if condition checks if push button is pressed
  // if pressed LED will turn on otherwise remain off
  digitalWrite(relay2, HIGH);
  if ( Push_button_state2 == HIGH )
  {
    digitalWrite(relay2, LOW);
  }
  else
  {
    digitalWrite(relay2, HIGH);
  }
}