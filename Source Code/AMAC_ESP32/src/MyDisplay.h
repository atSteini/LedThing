#include <Arduino.h>
#include <Wire.h>

#include "SSD1306Wire.h"

SSD1306Wire display(0x3c, SDA, SCL);

const uint8_t *font;

void printDisplay(String s) {
  display.clear();

  display.println(s);

  display.display();
}

SSD1306Wire getDisplay() {
  return display;
}

void setFont(const uint8_t *fontData) {
  font = fontData;
  display.setFont(font);
}

void initDisplay() {
  display.init();

  display.flipScreenVertically();
  setFont(ArialMT_Plain_10);
}