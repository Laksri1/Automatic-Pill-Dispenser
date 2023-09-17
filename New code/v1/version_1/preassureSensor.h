
#include "HX710B.h"

const int DOUT = 26;   //sensor data pin
const int SCLK  = 25;   //sensor clock pin

HX710B pressure_sensor; 

float preassure = 0;

float getPreassure() {
  delay(2000);
  if (pressure_sensor.is_ready()) {
  preassure = pressure_sensor.pascal();
  }
  // display.clearDisplay();
  // display.setCursor(0, 0);
  // display.print(F("Preasure : "));
  // display.print(preassure);
  // display.display();
  // Serial.print("preasure: ");
  // Serial.println(preassure);
  return 700;

}
