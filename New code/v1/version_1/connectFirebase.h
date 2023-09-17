//libriers for firebase
#include <WiFi.h>
#include <Firebase_ESP_Client.h>
#include <String.h>
//tokeen generation process
#include "addons/TokenHelper.h"
#include "addons/RTDBHelper.h"

//insert wifi credentials
#define WIFI_SSID "VenuraWifi"
#define WIFI_PASSWORD "notyabaya.com"

//insert project api key
#define API_KEY "AIzaSyDhjQiFCvXLotnVMuNR3u5Jiqsw2aKDyKA"

//insert project api key
#define API_KEY "AIzaSyDhjQiFCvXLotnVMuNR3u5Jiqsw2aKDyKA"

// Insert RTDB URLefine the RTDB URL */
#define DATABASE_URL "https://notyabaya-iot-default-rtdb.asia-southeast1.firebasedatabase.app/"

//Define Firebase Data object
FirebaseData fbdo;

FirebaseAuth auth;
FirebaseConfig config;

#define USER_EMAIL "shamalbandara14@gmail.com"
#define USER_PASSWORD "12345678"

unsigned long sendDataPrevMillis = 0;
String serial_no;       //device eke serial number eka passe one wenwa
bool signupOK = false;  //firebase

void connectFire() {
  //wifi connecting
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  // Serial.print("Connecting to Wi-Fi");
  while (WiFi.status() != WL_CONNECTED) {
    // Serial.print(".");
  //   display.clearDisplay();
  // display.print(F("."));
  // display.display();
    delay(300);
  }

  display.clearDisplay();
  display.print(F("Connecting to WIFI..."));
  display.display();
  // Serial.println();
  // Serial.print("Connected with IP: ");
  // Serial.println(WiFi.localIP());
  // Serial.println();

  /* Assign the api key (required) */
  config.api_key = API_KEY;

  // Assign the user sign in credentials
  auth.user.email = USER_EMAIL;
  auth.user.password = USER_PASSWORD;

  /* Assign the RTDB URL (required) */
  config.database_url = DATABASE_URL;

  /* Sign up */
  if (Firebase.signUp(&config, &auth, "", "")) {
    // Serial.println("auth ok");
    display.clearDisplay();
    display.print(F("Connected to Wifi"));
    display.display();
    signupOK = true;
  } else {
    display.clearDisplay();
    display.print(F("ERROR Connecting to Wifi"));
    display.display();
    //Serial.print("%s\n", config.signer.signupError.message.c_str());

  }

  /* Assign the callback function for the long running token generation task */
  config.token_status_callback = tokenStatusCallback;  //see addons/TokenHelper.h

  Firebase.begin(&config, &auth);
  Firebase.reconnectWiFi(true);
}