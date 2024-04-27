#include <myDuino.h>

myDuino robot(1);
int count = 1;

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
  // turns the outputs (solenoids, valves, motors) on and off in a repeating 1-second cycle
  
  robot.digital(1,0);
  robot.digital(2,0);
  robot.digital(3,0);
  robot.digital(4,0);
  robot.moveMotor(1,1,0); 
  robot.moveMotor(2,1,0); 
  delay(1000);
  
  robot.digital(1,1);
  robot.digital(2,1);
  robot.digital(3,1);
  robot.digital(4,1);
  robot.moveMotor(1,count,255); 
  robot.moveMotor(2,count,255); 
  delay(1000);
  
  if (count == 1){count = 2;} // switches motor speed on each loop to test both directions
  else {count = 1;}
}
