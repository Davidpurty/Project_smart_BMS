#include "BatteryBalancer.h"

// Constructor
BatteryBalancer::BatteryBalancer(int cells) {
  numCells = cells;
  cellVoltages = new float[numCells];
  avgVoltage = 0.0;
  minVoltage = 0.0;
  minCellIndex = -1;
}

// Destructor
BatteryBalancer::~BatteryBalancer() {
  delete[] cellVoltages;
}

void BatteryBalancer::begin() {
  Serial.begin(9600);
  Serial.println("Battery Balancer Initialized");
}

// Simulate reading voltages (replace with ADC read later)
void BatteryBalancer::readCellVoltages() {
  for (int i = 0; i < numCells; i++) {
    cellVoltages[i] = 3.5 + (float)random(-50, 50) / 100.0;  // Dummy values between 3.0–4.0V
  }
}

float BatteryBalancer::calculateAverage() {
  float sum = 0;
  for (int i = 0; i < numCells; i++) {
    sum += cellVoltages[i];
  }
  avgVoltage = sum / numCells;
  return avgVoltage;
}

void BatteryBalancer::findLowestCell() {
  minVoltage = cellVoltages[0];
  minCellIndex = 0;
  for (int i = 1; i < numCells; i++) {
    if (cellVoltages[i] < minVoltage) {
      minVoltage = cellVoltages[i];
      minCellIndex = i;
    }
  }
}

void BatteryBalancer::start() {
  Serial.println("Balancing process started...");
  readCellVoltages();
  calculateAverage();
  findLowestCell();
  balanceCells();
}

void BatteryBalancer::sleep() {
  Serial.println("Entering sleep mode...");
  // Insert low power code if using on MCU
}

void BatteryBalancer::displayStatus() {
  Serial.println("---- Battery Status ----");
  for (int i = 0; i < numCells; i++) {
    Serial.print("Cell ");
    Serial.print(i + 1);
    Serial.print(": ");
    Serial.print(cellVoltages[i], 3);
    Serial.println(" V");
  }
  Serial.print("Average Voltage: ");
  Serial.println(avgVoltage, 3);
  Serial.print("Lowest Cell: ");
  Serial.print(minCellIndex + 1);
  Serial.print(" (");
  Serial.print(minVoltage, 3);
  Serial.println(" V)");
  Serial.println("------------------------");
}

void BatteryBalancer::balanceCells() {
  Serial.print("Charging cell ");
  Serial.print(minCellIndex + 1);
  Serial.print(" (");
  Serial.print(minVoltage, 3);
  Serial.print(" V) until it reaches ");
  Serial.print(avgVoltage, 3);
  Serial.println(" V...");

  // Simulate charging (replace with real PSU control logic)
  while (cellVoltages[minCellIndex] < avgVoltage) {
    cellVoltages[minCellIndex] += 0.01; // simulate charge step
    delay(100);
  }

  Serial.println("Balancing complete for lowest cell.");
}
