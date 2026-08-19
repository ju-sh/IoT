#pragma once

namespace Pins {
    // GPIO pins
    inline static constexpr uint8_t FAN = 13;
    inline static constexpr uint8_t LIGHT = 14;
};


struct WifiCreds {
    // WiFi credentials
    inline static constexpr const char* SSID = "Tinker Space";
    inline static constexpr const char* PASSWORD = "123tinkerspace";
    //inline static constexpr const char* SSID = "FanIn";
    //inline static constexpr const char* PASSWORD = "fanfanfan";
};

inline constexpr unsigned long BAUD_RATE = 115200;
inline constexpr char OTA_NAME[10] = "esp32-dev";
