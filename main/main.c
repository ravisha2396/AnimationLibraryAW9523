#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "esp_timer.h"
#include "animations.h"
#include "esp_log.h"
#include <assert.h>

static const char* TAG = "main";

void app_main(void)
{
        animation_led_t a = {
                .br_val = 200,
                .step_time = 2,
                .type = 3,
                .led_num = 0,
                .color = 3,
                .animation_flag = true,
        };

        prepare_animation(&a);
        
        esp_timer_start_periodic(periodic_timer, timePeriod);
        
        while(1){
                if(a.animation_flag){
                        animation_handler();
                }
                
        }

} 