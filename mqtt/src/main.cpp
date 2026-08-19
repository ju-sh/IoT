#include <Arduino.h>
#include <WiFi.h>
#include <PubSubClient.h>
#include <ESP32Encoder.h>

#include "config.h"
#include "globals.h"
#include "utils.h"


void setup() {
    Serial.begin(115200);
    Serial.println("Set baude rate");
    delay(2000);

    initPins();
    Serial.println("Initialized pins");
    delay(2000);

    wifiConnect();
    Serial.println("Connected wifi");
    delay(2000);

    initMqtt();
    Serial.println("Initialized mqtt");
    delay(2000);

    initSineVals();
    Serial.println("Initialized sine values");
    delay(2000);

    // Force initial connection & subscription right in setup!
    wifiReconnect(); 
    Serial.println("re-Connected wifi");
    delay(2000);
}


void loop() {
    if (!client.connected()) {
        wifiReconnect();
    }
    client.loop();

    processAnalogVal();
    writeSineVal();
}
