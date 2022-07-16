/** @file animations.h
 *  @brief Function prototypes to create LED animations.
 *
 *  This contains the prototypes to create
 *  LED animations when they are driven by
 *  a constant current driver IC.
 *
 *  @author Ravi Shankar (rnolas13@asu.edu)
 *  @bug Code is tightly coupled with AW9523 IC. 
 */


#define MIN_TIME 1000U /*!< Timer period value is a multiple of this base value */

uint64_t timePeriod;   /*!< Used for setting the timer period */

esp_timer_handle_t periodic_timer; /*!< Contains a handle to a periodic timer */

/**
 * @brief This a global animation structure
 * 
 *  User is expected to initialize this structure in
 *  order to create different kinds of animation.
 *  
 *  @param step_time is the multiple of MIN_TIME to set the timer period(1-5)
 *  @param type is the type of animation(1-3)
 *  @param led_num is the led number to glow or fade
 *  @param br_val is the brightness value to be set on led(s)
 *  @param color is the color of LED (R,G,B)
 *  @param max_leds is the maximum number of LED(s) for the animation
 *  @param animation_flag is the flag which enables animation
 * 
 */
typedef struct {      
    uint8_t step_time;                      
    uint8_t type;              
    uint8_t led_num;    
    uint8_t br_val;
    uint8_t color; 
    uint8_t max_leds;
    bool animation_flag;
} animation_led_t;

/**
 * @brief This a structure for animation type 1
 * 
 *  This structure is used to configure and manage 
 *  the state of LEDs in animation 1.
 *  
 *  @param led_status stores each LEDs state
 *  @param set is a boolean to show if an interrupt occured
 *  @param iter_done is a boolean to show if an LED has achieved its set level of brightness
 *  @param br indicates the brightness that each LED in a sequence needs to achieve
 *  @param ctr is used as an index which tracks the current LED
 * 
 */
typedef struct {
    bool led_status[5];
    bool set;
    bool iter_done;
    uint8_t br;
    uint8_t ctr;       
} animation_uno_t;

/**
 * @brief This a structure for animation type 2
 * 
 *  This structure is used to configure and manage 
 *  the state of LEDs in animation 2.
 *  
 *  @param set is a boolean to show if an interrupt occured
 *  @param iter_done is a boolean to show if an LED has achieved its set level of brightness
 *  @param br indicates the brightness that a LED needs to achieve
 * 
 */
typedef struct {
    bool set;
    bool iter_done;  
    uint8_t br;     
} animation_duo_t;

/**
 * @brief This a structure for animation type 3
 * 
 *  This structure is used to configure and manage 
 *  the state of LEDs in animation 3.
 *  
 *  @param set is a boolean to show if an interrupt occured
 *  @param iter_done is a boolean to show if an LED has achieved its set level of brightness
 *  @param br indicates the brightness that a LED needs to achieve
 * 
 */
typedef struct {
    bool set;
    bool iter_done;
    uint8_t br;        
} animation_tres_t;

/** @brief Initializes the configuration 
 *  for creating animations on LEDs.
 * 
 *  @param a_ptr is a pointer to the struct of 
 *  type animation_led_t in which the animation
 *  configuration is stored.
 * 
 *  @return 0 if successful, -1 if not
 */
int32_t prepare_animation(animation_led_t* a_ptr);


/** @brief is a function to call the 
 *  desired animation.
 * 
 *  The function calls the desired animation
 *  after a timer interrupt occurs. It also 
 *  performs state configuration changes of 
 *  the LEDs to create the desired animation sequence.
 * 
 *  @return void
 */
void animation_handler(void);

/** @brief is a function to create 
 *  animation 1.
 * 
 *  This is the function to create
 *  animation 1. It glows the LEDs
 *  in a series sequence. The parameter
 *  led_num of the animation_led_t
 *  struct doesn't matter for 
 *  this animation.
 * 
 *  @return void
 */
void animation_uno(void);

/** @brief is a function to create 
 *  animation 2.
 * 
 *  This is the function to create
 *  animation 2. It simply increases
 *  the brightness of the LEDs till
 *  the desired brightness is acheived
 *  in a non-blocking interrupt driven
 *  way. 
 * 
 *  @return void
 */
void animation_duo(void);

/** @brief is a function to create 
 *  animation 3.
 * 
 *  This is the function to create
 *  animation 3. It simply reduces
 *  the brightness of the LEDs till
 *  it becomes 0 in a non-blocking 
 *  interrupt driven way. 
 * 
 *  @return void
 */
void animation_tres(void);

/** @brief is a function to find 
 *  the pin mapped for a particular
 *  color
 * 
 *  Each LED number has 3 channels 
 *  R, G and B.
 * 
 *  @param num is the led number.
 * 
 *  @return a pin number between 0 and 15
 */
uint8_t findPin(uint8_t num);

