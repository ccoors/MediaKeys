/*
  MediaKeys
*/
#define HID_CUSTOM_LAYOUT
#define LAYOUT_US_ENGLISH

#include "HID-Project.h"

void setup() {
  for (auto i = 2; i < 8; i++) {
    pinMode(i, INPUT_PULLUP);
  }

  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);

  Consumer.begin();
}

void setKey(int pin, uint16_t key) {
  if (digitalRead(pin) == LOW) {
    Consumer.press(key);
  } else {
    Consumer.release(key);
  }
}

void loop() {
  setKey(2, MEDIA_PLAY_PAUSE);
  setKey(3, MEDIA_STOP);
  setKey(4, MEDIA_PREVIOUS);
  setKey(5, MEDIA_NEXT);
  setKey(6, MEDIA_VOLUME_DOWN);
  setKey(7, MEDIA_VOLUME_UP);

  delay(50);
}
