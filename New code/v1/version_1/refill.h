
void refill() {

  lift();

  if (slotNo == 1){
    moveTo(5);
    display.clearDisplay();
    display.print(F("Change Pills in container 1"));
    display.display();
  }
  else if (slotNo == 2){
    moveTo(6);
    display.clearDisplay();
    display.print(F("Change Pills in container 2"));
    display.display();
  }
  else if (slotNo == 3){
    moveTo(7);
    display.clearDisplay();
    display.print(F("Change Pills in container 3"));
    display.display();
  }
  else if (slotNo == 4){
    moveTo(8);
    display.clearDisplay();
    display.print(F("Change Pills in container 4"));
    display.display();
  }
  else if (slotNo == 5){
    moveTo(1);
    display.clearDisplay();
    display.print(F("Change Pills in container 5"));
    display.display();
  }
  else if (slotNo == 6){
    moveTo(2);
    display.clearDisplay();
    display.print(F("Change Pills in container 6"));
    display.display();
  }
  else if (slotNo == 7){
    moveTo(3);
    display.clearDisplay();
    display.print(F("Change Pills in container 7"));
    display.display();
  }
  else if (slotNo == 8){
    moveTo(4);
    display.clearDisplay();
    display.print(F("Change Pills in container 8"));
    display.display();
  }
  else {
    display.clearDisplay();
    display.print(F("Error refill!!"));
    display.display();
  }
}