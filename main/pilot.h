#ifndef PILOT_H
#define PILOT_H
#include <stdbool.h>
#include <stdint.h>

typedef struct {
    float frequency_hz;
    float duty_percent;
    bool valid;
} PilotMeasurement;

typedef struct {
    float min_freq_hz;
    float max_freq_hz;
    float min_duty_percent;
    float max_duty_percent;
} PilotLimits;

PilotMeasurement pilot_evaluate(uint32_t period_us,uint32_t high_us,const PilotLimits *limits);

#endif
