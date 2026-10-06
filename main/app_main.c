#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"
#include "esp_task_wdt.h"
#include "monitor.h"
#include "pilot.h"

static const char *TAG="EV_MONITOR";

void app_main(void){
    const MonitorConfig cfg={
        .warning_temp_c=55.0f,
        .critical_temp_c=70.0f,
        .pilot_limits={.min_freq_hz=950.0f,.max_freq_hz=1050.0f,.min_duty_percent=5.0f,.max_duty_percent=95.0f}
    };
    monitor_init(&cfg);

    while(1){
        /* Demo signal; replace with ADC/GPT capture + NTC ADC hardware drivers. */
        const float temperature_c=42.0f;
        const PilotMeasurement pilot=pilot_evaluate(1000U,500U,&cfg.pilot_limits);
        monitor_update(temperature_c,pilot,false,1U);

        MonitorStatus s;
        monitor_get_status(&s);
        ESP_LOGI(TAG,"T=%.1fC f=%.0fHz duty=%.1f%% state=%d faults=%lu",s.temperature_c,s.pilot.frequency_hz,s.pilot.duty_percent,(int)s.state,(unsigned long)s.fault_count);
        esp_task_wdt_reset();
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}
