# Animation Library

This is an Animation Library using constant current driver IC AW9523. This piece of hardware allows us to drive LEDs with constant current thereby avoiding jitter.
Moreover for MCUs with low I/O pins this can also be used as a GPIO expander. It provides 16 pins for use and it is driven as a slave on the i2c bus. ESP32 is used as master.

## Overview

This project demonstrates APIs for creating LED animations. An example is provided in the main.c file to create a sequence animation.

At the foundation level, it makes use of i2c to communicate with the AW9523 constant current driver to drive the LEDs with particular brightness levels. 

On top of the base layer there is a wrapper class for sending and receiving data from the AW9523. 

This is further wrapped by an ledbase driver, which provides simple apis to configure, setup, set brightness and uninitialize the leds.

Finally the top most layer includes a animation driver which makes use of the aforementioned lower level APIs to create multiple beautiful animations on the LEDs.

The number of animations right now is limited but this library can be largely expanded and is only limited by ones vision.

## How to use example

- Clone the library.
- Inside the main.c file simply create structures for the animation frames that are defined in animation.hardware
- Use the animation handler function your main while(true) loop while checking for the global animations structs animation flag. 
- The implementation is highly non blocking and interrupt driven so you can perform other important things in the main while this happens in the background. 
- A priority can be given to the interrupt if you do not have other critical tasks running in the main while(true) loop.

### Hardware Required

To run this example, you should have one ESP32, ESP32-S or ESP32-C based development board as well as a AW9523. You would also need common anode LEDs and a few wires. 

AW9523 datasheet - https://pdf1.alldatasheet.com/datasheet-pdf/view/1148542/AWINIC/AW9523B.html.
#### Pin Assignment:

**Note:** The following pin assignments are used by default, you can change these in the `menuconfig` .

|                  | SDA             | SCL           |
| ---------------- | -------------- | -------------- |
| ESP I2C Master   | I2C_MASTER_SDA | I2C_MASTER_SCL |
| AW9523		   | SDA            | SCL            |


For the actual default value of `I2C_MASTER_SDA` and `I2C_MASTER_SCL` in `menuconfig`. It is pin 18 and 19 on the ESP32 but varies for other ESPs.

**Note: ** There’s no need to add an external pull-up resistors for SDA/SCL pin, because the driver will enable the internal pull-up resistors.

### Build and Flash

Enter `idf.py -p PORT flash monitor` to build, flash and monitor the project.

(To exit the serial monitor, type ``Ctrl-]``.)

See the [Getting Started Guide](https://docs.espressif.com/projects/esp-idf/en/latest/get-started/index.html) for full steps to configure and use ESP-IDF to build projects.

## Example Output

```bash
I (307) animation: Preparing animation configuration

I (1117) main: Animation 1 complete

I (1117) animation: Preparing animation configuration

I (1927) main: Animation 2 complete

I (1927) animation: Preparing animation configuration

I (2727) main: Animation 3 complete
```

## Troubleshooting

(For any technical queries, please open an [issue](https://github.com/ravisha2396/AnimationLibraryAW9523/issues) on GitHub. We will get back to you as soon as possible.)
