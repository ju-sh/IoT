#include "utils.h"


void initPins() {
    pinMode(Pins::LED1, OUTPUT);
    pinMode(Pins::LED2, OUTPUT);
    pinMode(Pins::LED3, OUTPUT);

    pinMode(Pins::SINE_OUT, OUTPUT);
    pinMode(Pins::SINE_IN, INPUT);
}

void updateLEDs(int level) {
    digitalWrite(Pins::LED1, level >=  8 ? HIGH : LOW);
    digitalWrite(Pins::LED2, level >= 18 ? HIGH : LOW);
    digitalWrite(Pins::LED3, level >= 25 ? HIGH : LOW);
    /*
    digitalWrite(Pins::LED1, level >= 33 ? HIGH : LOW);
    digitalWrite(Pins::LED2, level >= 66 ? HIGH : LOW);
    digitalWrite(Pins::LED3, level >= 99 ? HIGH : LOW);
    */
}

void wifiConnect() {
    // Connect to Wi-Fi
    WiFi.begin(WifiCreds::SSID, WifiCreds::PASSWORD);
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
    Serial.println("\nWiFi Connected!");
}

void wifiReconnect() {
    // Loop until we're reconnected to Mosquitto
    while (!client.connected()) {
        Serial.print("Attempting MQTT connection...");
        
        if (client.connect("ESP32_Level_Node")) {
            Serial.println("Connected to Mosquitto Broker!");
            
            client.subscribe(Mqtt::TOPIC);
            
        } else {
            Serial.print("Failed, rc=");
            Serial.print(client.state());
            Serial.println(" Retrying in 5 seconds...");
            delay(5000);
        }
    }
}

// Triggered when the esp32 receives a message on a subscribed topic
void callback(char* topic, byte* payload, unsigned int length) {
    String msg = "";
    payloadToString(payload, length, msg);

    if (String(topic) == Mqtt::TOPIC) {
        int level = msg.toInt();
        Serial.printf("[MQTT RX] Level received: %d%%\n", level);
        
        // Update LEDs according to received percentage
        updateLEDs(level);
    }
}

void initMqtt() {
    // Configure MQTT Server & Callback
    client.setServer(Mqtt::SERVER_IP, Mqtt::PORT);
    client.setCallback(callback);
}

void initSineVals() {
    for (int i = 0; i < SINE_SAMPLES; i++) {
      sineTable[i] = i;
    }
    /*
    // Pre-calculate the sine values (scaled from 0 to 255 for 8-bit DAC)
    for (int i = 0; i < SINE_SAMPLES; i++) {
      sineTable[i] = (uint8_t)((sin(i * 2.0 * PI / SINE_SAMPLES) + 1.0) * 127.5);
    }
     */
}

void writeSineVal() {
    dacWrite(Pins::SINE_OUT, sineTable[sineTableIdx]);
    sineTableIdx = (sineTableIdx + 1)%SINE_SAMPLES;
    delay(500);
    //delayMicroseconds(10000); // Adjust this delay to control frequency
    /*
    for (int i = 0; i < SINE_SAMPLES; i++) {
        dacWrite(Pins::SINE_OUT, sineTable[i]);
        delayMicroseconds(100); // Adjust this delay to control frequency
    }
    */
}

// Helper function: converts byte payload to String
void payloadToString(const byte* payload, unsigned int length, String& output) {
    output.reserve(length); // Optimize memory allocation
    for (unsigned int i = 0; i < length; i++) {
        output += (char)payload[i];
    }
}

void processAnalogVal() {
    // Read analog value
    int rawVal = analogRead(Pins::SINE_IN);

    // Normalize
    int inpVal = (rawVal / 4095.0) * 100;

    updateLEDs(inpVal);
    
    // Publish via MQTT ONLY when the percentage changes
    if (inpVal != lastInpVal) {
        lastInpVal = inpVal;

        String payload = String(inpVal);
        client.publish(Mqtt::TOPIC, payload.c_str());
        Serial.printf("[MQTT TX] Value percentage Published: %d%%\n", inpVal);
    }
}
