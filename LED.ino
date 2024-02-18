#include <myDuino.h>


void setup() {
  // put your setup code here, to run once:

serial.begin(9600)


}

void loop() {
  // put your main code here, to run repeatedly:

robot.LED(1, 1);
dealy(500);
robot.LED(1, 0);
delay(500);


}
