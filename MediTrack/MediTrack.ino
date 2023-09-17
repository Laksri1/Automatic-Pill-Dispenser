// Product design


#include "vaccum.h"
#include "preassureSensor.h"
//#include "stepper.h"
#include "servo.h"
#include "medTray.h"
#include "shake.h"
#include "calibrate.h"
#include "pickNplace.h"



void setup() {

  Serial.begin(9600);
  pressure_sensor.begin(DOUT, SCLK); 

  trayStepper.setSpeed(5);
  //  xStepper.setSpeed(5);
  //  yStepper.setSpeed(5);

  arm.attach(SERVO_PIN);

  pinMode(trayLimit, INPUT_PULLUP);

  pinMode(16, OUTPUT);

  arm.write(130);

}

void loop() {
//  if (pressure_sensor.is_ready()) {
//  Serial.println(getPreassure());
  moveTo(1);
  delay(100);
  pick();
  lift();
  moveTo(4);
  delay(100);
  place();
delay(100);
   moveTo(2);
  delay(100);
  pick();
  lift();
  moveTo(4);
  delay(100);
  place();
//  delay (10);
//  }

//  arm.write(i);!!!!!!!!!!!
}
