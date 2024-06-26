/*

*/

#ifndef MYSERVO_H
#define MYSERVO_H

#include "car.h"
#include <arduino.h>

Servo UCServo // create servo object to control a servo

// Servo manipulation
void myServo::servoInit()  {
  UCServo.attach(SRVO, 500, 2400);    // 500 = 0 degrees & 2400 = 180 degrees
  UCServo.attach(SRVO);
  UCServo.write(90);  // Set servo to the middle (90 degrees)
  delay(500);         // Give the servo some time to look in the middle
  myservo.detach();
}

void myServo::servoTest()  {
  UCServo.attach(SRVO);
  for (int i = 0;i <= 90; i++)    {
    UCServo.write(90 + i);
    delay(500);
    UCServo.write(90 - i);
    delay(500);
  }
  myservo.detach();
}

void myServo::lookAtDegree(unsigned int degree) {
  UCServo.attach(SRVO);
  UCServo.write(degree);  // Set servo to the middle (90 degrees)
  delay(500);         // Give the servo some time to look in the middle
  myservo.detach();
}

// Dynamic modes
void myServo::lookRight(unsigned int degreesRight)  {
  UCServo.attach(SRVO);
  if(currentDegree + degreesRight < 0)    {
    currentDegree = 0;
  }
  else if(currentDegree + degreesRight > 180)   {
    currentDegree = 180;
  }
  else    {
    currentDegree += degreesRight;
  }

  UCServo.write(currentDegree);
  delay(500);
  myservo.detach();
}

void myServo::lookLeft(unsigned int degreesLeft)  {
  UCServo.attach(SRVO);
  if(currentDegree + degreesLeft < 0)    {
    currentDegree = 0;
  }
  else if(currentDegree + degreesLeft > 180)   {
    currentDegree = 180;
  }
  else    {
    currentDegree += degreesLeft;
  }

  UCServo.write(currentDegree);
  delay(500);
  myservo.detach();
}

#endif