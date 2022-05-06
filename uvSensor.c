#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int UVOUT = A0; 
int REF_3V3 = A1; 
 
void setup()
{
  Serial.begin(9600);
  lcd.begin(16, 2);
 
  pinMode(UVOUT, INPUT);
  pinMode(REF_3V3, INPUT);
 
  Serial.println("ML8511 example");
  
}
 
void loop()
{
  int uvLvl = averageAnalogRead(UVOUT);
  int refLvl = averageAnalogRead(REF_3V3);
  
 
  float outputVoltage = 3.3 / refLvl * uvLvl;
  
  float uvIntensity = mapfloat(outputVoltage, 0.99, 2.8, 0.0, 15.0); 
  Serial.print("output: ");
  Serial.print(refLvl);
 
  Serial.print("ML8511 output: ");
  Serial.print(uvLvl);
 
  Serial.print(" / ML8511 voltage: ");
  Serial.print(outputVoltage);
 
  Serial.print(" / UV Intensity (mW/cm^2): ");
  Serial.print(uvIntensity);
  lcd.clear();
  lcd.print("UV Ray Intensity");
  lcd.setCursor(0, 1);
  lcd.print(uvIntensity);
  lcd.print(" mW/cm^2");
  Serial.println();
  
  delay(200);
}
 

int averageAnalogRead(int pinToRead)
{
  byte numberOfReadings = 8;
  unsigned int runningValue = 0; 
 
  for(int x = 0 ; x < numberOfReadings ; x++)
    runningValue += analogRead(pinToRead);
  runningValue /= numberOfReadings;
 
  return(runningValue);
}
 
float mapfloat(float x, float in_min, float in_max, float out_min, float out_max)
{
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}
