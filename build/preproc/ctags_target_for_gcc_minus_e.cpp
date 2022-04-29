# 1 "c:\\Users\\Forest\\Voron_config\\voron2.4_klipper-MainSail_config\\Button2.h"
/////////////////////////////////////////////////////////////////
/*

  Button2.h - Arduino Library to simplify working with buttons.

  Created by Lennart Hennigs.

*/
# 6 "c:\\Users\\Forest\\Voron_config\\voron2.4_klipper-MainSail_config\\Button2.h"
/////////////////////////////////////////////////////////////////
       



/////////////////////////////////////////////////////////////////

# 14 "c:\\Users\\Forest\\Voron_config\\voron2.4_klipper-MainSail_config\\Button2.h" 2

# 16 "c:\\Users\\Forest\\Voron_config\\voron2.4_klipper-MainSail_config\\Button2.h" 2
/////////////////////////////////////////////////////////////////
# 26 "c:\\Users\\Forest\\Voron_config\\voron2.4_klipper-MainSail_config\\Button2.h"
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


  typedef std::function<void(Button2 &btn)> CallbackFunction;
  typedef std::function<byte()> StateCallbackFunction;





  StateCallbackFunction get_state_cb = 
# 70 "c:\\Users\\Forest\\Voron_config\\voron2.4_klipper-MainSail_config\\Button2.h" 3 4
                                      __null
# 70 "c:\\Users\\Forest\\Voron_config\\voron2.4_klipper-MainSail_config\\Button2.h"
                                          ;

  CallbackFunction pressed_cb = 
# 72 "c:\\Users\\Forest\\Voron_config\\voron2.4_klipper-MainSail_config\\Button2.h" 3 4
                               __null
# 72 "c:\\Users\\Forest\\Voron_config\\voron2.4_klipper-MainSail_config\\Button2.h"
                                   ;
  CallbackFunction released_cb = 
# 73 "c:\\Users\\Forest\\Voron_config\\voron2.4_klipper-MainSail_config\\Button2.h" 3 4
                                __null
# 73 "c:\\Users\\Forest\\Voron_config\\voron2.4_klipper-MainSail_config\\Button2.h"
                                    ;
  CallbackFunction change_cb = 
# 74 "c:\\Users\\Forest\\Voron_config\\voron2.4_klipper-MainSail_config\\Button2.h" 3 4
                              __null
# 74 "c:\\Users\\Forest\\Voron_config\\voron2.4_klipper-MainSail_config\\Button2.h"
                                  ;
  CallbackFunction tap_cb = 
# 75 "c:\\Users\\Forest\\Voron_config\\voron2.4_klipper-MainSail_config\\Button2.h" 3 4
                           __null
# 75 "c:\\Users\\Forest\\Voron_config\\voron2.4_klipper-MainSail_config\\Button2.h"
                               ;
  CallbackFunction click_cb = 
# 76 "c:\\Users\\Forest\\Voron_config\\voron2.4_klipper-MainSail_config\\Button2.h" 3 4
                             __null
# 76 "c:\\Users\\Forest\\Voron_config\\voron2.4_klipper-MainSail_config\\Button2.h"
                                 ;
  CallbackFunction long_cb = 
# 77 "c:\\Users\\Forest\\Voron_config\\voron2.4_klipper-MainSail_config\\Button2.h" 3 4
                            __null
# 77 "c:\\Users\\Forest\\Voron_config\\voron2.4_klipper-MainSail_config\\Button2.h"
                                ;
  CallbackFunction double_cb = 
# 78 "c:\\Users\\Forest\\Voron_config\\voron2.4_klipper-MainSail_config\\Button2.h" 3 4
                              __null
# 78 "c:\\Users\\Forest\\Voron_config\\voron2.4_klipper-MainSail_config\\Button2.h"
                                  ;
  CallbackFunction triple_cb = 
# 79 "c:\\Users\\Forest\\Voron_config\\voron2.4_klipper-MainSail_config\\Button2.h" 3 4
                              __null
# 79 "c:\\Users\\Forest\\Voron_config\\voron2.4_klipper-MainSail_config\\Button2.h"
                                  ;
  CallbackFunction longclick_detected_cb = 
# 80 "c:\\Users\\Forest\\Voron_config\\voron2.4_klipper-MainSail_config\\Button2.h" 3 4
                                          __null
# 80 "c:\\Users\\Forest\\Voron_config\\voron2.4_klipper-MainSail_config\\Button2.h"
                                              ;

public:
  Button2();
  Button2(byte attachTo, byte buttonMode = 0x05, boolean isCapacitive = false, boolean activeLow = true);

  void begin(byte attachTo, byte buttonMode = 0x05, boolean isCapacitive = false , boolean activeLow = true);

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

/////////////////////////////////////////////////////////////////
# 1 "c:\\Users\\Forest\\Voron_config\\voron2.4_klipper-MainSail_config\\sketch.ino"
# 2 "c:\\Users\\Forest\\Voron_config\\voron2.4_klipper-MainSail_config\\sketch.ino" 2
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
  pinMode(relay1, 0x02);
  pinMode(relay2, 0x02);
  // This statement will declare pin 15 as digital input
  pinMode(trig0, 0x05); // MIGHT NEED TO CHAGE TO "(TRIGx,INPUT)"
  pinMode(trig1, 0x05); // MIGHT NEED TO CHAGE TO "(TRIGx,INPUT)"
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
  digitalWrite(relay1, 0x1);
  if ( Push_button_state == 0x1 )
  {
    digitalWrite(relay1, 0x0);
  }
  else
  {
    digitalWrite(relay1, 0x1);
    Serial.println("RELAY HAS CHANGEd");
  }
  // digitalRead function stores the Push button state
  // in variable push_button_state
  int Push_button_state2 = digitalRead(trig1);
  // if condition checks if push button is pressed
  // if pressed LED will turn on otherwise remain off
  digitalWrite(relay2, 0x1);
  if ( Push_button_state2 == 0x1 )
  {
    digitalWrite(relay2, 0x0);
  }
  else
  {
    digitalWrite(relay2, 0x1);
  }
}
