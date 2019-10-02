#include <EEPROM.h>

int addr = 0;

struct {
  uint8_t param1=1;
  uint8_t param2=1;
  uint8_t param3=0;
  uint8_t lum=255;
  uint8_t spd=1;
  uint8_t rVal=0;
  uint8_t gVal=0;
  uint8_t bVal=0;
  } data;

void setup() {
  // put your setup code here, to run once:
    EEPROM.begin(512);
    EEPROM.put(addr,data);
    EEPROM.commit();

}

void loop() {
  delay(10);

}
