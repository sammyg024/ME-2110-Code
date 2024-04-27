#include<myDuino.h>

myDuino robot(1);

int i = 0;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
while (i < 1) {
  robot.moveMotor(2,2,255);
  delay(100);
  robot.moveMotor(2,2,0);
  i = i + 1;
}

}
