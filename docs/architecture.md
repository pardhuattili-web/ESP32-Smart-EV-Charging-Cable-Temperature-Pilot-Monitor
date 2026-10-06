# Architecture

## Data path

NTC ADC -> temperature conversion -> filtering -> thermal thresholds -> monitor state machine.

Conditioned pilot input -> pulse timing capture -> frequency/duty calculation -> validity check -> state machine.

State machine -> OLED/dashboard/logging.

## FreeRTOS integration

The reference application is intentionally small. A production ESP-IDF build should split acquisition, monitoring, display, and networking into separate FreeRTOS tasks connected by queues/event groups.

## Hardware abstraction

The pure logic modules do not depend on ESP-IDF. ESP-IDF drivers can feed them with ADC and pulse-capture measurements.
