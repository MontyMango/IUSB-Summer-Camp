// For Elegoo smart car V4.0, functions for car movement.
// The programs coming with V4.0 tutorials are unnecessarily complex, not beginner-friendly.
// The code below allows you program V4.0 cars in a way similar as in previous versions. 
// Liqiang Zhang
// Cameron Harter
// June 2024
// Insipred by Martin Hebel's example code. 

#include <Servo.h>

#ifndef _CARMOVEMENT_H_
#define _CARMOVEMENT_H_

/* DEFINING IO pins */

// Robot functionality
#define modeSwitch 2 // Mode Switch input
#define STBY 3  // place H-bridge in standby if LOW, run if HIGH


// Motor Pins
#define RPC 5   // controls power to right motor
#define LPC 6   // controls power to left motor
#define RDC 7   // controls direction of right motor, HIGH = FORWARD, LOW=REVERSE
#define LDC 8   // controls direction of left motor, HIGH = FORWARD, LOW=REVERSE

// EXPERIMENTAL: Servo Pins & Variables
Servo UCServo;  // Ultrasonic & Camera Servo
#define SRVO 10
int currentDegree 90



/*define forward function*/
void moveForward(int speed)
{ 
  analogWrite(RPC,speed);
  analogWrite(LPC,speed);
  digitalWrite(RDC,HIGH); 
  digitalWrite(LDC,HIGH);
}
/*define back function*/
void moveBack(int speed)
{
  analogWrite(RPC,speed);
  analogWrite(LPC,speed);
  digitalWrite(RDC,LOW); 
  digitalWrite(LDC,LOW);
}
/*define left function*/
void moveLeft(int speed)
{
  analogWrite(RPC,speed);
  analogWrite(LPC,speed);
  digitalWrite(RDC,HIGH); 
  digitalWrite(LDC,LOW);
}
/*define right function*/
void moveRight(int speed)
{
  analogWrite(RPC,speed);
  analogWrite(LPC,speed);
  digitalWrite(RDC,LOW); 
  digitalWrite(LDC,HIGH);
}

class Servo	{
public:
	void servoInit(void);
	void servoTest(void);
}

void stop()
{
  analogWrite(RPC,0);
  analogWrite(LPC,0);	
}

/*put your setup code here, to run once*/
void initialSetup() 
{
  pinMode(RPC, OUTPUT);     
  pinMode(LPC, OUTPUT);
  pinMode(RDC, OUTPUT);
  pinMode(LDC, OUTPUT);
  pinMode(STBY, OUTPUT);

  digitalWrite(STBY, HIGH);  //Enable Motors to run
  servoInit();
}

#endif