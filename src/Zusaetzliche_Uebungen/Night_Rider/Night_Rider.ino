#define BITMUSTER 0b11000000
#define DELAY 500

unsigned long long millistime = 0, counter = 0;

void setup() {
  DDRA = 0xff;
}

void loop() {
  if(millis() - millistime > DELAY) {
    PORTA = BITMUSTER >> counter%8;
    counter++;
    millistime = millis();
  }
}