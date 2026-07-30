# Suzie's Flight Radar

A personalised 5-inch ESP32-S3 touchscreen flight radar for the Elecrow CrowPanel Advance 5-inch 800x480 display.

## Planned features

- LVGL 8 landscape radar display
- Touch aircraft selection
- On-device settings
- First-boot Wi-Fi configuration
- OpenSky Network flight data
- Configurable location and range
- Flight list and favourite aircraft
- Personalised Suzie boot screen

## Current milestone

The initial firmware scaffold provides:

- ESP32-S3 PlatformIO project
- LVGL application structure
- Radar coordinate projection
- Sample aircraft data
- Dedicated board configuration header

The display and touch pin mapping must be verified against the exact Elecrow `DIS02050A-1` factory example before flashing.

## Hardware

- Elecrow CrowPanel Advance 5-inch HMI
- ESP32-S3-WROOM-1-N16R8
- 800x480 IPS capacitive touchscreen
- Stable 5V 2A USB-C power supply

## Attribution

Inspired by [Micro Radar](https://github.com/AnthonySturdy/micro-radar) by Anthony Sturdy.

## Licence

MIT
