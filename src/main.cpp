#include <Arduino.h>

#include "aircraft.h"
#include "app_config.h"
#include "board_config.h"

namespace {

void printBanner() {
    Serial.println();
    Serial.println("========================================");
    Serial.printf("        %s\n", AppConfig::DEVICE_NAME);
    Serial.println("========================================");
}

void printHardwareStatus() {
    Serial.printf("Board: %s\n", BoardConfig::BOARD_NAME);
    Serial.printf("SKU: %s\n", BoardConfig::BOARD_SKU);
    Serial.printf("PCB revision: %s\n", BoardConfig::PCB_REVISION);
    Serial.printf(
        "Target display: %ux%u\n",
        BoardConfig::SCREEN_WIDTH,
        BoardConfig::SCREEN_HEIGHT
    );

    if (!BoardConfig::DISPLAY_PROFILE_TESTED) {
        Serial.println("DISPLAY DISABLED: V1.1 display profile has not been hardware-tested.");
        Serial.println("Serial and radar calculation tests will continue safely.");
    }
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
        AppConfig::DEFAULT_LATITUDE,
        AppConfig::DEFAULT_LONGITUDE,
        testAircraft,
        AppConfig::DEFAULT_RADIUS_KM,
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

}  // namespace

void setup() {
    Serial.begin(115200);
    delay(1200);

    printBanner();
    printHardwareStatus();
    runProjectionSelfTest();

    Serial.printf(
        "First-boot demonstration mode: %s\n",
        AppConfig::DEMO_MODE_ON_FIRST_BOOT ? "enabled" : "disabled"
    );
    Serial.println("Firmware scaffold started successfully.");
}

void loop() {
    delay(1000);
}
