#pragma once

#include <Arduino.h>
#include <WiFi.h>
#include <PubSubClient.h>
//#include <ESP32Encoder.h>
#include "config.h"

extern PubSubClient client;
//extern ESP32Encoder encoder;

extern int lastInpVal;
extern uint8_t sineTable[SINE_SAMPLES];
extern size_t sineTableIdx;
