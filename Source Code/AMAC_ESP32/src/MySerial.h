#include <Arduino.h>

int baudRate = 115200;
boolean enableDebug = true;

void printSerial(String s) {
    if (!enableDebug) {
        return;
    }

    Serial.print(s);
}

void logSerial(String s) {
    printSerial(s + "\n");
}

void beginSerial() {
    Serial.begin(baudRate);
    while (!Serial) {}
}

void endSerial() {
    Serial.end();
}

void setEnableDebug(boolean debug) {
    enableDebug = debug;

    if (enableDebug) {
        beginSerial();

        return;
    }

    endSerial();
}

boolean isEnabled() {
    return enableDebug;
}

void initSerial() {
    setEnableDebug(enableDebug);
}