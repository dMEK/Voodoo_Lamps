
#include <Servo.h>

Servo slew;  // create servo object to control a servo
Servo base;
Servo elbow;
Servo headTilt;
Servo headTurn;

// define Pots ADC Pins

int slewPot = A0;  
int basePot = A1;
int elbowPot = A2;
int headTiltPot = A3;
int headTurnPot = A4;
int val;    // variable to read the value from the analog pin

void setup() {
  
  //attach Servo objects
  slew.attach(3);  // create servo object to control a servo
  base.attach(5);
  elbow.attach(6);
  headTilt.attach(9);
  headTurn.attach(10);
}

void loop() {
  val = analogRead(slewPot);            // reads the value of the potentiometer (value between 0 and 1023)
  val = map(val, 0, 1023, 0, 180);     // scale it to use it with the servo (value between 0 and 180)
  slew.write(val);                  // sets the servo position according to the scaled value
  delay(15);                           // waits for the servo to get there
}
