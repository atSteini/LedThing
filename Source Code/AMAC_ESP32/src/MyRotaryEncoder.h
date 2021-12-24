#include <Arduino.h>

#include "AiEsp32RotaryEncoder.h"

const uint8_t ROTARY_ENCODER_DT_PIN = 18;
const uint8_t ROTARY_ENCODER_CLK_PIN = 5;
const uint8_t ROTARY_ENCODER_SW_PIN = 19;

const uint8_t ROTARY_ENCODER_STEPS = 4;

const int minValue = 0, maxValue = 100, useCircleValues = true, acceleration = 1;

AiEsp32RotaryEncoder rotaryEncoder = AiEsp32RotaryEncoder(ROTARY_ENCODER_DT_PIN, ROTARY_ENCODER_CLK_PIN, ROTARY_ENCODER_SW_PIN, -1, ROTARY_ENCODER_STEPS);
unsigned long lastTimePressed = 0;
    
void (*onButtonPress)();
void (*onValueChange)();

int getEncoderValue() {
    return rotaryEncoder.readEncoder();
}

void valueChanged() {
    logSerial(getEncoderValue() + "");
}

void buttonPress() {
    if (millis() - lastTimePressed < 200) {
        return;
    }

    lastTimePressed = millis();

    logSerial(getEncoderValue() + "");
}

void IRAM_ATTR readEncoderISR() {
    rotaryEncoder.readEncoder_ISR();
}

void handleEncoder() {
    if (rotaryEncoder.encoderChanged()) {
        valueChanged();
    }

    if (rotaryEncoder.isEncoderButtonClicked()) {
        buttonPress();
    }
}

void initRotaryEncoder(void (*onButtonPress)(), void (*onValueChange)()) {
    onButtonPress = onButtonPress;
    onValueChange = onValueChange;

    rotaryEncoder.begin();
    rotaryEncoder.setup(readEncoderISR);

    rotaryEncoder.setBoundaries(minValue, maxValue, useCircleValues);
    rotaryEncoder.setEncoderValue(minValue);

    rotaryEncoder.setAcceleration(acceleration);
}