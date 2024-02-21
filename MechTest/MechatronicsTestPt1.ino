#include <myDuino.h>

myDuino robot(1);

int switch1 = 0;
int mod1 = 2;

void setup() {
  // put your setup code here, to run once:

Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:

switch1 = robot.readButton(1);
mod1 = mod1 % 2;
Serial.println(String(mod1));

if (switch1 == 1) { 
  robot.digital(1,1);
  //Serial.println("on");
  delay(100);
  mod1 = mod1 + 1 ;
}
else if (switch1 == 0) {
  robot.digital(1,0);
  //Serial.println("off");
  delay(100);
}
else {
  //Serial.println("error");
}
//robot.digital(1,0);
//robot.moveMotor(1,1,255);

}
