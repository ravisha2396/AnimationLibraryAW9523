#define MIN_TIME 1000U

uint64_t timePeriod;

esp_timer_handle_t periodic_timer; 

typedef struct {      
    uint8_t step_time;                      
    uint8_t type;              
    uint8_t led_num;    
    uint8_t br_val;
    uint8_t color; 
    uint8_t max_leds;
    bool animation_flag;
} animation_led_t;

typedef struct {
    bool led_status[5];
    bool set;
    bool iter_done;
    uint8_t br;
    uint8_t ctr;       
} animation_uno_t;

typedef struct {
    bool set;
    bool iter_done;  
    uint8_t br;     
} animation_duo_t;

typedef struct {
    bool set;
    bool iter_done;
    uint8_t br;        
} animation_tres_t;



int32_t prepare_animation(animation_led_t* a_ptr);

void animation_handler(void);

void animation_uno(void);

void animation_duo(void);

void animation_tres(void);

uint8_t findPin(uint8_t num);

