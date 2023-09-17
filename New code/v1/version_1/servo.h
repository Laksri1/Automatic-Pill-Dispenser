#include <ESP32Servo.h>

Servo servo;

#define SERVO_PIN 23

void distribute() {

  if (timeNow = currTime) {
    servo.attach(SERVO_PIN);
    servo.write(60);
    delay(500);
    pinMode(23, OUTPUT);
    ready = 0;
  }
}
