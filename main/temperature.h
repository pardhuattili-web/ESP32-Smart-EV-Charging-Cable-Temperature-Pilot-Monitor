#ifndef TEMPERATURE_H
#define TEMPERATURE_H
#include <stdbool.h>
#include <stdint.h>

typedef struct {
    float beta;
    float r0;
    float t0_kelvin;
    float series_r;
} NtcConfig;

typedef enum { SENSOR_OK=0, SENSOR_OPEN, SENSOR_SHORT } SensorStatus;

float ntc_adc_to_celsius(uint32_t adc, uint32_t full_scale, float vref, const NtcConfig *cfg);
SensorStatus ntc_classify(uint32_t adc, uint32_t full_scale);

#endif
