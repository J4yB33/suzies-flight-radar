#include "aircraft.h"
#include <math.h>

namespace {
constexpr double EARTH_RADIUS_KM = 6371.0088;
constexpr double DEG_TO_RAD_D = M_PI / 180.0;
constexpr double RAD_TO_DEG_D = 180.0 / M_PI;
}

RadarPoint projectAircraft(
    double stationLatitude,
    double stationLongitude,
    const Aircraft& aircraft,
    float radarRadiusKm,
    int16_t centreX,
    int16_t centreY,
    int16_t radiusPixels
) {
    const double lat1 = stationLatitude * DEG_TO_RAD_D;
    const double lat2 = aircraft.latitude * DEG_TO_RAD_D;
    const double deltaLat = (aircraft.latitude - stationLatitude) * DEG_TO_RAD_D;
    const double deltaLon = (aircraft.longitude - stationLongitude) * DEG_TO_RAD_D;

    const double a = sin(deltaLat / 2.0) * sin(deltaLat / 2.0) +
                     cos(lat1) * cos(lat2) *
                     sin(deltaLon / 2.0) * sin(deltaLon / 2.0);
    const double angularDistance = 2.0 * atan2(sqrt(a), sqrt(1.0 - a));
    const float distanceKm = static_cast<float>(EARTH_RADIUS_KM * angularDistance);

    const double y = sin(deltaLon) * cos(lat2);
    const double x = cos(lat1) * sin(lat2) -
                     sin(lat1) * cos(lat2) * cos(deltaLon);
    double bearing = atan2(y, x) * RAD_TO_DEG_D;
    bearing = fmod(bearing + 360.0, 360.0);

    const float scale = radarRadiusKm > 0.0F
        ? static_cast<float>(radiusPixels) / radarRadiusKm
        : 0.0F;
    const float radialPixels = distanceKm * scale;
    const double bearingRad = bearing * DEG_TO_RAD_D;

    RadarPoint point{};
    point.x = centreX + static_cast<int16_t>(sin(bearingRad) * radialPixels);
    point.y = centreY - static_cast<int16_t>(cos(bearingRad) * radialPixels);
    point.distanceKm = distanceKm;
    point.bearingDegrees = static_cast<float>(bearing);
    point.visible = distanceKm <= radarRadiusKm;
    return point;
}
