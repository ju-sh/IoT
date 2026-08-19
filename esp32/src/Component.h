#pragma once

#include<Arduino.h>

class Component {
    char name[10];
    uint8_t pin;
    bool state;

public:
    Component(
        const char* _name,
        uint8_t _pin,
        bool _state
    );

    const char* getName() const;
    uint8_t getPin() const;
    bool getState() const;

    bool flipState();
    void handleButton();
};
