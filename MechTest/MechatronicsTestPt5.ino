#include<myDuino.h>

myDuino robot(1);
int pot = 0;
bool switch1 = 0;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

pot = robot.readPOT();

Serial.println(String(pot));

//Banana Plugs
switch1 = robot.readButton(1);

while (switch1 == 1){
  Serial.println(String(switch1));
  Serial.println("ON");

  pot = robot.readPOT();
  Serial.println(String(pot));

  if (pot >= 514) {
    robot.LED(1,1);
   // delay(5000);
    robot.LED(1,0);
    robot.LED(2,1);
    //delay(5000);
    robot.LED(2,0);
    robot.digital(4,1);

    // All else off
    robot.digital(1,0);
    robot.digital(2,0);
    robot.digital(3,0);
  }
  else if (pot <= 514 && pot >= 343) {
    robot.LED(1,1);
    //delay(5000);
    robot.LED(1,0);
    robot.digital(3,1);

    // All else off
    robot.digital(2,0);
    robot.digital(1,0);
    robot.digital(4,0);
  }
  else if (pot < 343 && pot >= 172) {
    robot.LED(2,1);
    robot.digital(1,1);
    //delay(5000);
    robot.LED(2,0);

    //Motor Turn offs
    robot.digital(2,0);
    robot.digital(3,0);
    robot.digital(4,0);
  }
  else if (pot < 172) {
    robot.LED(1,0);
    robot.LED(2,0);
    robot.digital(2,1);

    //All else off
    robot.digital(1,0);
    robot.digital(3,0);
    robot.digital(4,0);
  }

  }
  else {
    robot.digital(1,0);
    robot.digital(2,0);
    robot.LED(1,0);
    robot.LED(2,0);
    robot.digital(3,0);
    robot.digital(4,0);
  }

  switch1 = robot.readButton(1);
}
}
