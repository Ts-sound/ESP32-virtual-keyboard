#include "param.h"

#include "EEPROM.h"

#define MAX_SIZE 4096
#define POS(i) (i * 4)

typedef struct ParamInfo {
  int pos;
  int size;
}ParamInfo;

//
ParamInfo wifi_name = {POS(0), POS(4) - POS(0)};
ParamInfo password = {POS(4), POS(8) - POS(4)};
//

void Param::SetUp() { EEPROM.begin(MAX_SIZE); }
std::string Param::GetWifiName() {
   std::string s = EEPROM.readString(wifi_name.pos);
     return s; }

std::string Param::GetWifiPassword() {    std::string s = EEPROM.readString(password.pos);
     return s;  }

void Param::SetWifiName(std::string& name) {
    if(name.size()>wifi_name.size){
        Serial.println("SetWifiName size too long ");
    }

    EEPROM.writeString(wifi_name.pos,name);

}

void Param::SetWifiPassword(std::string& password) {
        if(password.size()>password.size){
        Serial.println("SetWifiPassword size too long ");
    }

    EEPROM.writeString(password.pos,name);

}
