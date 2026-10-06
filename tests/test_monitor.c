#include <assert.h>
#include <stdio.h>
#include "../main/monitor.h"

int main(void){
    MonitorConfig cfg={
        .warning_temp_c=55.0f,
        .critical_temp_c=70.0f,
        .pilot_limits={.min_freq_hz=950.0f,.max_freq_hz=1050.0f,.min_duty_percent=5.0f,.max_duty_percent=95.0f}
    };
    monitor_init(&cfg);
    PilotMeasurement ok={1000.0f,50.0f,true};
    monitor_update(40.0f,ok,false,1);
    MonitorStatus s; monitor_get_status(&s);
    assert(s.state==CHARGING);
    monitor_update(60.0f,ok,false,1);
    monitor_get_status(&s);
    assert(s.state==WARNING);
    monitor_update(75.0f,ok,false,1);
    monitor_get_status(&s);
    assert(s.state==FAULT);
    monitor_clear_faults();
    monitor_inject_fault(true);
    monitor_update(30.0f,ok,false,1);
    monitor_get_status(&s);
    assert(s.state==FAULT);
    puts("Monitor tests: PASS");
    return 0;
}
