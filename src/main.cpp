#include <Arduino.h>

#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>
#include <Hash.h>

#define BAUD 115200
#define PORT 81
#define SSID "VirtualSensors"

// Forward declarations
void setupWifi();

void setup()
{
  delay(1000); // not so fast...

  Serial.begin(BAUD);
  Serial.setDebugOutput(true);

  Serial.println();
  Serial.println();
  Serial.println();

  // Setup WIFI
  Serial.println("setup");
  setupWifi();

  Serial.println("Ready");
}

void loop()
{
}

void setupWifi()
{
  for (uint8_t t = 4; t > 0; t--)
  {
    Serial.printf("[SETUP] BOOT WAIT %d...\n", t);
    Serial.flush();
    delay(1000);
  }

  Serial.println("Connecting");

  WiFi.mode(WIFI_AP);
  WiFi.softAP(SSID); // Start the access point
  Serial.print("Access Point \"");
  Serial.print(SSID);
  Serial.println("\" started");

  Serial.print("IP address:\t");
  Serial.println(WiFi.softAPIP());
}
