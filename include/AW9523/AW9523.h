/** @file AW9523.h
 *  @brief Function prototypes to communicate with AW9523 IC over I2C.
 *
 *  This contains the prototypes for i2c communcation 
 *  AW9523 using i2c and eventually any macros, constants,
 *  or global variables you will need.
 *  The driver functions in this file can be
 *  used to control the AW9523 IC in three modes:
 *  a) LED driver constant current mode
 *  b) GPIO Input
 *  c) GPIO Output
 * 
 *  AW9523 is an inexpensive GPIO expander with constant
 *  current driving capabilities. The I2C address of the IC
 *  is subject to change based on the mode it is configured in.
 *
 *  @author Ravi Shankar (rnolas13@asu.edu)
 *  @bug No known bugs. 
 */

#define I2C_TARGET_DEVICE           CONFIG_IDF_TARGET_ESP32    /*!< Target architecture set to ESP32 */
#define I2C_MASTER_SCL_IO           CONFIG_I2C_MASTER_SCL      /*!< GPIO number used for I2C master clock */
#define I2C_MASTER_SDA_IO           CONFIG_I2C_MASTER_SDA      /*!< GPIO number used for I2C master data  */
#define I2C_MASTER_NUM              0                          /*!< I2C master i2c port number, the number of i2c peripheral interfaces available will depend on the chip */
#define I2C_MASTER_FREQ_HZ          400000                     /*!< I2C master clock frequency */
#define I2C_MASTER_TX_BUF_DISABLE   0                          /*!< I2C master doesn't need buffer */
#define I2C_MASTER_RX_BUF_DISABLE   0                          /*!< I2C master doesn't need buffer */
#define I2C_MASTER_TIMEOUT_MS       1000                       /*!< I2C Communication timeout value */

#ifndef AW9523_DRIVER_ADDR
#define AW9523_DRIVER_ADDR                    0x58             /*!< AW9523 default address */

/** @brief Initializes the I2C configuration on master 
 *  and registers I2C driver.
 * 
 *  Currently defined only for ESP32 architecure.
 * 
 *  @return 0 if successful, -1 if not
 */
int aw9523_init(void);

/** @brief This is a helper function to 
 *  read the value of a register of AW9523.
 * 
 *  Currently defined for ESP32 architecture.
 * 
 *  @param reg_addr the hex register address value
 *  @param data a pointer to the data of size one byte
 *  @param len number of bytes, always 1 in this case
 * 
 *  @return 0 if successful, -1 if not
 */
int aw9523_register_read(uint8_t reg_addr, uint8_t *data, size_t len);

/** @brief This is a helper function to 
 *  write a value to a register of AW9523.
 * 
 *  Currently defined for ESP32 architecture.
 * 
 *  @param reg_addr the hex register address value
 *  @param data a pointer to the data of size one byte
 * 
 *  @return 0 if successful, -1 if not
 */
int aw9523_register_write_byte(uint8_t reg_addr, uint8_t data);


/** @brief This is a helper function to 
 *  unregister the I2C communication with
 *  AW9523 slave device.
 * 
 *  Currently defined for ESP32 architecture.
 * 
 *  @return 0 if successful, -1 if not
 */
int aw9523_driver_delete(void);

#endif /* AW9523_DRIVER_ADDR */







