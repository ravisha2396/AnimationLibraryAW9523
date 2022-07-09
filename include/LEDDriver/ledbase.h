#define GLOBAL_CONTROL_REG                          0x11
#define LED0_MODE_REG                               0x12
#define LED1_MODE_REG                               0x13

            // REG   PIN 
            // 0x20  8
            // 0x21  9
            // 0x22  10
            // 0x23  11
            // 0x24  0
            // 0x25  1
            // 0x26  2
            // 0x27  3
            // 0x28  4
            // 0x29  5
            // 0x2A  6
            // 0x2B  7
            // 0x2C  12
            // 0x2D  13
            // 0x2E  14
            // 0X2F  15

enum LED{ 
          LED0 = 0x24,
          LED1 = 0x25,  
          LED2 = 0x26,
          LED3 = 0x27,
          LED4 = 0x28,
          LED5 = 0x29,  
          LED6 = 0x2A,
          LED7 = 0x2B,
          LED8 = 0x20,
          LED9 = 0x21,  
          LED10 = 0x22,
          LED11 = 0x23,
          LED12 = 0x2C,
          LED13 = 0x2D,  
          LED14 = 0x2E,
          LED15 = 0x2F
                };


enum COLORS{
      RED = 1,
      BLUE = 2,
      GREEN = 3,
      MAGENTA = 4,
      YELLOW = 5,
      CYAN = 6,
};
// set the AW9523 chip LED MODE REGISTER
int32_t ledbase_init(void);

// set brightness 0-255 
int32_t ledbase_set_brightness(uint8_t pin, uint8_t val);

// set Global Control Register to set the max current to draw from Vin
int32_t ledbase_set_gcr(uint8_t val);

// delete LED driver
int32_t ledbase_remove(void);
 












