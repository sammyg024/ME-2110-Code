#include <myDuino.h>

myDuino robot(1);

unsigned long IRdist = 0;
bool switch1 = 0;
int dist = 0;
int x = -0.011;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

IRdist = robot.readIR();
Serial.println((IRdist));

switch1 = robot.readButton(1);
Serial.println(String(switch1));
dist = ((IRdist-1023)*x);
Serial.println(String(dist));

if (switch1 == 1) {
  Serial.println(String(dist));
  if (dist >= 6 && dist <= 10) { 
    robot.moveMotor(1,1,255);
    IRdist = robot.readIR();
    dist = ((IRdist-1023)*x);
  }
  else if (dist < 6 || dist > 10){
    robot.moveMotor(1,1,0);
    IRdist = robot.readIR();
    dist = ((IRdist-1023)*x);
}

else if (switch1 == 0) {
  robot.moveMotor(1,1,0);
}
}
}
