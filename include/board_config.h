#pragma once

#include <Arduino.h>

namespace BoardConfig {

constexpr char BOARD_NAME[] = "Elecrow CrowPanel Advance 5.0";
constexpr char BOARD_SKU[] = "DIS02050A";
constexpr char PCB_REVISION[] = "V1.1";

constexpr uint16_t SCREEN_WIDTH = 800;
constexpr uint16_t SCREEN_HEIGHT = 480;
constexpr uint8_t BACKLIGHT_DEFAULT = 220;

// The physical board revision has been confirmed from the PCB marking.
constexpr bool BOARD_IDENTITY_VERIFIED = true;

// Set true only after the RGB timing, GT911 touch mapping and V1.1 backlight
// control have been copied from Elecrow's matching factory example and tested
// on the physical panel.
constexpr bool DISPLAY_PROFILE_TESTED = false;

}  // namespace BoardConfig
