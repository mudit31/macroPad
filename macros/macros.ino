#include <Keyboard.h>

byte RXLED = 17;
bool flagLED = false;

// pin layout as wired
int keys[] = {15, 8, 9,
              10, 5, 6,
              7, 4, 3, 2,
              14, 18, 19, 16};
int numberTotalKeys = (sizeof(keys) / sizeof(keys[0]));

int modifierSequence[] = {KEY_LEFT_SHIFT, 
                          KEY_LEFT_CTRL, 
                          KEY_LEFT_ALT, 
                          KEY_LEFT_GUI};
int lenModifierSequence = (sizeof(modifierSequence) / sizeof(modifierSequence[0]));

// setup does one time initialization
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

// loop is the one that does actual work
void loop() {

  for (int i = 0; i < numberTotalKeys; i++) {
    if (digitalRead(keys[i]) == LOW) {

      digitalWrite(RXLED, HIGH);
      handleKeyStroke(i);
      digitalWrite(RXLED, LOW);
    }
  }
}

// sendModifierSequence sends modifier keys set in 
// modifierSequence array
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
    case 10:
      Keyboard.press('a');
      break;

    case 11:
      Keyboard.press('b');
      break;

    case 12:
      Keyboard.press('c');
      break;

    case 13:
      Keyboard.press('d');
      break;

    default:
      Keyboard.press(keyIndex);
      break;
  }

  delay(100);
  Keyboard.releaseAll();
}
