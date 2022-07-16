/** @file ledbase.h
 *  @brief Function prototypes to drive the AW9523 in constant 
 *   current LED driver mode.
 *
 *  This contains the prototypes for i2c communcation 
 *  AW9523 in constant current LED driver mode 
 *  using i2c and eventually any macros, constants,
 *  or global variables you will need.
 *
 *  @author Ravi Shankar (rnolas13@asu.edu)
 *  @bug No known bugs. 
 */

#define GLOBAL_CONTROL_REG    0x11 /*!< Address of GCR register on AW9523 */
#define LED0_MODE_REG         0x12 /*!< Address of LED0 mode register on AW9523 */
#define LED1_MODE_REG         0x13 /*!< Address of LED1 mode register on AW9523 */

/**
 * @brief The enum contains LEDx where x ranges
 * from 0-15.
 *  
 *  The total number of pins on the
 *  AW9523 IC is labelled below.
 *  The pins and their corresponding 
 *  register mapping is in comments below.
 * 
 */
enum LED{                       // REG -> PIN  
          LED0 = 0,             // 0x24   0
          LED1 = 1,             // 0x25   1
          LED2 = 2,             // 0x26   2
          LED3 = 3,             // 0x27   3
          LED4 = 4,             // 0x28   4
          LED5 = 5,             // 0x29   5
          LED6 = 6,             // 0x2A   6
          LED7 = 7,             // 0x2B   7
          LED8 = 8,             // 0x20   8
          LED9 = 9,             // 0x21   9
          LED10 = 10,           // 0x22   10
          LED11 = 11,           // 0x23   11
          LED12 = 12,           // 0x2C   12
          LED13 = 13,           // 0x2D   13
          LED14 = 14,           // 0x2E   14
          LED15 = 15            // 0x2F   15
                };

/** @brief Initializes the AW9523 device 
 *  in constant current mode. 
 * 
 *  @return 0 if successful, -1 if not
 */
int32_t ledbase_init(void);

/** @brief This is a function to set brightness
 *  of an LED connected to a pin on AW9523.
 * 
 *  Brightness values range from 0-255
 *  pin values range from 0-15
 * 
 *  @param pin is the pin to which LED is connected
 *  @param val is the brightness value
 * 
 *  @return 0 if successful, -1 if not
 */
int32_t ledbase_set_brightness(uint8_t pin, uint8_t val);

/** @brief This is a configure GCR register.
 * 
 *  The value determines the amount of
 *  current required to drive the LEDs 
 *  in constant current mode.
 * 
 *  @param val is the hex value to set
 * 
 *  @return 0 if successful, -1 if not
 */
int32_t ledbase_set_gcr(uint8_t val);

/** @brief This deinitializes the ledbase driver.
 * 
 *  @return 0 if successful, -1 if not
 */
int32_t ledbase_remove(void);
 












