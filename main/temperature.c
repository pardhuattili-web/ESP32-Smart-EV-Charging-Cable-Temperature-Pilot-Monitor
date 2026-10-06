#include "temperature.h"
#include <math.h>

float ntc_adc_to_celsius(uint32_t adc,uint32_t full_scale,float vref,const NtcConfig *cfg){
    if(cfg==0||full_scale==0U||vref<=0.0f) return -273.15f;
    if(adc==0U||adc>=full_scale) return -273.15f;
    const float v=((float)adc/(float)full_scale)*vref;
    const float r=cfg->series_r*v/(vref-v);
    const float inv_t=(1.0f/cfg->t0_kelvin)+(1.0f/cfg->beta)*logf(r/cfg->r0);
    return (1.0f/inv_t)-273.15f;
}
SensorStatus ntc_classify(uint32_t adc,uint32_t full_scale){
    if(adc<=3U) return SENSOR_SHORT;
    if(adc+3U>=full_scale) return SENSOR_OPEN;
    return SENSOR_OK;
}
