#include <Stepper.h>
#include<Servo.h>
Servo Myservo;
int MotorRevolution = 200; // DO NOT CHANGE
int MotorSpeed=400; // FEE: FREE TO CHANGE 

Stepper stepper1(MotorRevolution,2,3); // X Stepper 
Stepper stepper2(MotorRevolution,7,8); // Y Stepper

int Xpin=A0;
int Ypin=A1;
int Joy_switch = 13;
int Xvalue;
int Yvalue;


void setup() {
  Serial.begin(9600);
  stepper1.setSpeed(MotorSpeed);
  stepper2.setSpeed(MotorSpeed);
  
  pinMode(Xpin,INPUT);
  pinMode(Ypin,INPUT);
  pinMode(Joy_switch, INPUT_PULLUP);
  Myservo.attach(10);
}

void loop() {
 if (!digitalRead(Joy_switch)) {  //  If Joystick switch is clicked
    Myservo.write(180);
  }
  else {
    Myservo.write(0);
  }
  Xvalue=analogRead(Xpin);
  Yvalue=analogRead(Ypin);

Serial.println("Xvalue:"+(String)Xvalue+" Yvalue: "+(String)Yvalue);

if(Xvalue>800){stepper1.step(MotorRevolution);}
if(Xvalue<100){stepper1.step(-MotorRevolution);}
if(Yvalue>800){stepper2.step(MotorRevolution);}
if(Yvalue<100){stepper2.step(-MotorRevolution);}
}
