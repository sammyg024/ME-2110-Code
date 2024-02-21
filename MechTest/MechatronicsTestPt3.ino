#include <myDuino.h>

myDuino robot(1);

int IRdist = 0;
bool switch1 = 0;
int dist = 0;
int x = 1;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

IRdist = robot.readIR();
switch1 = robot.readButton(1);
Serial.println(String(switch1));
dist = (IRdist/x);
Serial.println(String(dist));

if (switch1 == 1) {
  Serial.println(String(dist));
  if (dist >= 6 && dist <= 10) { 
    robot.moveMotor(1,1,255);
    IRdist = robot.readIR();
    dist = (IRdist/x);
  }
  else if (dist < 6 || dist > 10){
    robot.moveMotor(1,1,0);
    IRdist = robot.readIR();
    dist = (IRdist/x);
}

else if (switch1 == 0) {
  robot.moveMotor(1,1,0);
}
}
}
