#ifndef LED_H
#define LED_H

#include <Arduino.h>

class Led {
  int pin;
public:
  Led(int p);
  void on();
  void off();
};

#endif
