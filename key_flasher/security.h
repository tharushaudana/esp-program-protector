#include <MD5.h>

MD5Builder md5;

String gen_security_key() {
  String id1 = String(ESP.getChipId());
  String id2 = String(ESP.getFlashChipId());

  md5.begin();
  md5.add(id1 + id2);
  md5.calculate();
  
  return md5.toString(); 
}

bool is_security_passed() {
  String key = gen_security_key();
  
  for (int i = 0; i < 32; i++) {
    char c = EEPROM.read(i);
    if (c != key.charAt(i)) return false;
  }
  
  return true;
}
