/**
 * This example turns the ESP32 into a Bluetooth LE mouse that continuously
 * moves the mouse.
 */

#include <Arduino.h>
#include <cJSON.h>

#include "BleMouse.h"
#include "wifi.h"

class Wifi wifi;

void setup() {
  Serial.begin(115200);
  Serial.println("Starting work!");
  wifi.SetUp("T", "12345678");
}

void loop() {
  while (wifi.IsConnect()) {
    auto s = wifi.ServerRead();
    if (s != "") {
      Serial.println("read : %s"s.c_str());
      wifi.ServerWrite(s);
    }
    delay(500);

    delay(50*1000);
  }
}