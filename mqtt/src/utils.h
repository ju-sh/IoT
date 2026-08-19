#pragma once

#include <Arduino.h>
#include <WiFi.h>
#include <PubSubClient.h>
#include <ESP32Encoder.h>

#include "config.h"
#include "globals.h"

void initPins();
void updateLEDs(int level);
void wifiConnect();
void wifiReconnect();
void initMqtt();
void initSineVals();
void writeSineVal();
void payloadToString(const byte* payload, unsigned int length, String& output);
void callback(char* topic, byte* payload, unsigned int length);
void processAnalogVal();
