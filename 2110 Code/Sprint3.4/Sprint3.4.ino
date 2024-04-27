#include <myDuino.h>
myDuino robot(1);
unsigned long curtime;


void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
curtime = millis();
Serial.println(curtime);
delay(5000);
Serial.println(curtime);
curtime = millis();
Serial.println();
}
