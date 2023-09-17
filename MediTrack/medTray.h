
#include "stepper.h"

void moveTo(int slot) {
  if (slot == 1){
    turn(256);
    Serial.println("tray1");
  }
  else if (slot == 2){
    turn(512);
    Serial.println("tray2");
  }
  else if (slot == 3){
    turn(768);
  }
  else if (slot == 4){
    turn(1024);
    Serial.println("tray4");
  }
  else if (slot == 5){
    turn(1280);
  }
  else if (slot == 6){
    turn(1536);
  }
  else if (slot == 7){
    turn(1792);
  }
  else if (slot == 8){
    turn(2048);
  }
  else{
    Serial.println("slot number error!!!!!");
  }
}
