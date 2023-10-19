#include "wifi.h"

#include <WiFiClient.h>
#include <WiFiServer.h>
#include <WiFi.h>

Wifi::Wifi() {}

void Wifi::SetUp(std::string& ssid, std::string& password) {
  this->ssid = ssid;
  this->password = password;
  WiFi.setAutoReconnect(true);

    Serial.println();
    Serial.println();
    Serial.print("Connecting to ");
    Serial.println(ssid);

    WiFi.begin(ssid, password);

    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }


  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("local IP address: ");
  Serial.println(WiFi.localIP());

  server.begin();
  delay(500);
  client = server.available();  // listen for incoming clients
  delay(500);
}

bool Wifi::IsConnect() {
  switch (WiFi.status()) {
    case WL_NO_SSID_AVAIL:
      Serial.println("[WiFi] SSID not found");
      break;
    case WL_CONNECT_FAILED:
      Serial.print("[WiFi] Failed - WiFi not connected! Reason: ");
      break;
    case WL_CONNECTION_LOST:
      Serial.println("[WiFi] Connection was lost");
      break;
    case WL_SCAN_COMPLETED:
      Serial.println("[WiFi] Scan is completed");
      break;
    case WL_DISCONNECTED:
      Serial.println("[WiFi] WiFi is disconnected");
      break;
    case WL_CONNECTED:
      Serial.println("[WiFi] WiFi is connected!");
      Serial.print("[WiFi] IP address: ");
      Serial.println(WiFi.localIP());
      return true;
      break;
    default:
      Serial.print("[WiFi] WiFi Status: ");
      Serial.println(WiFi.status());
      break;
  }

  return false;
}

std::string Wifi::ServerRead() {
  char temp[65535];

  int len = client.read((uint8_t*)temp, sizeof(temp));

  if (len > 0)
    return std::string(temp, 0, len);
  else
    return std::string();
}

bool Wifi::ServerWrite(const std::string& data) {
  client.write(data.data(), data.size());
  return true;
}
