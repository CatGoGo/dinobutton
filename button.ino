#include "DigiKeyboard.h"

int btn;
int timenum;
void setup() {
  pinMode(1, INPUT);
  pinMode(2, OUTPUT);
  digitalWrite(2, HIGH);
  btn = 0;
  timenum = 0;
}
void loop() {

  timenum += 1;


  if (timenum > 100) {
    timenum = 0;
    if (btn > 0 && btn < 30) {
      DigiKeyboard.sendKeyStroke(0);
      DigiKeyboard.sendKeyStroke(KEY_SPACE);
    }
    if (btn > 30 && btn < 80) {
      DigiKeyboard.sendKeyStroke(0);
      DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
      DigiKeyboard.delay(1000);
      DigiKeyboard.println("chrome.exe");
      DigiKeyboard.delay(1000);
      DigiKeyboard.println("chrome://dino");
    }
    if (btn > 80) {
      DigiKeyboard.sendKeyStroke(0);
      DigiKeyboard.sendKeyStroke(KEY_F4, MOD_ALT_LEFT);
    }
    btn = 0;
    timenum = 0;
  }


  if (digitalRead(1) == HIGH) {
    btn += 1;
    DigiKeyboard.delay(10);
  }

}
