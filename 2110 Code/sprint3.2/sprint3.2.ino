#include <myDuino.h>

// DO1 is pneumatics & DO2 is solenoids

myDuino robot(1);
//Banana Plugs
bool plug1 = 0;
//Dragon Scroll Switch
bool but1 = 0;
unsigned long curtime;

void setup() {
  // put your setup code here, to run once:

Serial.begin(9600);
robot.LED(2,1);

}

unsigned long endtime = 40000;

void loop() {
  // put your main code here, to run repeatedly:

plug1 = robot.readButton(1);
Serial.println(String(plug1));
//curtime = millis();

while (curtime <= endtime) {
  //Banana Plugs Connected
  curtime = millis();
  if (plug1 == true) {
    robot.LED(1,1);
  

    /*
    //pneaumatic
    robot.digital(1,1);
    delay(500);
    robot.digital(1,0);

    //premove motor
    robot.moveMotor(2,2,255);
    delay(3000);
    robot.moveMotor(2,2,0);
    */
    //Dragon Scroll switch
    /*
    while (curtime <= 20000 && curtime >= 0) {
      if (but1 == true){
          robot.moveMotor(2,2,255);
          delay(3000);
          robot.moveMotor(2,2,0);
          but1 = robot.readButton(2);

      }
    }
    */
    //Cascade Motor Stuff
    robot.moveMotor(1,2,255);
    delay(17500);
    robot.moveMotor(1,2,0);
    plug1 = robot.readButton(1);

  }

  if (plug1 == false) {
    robot.moveMotor(1,2,0);
    robot.LED(2,0);
  }
}
}
