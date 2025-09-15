

#include "BatteryMonitor.h"

BatteryMonitor battery;
void setup()
{
  Serial.begin(115200);
  
  
  Serial.print("Simple TinyGPS library v. "); 
  Serial.println("by Mikal Hart");
  Serial.println();
}

void loop()
{
  bool newData = false;
  unsigned long chars;
  unsigned short sentences, failed;
  Serial.println("test done");
  Serial.println("Battery voltage is : "+ battery.getCell1());

  // For one second we parse GPS data and report some key values
  
}