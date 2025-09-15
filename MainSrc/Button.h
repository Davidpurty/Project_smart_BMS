#ifndef BUTTON_H
#define BUTTON_H

#include <Arduino.h>

class Button {
  int pin;
public:
  Button(int p);
  bool isPressed();
};

#endif
