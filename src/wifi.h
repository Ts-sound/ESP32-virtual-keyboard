#pragma once

#include <WiFiClient.h>
#include <WiFiServer.h>

#include <string>

class Wifi {
 public:

  void SetUp(std::string& ssid, std::string& password);

  bool IsConnect();

  std::string ServerRead();

  bool ServerWrite(const std::string& data);

 private:
  std::string ssid;
  std::string password;

  WiFiServer server = WiFiServer(80);
  WiFiClient client;
};