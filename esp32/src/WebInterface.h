#pragma once

#include <WebServer.h>
#include "Component.h"
#include "consts.h"

class WebInterface {
private:
    static Component fan;
    static Component light;
    static WebServer server;

    static void handleRoot();
    static void handleButtons();
public:
    static void begin();
    static WebServer& getServer();
};


