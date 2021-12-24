//Libraries
#include <Arduino.h>

//My Libraries
#include "MySerial.h"
#include "MyDisplay.h"
#include "MyWifi.h"
#include "MyRotaryEncoder.h"
#include "MyLedStrip.h"

void onEncoderButtonPress();
void onEncoderValueChange();

void setup() {
  initSerial();

  //initDisplay();
  initLedStrip();
  //initDefaultWiFi();
}

void loop() {
  loopLedStrip();
}

void onEncoderButtonPress() {
  logSerial("Button pressed");
}

void onEncoderValueChange() {
  logSerial("Value changed!");
}