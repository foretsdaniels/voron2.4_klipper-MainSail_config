##line 9 "c:\\Users\\Forest\\Voron_config\\voron2.4_klipper-MainSail_config\\sketch.ino"
void setup();
#line 0 "c:\\Users\\Forest\\Voron_config\\voron2.4_klipper-MainSail_config\\sketch.ino"
line 1 "c:\\Users\\Forest\\Voron_config\\voron2.4_klipper-MainSail_config\\Button2.h"
/////////////////////////////////////////////////////////////////
/*
  Button2.h - Arduino Library to simplify working with buttons.
  Created by Lennart Hennigs.
*/
/////////////////////////////////////////////////////////////////
#pragma once

#ifndef Button2_h
#define Button2_h
/////////////////////////////////////////////////////////////////
#if defined(ARDUINO_ARCH_ESP32) || defined(ESP8266)
  #include <functional>
#endif
#include "Arduino.h"
/////////////////////////////////////////////////////////////////

#define DEBOUNCE_MS 50
#define LONGCLICK_MS 200
#define DOUBLECLICK_MS 300
#define CAPACITIVE_TOUCH_THRESHOLD 35

#define UNDEFINED_PIN 255
#define VIRTUAL_PIN 254

/////////////////////////////////////////////////////////////////

enum clickType {
  single_click, 
  double_click, 
  triple_click, 
  long_click,
  empty
};

class Button2 {

protected:
  int id;
  byte pin;
  byte state;
  byte prev_state;
  byte click_count = 0;
  clickType last_click_type = empty;
  bool was_pressed = false;
  bool is_capacitive = false;
  unsigned long click_ms;
  unsigned long down_ms;

  bool longclick_detected_retriggerable;
  uint16_t longclick_detected_counter = 0;
  bool longclick_detected = false;
  bool longclick_detected_reported = false;
  
  unsigned int debounce_time_ms;
  unsigned int longclick_time_ms;
  unsigned int doubleclick_time_ms;
  
  unsigned int down_time_ms = 0;
  bool pressed_triggered = false;

#if defined(ARDUINO_ARCH_ESP32) || defined(ESP8266)
  typedef std::function<void(Button2 &btn)> CallbackFunction;
  typedef std::function<byte()> StateCallbackFunction;
#else
  typedef void (*CallbackFunction)(Button2 &);
  typedef byte (*StateCallbackFunction)();
#endif

  StateCallbackFunction get_state_cb = NULL;

  CallbackFunction pressed_cb = NULL;
  CallbackFunction released_cb = NULL;
  CallbackFunction change_cb = NULL;
  CallbackFunction tap_cb = NULL;
  CallbackFunction click_cb = NULL;
  CallbackFunction long_cb = NULL;
  CallbackFunction double_cb = NULL;
  CallbackFunction triple_cb = NULL;
  CallbackFunction longclick_detected_cb = NULL;

public:
  Button2();
  Button2(byte attachTo, byte buttonMode = INPUT_PULLUP, boolean isCapacitive = false, boolean activeLow = true);

  void begin(byte attachTo, byte buttonMode = INPUT_PULLUP, boolean isCapacitive = false , boolean activeLow  = true);

  void setDebounceTime(unsigned int ms);
  void setLongClickTime(unsigned int ms);
  void setDoubleClickTime(unsigned int ms);
  
  unsigned int getDebounceTime() const;
  unsigned int getLongClickTime() const;
  unsigned int getDoubleClickTime() const;
  byte getPin() const;

  void reset();

  void setButtonStateFunction(StateCallbackFunction f);

  void setChangedHandler(CallbackFunction f);
  void setPressedHandler(CallbackFunction f);
  void setReleasedHandler(CallbackFunction f);

  void setTapHandler(CallbackFunction f);
  void setClickHandler(CallbackFunction f);
  void setDoubleClickHandler(CallbackFunction f);
  void setTripleClickHandler(CallbackFunction f);

  void setLongClickHandler(CallbackFunction f);
  void setLongClickDetectedHandler(CallbackFunction f);
  void setLongClickDetectedRetriggerable(bool retriggerable);

  unsigned int wasPressedFor() const;
  boolean isPressed() const;
  boolean isPressedRaw();

  bool wasPressed() const;
  clickType read(bool keepState = false);
  clickType wait(bool keepState = false);
  void waitForClick(bool keepState = false);
  void waitForDouble(bool keepState = false);
  void waitForTriple(bool keepState = false);
  void waitForLong(bool keepState = false);

  byte getNumberOfClicks() const;
  clickType getType() const;
  String clickToString(clickType type) const;

  int getID() const;
  void setID(int newID);

  bool operator == (Button2 &rhs);

  void loop();

private: 
  static int _nextID;
  
  byte _pressedState;
  byte _getState();
};
/////////////////////////////////////////////////////////////////
#endif
/////////////////////////////////////////////////////////////////
#line 1 "c:\\Users\\Forest\\Voron_config\\voron2.4_klipper-MainSail_config\\sketch.ino"
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
