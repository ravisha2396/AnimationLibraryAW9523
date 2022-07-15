#include <stdio.h>
#include "AW9523.h"
#include "ledbase.h"

//#include <esp_log.h>

//static const char* const TAG = "LEDBASE";

int32_t ledbase_init(void){

    /** Initialize the AW9523 on the I2C bus
     * Sets the SCL and SDA lines for I2C
     * **/
    if(aw9523_init()<0){
        return -1;
    }
    
    /** default value is 0xFF which is GPIO mode 
     * we set it to 0x00 which is the LED drive mode
     * for all the pins of port 0
    **/

    if(aw9523_register_write_byte(LED0_MODE_REG, 0x00)){
        return -1;
    }

    /** default value is 0xFF which is GPIO mode 
     * we set it to 0x00 which is the LED drive mode
     * for all the pins of port 0
    **/
    
    if(ledbase_set_gcr(0x02)){
        return -1;
    }

    /** default value is 0xFF which is GPIO mode 
     * we set it to 0x00 which is the LED drive mode
     *  for all the pins of port 0
    **/
    if(aw9523_register_write_byte(LED1_MODE_REG, 0x00)){
        return -1;
    }

    return 0;
}

int32_t ledbase_set_brightness( uint8_t pin, uint8_t val){

    uint8_t reg_addr = 0x20;

    switch(pin){
            case 8:
                reg_addr+=0;
                break;
            case 9:
                reg_addr+=1;
                break;
            case 10:
                reg_addr+=2;
                break;
            case 11:
                reg_addr+=3;
                break;
            case 12:
                reg_addr+=12;
                break;
            case 13:
                reg_addr+=13;
                break;
            case 14:
                reg_addr+=14;
                break;
            case 15:
                reg_addr+=15;
                break;
            default:
                reg_addr=0x24+pin;
            } 

    /** This function helps to write brightness values (0-255)
     * to the pin designated to be a constant current LED driver.
     * The register values start from 0x24 and go up till 0x2F.
    **/
    if(reg_addr < 0x20 || reg_addr > 0x2F)
        return -1;  
    if(aw9523_register_write_byte(reg_addr, val)){
        //ESP_LOGI(TAG, "Write failed\n");
        return -1;
    }
    //ESP_LOGI(TAG, "Write ok\n");

    return 0;

}

int32_t ledbase_set_gcr(uint8_t val){

    if(aw9523_register_write_byte(GLOBAL_CONTROL_REG, val)){
        return -1;
    }

    return 0;
    
}

int32_t ledbase_remove(void){
    if(aw9523_driver_delete()){
        return -1;
    }
        return 0;
}

