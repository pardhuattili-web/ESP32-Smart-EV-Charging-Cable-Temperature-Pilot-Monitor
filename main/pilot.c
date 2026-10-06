#include "pilot.h"
PilotMeasurement pilot_evaluate(uint32_t period_us,uint32_t high_us,const PilotLimits *limits){
    PilotMeasurement m={0};
    if(period_us==0U||high_us>period_us||limits==0) return m;
    m.frequency_hz=1000000.0f/(float)period_us;
    m.duty_percent=(100.0f*(float)high_us)/(float)period_us;
    m.valid=(m.frequency_hz>=limits->min_freq_hz&&m.frequency_hz<=limits->max_freq_hz&&m.duty_percent>=limits->min_duty_percent&&m.duty_percent<=limits->max_duty_percent);
    return m;
}
