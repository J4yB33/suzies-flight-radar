#include <Arduino.h>
#include "aircraft.h"
#include "board_config.h"

namespace {
constexpr double TEST_STATION_LAT = 54.5460;
constexpr double TEST_STATION_LON = -1.7050;
constexpr float TEST_RADAR_RADIUS_KM = 100.0F;

void printBanner() {
    Serial.println();
    Serial.println("========================================");
    Serial.println("        SUZIE'S FLIGHT RADAR");
    Serial.println("========================================");
}

void runProjectionSelfTest() {
    const Aircraft testAircraft{
        "40621d",
        "BAW123",
        54.9000,
        -1.3000,
        31000.0F,
        447.0F,
        212.0F,
        false
    };

    const RadarPoint point = projectAircraft(
        TEST_STATION_LAT,
        TEST_STATION_LON,
        testAircraft,
        TEST_RADAR_RADIUS_KM,
        300,
        240,
        200
    );

    Serial.printf(
        "Projection test: %s, %.1f km, bearing %.1f deg, pixel (%d,%d), visible=%s\n",
        testAircraft.callsign.c_str(),
        point.distanceKm,
        point.bearingDegrees,
        point.x,
        point.y,
        point.visible ? "yes" : "no"
    );
}
}

void setup() {
    Serial.begin(115200);
    delay(1200);
    printBanner();

    Serial.printf("Target display: %ux%u\n", BoardConfig::SCREEN_WIDTH, BoardConfig::SCREEN_HEIGHT);

    if (!BoardConfig::HARDWARE_PROFILE_VERIFIED) {
        Serial.println("DISPLAY DISABLED: board pin mapping has not been verified.");
        Serial.println("Copy the RGB, touch and backlight values from the exact Elecrow factory example.");
    }

    runProjectionSelfTest();
    Serial.println("Firmware scaffold started successfully.");
}

void loop() {
    delay(1000);
}
