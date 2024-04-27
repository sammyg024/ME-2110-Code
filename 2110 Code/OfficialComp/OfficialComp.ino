#include <myDuino.h>

myDuino robot(1);

//WORKING CODE DONT FUCK IT
// DI1 is banana plugs, DI2 is scroll switch
//M1 Cascade motor, M2 Scroll motor

unsigned long curtime = 0;
unsigned long starttime;
int count = 0;
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
int pot = 0;

void setup() {
  count = 0;
  // put your setup code here, to run once:
  Serial.begin(9600);
  //robot.LED(1,1);
  // potentiometer stuff to set color equal to our position
  pot = robot.readPOT();

  if (pot >= 514) {
    //delay(5000);
    robot.LED(2,0);
    robot.LED(1,0);
    robot.digital(2,0);
    robot.digital(3,0);
    color = 0;
  }
  else if (pot <= 514 && pot >= 343) {
    //White w/ Green LED
    robot.LED(1,1);
    //delay(5000);
    robot.LED(2,0);
    robot.digital(2,1);
    robot.digital(3,0);
    color = 1;
  }
  else if (pot < 343 && pot >= 172) {
    //Blue w/ red LED
    robot.LED(2,1);
    robot.LED(1,0);
    robot.digital(2,0);
    robot.digital(3,1);
    color = 2;
  }
  else if (pot < 172) {
    //Black w/ Both LEDs
    robot.LED(1,1);
    //delay(500);
    robot.LED(2,1);
    //delay(500);
    robot.digital(2,1);
    robot.digital(3,1);
    color = 3;
  }
}
unsigned long ihatethis = 0;
unsigned long endtime = 38000;

void loop() {
  // put your main code here, to run repeatedly:
plug1 = robot.readButton(1);

//Banana plug turn ons
if (plug1 == 1) {
  Serial.println("howdy");
  if (count == 0){
    starttime = millis();
    count++;
    ihatethis = starttime + 17500;
  }

  //Turn off when endtime hits
  while (curtime <= endtime) {
    curtime = millis() - starttime;

    if (curtime < endtime && curtime < ihatethis){
      robot.moveMotor(1,1,255);
      //Serial.println("Starting" + curtime + ihatethis);
    } else {
      robot.moveMotor(1,1,0);
      //Serial.println("Ending");
    }
    // Stop Scroll stuff move to lift
    if (curtime <= endtime) {

      //Initial Actions
      if (i < 1){
        //Pneumatic
        robot.digital(1,1);
        delay(250);
        robot.digital(1,0);
        i = i + 1;
      }
          //Dragon Scroll Grabbing
        //First trigger for start time
        switch1 = robot.readButton(2);
      if ((switch1 == 1) && (triggered == 0)) {
        Serial.println("first trigger");
        trigTime1 = millis();
        triggered++;
        switch1 = 0;
        delay(1000);
        }
        //Timing Stuff starts when switch is hit and after first trigger
      switch1 = robot.readButton(2);
      if ((switch1 == 1) && ( triggered == 1)) {
        Serial.println("second trigger");
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
          Serial.println("Please");
          robot.moveMotor(2,1,255);
          delay(1000);
          robot.moveMotor(2,1,0);
          delay(100);
          robot.moveMotor(2,2,255);
          delay(900);
          robot.moveMotor(2,2,0);
          mScroll = false;
        }
      
    }
     curtime = millis() - starttime;
    //Serial.println(curtime);
 
  }
  //Turn ON LED off and turns motor OFF
  robot.LED(1,0);
  robot.LED(2,0);
  //robot.moveMotor(1,1,0);
}
}