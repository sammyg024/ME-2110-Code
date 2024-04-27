#include <myDuino.h>

//Motor in m1, pneumatic in DO1 and banana plugs in DI1

myDuino robot(1);

bool but1 = 0;
bool case1 = 0;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
delay(100);

}

void loop() {
  // put your main code here, to run repeatedly:

but1 = robot.readButton(1);
Serial.println(String(but1));
if (case1 = 0);
    if (but1 == true) {
      //Rotate motor about 90 degrees 
      robot.moveMotor(1,2,255);
      delay((1300));
      Serial.println("motor");
      robot.moveMotor(1,1,0);
      //delay(2000);

      //Run pneumatic once for 2 seconds then cut it
      robot.digital(1,1);
      Serial.println("Pneumatic");
      delay(2500);
      robot.digital(1,0);

      //Just in case things do not turn off
      robot.moveMotor(1,1,0);
      robot.digital(1,0);

      robot.readButton(1);

      case1 = 1;

      //delay(40000);
    } 
    
  else if (but1 == false) {
      robot.digital(1,0);
      robot.moveMotor(1,1,0);
    }
else if (case1 = 1) {
    robot.digital(1,0);
    robot.moveMotor(1,1,0);
}
  }


