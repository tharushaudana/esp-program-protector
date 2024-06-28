void flash_key() {
  String key = gen_security_key();

  for (int i = 0; i < 32; i++) {
    EEPROM.write(i, key.charAt(i));
  }

  if (EEPROM.commit()) {
    Serial.println(">>> SECURITY KEY FLASHED.");
    Serial.println(">>> CHECKING...");
    if (is_security_passed()) {
      Serial.println(">>> SUCCESSFULLY. DEVICE IS SECURED NOW!");
    } else {
      Serial.println(">>> UNKNOWN ERROR!");
    }
  } else {
    Serial.println(">>> FLASH ERROR");
  }
}
