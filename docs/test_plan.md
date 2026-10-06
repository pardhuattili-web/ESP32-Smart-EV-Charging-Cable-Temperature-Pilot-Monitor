# Test Plan

## Software

- Valid 1 kHz / 50% pilot -> CHARGING
- 1 kHz / 10% pilot -> CHARGING
- 800 Hz pilot -> FAULT
- 1200 Hz pilot -> FAULT
- 40 C + valid pilot -> CHARGING
- 60 C + valid pilot -> WARNING
- 75 C + valid pilot -> FAULT
- Sensor fault -> FAULT
- Injected fault -> FAULT

## Hardware

Validate the NTC ADC path, OLED refresh, conditioned PWM timing capture, Wi-Fi endpoint, watchdog reset behavior, and fault recovery.

## Acceptance

A fault state must be deterministic and must never cause the firmware to directly energize or switch mains power.
