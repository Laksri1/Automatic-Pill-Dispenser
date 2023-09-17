

struct Variables {
  char var1[20];
  char var2[20];
  char var3[20];
};

Variables myVariables;
Variables gotVariables;

void handleRoot() {
  String html = "<html><body>";
  html += "<h1>VEDHA</h1>";
  html += "<form method='post' action='/save'>";
  html += "SSID: <input type='text' name='var1'><br>";
  html += "Password: <input type='text' name='var2'><br>";
  html += "<input type='submit' value='Save'>";
  html += "</form>";
  html += "</body></html>";
  server.send(200, "text/html", html);
}

void handleSave() {
  strncpy(myVariables.var2, server.arg("var2").c_str(), sizeof(myVariables.var2));
  strncpy(myVariables.var3, server.arg("var3").c_str(), sizeof(myVariables.var3));

  // Save to EEPROM
  // EEPROM.begin(eepromSize);
  EEPROM.put(1, myVariables);
  wifikey = 100;
  EEPROM.put(0, wifikey);
  EEPROM.commit();

  // Serial print the storing variables
  Serial.println("Variables saved:");
  Serial.print("Variable 1: ");
  Serial.println(myVariables.var2);
  Serial.print("Variable 2: ");
  Serial.println(myVariables.var3);

  server.send(200, "text/plain", "Variables saved successfully.");
}

void handleGetVariables() {
  // Read from EEPROM
  // EEPROM.begin(eepromSize);
  EEPROM.get(1, myVariables);

  // Send the variables as a JSON response
  String json = "{";
  json += "\"var1\": " + String(myVariables.var2) + ",";
  json += "\"var2\": " + String(myVariables.var3) + ",";
  json += "}";

  server.send(200, "application/json", json);
}


void serverr() {
  while (EEPROM.get(0, wifikey) < 5) {
    EEPROM.get(1, gotVariables);
    server.handleClient();
    display.clearDisplay();
    display.println(gotVariables.var2);
    display.println(gotVariables.var3);
    display.display();
  }
  ESP.restart();
}

void serverBegin() {
  WiFi.softAP(ssid, password);  // Create WiFi access point, ESP32 acts as the server

  IPAddress IP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(IP);

  server.on("/", handleRoot);
  server.on("/save", handleSave);
  server.on("/getVariables", handleGetVariables);

  server.begin();
  Serial.println("HTTP server started");
}