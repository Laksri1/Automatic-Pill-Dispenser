
void sort() {

  if (ready == 0) {
    Serial.println("moving x");
    moveToTray();

    if (slot1 != 0) {
      Serial.println("in slot 1");
      delay(100);
      while (0 < slot1) {
        moveTo(1);
        pick();
        lift();
        place();
        moveToTray();
        slot1--;
      }
    }

    if (slot2 != 0) {
      delay(100);
      while (0 < slot2) {
        moveTo(2);
        pick();
        lift();
        place();
        moveToTray();
        slot2--;
      }
    }

    if (slot3 != 0) {
      delay(100);
      while (0 < slot3) {
        moveTo(3);
        pick();
        lift();
        place();
        moveToTray();
        slot3--;
      }
    }

    if (slot4 != 0) {
      delay(100);
      Serial.println("in slot 4");
      while (0 < slot4) {
        Serial.println("tray moving to 4");
        moveTo(4);
        Serial.println("picking up");
        pick();
        Serial.println("lifting");
        lift();
        Serial.println("placing");
        place();
        Serial.println("moving to tray");
        lift();
        moveToTray();
        slot4--;
      }
    }

    if (slot5 != 0) {
      delay(100);
      while (0 < slot5) {
        moveTo(5);
        pick();
        lift();
        place();
        moveToTray();
        slot5--;
      }
    }

    if (slot6 != 0) {
      delay(100);
      while (0 < slot6) {
        moveTo(6);
        pick();
        lift();
        place();
        moveToTray();
        slot6--;
      }
    }

    if (slot7 != 0) {
      delay(100);
      while (0 < slot7) {
        moveTo(7);
        pick();
        lift();
        place();
        moveToTray();
        slot7--;
      }
    }

    if (slot8 != 0) {
      delay(100);
      while (0 < slot8) {
        moveTo(8);
        pick();
        lift();
        place();
        moveToTray();
        slot8--;
      }
    }
    ready = 1;
  }
}