
int yPos;
int xPos;
int trayPos;
int noOfEntries = 0;
int timeNow = 0;
int slot1 = 0, slot2 = 0, slot3 = 0, slot4 = 0, slot5 = 0, slot6 = 0, slot7 = 0, slot8 = 0;
unsigned long long entry1, entry2, entry3;
unsigned long long time1, time2, time3;
long int dose1, dose2, dose3;
long int timeList[3];
unsigned long long doseList[3];
int currTime;
int limit1 = 0, limit2 = 0, limit3 = 0;
int trayLoc = 1800;
float val;
int err = 0;
int crntPos = 130;
int newPos = 0;
int servoPos;
int dropX = 10;
int dropY = 1000;
const int stepsPerRevolution = 2048;
int ready = 0;
int settings = 0;
int slotNo = 0;
int wifikey = 0;

unsigned long long int value;  //firebase reading

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <WiFi.h>
#include <EEPROM.h>
#include <WebServer.h>

const char* ssid = "wedha";          // Replace with your WiFi SSID
const char* password = "123456789";  // Replace with your WiFi password
const int eepromSize = 512;          // Adjust this based on the ESP32 board's EEPROM size

WebServer server(80);

#define SCREEN_WIDTH 128  // OLED display width, in pixels
#define SCREEN_HEIGHT 32  // OLED display height, in pixels

#define OLED_RESET -1        // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C  ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

#define NUMFLAKES 10  // Number of snowflakes in the animation example

#define LOGO_HEIGHT 16
#define LOGO_WIDTH 16

static const unsigned char PROGMEM logo_bmp[] = { 0b00000000, 0b11000000,
                                                  0b00000001, 0b11000000,
                                                  0b00000001, 0b11000000,
                                                  0b00000011, 0b11100000,
                                                  0b11110011, 0b11100000,
                                                  0b11111110, 0b11111000,
                                                  0b01111110, 0b11111111,
                                                  0b00110011, 0b10011111,
                                                  0b00011111, 0b11111100,
                                                  0b00001101, 0b01110000,
                                                  0b00011011, 0b10100000,
                                                  0b00111111, 0b11100000,
                                                  0b00111111, 0b11110000,
                                                  0b01111100, 0b11110000,
                                                  0b01110000, 0b01110000,
                                                  0b00000000, 0b00110000 };

#include "connectFirebase.h"
#include "steppers.h"
#include "limitSw.h"
#include "servo.h"
#include "calibrate.h"
#include "medTray.h"
#include "getTime.h"
#include "getVals.h"
#include "preassureSensor.h"
#include "vaccum.h"
#include "shake.h"
#include "pickNplace.h"
#include "sort.h"
#include "refill.h"
#include "webServer.h"
#include "buzz.h"



void setup() {
  // Serial.begin(9600);
  // Serial.begin(115200);

  // EEPROM.begin(eepromSize);

  // // EEPROM.put(0, wifikey);
  // // EEPROM.commit();
  // EEPROM.get(0, wifikey);

  if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    // Serial.println(F("SSD1306 allocation failed"));
    for (;;)
      ;  // Don't proceed, loop forever
  }

  // Show initial display buffer contents on the screen --
  // the library initializes this with an Adafruit splash screen.
  // display.display();
  // delay(2000);  // Pause for 2 seconds

  // Clear the buffer
  display.clearDisplay();

  // Draw a single pixel in white
  // display.drawPixel(10, 10, SSD1306_WHITE);?

  // Show the display buffer on the screen. You MUST call display() after
  // drawing commands to make them visible on screen!
  display.display();
  delay(2000);

  display.invertDisplay(false);
  delay(1000);

  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);

  pinMode(speakerPin, OUTPUT); 

  for(int period = 15289; period >= 477; period = period / 2)
  {
    playTone(period, 200);  

  display.clearDisplay();
  display.print(F("starting..."));
  display.display();
  delay(2000);

  display.setTextSize(1);

  ///////////////////////////////////////////////////
  // display.clearDisplay();
  // display.println(wifikey);
  // display.display();
  // delay(2000);

  // if (wifikey < 5) {
  //   serverBegin();
  //   serverr();
  // }

  // EEPROM.get(1, gotVariables);
  // display.clearDisplay();
  // display.println(gotVariables.var2);
  // display.println(gotVariables.var3);
  // display.display();

  /////////////////////////////////////////////////

  pressure_sensor.begin(DOUT, SCLK);

  pinMode(27, OUTPUT);
  
  }

  // servo.attach(SERVO_PIN);

  tray.setSpeed(15);
  x_axis.setSpeed(15);
  y_axis.setSpeed(15);

  // liftTillUp();

  calibrate();

  connectFire();


}

void loop() {
  // connectFire();
  readVals();
  // WiFi.disconnect(true);
  // WiFi.mode(WIFI_OFF);
  // // WiFi.disconnect();
  // // WiFi.mode(WIFI_OFF);
  // Stepper y_axis(stepsPerRevolution, 15, 4, 16, 2);

  // Serial.print("time1: ");
  // Serial.print(time1);
  // Serial.print("  ");
  // Serial.print(slot1);
  // Serial.print("  ");
  // Serial.print(slot2);
  // Serial.print("  ");
  // Serial.print(slot3);
  // Serial.print("  ");
  // Serial.print(slot4);
  // Serial.print("  ");
  // Serial.print(slot5);
  // Serial.print("  ");
  // Serial.print(slot6);
  // Serial.print("  ");
  // Serial.print(slot7);
  // Serial.print("  ");
  // Serial.println(slot8);
  if (settings == 0) {
    WiFi.disconnect(true);
    WiFi.mode(WIFI_OFF);
    // WiFi.disconnect();
    // WiFi.mode(WIFI_OFF);
    Stepper y_axis(stepsPerRevolution, 15, 4, 16, 2);
    display.clearDisplay();
    display.setCursor(0, 0);
    display.print(F("Sorting!!"));
    display.display();
    sort();
    distribute();
    connectFire();
  } else if (settings == 1) {
    display.clearDisplay();
    display.setCursor(0, 0);
    display.print(F("Refill!!"));
    display.display();
    refill();
  } else {
    display.clearDisplay();
    display.setCursor(0, 0);
    display.print(F("Error!!"));
    display.display();
  }
}
