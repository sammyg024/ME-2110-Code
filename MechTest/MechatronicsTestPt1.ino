#include <myDuino.h>

myDuino robot(1);

bool but1 = 0;
int val = 0;


void setup() {
  // put your setup code here, to run once:

Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:

but1 = robot.readButton(1);
if (val % 2 == 0) {
  robot.digital(1,0);
  but1 = robot.readButton(1);
  if (but1 == true) {
    val = val + 1;
    delay(500);
  }
  Serial.println("off");
}
else if(val % 2 == 1) {
  robot.digital(1,1);
  but1 = robot.readButton(1);
  if (but1 == true) {
    val = val + 1;
    delay(500);
  }
  Serial.println("on");
}
//Serial.println(but1);
//Serial.println(val);
}
