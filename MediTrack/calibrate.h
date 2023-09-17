
#define trayLimit 21
//#define servoLimit 21

int limitState = 0;

void calibrator() {

  limitState = digitalRead(trayLimit);

  while (limitState == 0) {
    trayStepper.step(-10);
    limitState = digitalRead(trayLimit);
  }

  if (limitState == 0){
    currentPos = 0;
  }

}
