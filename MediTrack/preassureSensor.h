
#include "HX710B.h"
const int DOUT = 27;   //sensor data pin
const int SCLK  = 26;   //sensor clock pin
HX710B pressure_sensor;

int preassure = 0;

int getPreassure() {

  preassure = pressure_sensor.pascal();
  return preassure;

}
