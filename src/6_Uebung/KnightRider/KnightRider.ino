/*
  Autor:  Benedikt Walter
  Klasse: 2AHELS
  Titel:  Knight Rider
  Datum:  28.2.2022
*/

#define START_BITMUSTER 0b11000000
#define DELAY 500

unsigned long long millistime = 0, counter = 0, direction = 0;

void setup() {
  DDRA = 0xff;
  PORTA = START_BITMUSTER;
}

void loop() {
  if(millis() - millistime > DELAY) {
    if(direction == 0) {
      PORTA >>= 1;
      counter++;
    }
    else {
      PORTA <<= 1;
      counter--;
    }

    if(counter == 0 || counter == 6) {
      direction = !direction;
    }
    millistime = millis();
  }
}
