#include <Stepper.h>

#define upperYLimit 300

// Stepper tray(stepsPerRevolution, 17, 18, 19, 5);
Stepper tray(stepsPerRevolution, 1, 32, 3, 33);     // define pins of the tray stepper
Stepper x_axis(stepsPerRevolution, 17, 18, 19, 5);  // define pins of the x axis stepper
Stepper y_axis(stepsPerRevolution, 15, 4, 16, 2);   // define pins of the y axis stepper

// define the speeds of the steppers
// tray.setSpeed(5);
// x_axis.setSpeed(5);
// y_axis.setSpeed(5);

int currentPos = 0;
int pos;

void turnTray(int newPos) {

  pos = newPos - currentPos;

  if (pos < 0) {
    pos = (pos * -1) / 10;
    for (int i = 0; i <= pos; i++) {
      tray.step(-10);
    }
  } else if (pos > 0) {
    pos = pos / 10;
    for (int i = 0; i <= pos; i++) {
      tray.step(10);
    }
  }
  currentPos = newPos;
}

// void liftTillUp() {
//   for (int i = 0; i <= upperYLimit; i++) {
//     y_axis.step(-10);
//   }
// }

void lift() {
  Serial.print("Y : ");
  Serial.println(yPos);
  // if (yPos > 0) {
  // for (int i = 0; i <= upperYLimit; i++) {
  while (yPos > 150) {
    y_axis.step(-50);
    yPos = yPos - 50;
  }
  // }
}