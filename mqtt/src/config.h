#pragma once

namespace Pins {
    // GPIO pins
    inline static constexpr uint8_t LED1 = 17;
    inline static constexpr uint8_t LED2 = 18;
    inline static constexpr uint8_t LED3 = 19;
    inline static constexpr uint8_t SINE_OUT = 25;
    inline static constexpr uint8_t SINE_IN = 35;
};


struct WifiCreds {
    // WiFi credentials
    inline static constexpr const char* SSID = "Tinker Space";
    inline static constexpr const char* PASSWORD = "123tinkerspace";
};

struct Mqtt {
    inline static constexpr const char* SERVER_IP = "192.168.10.108";
    inline static constexpr const int PORT = 1883;
    inline static constexpr const char* TOPIC = "home/knob/percentage";
};

inline constexpr unsigned long BAUD_RATE = 115200;
inline constexpr char OTA_NAME[10] = "esp32-dev";
inline constexpr uint8_t SINE_SAMPLES = 100;
//inline constexpr uint8_t SINE_SAMPLES = 64;

