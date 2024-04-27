#include <myDuino.h>

myDuino robot(1);

bool val = 0;

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

val = robot.encoderDir();
Serial.println(val);

}
