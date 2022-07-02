#include "leddriver.h"
#include "AW9523.h"
#include <stdio.h>

int leddriver_init(void){

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
    
    if(leddriver_set_gcr(0x02)){
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

int leddriver_set_brightness(uint8_t pin, uint8_t val){

    uint8_t reg_addr = 0x24 + pin;

    /** This function helps to write brightness values (0-255)
     * to the pin designated to be a constant current LED driver.
     * The register values start from 0x24 and go up till 0x2F.
    **/
    
    if(aw9523_register_write_byte(reg_addr, val)){
        return -1;
    }

    return 0;

}

int leddriver_set_gcr(uint8_t val){

    if(aw9523_register_write_byte(GLOBAL_CONTROL_REG, val)){
        return -1;
    }

    return 0;
    
}