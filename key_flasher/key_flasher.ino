#include <EEPROM.h>
#include "security.h"

void setup() {
  Serial.begin(115200);
  EEPROM.begin(512);

  Serial.println();
  Serial.println();

  flash_key();

  //Serial.println("======================================================");
  //Serial.println("#define SECURITY_KEY \"" + gen_security_key() + "\"");
  //Serial.println("======================================================");
}

void loop() {
  //...
}
