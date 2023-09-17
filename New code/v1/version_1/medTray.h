

void moveTo(int slot) {
  if (slot == 1){
    turnTray(128);
  }
  else if (slot == 2){
    turnTray(384);
  }
  else if (slot == 3){
    turnTray(640);
  }
  else if (slot == 4){
    turnTray(896);
  }
  else if (slot == 5){
    turnTray(1152);
  }
  else if (slot == 6){
    turnTray(1408);
  }
  else if (slot == 7){
    turnTray(1664);
  }
  else if (slot == 8){
    turnTray(1920);
  }
  else{
    
  }
}


void moveToTray() {
  while (xPos<trayLoc) {
    x_axis.step(-1);
    xPos++;
  }
}
