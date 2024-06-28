# ESP Program Security Guard

A simple but powerful method to prevent copying the program binary file from ESP devices and reflashing it to another ESP device.

## How to Use

1. **Clone the Repository**

   ```sh
   git clone https://github.com/tharushaudana/esp-program-protector.git
   cd esp-program-protector
   ```

2. **Upload `key_flasher` Code**

   Upload the `key_flasher` code to your ESP device. This will generate a unique key for the device (using the chip ID and flash chip ID) and write it to EEPROM.

3. **Add `security_barier()` to Your Program**

   In your program code, add `security_barier()` at the beginning of the `void setup()` function. Then, upload your program code. See `program/program.ino` for an example.

   ```cpp
   void setup() {
       security_barier();
       // Your setup code here
   }
   ```

## How It Works

1. **Key Generation**

   When you upload the `key_flasher` code, it generates a unique key for the device using the chip ID and flash chip ID. This key is then written to EEPROM.

2. **Key Validation**

   In your program code, `security_barier()` reads the stored key from EEPROM and compares it with the device's actual key. If the key is valid, the program continues to run. If the key is not valid (or not written), the program will not continue.

## Custom Key Generation

You can use your own unique key generation method or algorithm to generate your own key type. Simply modify the `gen_security_key()` in the `security.h` files.

## Conclusion

We hope this simple method helps you secure your program from being copied and flashed onto unauthorized ESP devices.

---

Feel free to contribute to this project or report any issues you encounter. Your feedback is valuable in improving the security and functionality of this guard method.
