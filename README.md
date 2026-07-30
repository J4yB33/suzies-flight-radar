# Suzie's Flight Radar

A personalised, open-source flight radar for the Elecrow CrowPanel Advance 5.0 touchscreen.

The project is designed so another person can clone the repository, connect the supported panel, flash it with PlatformIO, and complete setup on the device.

## Target hardware

- Elecrow CrowPanel Advance 5.0
- SKU `DIS02050A`
- PCB revision `V1.1`
- ESP32-S3-WROOM-1-N16R8
- 800 x 480 capacitive touchscreen
- 5 V, 2 A USB-C power supply

## Planned user experience

1. Flash the firmware.
2. Connect to the temporary `Suzies-Radar-Setup` Wi-Fi network.
3. Enter Wi-Fi, home location and optional OpenSky credentials.
4. The device restarts into the live radar screen.
5. All settings remain available through the touchscreen.

No source-code editing should be required for normal setup.

## Version 1 scope

- Personalised boot screen
- Live radar screen
- Touch aircraft selection
- Nearby-flight list
- On-device settings
- First-boot Wi-Fi setup
- OpenSky state-vector data
- Configurable home location and radius
- Metric and aviation unit options
- Demonstration mode without API credentials
- Saved configuration in ESP32 non-volatile storage

## Current status

The repository currently contains the ESP32-S3 PlatformIO base, board identification, aircraft model and radar coordinate projection.

The next firmware milestone is the verified V1.1 RGB display, GT911 touch and backlight driver. Do not treat the current branch as a release image yet.

## Quick start

See [`docs/QUICKSTART.md`](docs/QUICKSTART.md).

Basic commands:

```bash
git clone https://github.com/J4yB33/suzies-flight-radar.git
cd suzies-flight-radar
pio run
pio run --target upload
pio device monitor
```

## Project layout

```text
include/          Shared configuration and data types
src/              Firmware source
src/display/      RGB panel, touch and LVGL integration
src/network/      Wi-Fi, captive portal and OpenSky client
src/radar/        Projection, filtering and aircraft cache
src/storage/      Saved configuration and favourites
src/ui/           LVGL screens and widgets
docs/             Build and replication instructions
```

## Configuration policy

- Wi-Fi and OpenSky secrets must never be committed.
- Runtime configuration will be stored in ESP32 NVS.
- Demonstration mode will work without network credentials.
- Board-specific pins remain isolated in `include/board_config.h`.

## Attribution

Inspired by [Micro Radar](https://github.com/AnthonySturdy/micro-radar) by Anthony Sturdy.

This project uses the original idea and compatible flight-data concepts, but provides a separate ESP32-S3, 800 x 480 touchscreen implementation.

## Licence

MIT
