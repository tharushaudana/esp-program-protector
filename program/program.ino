#include "security.h"

void setup() {
  security_barier();

  // program setup code here...

  Serial.begin(115200); 
}

void loop() {
  Serial.println("Hello World");
  delay(1000);
}
