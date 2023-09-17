/*
  Rui Santos
  Complete project details at https://RandomNerdTutorials.com/esp32-stepper-motor-28byj-48-uln2003/
  
  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files.
  
  The above copyright notice and this permission notice shall be included in all
  copies or substantial portions of the Software.
  
  Based on Stepper Motor Control - one revolution by Tom Igoe
*/

#include <Stepper.h>

const int stepsPerRevolution = 2048;  // change this to fit the number of steps per revolution

// ULN2003 Motor Driver Pins
#define IN1 17
#define IN2 19
#define IN3 18
#define IN4 5

// ULN2003 Motor Driver Pins
// #define IN1 15
// #define IN2 16
// #define IN3 4
// #define IN4 2

// ULN2003 Motor Driver Pins+
// #define IN1 1
// #define IN2 3
// #define IN3 32
// #define IN4 33

// initialize the stepper library
Stepper myStepper(stepsPerRevolution, IN1, IN3, IN2, IN4);

void setup() {

  // set the speed at 5 rpm
  myStepper.setSpeed(5);
  // initialize the serial port
  // Serial.begin(115200);
}

void loop() {
  // step one revolution in one direction:
  // Serial.println("clockwise");
  myStepper.step(stepsPerRevolution);
  delay(1000);

  // step one revolution in the other direction:
  // Serial.println("counterclockwise");
  myStepper.step(-stepsPerRevolution);
  delay(1000);
}