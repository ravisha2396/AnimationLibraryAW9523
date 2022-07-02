#define GLOBAL_CONTROL_REG                          0x11
#define LED0_MODE_REG                               0x12
#define LED1_MODE_REG                               0x13

#include <stdio.h>

// set the AW9523 chip LED MODE REGISTER
int leddriver_init(void);

// set brightness 0-255 
int leddriver_set_brightness(uint8_t pin, uint8_t val);

// set Global Control Register to set the max current to draw from Vin
int leddriver_set_gcr(uint8_t val);

 












