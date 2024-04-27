#include <myDuino.h>

myDuino robot(1);
bool plug1 = 0;

void setup() {
  // put your setup code here, to run once:

Serial.begin(9600);
robot.LED(2,1);

}

void loop() {
  // put your main code here, to run repeatedly:

plug1 = robot.readButton(1);
Serial.println(String(plug1));

if (plug1 == true) {
  robot.moveMotor(1,2,255);
  delay(15000);
  robot.moveMotor(1,1,0);
  robot.readButton(1);
}

if (plug1 == false) {
  robot.moveMotor(1,2,0);
  robot.LED(2,0);
}

}
