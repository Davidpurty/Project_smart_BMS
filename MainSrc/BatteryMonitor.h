#ifndef BATTERYMONITOR_H
#define BATTERYMONITOR_H

#include <Arduino.h>

class BatteryMonitor {
  private:
    int pinCell1, pinCell12, pinCell123;
    float R1, R2;     // resistor divider values
    float Vref;       // ADC reference voltage
    int ADCres;       // ADC resolution

    float readVoltage(int pin);

  public:
    BatteryMonitor(int c1, int c12, int c123,
                   float r1 = 30000.0, float r2 = 7500.0,
                   float vref = 5.0, int adcRes = 1023);

    float getCell1();
    float getCell2();
    float getCell3();
    float getTotal();
};

#endif
