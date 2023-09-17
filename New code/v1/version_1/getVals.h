#include <String.h>


String data = "";

void readVals() {

  entry1 = 108001000200111;
  entry2 = 111301000200001;
  entry3 = 113001101010101;

  //
  //  Firebase Code Here
  ///////////////////////////////////////////////////////////////
  // get an Int number on the database
  if (Firebase.RTDB.getInt(&fbdo, "/settings/mode")) {
    settings = fbdo.intData();
    //int intHour = fbdo.intData();
    // Serial.print("settings ");
    // Serial.println(settings);


  } else {
    //Serial.println(fbdo.errorReason());
    // Serial.println("error happen when retriving ddata from fb");
  }

  if (Firebase.RTDB.getInt(&fbdo, "/settings/container")) {
    slotNo = fbdo.intData();
    //int intHour = fbdo.intData();
    // Serial.print("slotNo ");
    // Serial.println(slotNo);
  }

  ///////////////////////////////////////////////////////////////////////

  entry1 = 108001000200111;
  entry2 = 111301000200001;
  entry3 = 113001101010101;
  // settings = 0;
  // slotNo = 2;
  // entry4 = 0;
  // entry5 = 0;
  // entry6 = 0;
  // entry7 = 0;
  // entry8 = 0;
  // entry9 = 0;

  ///////////////////////////////////////////////////////

  // time1 = 1083012010011ULL/100000000UL;
  time1 = entry1 / 10000000000;
  time2 = entry2 / 10000000000;
  time3 = entry3 / 10000000000;

  dose1 = entry1 % 10000000000;
  dose2 = entry2 % 10000000000;
  dose3 = entry3 % 10000000000;

  // Serial.print("dose2: ");
  // Serial.print(dose2);
  // Serial.print("  ");

  timeList[0] = time1;
  timeList[1] = time2;
  timeList[2] = time3;
  doseList[0] = dose1;
  doseList[1] = dose2;
  doseList[2] = dose3;

  // sort(timeList,doseList);
  for (int i = 1; i < 3; ++i) {
    int j = timeList[i];
    long long int l = doseList[i];
    int k;
    for (k = i - 1; (k >= 0) && (j < timeList[k]); k--) {
      timeList[k + 1] = timeList[k];
      doseList[k + 1] = doseList[k];
    }
    timeList[k + 1] = j;
    doseList[k + 1] = l;
  }

  currTime = getTime();
  // currTime = 10800;

  for (int i = 0; i < 3; i++) {
    if (currTime < timeList[i]) {
      slot8 = (doseList[i] / 10) % 10;
      slot7 = (doseList[i] / 100) % 10;
      slot6 = (doseList[i] / 1000) % 10;
      slot5 = (doseList[i] / 10000) % 10;
      slot4 = (doseList[i] / 100000) % 10;
      slot3 = (doseList[i] / 1000000) % 10;
      slot2 = (doseList[i] / 10000000) % 10;
      slot1 = (doseList[i] / 100000000) % 10;
      timeNow = timeList[i];
      // Serial.print("dose list: ");
      // Serial.print(doseList[i]);
      // Serial.print("  ");
      break;
    }
  }
}


// void sort( *timeLst,  *doseLst) {
//   for (int i = 1; i < 3; ++i)
//   {
//     int j = timeLst[i];
//     int k;
//     for (k = i - 1; (k >= 0) && (j < timeLst[k]); k--)
//     {
//       timeLst[k + 1] = timeLst[k];
//       doseLst[k + 1] = doseLst[k];
//     }
//     timeLst[k + 1] = j;
//     doseLst[k + 1] = j;
//   }
