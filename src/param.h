#pragma once

#include <string>

class Param {
 public:
  static void SetUp();

  static std::string GetWifiName();
  static std::string GetWifiPassword();
  static void SetWifiName(std::string & name);
  static void SetWifiPassword(std::string & password);
};
