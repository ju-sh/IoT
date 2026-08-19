#include<Arduino.h>
#include "consts.h"
#include "Component.h"

Component::Component(
    const char* _name,
    uint8_t _pin,
    bool _state
) : pin(_pin),
    state(_state) {
    strncpy(name, _name, sizeof(name) - 1);
}

uint8_t Component::getPin() const {
    return pin;
}

bool Component::getState() const {
    return state;
}

bool Component::flipState() {
    state = !state;
    return state;
}

void Component::handleButton() {
    snprintf(
        buff,
        sizeof(buff),
        "Button %s pressed",
        name
    );
    Serial.println(buff);

    flipState();
    digitalWrite(pin, state);
}
