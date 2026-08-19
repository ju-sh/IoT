#include <WebServer.h>
#include "consts.h"
#include "Component.h"
#include "WebInterface.h"

Component WebInterface::fan("fan", Pins::FAN, false);
Component WebInterface::light("light", Pins::LIGHT, false);
WebServer WebInterface::server(80);

void WebInterface::begin() {
    pinMode(fan.getPin(), OUTPUT);
    pinMode(light.getPin(), OUTPUT);

    server.on("/", handleRoot);
    server.on("/buttons", handleButtons);

    server.begin();
    Serial.println("Web server started");
}

WebServer& WebInterface::getServer() {
    return server;
}

// Route: /
void WebInterface::handleRoot() {
    // Use HTML from flash
    server.send_P(200, "text/html", HTML);
}

// Route: /buttons
void WebInterface::handleButtons() {
    String name = server.arg("name");
    snprintf(
        buff,
        sizeof(buff),
        "Button %s activated}",
        name
    );
    Serial.println(buff);
    if(name == "light") {
        fan.handleButton();
    } else {
        light.handleButton();
    }
    server.send(200, "text/plain", buff);
}
