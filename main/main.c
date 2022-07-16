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
                .step_time = 1,
                .type = 1,
                .led_num = 0,
                .color = 1,
                .max_leds = 4,
                .animation_flag = true,
        };

        prepare_animation(&a);
        
        esp_timer_start_periodic(periodic_timer, timePeriod);
        
        while(1){
                if(a.animation_flag){
                        animation_handler();
                }
                if(!a.animation_flag)
                        break;
        }
        ESP_LOGI(TAG,"Animation 1 complete\n");
        
        animation_led_t b = {
                .br_val = 200,
                .step_time = 1,
                .type = 1,
                .led_num = 0,
                .color = 2,
                .max_leds = 4,
                .animation_flag = true,
        };        
        prepare_animation(&b);
        
        esp_timer_start_periodic(periodic_timer, timePeriod);

        while(1){
                if(b.animation_flag){
                        animation_handler();
                }
                if(!b.animation_flag)
                        break;
        }
        ESP_LOGI(TAG,"Animation 2 complete\n");

        animation_led_t c = {
                .br_val = 200,
                .step_time = 1,
                .type = 1,
                .led_num = 0,
                .color = 3,
                .max_leds = 4,
                .animation_flag = true,
        };

        prepare_animation(&c);
        
        esp_timer_start_periodic(periodic_timer, timePeriod);
        
        while(1){
                if(c.animation_flag){
                        animation_handler();
                }
                if(!c.animation_flag)
                        break;
        }    
        ESP_LOGI(TAG,"Animation 3 complete\n");
} 