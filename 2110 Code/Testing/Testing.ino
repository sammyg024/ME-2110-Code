#include <myDuino.h>

myDuino robot(1);

bool but1 = robot.readButton(1);
bool but2 = robot.readButton(2);

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
robot.digital(1,0);
robot.digital(2,0);
}

void loop() {
  // put your main code here, to run repeatedly:

if (but1 == 1 && but2 == 0) {
  robot.digital(1,1);
  robot.digital(2,0);
  but1 = robot.readButton(1);
  but2 = robot.readButton(2);
  Serial.println(String(but1) + String(but2));
}
else if(but2 == 1 && but1 == 0){
  robot.digital(2,1);
  robot.digital(1,0);
  but1 = robot.readButton(1);
  but2 = robot.readButton(2);
  Serial.println(String(but1) + String(but2));
}
else if(but1 == 1 && but2 == 1){
  robot.digital(1,1);
  robot.digital(2,1);
  but1 = robot.readButton(1);
  but2 = robot.readButton(2);
  Serial.println(String(but1) + String(but2));
}
else if(but1 == 0 && but2 == 0){
  robot.digital(1,0);
  robot.digital(2,0);
  but1 = robot.readButton(1);
  but2 = robot.readButton(2);
  Serial.println(String(but1) + String(but2));
}


/*
robot.digital(1,0);
delay(1000);
robot.digital(1,0);
delay(1000);
*/
}
