

// void lift() {
//   // Serial.println("lifting");
//   for (int i = crntPos; i <= 130; i++) {
//     arm.write(i);
//     delay(50);
//   }
//   err = 0;
// }

void tryAgain() {
  delay(100);
  lift();

  while (val > 630) {

    if (pressure_sensor.is_ready()) {
      val = getPreassure();
    }
    // if (err == 1) {
    //   lift();
    //   shake();
    //   tryAgain();
    // }
    y_axis.step(50);
    yPos = yPos + 50;
    if (yPos > 1000) {
      break;
      // Serial.println("not found");
      // err = 1;
      // val = 0;
    }
    delay(1500);
  }
}

void pick() {
  delay(100);

  vacumOn();
  delay(100);

  if (pressure_sensor.is_ready()) {
    val = getPreassure();
    val = 700;
  }

  err = 0;
  delay(100);

  while (val > 630) {

    if (pressure_sensor.is_ready()) {
    // val = getPreassure();
    }

    y_axis.step(50);
    yPos = yPos + 50;
    if (yPos > 2100) {
      // Serial.println("not found");
      // err = 1;
      val = 0;
    }
    delay(150);

    if (err == 1) {
      lift();
      shake();
      // tryAgain();
      pick();
    }
    // display.clearDisplay();
    // display.setCursor(0, 0);
    // display.print(val);
    // display.display();
  }

  //  lift();
}

void place() {

  while (xPos > dropX) {
    x_axis.step(1);
    xPos--;
  }

  while (yPos < dropY) {
    y_axis.step(1);
    yPos++;
  }
  vacumOff();
  delay(250);
  // lift();
  // Serial.println("placing");
  // for (int i = 130; i >= 110; i--) {
  //   arm.write(i);
  //   delay(50);
  // }
  // vacumOff();
  // delay(250);

  // for (int i = 110; i <= 130; i++) {
  //   arm.write(i);
  //   delay(50);
  // }
  // crntPos = 130;
}
