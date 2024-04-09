#include <myDuino.h>

myDuino robot(1);

//WORKING CODE DONT FUCK IT
// DI1 is banana plugs, DI2 is scroll switch
//M1 Cascade motor, M2 Scroll motor

unsigned long curtime;
bool switch1 = 0;
bool plug1 = 0;
int i = 0;
unsigned long trigTime1 = 0;
unsigned long trigTime2 = 0;
unsigned long rotTime = 0;
unsigned long waitTime = 0;
int triggered = 0;
unsigned long scrollStartTime = 0;
bool mScroll = false;
int color = 2; //Gold0White1Blue2Black3

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  robot.LED(1,1);
}

unsigned long endtime = 40000;
unsigned long scrolltime = 2400;

void loop() {
  // put your main code here, to run repeatedly:
plug1 = robot.readButton(1);

//Banana plug turn ons
if (plug1 == 1) {
  trigTime1 = millis();
  //switch1 = robot.readButton(2);
  
  //Turn off when endtime hits
  while (curtime <= endtime) {
    curtime = millis();
    
    // Stop Scroll stuff move to lift
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
        i = i + 1;
      }
        //First trigger for start time
        if ((switch1 == 1) && (triggered == 0)) {
          trigTime1 = millis();
          triggered++;
        delay(1000);
        }
        //Timing Stuff starts when switch is hit and after first trigger
        else if ((switch1 == 1) && ( triggered == 1)) {
          //Second trigger for calculations
          trigTime2 = millis();
          rotTime = trigTime2 - trigTime1;
          switch (color) {
            case 0:
              waitTime = 0;
              break;
            case 1: 
              waitTime = (rotTime /4);
              break;
            case 2:
              waitTime =2*(rotTime / 4);
              break;
            case 3: 
              waitTime = 3*(rotTime / 4);
              break;
          }
          scrollStartTime = millis();
          triggered++;
        } 
        // Starts when the total time is less than Scrolltime and color stuff and trigger has been hit twice
        else if ((triggered == 2 ) && ( millis() > scrollStartTime + waitTime)) {
          mScroll = true;
          triggered++;
        }
        //Code to activate motor for scroll
        if (mScroll == true) {
          robot.moveMotor(2,2,255);
          delay(1000);
          robot.moveMotor(2,2,0);
          delay(100);
          robot.moveMotor(2,2,255);
          delay(900);
          robot.moveMotor(2,2,0);
          mScroll = false;
        } 

    }
    curtime = millis();
    //Serial.println(curtime);
    //Cascade Lift
    /*
    robot.moveMotor(1,1,255);
    delay(17500);
    */
    
  }
  //Turn ON LED off and turns motor OFF
  robot.LED(1,0);
  //robot.moveMotor(1,1,0);
  robot.LED(2,1);
  delay(5000);
  robot.LED(2,0);
}
}


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

