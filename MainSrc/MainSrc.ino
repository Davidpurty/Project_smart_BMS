
#include <Arduino.h>
#include <Wire.h>

#include "BatteryMonitor.h"
#include "Button.h"
#include "Led.h"
#include "LiquidCrystal_PCF8574.h"


BatteryMonitor battery(A0,A1,A2);
Button mainbutton(1);
Led LCD_display(2);

LiquidCrystal_PCF8574 lcd(0x27);  // set the LCD address to 0x27 for a 16 chars and 2 line display
void setup()
{
  Serial.begin(115200);
  
  Wire.begin();
  Wire.beginTransmission(0x27);
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
  Serial.println("Battery voltage is : ");
  Serial.print(battery.getCell1());
  Serial.println("Battery 2 voltage:");
  Serial.println(battery.getCell2());
  Serial.println("Lcd display ");
  


  // For one second we parse GPS data and report some key values
  
}
