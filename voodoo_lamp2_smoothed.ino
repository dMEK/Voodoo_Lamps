#include <Servo.h>

#define SLEW 0
#define BASE 1
#define ELBOW 2
#define HEADTILT 3
#define HEADTURN 4

//create servo objects for each lamp joint

Servo lampServo[5]; //servo array

// define Pots ADC Pins

int slewPot = A0;  
int basePot = A1;
int elbowPot = A2;
int headTiltPot = A3;
int headTurnPot = A4;


int controlPot[] = {A0, A1, A2, A3, A4}; //control pot array
int potVal[5];    // variable to read the value from the analog pin

void setup() {
  
  //attach Servo objects
  lampServo[0].attach(3);  // create servo object to control a servo
  lampServo[1].attach(5);
  lampServo[2].attach(6);
  lampServo[3].attach(9);
  lampServo[4].attach(10);
}

void loop() {
  for(int i = 0; i <5 ; i++) {
        potVal[i] = analogRead(controlPot[i]);            // reads the value of the potentiometer (value between 0 and 1023)
        potVal[i]= map(potVal[i], 0, 1023, 0, 1400);     // scale it to use it with the servo (value between 0 and 180)
        potVal[i] = 2400 - potVal[i];
        lampServo[i].writeMicroseconds(potVal[i]);                  // sets the servo position according to the scaled value
        delay(5);        // waits for the servo to get there
  }                
}
