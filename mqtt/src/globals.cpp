#include <Arduino.h>
#include <WiFi.h>
#include <PubSubClient.h>
//#include <ESP32Encoder.h>
#include "config.h"

WiFiClient espClient;
PubSubClient client(espClient);
//ESP32Encoder encoder;

int lastInpVal = 0;
uint8_t sineTable[SINE_SAMPLES];
size_t sineTableIdx = 0;

