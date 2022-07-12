#include <stdio.h>
#include "driver/i2c.h"
#include "driver/timer.h"
#include "AW9523.h"
#include "ledbase.h"

//hw_timer_t *step_timer=NULL;
#define TIMER_DIVIDER   (16)

uint8_t brightness=0, color=0, type=0, n=0, br=0, br_old=0, temp=0;
bool glow=false, done=false; 
bool led_status[4]={0};
volatile bool anim1_init=true;
bool channel_status[15]={0};
volatile bool animation_flag = false;
uint8_t ctr=0;

static bool IRAM_ATTR onTimer(void * args){
    
    if(temp>0){
        temp--;
        anim1_init=true;
    }
    else{
        br=0;
        //anim_init? anim_init=false: led_status[ctr]=true;
        temp = brightness;
        led_status[ctr]=true;
        if(ctr<4){
            ctr++;
            anim1_init=true;
        }
        else{
            ctr=0;
            anim1_init=false;
            brightness = 0;
            temp = 0;
        }
    }
    if(!anim1_init){
        animation_flag=false;
    }
    return animation_flag;
}

void create_animation(uint8_t br){
    // uint32_t step_time, uint8_t br, uint8_t color,  bool glow, uint8_t type, uint8_t led_num
    timer_config_t config = {
        .divider = TIMER_DIVIDER,
        .counter_dir = TIMER_COUNT_UP,
        .counter_en = TIMER_PAUSE,
        .alarm_en = TIMER_ALARM_EN,
        .auto_reload = TIMER_AUTORELOAD_EN
    };
    timer_init(TIMER_GROUP_0, TIMER_0, &config);
    timer_set_counter_value(TIMER_GROUP_0, TIMER_0, 0);
    timer_set_alarm_value(TIMER_GROUP_0, TIMER_0, (TIMER_BASE_CLK / 10000*TIMER_DIVIDER));
    timer_enable_intr(TIMER_GROUP_0, TIMER_0);
    timer_isr_callback_add(TIMER_GROUP_0, TIMER_0, onTimer, NULL, 0);

    brightness = br;
    temp=brightness;
    animation_flag=true;

}

void app_main(void)
{   
    

    // define an animation function
    // params
    // brightness
    // fade in or fade out (glow)
    // timer expiry duration
    // type of animation
    // color
    // define a timer
    // attach a handler

    
    ledbase_init();
    ledbase_set_brightness(12, 0);
    ledbase_set_brightness(13, 0);
    ledbase_set_brightness(14, 0);
    ledbase_set_brightness(15, 0);

    create_animation(120); 

    timer_start(TIMER_GROUP_0, TIMER_0);
    int count=0;
     while(1){
        
        if(animation_flag){
            if(anim1_init){
                if(!led_status[0]){
                    count++;
                    ledbase_set_brightness(12,br);
                    br++;
                    anim1_init=false;
                }
                else if(led_status[0]==true && !led_status[1]){
                    ledbase_set_brightness(13,br);
                    br++;
                    anim1_init=false;
                }
                else if(led_status[0]==true && led_status[1]==true && !led_status[2]){
                    ledbase_set_brightness(14,br);
                    br++;
                    anim1_init=false;
                }
                else if(led_status[0]==true && led_status[1]==true && led_status[2]==true && !led_status[3]){
                    ledbase_set_brightness(15,br);
                    br++;
                    anim1_init=false;
                }
                else{ 
                    animation_flag=false;
                }

        }
    }

     }
    
} 
