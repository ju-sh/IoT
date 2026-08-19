#pragma once

namespace Pins {
    // GPIO pins
    inline static constexpr uint8_t SERVO = 18;

    // Probably not a good idea to use this pin.
    // Active LOW, goes to GND when pressed.
    inline static constexpr uint8_t BUTTON = 0;
};


namespace ServoMotor {
    // Min pulse width
    // A pulse of 500 µs => servo moves to 0 degrees
    inline static constexpr int MIN_PW = 500;

    // Max pulse width
    // A pulse of 2400 µs => servo moves to 180 degrees
    inline static constexpr int MAX_PW = 2400;

    // Rate at which how often control signal (as PWM) is sent to servo
    inline static constexpr int FREQ = 50;
};

