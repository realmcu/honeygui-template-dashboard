# dashboard

A HoneyGUI project created with HoneyGUI Visual Designer.

## Project Information

- **APP ID**: com.example.dashboard
- **Resolution**: 800X480
- **Format**: Standard HML Format (v1.0)
- **Created**: 2026-01-15T08:03:41.978Z

## Project Structure

- **ui/**: HML UI definition files
- **src/**: C++ source code files
- **assets/**: Project assets (images, fonts, etc.)

## Getting Started

Open this project in HoneyGUI Visual Designer to start editing your UI.

## Shell cmd

In the simulator build (`_HONEYGUI_SIMULATOR_`), the shell command `cmd` updates the dashboard data in real time, handled by `dashboard_info_update()`.
Format: `cmd <subcommand> [arg]`. Multiple subcommands can be chained in a single line.

| Subcommand | Argument | Type | Description |
| --- | --- | --- | --- |
| `map` | none | - | Advance the map image index, wrapping around (0–12) |
| `speed` | speed value | uint16_t | Set speed (displayed value is taken modulo 160) |
| `power` | power value | uint16_t | Set power (displayed value is taken modulo 160) |
| `odo` | odometer value | uint16_t | Set ODO mileage (km) |
| `battery` | battery value | uint16_t | Set battery level (%) |
| `location` | location string | char* | Set the location name shown at the top |
| `temp` | temperature value | uint8_t | Set temperature (°C) |
| `turnl` | 0 / 1 | bool | Left turn signal off / on |
| `turnr` | 0 / 1 | bool | Right turn signal off / on |
| `bt` | 0 / 1 | bool | Bluetooth icon dimmed / lit |
| `wifi` | 0 / 1 | bool | WiFi icon dimmed / lit |
| `led0` | 0 / 1 | bool | LED0 off / on (green) |
| `led1` | 0 / 1 | bool | LED1 off / on (green) |
| `led2` | 0 / 1 | bool | LED2 off / on (green) |
| `led3` | 0 / 1 | bool | LED3 off / on (orange) |
| `led4` | 0 / 1 | bool | LED4 off / on (orange) |
| `led5` | 0 / 1 | bool | LED5 off / on (orange) |
| `volume` | 0 / 1 | bool | Volume -10 / +10 (pops up the volume window, range 0–100) |
| `play` | 0 / 1 | bool | Pause / play the current track |
| `next` | none | - | Switch to the next track |
| `last` | none | - | Switch to the previous track |
| `lyrics` | none | - | Cycle through the lyrics text |

Examples:

```shell
cmd speed 60
cmd power 80 wifi 1 bt 1
cmd location Suzhou temp 28
cmd play 1
cmd next
```

## HML File Format

This project uses the standard HML format:

```xml
<?xml version="1.0" encoding="UTF-8"?>
<hml>
    <meta>
        <project ... />
        <author ... />
    </meta>
    <view>
        <!-- UI components -->
    </view>
</hml>
```
