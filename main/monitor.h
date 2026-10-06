#ifndef MONITOR_H
#define MONITOR_H
#include <stdbool.h>
#include <stdint.h>
#include "pilot.h"

typedef enum { MON_IDLE, MONITORING, CHARGING, WARNING, FAULT } MonitorState;
typedef struct {
    float temperature_c;
    float peak_temperature_c;
    PilotMeasurement pilot;
    MonitorState state;
    uint32_t session_seconds;
    uint32_t fault_count;
    bool sensor_fault;
} MonitorStatus;

typedef struct {
    float warning_temp_c;
    float critical_temp_c;
    PilotLimits pilot_limits;
} MonitorConfig;

void monitor_init(const MonitorConfig *cfg);
void monitor_update(float temperature_c, PilotMeasurement pilot, bool sensor_fault, uint32_t elapsed_seconds);
void monitor_get_status(MonitorStatus *status);
void monitor_clear_faults(void);
void monitor_inject_fault(bool enable);

#endif
