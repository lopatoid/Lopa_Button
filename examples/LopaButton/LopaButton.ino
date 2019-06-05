// Created by lopatoid

#include <Lopa_Button.h>

#define DEBUG true
#define Serial if (DEBUG) Serial

#define PIN_BUTTON 10

Lopa::Button button1(PIN_BUTTON, INPUT_PULLUP);


void setup() {
  Serial.begin(9600);
}

void loop() {
  if (button1.onPressed())
    Serial.println("Button pressed");
  if (button1.onReleased())
    Serial.println("Button released");
  digitalWrite(LED_BUILTIN, button1.isPressed());
}

