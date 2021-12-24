#include <Arduino.h>

#include <WiFi.h>

const char* DEFAULT_SSID = "<WIFI_SSID>";
const char* DEFAULT_PSK = "<WIFI_PSK>";

const int timeOut = 5000; //ms
const int loopDelay = 500;  //ms

char* ssid, psk;

int initWiFi(const char* ssid, const char* psk) {
    ssid = ssid;
    psk = psk;

    printSerial("Connecting to WiFi ");
    printSerial(ssid);

    WiFi.begin(ssid, psk);

    int timeOutCounter = timeOut;
    while (((timeOutCounter -= loopDelay) > 0) && WiFi.status() != WL_CONNECTED) {
        printSerial(".");

        delay(loopDelay);
    }

    logSerial("");

    if (WiFi.status() == WL_CONNECTED) {
        logSerial("Connected");
    } else {
        logSerial("Error connecting. Connection timeout.");
    }

    return WiFi.status();
}

int initDefaultWiFi() {
    return initWiFi(DEFAULT_SSID, DEFAULT_PSK);
}
