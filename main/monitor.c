#include "monitor.h"
#include <string.h>

static MonitorConfig g_cfg;
static MonitorStatus g_status;
static bool g_injected;

void monitor_init(const MonitorConfig *cfg){memset(&g_status,0,sizeof(g_status));if(cfg)g_cfg=*cfg;g_status.state=MON_IDLE;}
void monitor_inject_fault(bool enable){g_injected=enable;}
void monitor_update(float temp,PilotMeasurement pilot,bool sensor_fault,uint32_t elapsed){
    g_status.temperature_c=temp;
    g_status.pilot=pilot;
    g_status.sensor_fault=sensor_fault;
    if(temp>g_status.peak_temperature_c) g_status.peak_temperature_c=temp;
    if(elapsed>0U && g_status.state!=MON_IDLE) g_status.session_seconds+=elapsed;

    if(g_injected||sensor_fault||temp>=g_cfg.critical_temp_c||!pilot.valid){
        g_status.state=FAULT;
        ++g_status.fault_count;
        return;
    }
    if(temp>=g_cfg.warning_temp_c){
        g_status.state=WARNING;
        return;
    }
    if(pilot.valid){
        g_status.state=CHARGING;
        return;
    }
    g_status.state=MONITORING;
}
void monitor_get_status(MonitorStatus *status){if(status)*status=g_status;}
void monitor_clear_faults(void){g_status.fault_count=0U;if(g_status.state==FAULT)g_status.state=MONITORING;}
