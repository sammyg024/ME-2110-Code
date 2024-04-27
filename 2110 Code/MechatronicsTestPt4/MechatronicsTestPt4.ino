#include <myDuino.h>

myDuino robot(1);

//Connect Ultrasonic Sensor pins1&2 to DI2; pin3 to DI3a and pin4 to IR pin1

int dist = 0;
bool switch1 = 0;
int ms = 0;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

dist = robot.readUltrasonic();
Serial.println(String(dist));
switch1 = robot.readButton(1);
Serial.println(String(switch1));

if (switch1 == 1) {
  Serial.println(String(dist));
  if (dist >= 6 && dist <= 10) { 
    robot.moveMotor(1,1,255);
    dist = robot.readUltrasonic();
  }
  else if (dist < 6 || dist > 10){
    robot.moveMotor(1,1,0);
    dist = robot.readUltrasonic();
  }
  switch1 = robot.readButton(1);
}
/*
else if (switch1 == 0) {
  robot.moveMotor(1,1,0);
  Serial.println(String(switch1));
}
*/
}

