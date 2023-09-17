

int checkLimit_Tray() {

  limit1 = touchRead(13);
  // Serial.println(limit1);
  if (limit1<5){
    return 1;
  }
  else{
    return 0;
  }

}

int checkLimit_Y() {

  limit3 = touchRead(14);
  // Serial.println(limit3);
  if (limit3<5){
    return 1;
  }
  else{
    return 0;
  }
  
}

int checkLimit_X() {

  limit2 = touchRead(12);
  // Serial.println(limit2);
  if (limit2<5){
    return 1;
  }
  else{
    return 0;
  }
  
}

