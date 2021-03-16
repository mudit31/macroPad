#include <Keyboard.h>
#include <Mouse.h>

byte RXLED = 17;

bool mouseShakerFlipfop = false;
bool mouseShakerOnOff = false;
int mouseMovementSize = 8; // between -128 and +127

// pin layout as wired
int keys[] = {15,  8,  9,
              10,  5,  6,
               7,  4,  3,  2,
              14, 18, 19, 16};
int numberTotalKeys = (sizeof(keys) / sizeof(keys[0]));
int numAsciiDifference = 48; // ascii code of '0' character

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
  Mouse.begin();
}

// loop is the one that does actual work
void loop() {

  for (int i = 0; i < numberTotalKeys; i++) {
    if (digitalRead(keys[i]) == LOW) {
      handleKeyStroke(i);
    }
  }

  voidHandleMouseVibrator();
}

void voidHandleMouseVibrator () {
  if (mouseShakerOnOff) {
    mouseShakerFlipfop = !mouseShakerFlipfop;

    if (mouseShakerFlipfop){
      Mouse.move(mouseMovementSize, mouseMovementSize, 0);
    } else {
      Mouse.move((-1 * mouseMovementSize), (-1 * mouseMovementSize), 0);
    }
    delay(200);
  }  
}

void handleKeyStroke (int keyIndex) {
  /*
     the layout looks like:
      7  8  9
      4  5  6
      1  2  3  d
      0  a  b  c
  */

  switch (keyIndex) {
    case 10:
      sendKeyCode('a');
      break;

    case 11:
      sendKeyCode('b');
      break;

    case 12:
      sendKeyCode('c');
      break;

    case 13:
      mouseShakerOnOff = !mouseShakerOnOff;
      if (mouseShakerOnOff) {
        turnLEDOn();
      } else {
        turnLEDOff();
      }
      Serial.println(mouseShakerOnOff);
      break;

    default:
      sendKeyCode(keyIndex + numAsciiDifference);
      break;
  }
  delay(500);
}

void sendKeyCode (char keyToSend) {
  sendModifierSequence();

  Keyboard.press(keyToSend);

  delay(500);
  Keyboard.releaseAll();
}

// sendModifierSequence sends modifier keys set in 
// modifierSequence array
void sendModifierSequence () {  
  for (int i = 0; i < lenModifierSequence; i++) {
    Keyboard.press(modifierSequence[i]);
  }
  delay(500);
  Keyboard.releaseAll();
}

void turnLEDOn () {
  digitalWrite(RXLED, LOW);
}

void turnLEDOff () {
  digitalWrite(RXLED, HIGH);
}
