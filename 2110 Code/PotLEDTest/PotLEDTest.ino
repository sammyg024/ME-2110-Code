#include<myDuino.h>
int pot = 0;

myDuino robot(1);

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  pot = robot.readPOT();

if (pot >= 514) {
    robot.LED(1,1);
   // delay(5000);
    robot.LED(1,0);
    robot.LED(2,1);
    //delay(5000);
    robot.LED(2,0);
  }
  else if (pot <= 514 && pot >= 343) {
    robot.LED(1,1);
    //delay(5000);
    robot.LED(1,0);
  }
  else if (pot < 343 && pot >= 172) {
    robot.LED(2,1);
  }
  else if (pot < 172) {
    robot.LED(1,1);
    delay(500);
    robot.LED(1,0);
    robot.LED(2,1);
    delay(500);
    robot.LED(2,0);
  }

}

