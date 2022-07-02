/* i2c - Simple example

   Simple I2C example that shows how to initialize I2C
   as well as reading and writing from and to registers for a sensor connected over I2C.

   The sensor used in this example is a MPU9250 inertial measurement unit.

   For other examples please check:
   https://github.com/espressif/esp-idf/tree/master/examples

   See README.md file to get detailed usage of this example.

   This example code is in the Public Domain (or CC0 licensed, at your option.)

   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
*/
#include <stdio.h>
#include "esp_log.h"
#include "driver/i2c.h"
#include "AW9523.h"

//static const char *TAG = "i2c-simple-example";

void app_main(void)
{   
    /*
    printf("Inside main!\n");
    //uint8_t data[2];
    ESP_ERROR_CHECK(aw9523_init());
    ESP_LOGI(TAG, "I2C initialized successfully");

    printf("Starting writes!\n");

    aw9523_register_write_byte(CONTROL_REG, 0x10);
    printf("Wrote value to reg\n");

    // configure P0 as LED/GPIO mode
    aw9523_register_write_byte(MODE_REG, 0x00);
    printf("Wrote value to reg\n");

    aw9523_register_write_byte(0x13, 0xDF);
    printf("Wrote value to reg\n");

    const TickType_t xDelay = 10 / portTICK_PERIOD_MS;
    //aw9523_register_write_byte(0x24, 0);
    for(int i = 0; i <= 255 ; i++){
            aw9523_register_write_byte(0x24, i);
            vTaskDelay( xDelay );
            if(i == 255)
            {
                i=0;
                printf("i value is %d\n", i);
            }
        
     }
    //aw9523_register_write_byte(0x24, 0);
    
    //aw9523_register_write_byte(0x25, 0xDF);
    printf("Wrote value to reg\n");
    uint8_t val;

    aw9523_register_read(0x25, &val, sizeof(val));
    printf("Data in val register 5: %d\n", val);

    aw9523_register_read(0x26, &val, sizeof(val));
    printf("Data in val register 6: %d\n", val);

    aw9523_register_read(0x27, &val, sizeof(val));
    printf("Data in val register 7: %d\n", val);

    aw9523_register_read(CONTROL_REG, &val, sizeof(val));
    printf("Data in gcr register: %d\n", val);

    aw9523_register_read(MODE_REG, &val, sizeof(val));
    printf("Data in mode register: %d\n", val);

    aw9523_register_read(0x13, &val, sizeof(val));
    printf("Data in mode register: %d\n", val);

    ESP_ERROR_CHECK(i2c_driver_delete(I2C_MASTER_NUM));
    ESP_LOGI(TAG, "I2C unitialized successfully");
    */
}
