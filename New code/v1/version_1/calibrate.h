

void calibrate() {

  while (checkLimit_Y() == 0) {
    y_axis.step(-1);
  }
  yPos = 0;
  xPos = 0;
  trayPos = 0;
  delay(100);

  while (checkLimit_Tray() == 0) {
    tray.step(1);
  }
  delay(100);

  while (checkLimit_X() == 0) {
    x_axis.step(1);
  }
  delay(100);

  servo.attach(SERVO_PIN);
  servo.write(90);
  delay(500);
  pinMode(23, OUTPUT);
}
