#include <Arduino.h>
#include <Wire.h>
// #include <LiquidCrystal_I2C.h>
#include <I2C_LCD.h>

#include "config.h"

I2C_LCD lcd(Lcd::ADDR, &Wire);
//LiquidCrystal_I2C lcd(Lcd::ADDR, Lcd::COLS, Lcd::ROWS);

void setup() {
    Wire.begin(Pins::SDA, Pins::SCL);

    lcd.begin(Lcd::COLS, Lcd::ROWS); 

    //lcd.init();
    lcd.backlight();
    Serial.println("Backlight on");

    lcd.setCursor(0, 2);
    //lcd.setCursor(0, 0);
    lcd.print("ESP32 Ready");
    Serial.println("Msg displayed");
    delay(100000);

    lcd.setCursor(0, 1);
    //lcd.print("Hello!");
}

void loop() {
}
