#include <myDuino.h>

myDuino robot(1);

//WORKING CODE DONT FUCK IT
// DI1 is banana plugs, DI2 is scroll switch
//M1 Cascade motor, M2 Scroll motor

unsigned long curtime;
bool switch1 = 0;
bool plug1 = 0;
int i = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  robot.LED(1,1);
}

unsigned long endtime = 40000;
unsigned long scrolltime = 7500;

void loop() {
  // put your main code here, to run repeatedly:
plug1 = robot.readButton(1);
if (plug1 == 1) {
  switch1 = robot.readButton(2);
  while (curtime <= endtime) {
    curtime = millis();
    while (curtime <= scrolltime) {
      curtime = millis();
//Dragon Scroll Grabbing
      switch1 = robot.readButton(2);
      //Initial Actions
      while (i < 1){
        //Pneumatic
        robot.digital(1,1);
        delay(250);
        robot.digital(1,0);
        //delay(250);
        //Premove Motor
        robot.moveMotor(2,1,255);
        delay(500);
        robot.moveMotor(2,1,0);
        i = i + 1;
      }
      //when triggered move motor to grab scroll
        if (switch1 == 1) {
          robot.moveMotor(2,1,255);
          delay(600);
          robot.moveMotor(2,1,0);
        }
        Serial.println(millis());
    }
    curtime = millis();
    //Serial.println(curtime);
    //Cascade Lift
    robot.moveMotor(1,1,255);
    delay(17500);
    
  }
  //Turn ON LED off and turns motor OFF
  robot.LED(1,0);
  //robot.moveMotor(1,1,0);
  robot.LED(2,1);
  delay(5000);
  robot.LED(2,0);
}
}
