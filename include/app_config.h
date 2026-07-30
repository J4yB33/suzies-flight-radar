#pragma once

#include <Arduino.h>

namespace AppConfig {

constexpr char DEVICE_NAME[] = "Suzie's Flight Radar";
constexpr char SETUP_AP_NAME[] = "Suzies-Radar-Setup";
constexpr char MDNS_HOSTNAME[] = "suzies-radar";

// Defaults only. The finished application will allow these values to be
// changed on the touchscreen and stored in ESP32 non-volatile storage.
constexpr double DEFAULT_LATITUDE = 54.5460;
constexpr double DEFAULT_LONGITUDE = -1.7050;
constexpr float DEFAULT_RADIUS_KM = 100.0F;
constexpr uint32_t AUTHENTICATED_REFRESH_MS = 25000;
constexpr uint32_t ANONYMOUS_REFRESH_MS = 240000;

// Demonstration mode makes the interface usable before Wi-Fi and OpenSky are
// configured. It must remain available for testing and public demonstrations.
constexpr bool DEMO_MODE_ON_FIRST_BOOT = true;

}  // namespace AppConfig
