#include <myDuino.h>

myDuino robot(1);

void setup() {
  // put your setup code here, to run once:

Serial.begin(9600);


}

void loop() {
  // put your main code here, to run repeatedly:

robot.LED(2, 1);
delay(500);
Serial.println("on");
robot.LED(2, 0);
delay(500);


}
