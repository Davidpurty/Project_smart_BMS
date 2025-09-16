#ifndef BATTERY_BALANCER_H
#define BATTERY_BALANCER_H

#include <Arduino.h>

class BatteryBalancer {
  private:
    int numCells;
    float *cellVoltages;
    float avgVoltage;
    float minVoltage;
    int minCellIndex;

  public:
    BatteryBalancer(int cells);
    ~BatteryBalancer();

    void begin();
    void readCellVoltages();
    float calculateAverage();
    void findLowestCell();
    void start();
    void sleep();
    void displayStatus();
    void balanceCells();
};

#endif
