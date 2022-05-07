#include <Servo.h>
#include <IRremote.hpp>

Servo servo1; 
int IRpin = 12;
int motor_angle=0;
IRrecv rec(IRpin);
decode_results results;


void setup() {
  Serial.begin(9600);


  rec.enableIRIn();   

  servo1.attach(5); 

  servo1.write(motor_angle); // move the motor to 0 deg

  Serial.println("Servo motor angle 0 deg");

  delay(2000);    
}

void loop() {
  bool flag =true;
do{
  if (rec.decode(&results)) 
     {
      rotate(1);// move the motor to 0 deg
        }
      else 
        {
         rotate(0); // move the motor to 180 deg
        } 
  }
 while(flag);
}
       
         
    


void rotate(int i){
  if(i==1){
   Serial.println("servo motor angle 180 deg");
    motor_angle = 180;
    servo1.write(motor_angle);
  }
  else{
     Serial.println("servo motor angle 0 deg");
    motor_angle =-180 ;
    servo1.write(motor_angle);
  }
}
