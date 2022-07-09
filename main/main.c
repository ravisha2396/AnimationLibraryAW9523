#include <stdio.h>
#include "driver/i2c.h"
#include "driver/timer.h"
#include "AW9523.h"
#include "ledbase.h"

//hw_timer_t *step_timer=NULL;
#define TIMER_DIVIDER   (16)

uint8_t brightness=200, color=0, type=0, n=0, br=0;
bool glow=false, done=false; 

volatile bool interruptbool1 = false;

static bool IRAM_ATTR onTimer(void * args){
    if(brightness>0){
        brightness--;
        interruptbool1 = true;
    }
    //aw9523_register_write_byte(LED15, 200);
    else{
        //br=0;
        interruptbool1=false;
    }
    return interruptbool1;
}

void create_animation(){
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
    timer_set_alarm_value(TIMER_GROUP_0, TIMER_0, (TIMER_BASE_CLK / 80000*TIMER_DIVIDER));
    timer_enable_intr(TIMER_GROUP_0, TIMER_0);
    timer_isr_callback_add(TIMER_GROUP_0, TIMER_0, onTimer, NULL, 0);
    

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
    ledbase_set_brightness(14, 0);
    
    create_animation(); 
    //printf("Brightness: %d\n", brightness); 
    //brightness = 200;
    //printf("Brightness: %d\n", brightness);
    timer_start(TIMER_GROUP_0, TIMER_0);
    //printf("Clock freq: %d\n", APB_CLK_FREQ);
     while(1){
        
        if(interruptbool1){
            ledbase_set_brightness(14,brightness);
            printf("Brightness val: %d!\n", brightness);
            //br++;
            //brightness--;
        }
        else{
            
            printf("Animation complete!\n");
            //timer_pause(TIMER_GROUP_0, TIMER_0);

        }

     }
    
} 
