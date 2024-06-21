/*

*/

// Servo manipulation
void Servo::servoInit()  {
  UCServo.attach(SRVO, 500, 2400);    // 500 = 0 degrees & 2400 = 180 degrees
  UCServo.attach(SRVO);
  UCServo.write(90);  // Set servo to the middle (90 degrees)
  delay(500);         // Give the servo some time to look in the middle
}

void Servo::servoTest()  {
  for (int i = 0;i <= 90; i++)    {
    UCServo.attach(SRVO);
    UCServo.write(90 + i);
    delay(500);
    UCServo.write(90 - i);
    delay(500);
  }
}

void Servo::lookAtDegree(int degree) {
  UCServo.attach(SRVO);
  UCServo.write(degree);  // Set servo to the middle (90 degrees)
  delay(500);         // Give the servo some time to look in the middle
}

// Dynamic modes
void Servo::lookRight(int degreesRight)  {
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
}

void Servo::lookLeft(int degreesLeft)  {
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
}