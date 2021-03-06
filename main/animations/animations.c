#include <stdio.h>
#include "ledbase.h"
#include "esp_timer.h"
#include "animations.h"
#include "esp_log.h"
#include <string.h>
#include <assert.h>

static const char* TAG = "animation";

static animation_led_t* animation;

static animation_uno_t uno;

static animation_duo_t duo;

static animation_tres_t tres;

// interrupt service routine handler
static void onTimer(void * arg){

if(animation->animation_flag){
        if(animation->type == 1){
            uno.set = true;
        }
        else if(animation->type == 2){
            duo.set = true;
        }
        else{
            tres.set = true;
        }
    }
}

// init function
int32_t prepare_animation(animation_led_t* a_ptr){

    ESP_LOGI(TAG, "Preparing animation configuration\n");
    // turn of timer if already running
    esp_timer_stop(periodic_timer);

    assert(a_ptr!=NULL);
    animation = a_ptr;

    // reinitialize structures
    uno.br=0;
    uno.set=false;
    memset(&uno.led_status, 0, 4*sizeof(bool));
    uno.ctr=0;
    uno.iter_done=true;

    duo.br=0;
    duo.set=false;
    duo.iter_done = true;

    tres.br=animation->br_val;
    tres.set=false;
    tres.iter_done = true;

    // assertions on input values
    
    assert(animation->step_time>=1u && animation->step_time<6u);

    timePeriod = animation->step_time*MIN_TIME;

    assert(animation->type>=1u && animation->type<4u);

    assert(animation->led_num>=0 && animation->led_num<5u);

    assert(animation->br_val>=0 && animation->br_val<256u);

    assert(animation->color>=1u && animation->color<4u);

    assert(animation->max_leds>=1u && animation->max_leds<6u);

    // init/configure leds
    ledbase_init();

    // turn off all LEDs pre-animation
    for(int i=0u;i<16u;i++){   
        ledbase_set_brightness(i, 0u);
    }

    // init timer args and configs
    const esp_timer_create_args_t periodic_timer_args = {
            .callback = &onTimer, 
            /* name is optional, but may help identify the timer when debugging */
            .name = "periodic"
    };

    if(esp_timer_create(&periodic_timer_args, &periodic_timer)<0){
        return -1;
    }

    return 0;

}


// The handler called from main once animation interrupt occurs
void animation_handler(){

    switch(animation->type){
        case 1 : 
            if(uno.set){
                if(uno.br<animation->br_val){
                    uno.iter_done = false;
                }
                else{
                    uno.set=false;
                    uno.br=0;
                    uno.led_status[uno.ctr] = true;
                    uno.ctr++;
                    if(uno.ctr<animation->max_leds){
                        uno.set=true;
                    }
                    else{
                    uno.ctr=0;
                    uno.iter_done = false;
                    animation->animation_flag = false;
                    // stop timer
                    esp_timer_stop(periodic_timer);
                    }
                }
            }
            animation_uno();
            break;
        case 2 :   
            if(duo.set){ 
                if(duo.br<animation->br_val){
                    duo.iter_done = false;
                }
                else{
                    duo.iter_done=true;
                    duo.set = false;
                    animation->animation_flag = false;
                    // stop timer
                    esp_timer_stop(periodic_timer);
                }
            }
            animation_duo();
            break;
        case 3 :
            if(tres.set){
                if(tres.br>0){
                    tres.iter_done = false;
                }
                else{
                    tres.iter_done=true;
                    tres.set = false;
                    animation->animation_flag = false;
                    // stop timer
                    esp_timer_stop(periodic_timer);
                }
            }
            animation_tres();
            break;
    }

}

void animation_uno(void){

    if(!uno.iter_done){    
            // Check if the led is not already at brightness level
                if(!uno.led_status[0]){
                    ledbase_set_brightness(findPin(0), uno.br);
                    uno.br++;
                    uno.iter_done=true;
                    uno.set = false;
                }
                else if(uno.led_status[0] && !uno.led_status[1]){
                    ledbase_set_brightness(findPin(1), uno.br);
                    uno.br++;
                    uno.iter_done=true;
                    uno.set = false;
                }
                else if(uno.led_status[0] && uno.led_status[1] && !uno.led_status[2]){
                    ledbase_set_brightness(findPin(2), uno.br);
                    uno.br++;
                    uno.iter_done=true;
                    uno.set = false;
                }
                else if(uno.led_status[0] && uno.led_status[1] && uno.led_status[2] && !uno.led_status[3]){
                    ledbase_set_brightness(findPin(3), uno.br);
                    uno.br++;
                    uno.iter_done=true;
                    uno.set = false;
                }
                else if(uno.led_status[0] && uno.led_status[1] && uno.led_status[2] && uno.led_status[3] && !uno.led_status[4]){
                    ledbase_set_brightness(findPin(4), uno.br);
                    uno.br++;
                    uno.iter_done=true;
                    uno.set = false;
                }
        }

}


void animation_duo(){

    if(!duo.iter_done){
            duo.iter_done = true;
            duo.set = false;
            ledbase_set_brightness(findPin(animation->led_num), duo.br);
            duo.br++;
    }

}

void animation_tres(){
    
    if(!tres.iter_done){
        tres.set = false;
        tres.iter_done = true;
        ledbase_set_brightness(findPin(animation->led_num), tres.br);
        tres.br--;
        if(tres.br==0)
            ledbase_set_brightness(findPin(animation->led_num), tres.br);  
    }
}

uint8_t findPin(uint8_t num){

    uint8_t pin = 0;
    if(num==0){
        if(animation->color == 1){
            pin = LED0;
        }
        else if(animation->color == 2){
            pin = LED1;
        }
        else if(animation->color == 3){
            pin = LED2;
        }
    }
    else if(num==1){
        if(animation->color == 1){
            pin = LED3;
        }
        else if(animation->color == 2){
            pin = LED4;
        }
        else if(animation->color == 3){
            pin =LED5;
        }
    }
    else if(num==2){
        if(animation->color == 1){
            pin = LED6;
        }
        else if(animation->color == 2){
            pin = LED7;
        }
        else if(animation->color == 3){
            pin = LED12;
        }
    }
    else if(num==3){
        if(animation->color == 1){
            pin = LED13;
        }
        else if(animation->color == 2){
            pin = LED14;
        }
        else if(animation->color == 3){
            pin = LED15;
        }
    }
    else{
        if(animation->color == 1){
            pin = LED8;
        }
        else if(animation->color == 2){
            pin = LED9;
        }
        else if(animation->color == 3){
            pin = LED10;
        }
    }

    return pin;
}


