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
     07 08 09 ..
     04 05 06 ..
     01 02 03  d
     00  a  b  c
  */
  // when shift ctrl alt gui + f is set to finder on macos,
  // this opens finder first, and then executes the macro. 
  // this helps keep the macro from executing any application
  // specific shorcuts.
  // this only helps when the macropad is used to launch applications.
  sendModifierSequence();
  Keyboard.press('f');
  delay(100);
  Keyboard.releaseAll();

  sendModifierSequence();

  switch (keyIndex) {
    case 0:
      Keyboard.press('9');
      break;

    case 1:
      Keyboard.press('8');
      break;

    case 2:
      Keyboard.press('7');
      break;

    case 3:
      Keyboard.press('4');
      break;

    case 4:
      Keyboard.press('5');
      break;

    case 5:
      Keyboard.press('6');
      break;

    case 6:
      Keyboard.press('1');
      break;

    case 7:
      Keyboard.press('2');
      break;

    case 8:
      Keyboard.press('3');
      break;

    case 9:
      Keyboard.press('d');
      break;

    case 10:
      Keyboard.press('a');
      break;

    case 11:
      Keyboard.press('0');
      break;

    case 12:
      Keyboard.press('b');
      break;

    case 13:
      Keyboard.press('c');
      break;
  }

  delay(100);
  Keyboard.releaseAll();
}
