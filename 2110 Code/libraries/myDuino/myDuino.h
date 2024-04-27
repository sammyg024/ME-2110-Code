#ifndef myDuino_h
#define myDuino_h

#include "Arduino.h"

class myDuino
{
  public:
    myDuino(int unused);
    void digital(int pin, int io);
    void LED(int pin, int io);
    int readIR();
    int readPOT();
    int readAccel();
    int readPhoto();
    int readUltrasonic();
    int readButton(int pin);
    void trackerLED(int io);
    void doEncoder();
    int encoderCount();
    int encoderDir();
    void moveMotor(int mot, int dir, int spd);

   private:

    int _LED1;
    int _LED2;
    int _mot1For;
    int _mot1Bac;
    int _mot2For;
    int _mot2Bac;
    int _digi1;
    int _digi2;
    int _digi3;
    int _digi4;
    int _encA;
    int _encB;
    int _lastA;
    int _lastB; 
    int _IR;
    int _pot;
    int _but1;
    int _but2;
    int _but3;
    int _but4;
    int _encCount;
    int _encDir;
    int _aState;
    int _aLastState;
    int _bState;
    int _bLastState;
    int _bounce;
    long duration;
    int distance;
};

#endif
