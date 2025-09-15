#include "Button.h"

Button::Button(int p) : pin(p) {
  pinMode(pin, INPUT_PULLUP);
}

bool Button::isPressed() {
  return digitalRead(pin) == LOW; // active low
}