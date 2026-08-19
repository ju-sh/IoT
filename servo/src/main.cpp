#include <Arduino.h>
#include <ESP32Servo.h>

#include "globals.h"
#include "config.h"

const int servoPin = 18;

void setup() {
    pinMode(Pins::BUTTON, INPUT_PULLUP);

    // Servo frequency
    servo.setPeriodHertz(ServoMotor::FREQ);

    servo.attach(
        Pins::SERVO,
        ServoMotor::MIN_PW,
        ServoMotor::MAX_PW
    );

    angle = 0;
    rising = true;

    servo.write(angle);
    delay(1000);
}

void updateAngle() {
    if(angle >= 175) {
        rising = false;
    } else if(angle <= 5) {
        rising = true;
    }

    if(rising) {
        angle += 10;
    } else {
        angle -= 10;
    }
}


void loop() {
    if (digitalRead(Pins::BUTTON) == LOW) {
        // Servo rotates only by 0-180 degrees
        updateAngle();
        servo.write(angle);
        Serial.println("Wrote +10 degrees");
    }

    // Let button debounce
    delay(100);

    /*
    // Move to 0°
    servo.write(0);
    delay(1000);

    // Move to 90°
    servo.write(90);
    delay(1000);

    // Move to 180°
    servo.write(180);
    delay(1000);
    */
}
