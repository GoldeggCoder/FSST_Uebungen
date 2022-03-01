/*
  Autor:  Benedikt Walter
  Klasse: 2AHELS
  Titel:  Auffüllen
  Datum:  28.2.2022
*/

#define DELAY 500

char bits = 0x00, savedBits = 0x00;
unsigned long long millistime = 0;

void setup() {
  DDRA = 0xff;
  PORTA = 0x00;
}

void loop() {
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < (8-i); j++) {
      bits = 0x80 >> j;
      PORTA = bits | savedBits;
      while(millis() - millistime < DELAY);
      millistime = millis();
    }
    savedBits |= bits;
  }
  bits = 0x00;
  savedBits = 0x00;
  PORTA = 0x00;
  while(millis() - millistime < DELAY);
  millistime = millis();
}
