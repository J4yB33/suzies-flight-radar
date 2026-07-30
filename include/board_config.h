#pragma once

#include <Arduino.h>

namespace BoardConfig {
constexpr uint16_t SCREEN_WIDTH = 800;
constexpr uint16_t SCREEN_HEIGHT = 480;
constexpr uint8_t BACKLIGHT_DEFAULT = 220;

// Hardware pins and RGB timing must be copied from the exact Elecrow
// CrowPanel Advance 5-inch DIS02050A-1 factory example before flashing.
// Keeping these values isolated prevents hardware changes affecting app logic.
constexpr bool HARDWARE_PROFILE_VERIFIED = false;
}
