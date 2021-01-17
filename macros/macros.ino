#include <Keyboard.h>

byte RXLED = 17;
bool flagLED = false;

int keys[] = {2, 3, 4, 
              5, 6, 7, 
              8, 9, 10, 16, 
              14, 15, 18, 19};
int numberTotalKeys = (sizeof(keys) / sizeof(keys[0]));

int modifierSequence[] = {KEY_LEFT_SHIFT, 
                          KEY_LEFT_CTRL, 
                          KEY_LEFT_ALT, 
                          KEY_LEFT_GUI};
int lenModifierSequence = (sizeof(modifierSequence) / sizeof(modifierSequence[0]));

void setup() {

  pinMode(RXLED, OUTPUT);

  Serial.begin(9600);
  Serial.println("Initialize Serial Monitor");

  Serial1.begin(9600);
  Serial1.println("Initialize Serial Hardware UART Pins");

  for (int i = 0; i < numberTotalKeys; i++) {
    pinMode(keys[i], INPUT);
    digitalWrite(keys[i], HIGH);
  }

  Keyboard.begin();
}

void loop() {

  for (int i = 0; i < numberTotalKeys; i++) {
    if (digitalRead(keys[i]) == LOW) {

      digitalWrite(RXLED, HIGH);
      handleKeyStroke(i);
      digitalWrite(RXLED, LOW);
    }
  }
}

void sendModifierSequence () {
  
  for (int i = 0; i < lenModifierSequence; i++) {
    Keyboard.press(modifierSequence[i]);
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

  sendModifierSequence();

  switch (keyIndex) {
    case 0:
      // shortcut: shift ctrl alt gui 0
      Keyboard.press('0');
      break;

    case 1:
      // shortcut: shift ctrl alt gui 1
      Keyboard.press('1');
      break;

    case 2:
      // shortcut: shift ctrl alt gui 2
      Keyboard.press('2');
      break;

    case 3:
      // shortcut: shift ctrl alt gui 3
      Keyboard.press('3');
      break;

    case 4:
      // shortcut: shift ctrl alt gui 4
      Keyboard.press('4');
      break;

    case 5:
      // shortcut: shift ctrl alt gui 5
      Keyboard.press('5');
      break;

    case 6:
      // shortcut: shift ctrl alt gui 6
      Keyboard.press('6');
      break;

    case 7:
      // shortcut: shift ctrl alt gui 7
      Keyboard.press('7');
      break;

    case 8:
      // shortcut: shift ctrl alt gui 8
      Keyboard.press('8');
      break;

    case 9:
      // shortcut for locking windows: win l
      Keyboard.press(KEY_LEFT_GUI);
      Keyboard.press('l');
      break;

    case 10:
      // shortcut: shift ctrl alt gui a
      Keyboard.press('a');
      break;

    case 11:
      // shortcut: shift ctrl alt gui b
      Keyboard.press('b');
      break;

    case 12:
      // shortcut: shift ctrl alt gui c
      Keyboard.press('c');
      break;

    case 13:
      // shortcut for locking mac: shift command l
      Keyboard.press('l');
      break;
  }

  delay(100);
  Keyboard.releaseAll();
}
