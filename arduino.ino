
#include<IRremote.h>
#include<Servo.h>
int IRSensor = 5; // connect ir sensor to arduino pin 2
Servo servo9; 
int pos = 0;
void setup() 
{


Serial.begin(9600);
  pinMode (IRSensor, INPUT); // sensor pin INPUT
  pinMode(9,OUTPUT);
  servo9.attach(9);
}

void loop()
{
  int statusSensor = digitalRead (IRSensor);
  
  if ( statusSensor == true){
  for (pos = 0; pos <= 180; pos += 1) {
    // tell servo to go to position in variable 'pos'
    servo9.write(pos);
    // wait 15 ms for servo to reach the position
    delay(15);
   // LED LOW
 
  for (pos = 180; pos >= 0; pos -= 1) {
    // tell servo to go to position in variable 'pos'
    servo9.write(pos);
    // wait 15 ms for servo to reach the position
    delay(15);// LED High
  }
  
}}
}
