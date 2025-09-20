#include "PIRSensor.h"
#include <Arduino.h>

PIRSensor::PIRSensor(int pin) : _pin(pin) {}

void PIRSensor::begin() {
    pinMode(_pin, INPUT);
}

bool PIRSensor::isMotionDetected() {
    return digitalRead(_pin) == HIGH;
}

