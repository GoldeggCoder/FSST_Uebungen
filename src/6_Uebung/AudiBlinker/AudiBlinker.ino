/*
  Autor:  Benedikt Walter
  Klasse: 2AHELS
  Titel:  Audi Blinker
  Datum:  28.2.2022
*/

#define START_BITMUSTER 0b00000000
#define DELAY 150

char currentBitmuster = 0b10000000;
unsigned long long millistime = 0, counter = 0;

void setup() {
  DDRA = 0xff;
  PORTA = START_BITMUSTER;
}

void loop() {
  if(millis() - millistime > (DELAY - (counter*10))) {
    PORTA |= currentBitmuster;
    counter++;
    currentBitmuster >>= 1;

    if(counter == 9) {
      currentBitmuster = 0b10000000;
      PORTA = 0x00;
      counter = 0;
    }
    millistime = millis();
  }
}
