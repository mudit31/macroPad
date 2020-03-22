#include <Keyboard.h>

byte RXLED = 17;
bool flagLED = false;

int numberTotalKeys = 14;
int keys[] = {2, 3, 4, 5, 6, 7, 8, 9,
              10, 16, 14, 15, 18, 19
             };

void setup() {

  pinMode(RXLED, OUTPUT);

  Serial.begin(9600);
  Serial.println("Initialize Serial Monitor");

  Serial1.begin(9600);
  Serial1.println("Initialize Serial Hardware UART Pins");

  for (int i = 0; i <= numberTotalKeys; i++) {
    pinMode(keys[i], INPUT);
    digitalWrite(keys[i], HIGH);
  }

  Keyboard.begin();
  flipLED();
}

void loop() {

  for (int i = 0; i <= numberTotalKeys; i++) {
    if (digitalRead(keys[i]) == LOW) {
      flipLED();

      handleKeyStroke(i);

      delay(100);
      Keyboard.releaseAll();
      flipLED();
      delay(1000);
    }
  }
}

void handleKeyStroke (int keyIndex) {

  /*
     the layout looks like:
     02 01 00 ..
     03 04 05 ..
     06 07 08 09
     11 10 12 13
  */

  switch (keyIndex) {
    case 0:
      Keyboard.write('0');
      break;
    case 1:
      Keyboard.write('1');
      break;
    case 2:
      Keyboard.write('2');
      break;
    case 3:
      Keyboard.write('3');
      break;
    case 4:
      Keyboard.write('4');
      break;
    case 5:
      Keyboard.write('5');
      break;
    case 6:
      Keyboard.write('6');
      break;
    case 7:
      Keyboard.write('7');
      break;
    case 8:
      Keyboard.write('8');
      break;
    case 9:
      Keyboard.write('9');
      break;
    case 10:
      Keyboard.write('a');
      break;
    case 11:
      Keyboard.write('b');
      break;
    case 12:
      Keyboard.write('c');
      break;
    case 13:
      Keyboard.write('d');
      break;
  }



}


void flipLED() {

  Serial.println("flipping led");


  if (flagLED) {
    digitalWrite(RXLED, LOW);
    TXLED0;
  } else {
    digitalWrite(RXLED, HIGH);
    TXLED1;
  }
  flagLED = !flagLED;
}
