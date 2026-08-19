#include <WiFi.h>
#include <ArduinoOTA.h>
#include <WebServer.h>

#include "WebInterface.h"
#include "consts.h"

WebInterface interface;

void OTASetup() {
    ArduinoOTA.setHostname(OTA_NAME);


    ArduinoOTA
        .onStart([]() {
           Serial.println("OTA Start");
        });


    ArduinoOTA
        .onStart([]() {
            Serial.println("OTA update started");
        })
        .onEnd([]() {
            Serial.println("\nOTA update finished");
        })
        .onProgress([](unsigned int progress, unsigned int total) {
            Serial.printf("Progress: %u%%\r", (progress / (total / 100)));
        })
        .onError([](ota_error_t error) {
            Serial.printf("OTA Error[%u]: ", error);
            if (error == OTA_AUTH_ERROR) {
                 Serial.println("Auth failed");
            } else if(error == OTA_BEGIN_ERROR) {
                 Serial.println("Begin failed");
            } else if(error == OTA_CONNECT_ERROR) {
                 Serial.println("Connect failed");
            } else if(error == OTA_RECEIVE_ERROR) {
                 Serial.println("Receive failed");
            } else if(error == OTA_END_ERROR) { 
                  Serial.println("End failed");
            }
        });

    /*
    ArduinoOTA.onStart([]() {
        Serial.println("OTA Start");
    });

    ArduinoOTA.onEnd([]() {
        Serial.println("OTA End");
    });
    */

    ArduinoOTA.begin();
}

void wifiSetupAP() {
    // Make a WiFi access point
    WiFi.mode(WIFI_AP);
    WiFi.softAP(WifiCreds::SSID, WifiCreds::PASSWORD);
    Serial.println("Wifi ON");
    Serial.print("Name: ");
    Serial.println(WifiCreds::SSID);
    Serial.print("Pswd: ");
    Serial.println(WifiCreds::PASSWORD);
 
    Serial.print("Web server address: ");
    Serial.println(WiFi.softAPIP());
}

void wifiSetupSTA() {
    // Make a WiFi STA. Connect to another WiFi.
    WiFi.mode(WIFI_STA);
    WiFi.begin(WifiCreds::SSID, WifiCreds::PASSWORD);
    Serial.print("Connecting to WiFi");

    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }

    Serial.println();
    Serial.println("WiFi connected!");
 
    Serial.print("IP address: ");
    Serial.println(WiFi.localIP());
}

void setup() {
    Serial.begin(BAUD_RATE);
    wifiSetupAP(); 
    //wifiSetupSTA(); 
    interface.begin();
}

void loop() {
    interface.getServer().handleClient();
     ArduinoOTA.handle();
}
