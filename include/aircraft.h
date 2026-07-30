#pragma once

#include <Arduino.h>

struct Aircraft {
    String icao24;
    String callsign;
    double latitude;
    double longitude;
    float altitudeFeet;
    float speedKnots;
    float headingDegrees;
    bool onGround;
};

struct RadarPoint {
    int16_t x;
    int16_t y;
    float distanceKm;
    float bearingDegrees;
    bool visible;
};

RadarPoint projectAircraft(
    double stationLatitude,
    double stationLongitude,
    const Aircraft& aircraft,
    float radarRadiusKm,
    int16_t centreX,
    int16_t centreY,
    int16_t radiusPixels
);
