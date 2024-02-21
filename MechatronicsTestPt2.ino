#include <myDuino.h>

myDuino robot(1);

int encCount = 0;
int encDir = 0;
int encSize = 12;
unsigned long m1spd = 0;
int m1Dir = 1; 
bool but1 = 0;
bool but2 = 0;



void encHandler() {
  robot.doEncoder();
}


void setup() {
  // put your setup code here, to run once:
  attachInterrupt(digitalPinToInterrupt(2), encHandler, CHANGE);
  attachInterrupt(digitalPinToInterrupt(3), encHandler, CHANGE);

  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  but1 = robot.readButton(1);
  but2 = robot.readButton(2);
  encCount = robot.encoderCount();

  //x = encoder value per 1 rotation
  m1spd = 255 * 0.1 * (encCount/encSize);
  
  Serial.println(String(but1));
  Serial.println(String(but2));
  Serial.println(String(m1spd));
  
  //Change direction of the motor based on the two switches
  if(but1 == true && but2 == false){
    robot.LED(1,1);
    robot.moveMotor(1,2,m1spd); 
  }
  else if(but1 == false && but2 == true) {
    robot.LED(2,1);
    robot.moveMotor(1,1,m1spd); 
  }
  else{
    robot.LED(1,0);
    robot.LED(2,0);
    robot.moveMotor(1,1,0); 
  }

}
