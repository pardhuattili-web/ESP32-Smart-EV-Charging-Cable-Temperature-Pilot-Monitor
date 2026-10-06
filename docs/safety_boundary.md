# Safety Boundary

This project is a monitor, not an EV charger or EVSE controller.

The control-pilot input must enter the ESP32 through an appropriate protected/isolated or otherwise correctly designed low-voltage interface. The example code operates only on conditioned values such as frequency and duty cycle.

Do not connect an ESP32 GPIO/ADC directly to an EVSE pilot conductor or mains circuit. Any real deployment requires appropriate electrical protection, isolation, creepage/clearance, transient protection, and compliance engineering.
