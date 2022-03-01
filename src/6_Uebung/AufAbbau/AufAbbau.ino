/*
  Autor:  Benedikt Walter
  Klasse: 2AHELS
  Titel:  Auf/Abbau
  Datum:  28.2.2022
*/

#define DELAY 500

unsigned long long millistime = 0, counter = 0;

void setup() {
  DDRA = 0xff;
  PORTA = 0x00;
}

void loop() {
  if(millis() - millistime > DELAY) {
    counter++;
    if(counter == 16) {
      PORTA = 0x00;
      counter = 0;
    }
    if(counter < 8)
      PORTA = 0xff << (8-counter);
    else
      PORTA = 0xff >> (counter-8);
    millistime = millis();
  }
}
