#include "BatteryMonitor.h"

BatteryMonitor::BatteryMonitor(int c1, int c12, int c123,
                               float r1, float r2,
                               float vref, int adcRes) {
  pinCell1   = c1;
  pinCell12  = c12;
  pinCell123 = c123;
  R1 = r1;
  R2 = r2;
  Vref = vref;
  ADCres = adcRes;
}

float BatteryMonitor::readVoltage(int pin) {
  int raw = analogRead(pin);
  float vOut = (raw * Vref) / ADCres;
  float vIn = vOut * (R1 + R2) / R2;   // scale back up
  return vIn;
}

float BatteryMonitor::getCell1() {
  return readVoltage(pinCell1);
}

float BatteryMonitor::getCell2() {
  return readVoltage(pinCell12) - readVoltage(pinCell1);
}

float BatteryMonitor::getCell3() {
  return readVoltage(pinCell123) - readVoltage(pinCell12);
}

float BatteryMonitor::getTotal() {
  return readVoltage(pinCell123);
}
