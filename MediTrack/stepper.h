
#include <Stepper.h>
Stepper trayStepper(2048, 5, 18, 19, 17);

int currentPos = 0;
int pos;

void turn(int newPos) {

  pos = newPos - currentPos;

  if (pos < 0) {
    pos = (pos * -1) / 10;
    for (int i = 0; i <= pos; i++) {
      trayStepper.step(-10);
    }
  } else if (pos > 0) {
    pos = pos / 10;
    for (int i = 0; i <= pos; i++) {
      trayStepper.step(10);
    }
  }

  currentPos = newPos;


  //  if (pos <= 1024) {
  //    for (int i = 0; i <= pos; i++)  {
  //      trayStepper.step(10);
  //      currentPos = i;
  //    }
  //  }
  //  else {
  //    pos = 2048 - pos;
  //    for (int i = 0; i <= pos; i++) {
  //      trayStepper.step(-10);
  //      currentPos = i;
  //    }
  //  }

  //  while (stepCount < 100) {
  //    myStepper1.step(-10);
  //    stepCount++;
  //    //  delay(10);
  //  }
}
