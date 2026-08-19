#pragma once

namespace Pins {
    inline static constexpr uint8_t SDA = 21;
    inline static constexpr uint8_t SCL = 22;
};


namespace Lcd {
    inline static constexpr uint8_t ROWS = 2;
    inline static constexpr uint8_t COLS = 16;

    // Address: Most modules use 0x27 or 0x3F
    inline static constexpr uint8_t ADDR = 0x27;
};


