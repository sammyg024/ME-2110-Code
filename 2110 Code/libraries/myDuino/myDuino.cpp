#include "Arduino.h"
#include "myDuino.h"

//Please be silent while in the library

myDuino::myDuino(int unused) {
  // set up pin directions
  _LED1 = 12;
  _LED2 = 13;
  _mot1For = 5;
  _mot1Bac = 6;
  _mot2For = 11;
  _mot2Bac = 10;
  _digi1 = 9;
  _digi2 = 8;
  _digi3 = 7;
  _digi4 = 4;
  _encA = 2;  //Button 6
  _encB = 3;  //Button 5
  _but1 = A0;
  _but2 = A1; //echo pin for ultrasonic distance sensor
  _but3 = A2; //trig pin for ultrasonic distance sensor
  _but4 = A3;
  _pot = A4;
  _IR = A5;

  //Encoder
  _encCount = 0;
  _encDir = 0;
  _bounce = 50;
  
  // LEDS
  pinMode(_LED1, OUTPUT);
  pinMode(_LED2, OUTPUT);

  // Motors
  pinMode(_mot1For, OUTPUT);
  pinMode(_mot1Bac, OUTPUT);
  pinMode(_mot2For, OUTPUT);
  pinMode(_mot2Bac, OUTPUT);

  // Digital Outputs
  pinMode(_digi1, OUTPUT);
  pinMode(_digi2, OUTPUT);
  pinMode(_digi3, OUTPUT);
  pinMode(_digi4, OUTPUT);

  // Pull-up resistors for digitals to eliminate noise
  pinMode(_but1, INPUT_PULLUP);
    
  //Change _but2 pin mode to INPUT for ultrasonic distance sensor    
  //pinMode(_but2, INPUT_PULLUP); // Use this line if ultrasonic sensor is NOT in use
  //pinMode(_but2, INPUT); // Use this line if ultrasonic sensor IS in use
    
  //Change _but3 pin mode to OUTPUT for ultrasonic distance sensor
  //pinMode(_but3, INPUT_PULLUP);
  //pinMode(_but3, OUTPUT);
    
  //Change _but4 pin mode to OUTPUT to use LED'
  //pinMode(_but4, OUTPUT);
  pinMode(_but4, INPUT_PULLUP);
    
  pinMode(_encA, INPUT_PULLUP);
  pinMode(_encB, INPUT_PULLUP);

  // Analog sensors
  pinMode(_IR, INPUT);
  pinMode(_pot, INPUT);
}

//ANALOG INPUTS
int myDuino::readIR()
{
  int out = analogRead(_IR);
  return out;
}

int myDuino::readPOT()
{
  int out = analogRead(_pot);
  return out;
}

int myDuino::readAccel(){
  int out = analogRead(_pot);
  return out;
}

int myDuino::readPhoto(){
  int out = analogRead(_IR);
  return out;
}

//DIGITAL INPUTS
int myDuino::readButton(int pin)
{
  int out = 0;
  switch(pin) {
    case 1:
      out = !digitalRead(_but1);
      break;
    case 2:
      pinMode(_but2, INPUT_PULLUP);
      out = !digitalRead(_but2);
      break;
    case 3:
      pinMode(_but3, INPUT_PULLUP);
      out = !digitalRead(_but3);
      break;
    case 4: 
      out = !digitalRead(_but4);
      break;
    case 5: 
      out = !digitalRead(_encB);
      break;
    case 6: 
      out = !digitalRead(_encA);
      break;
    default:
      out = !digitalRead(_but1);
      break;
  }
return out; 
}

//DIGITAL OUTPUTS 
void myDuino::digital(int pin, int io) 
{
  int out = 0;
  int onOFF = LOW;
  switch(pin) {
    case 1:
      out = _digi1;
      break;
    case 2:
      out = _digi2;
      break;
    case 3:
      out = _digi3;
      break;
    case 4:
      out = _digi4;
      break;
    default:
      out = _digi1;
      break;
  }
  if (io == 1) {
    onOFF = HIGH;
  } else {
    onOFF = LOW;
  }
  digitalWrite(out, onOFF);
}

//LEDs
void myDuino::LED(int pin, int io) 
{
  int out = 0;
  int onOFF = LOW;
  switch(pin) {
    case 1:
      out = _LED1;
      break;
    case 2:
      out = _LED2;
      break;
    default:
      out = _LED1;
      break;
  }
  if (io == 1) {
    onOFF = HIGH;
  } else {
    onOFF = LOW;
  }
  digitalWrite(out, onOFF);
}

//Tracker LED connected to but4 pin
void myDuino::trackerLED(int io){
  int out = 0;
  int onOFF = LOW;
  if (io == 1) {
      onOFF = HIGH;
  }
  else {
    onOFF = LOW;   
  }
  digitalWrite(_but4, onOFF);
}

//MOTORS
void myDuino::moveMotor(int mot, int dir, int spd) {
  int out1 = 0;
  int out2 = 0;
  //1 is forwards, 2 is backwards
  if (mot == 1 && dir == 1) {
    out1 = _mot1For;
    out2 = _mot1Bac;
  }
  else if (mot == 1 && dir == 2) {
    out1 = _mot1Bac;
    out2 = _mot1For;
  }
  else if (mot == 2 && dir == 1) {
    out1 = _mot2For;
    out2 = _mot2Bac;
  }
  else if (mot == 2 && dir == 2) {
    out1 = _mot2Bac;
    out2 = _mot2For;
  }
  else {
    spd = 0;
  }

  if (spd < 0) {
    spd = 0;
  }
  else if (spd > 255) {
    spd = 255;
  }
  analogWrite(out1, spd);
  analogWrite(out2, 0); 
}

 void myDuino::doEncoder() {
  _aState = digitalRead(_encA); // Reads the "current" state of the outputA
  // If the previous and the current state of the outputA are different, that means a Pulse has occured
  if (_aState != _aLastState){     
    // If the outputB state is different to the outputA state, that means the encoder is rotating clockwise
    if (digitalRead(_encB) != _aState) { 
      _encCount = _encCount + 1;
      _encDir = 1;
    } else {
      _encCount = _encCount - 1;
      _encDir = -1;
    }    
  } 
  _bState = digitalRead(_encB); // Reads the "current" state of the outputA
  // If the previous and the current state of the outputA are different, that means a Pulse has occured
  if (_bState != _bLastState){     
    // If the outputB state is different to the outputA state, that means the encoder is rotating clockwise
    if (digitalRead(_encA) == _bState) { 
      _encCount = _encCount + 1;
      _encDir = 1;
    } else {
      _encCount = _encCount - 1;
      _encDir = -1;
    }     
  } 
   _aLastState = _aState; // Updates the previous state of the outputA with the current state
   _bLastState = _bState;
}

int myDuino::encoderCount()
{
  int out = _encCount;
  return out;
} 

int myDuino::encoderDir()
{
  int out = _encDir;
  return out; 
}


//ULTRASONIC DISTANCE SENSOR
int myDuino::readUltrasonic(){
    
  pinMode(_but2, INPUT);
  pinMode(_but3, OUTPUT);
  //Clears the trigPin condition
  digitalWrite(_but3, LOW);
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(_but3, HIGH);
  delayMicroseconds(10);
  digitalWrite(_but3, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(_but2, HIGH);
  // Calculating the distance
  distance = int(duration * 0.034 / 2); // Speed of sound wave divided by 2 (go and back)
  return distance;
}
