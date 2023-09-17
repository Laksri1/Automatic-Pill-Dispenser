#include <WiFi.h>
#include <EEPROM.h>
#include <WebServer.h>

const char* ssid = "wedha"; // Replace with your WiFi SSID
const char* password = "123456789"; // Replace with your WiFi password
const int eepromSize = 512; // Adjust this based on the ESP32 board's EEPROM size

WebServer server(80);

int ready = 0;
int ready2 = 0;

struct Variables {
  int var1;
  int var2;
  char var3[20];
};

Variables myVariables;
Variables gotVari;

void handleRoot() {
  String html = "<html><body>";
  html += "<h1>ESP32 Web Dashboard</h1>";
  html += "<form method='post' action='/save'>";
  html += "Variable 1: <input type='number' name='var1'><br>";
  html += "Variable 2: <input type='text' name='var2'><br>";
  html += "Variable 3: <input type='text' name='var3'><br>";
  html += "<input type='submit' value='Save'>";
  html += "</form>";
  html += "</body></html>";
  server.send(200, "text/html", html);
}

void handleSave() {
  myVariables.var1 = server.arg("var1").toInt();
  myVariables.var2 = server.arg("var2").toInt();
  strncpy(myVariables.var3, server.arg("var3").c_str(), sizeof(myVariables.var3));

  // Save to EEPROM
  EEPROM.begin(eepromSize);
  ready = 1;
  EEPROM.put(0, ready);
  EEPROM.put(1, myVariables);
  EEPROM.commit();

  // Serial print the storing variables
  Serial.println("Variables saved:");
  Serial.print("Variable 1: ");
  Serial.println(myVariables.var1);
  Serial.print("Variable 2: ");
  Serial.println(myVariables.var2);
  Serial.print("Variable 3: ");
  Serial.println(myVariables.var3);

  server.send(200, "text/plain", "Variables saved successfully.");
}

void handleGetVariables() {
  // Read from EEPROM
  EEPROM.begin(eepromSize);
  EEPROM.get(1, gotVari);

  // Send the variables as a JSON response
  String json = "{";
  json += "\"var1\": " + String(myVariables.var1) + ",";
  json += "\"var2\": " + String(myVariables.var2) + ",";
  json += "\"var3\": \"" + String(myVariables.var3) + "\"";
  json += "}";

  server.send(200, "application/json", json);
}

void setup() {
  Serial.begin(115200);

  WiFi.softAP(ssid, password); // Create WiFi access point, ESP32 acts as the server

  EEPROM.begin(eepromSize);

  IPAddress IP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(IP);

  server.on("/", handleRoot);
  server.on("/save", handleSave);
  server.on("/getVariables", handleGetVariables);

  server.begin();
  Serial.println("HTTP server started");
}

void loop() {
  server.handleClient();
  EEPROM.get(1, gotVari);
  EEPROM.get(0, ready2);
  Serial.print("ww: ");
  Serial.print(ready2);
  Serial.print("   1: ");
  Serial.print(gotVari.var1);
  Serial.print("   2: ");
  Serial.print(gotVari.var2);
  Serial.print("   3: ");
  Serial.println(gotVari.var3);
}
