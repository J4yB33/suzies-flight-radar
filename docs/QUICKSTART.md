# Quick start

This guide targets the Elecrow CrowPanel Advance 5.0, SKU `DIS02050A`, PCB revision `V1.1`.

## What you need

- CrowPanel Advance 5.0 V1.1
- USB-C data cable
- 5 V, 2 A power source
- macOS, Windows or Linux computer
- Visual Studio Code
- PlatformIO extension

## 1. Install the tools

Install Visual Studio Code, then install the PlatformIO IDE extension.

Command-line users can install PlatformIO Core:

```bash
python3 -m pip install --user platformio
```

Purpose: installs the compiler, ESP32 platform manager and upload tools.

Check the installation:

```bash
pio --version
```

## 2. Clone the project

```bash
git clone https://github.com/J4yB33/suzies-flight-radar.git
cd suzies-flight-radar
```

Purpose: downloads the firmware source and enters the project directory.

## 3. Build before connecting the panel

```bash
pio run
```

Purpose: downloads pinned dependencies and confirms the code compiles.

A successful build ends with `SUCCESS`.

## 4. Connect the panel

Use the USB-C port labelled `USB5V-IN`. Use a data-capable cable.

List detected serial ports:

```bash
pio device list
```

## 5. Upload

```bash
pio run --target upload
```

If upload fails:

1. Hold `BOOT`.
2. Press and release `RESET`.
3. Release `BOOT`.
4. Run the upload command again.

## 6. Read diagnostics

```bash
pio device monitor
```

Purpose: opens the serial console at 115200 baud.

Exit with `Ctrl+C`.

## Safe development rule

The current main branch is pre-release firmware. Build it freely, but only flash commits marked as hardware-tested in the README or a GitHub release.

## Planned first-boot setup

The release firmware will:

1. Start a Wi-Fi access point named `Suzies-Radar-Setup`.
2. Display setup instructions and a QR code.
3. Accept Wi-Fi, home location and OpenSky credentials.
4. Save settings to ESP32 NVS.
5. Restart into radar mode.

## OpenSky account

An OpenSky account is optional. Demonstration mode and anonymous mode will remain available. Authenticated use provides a more useful request allowance.

Never add OpenSky credentials to source files or commit them to GitHub.

## Replicating for another person

Personalisation will be stored as configuration rather than hard-coded source. A future release will allow these values to be changed on the device:

- Display name
- Gift message
- Home location
- Units
- Theme
- Favourite airlines and aircraft

This keeps one firmware image usable for many builds.
