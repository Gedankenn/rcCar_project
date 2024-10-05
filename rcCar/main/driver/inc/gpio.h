// *----gpio config -----------------------

// #define BLDC_DRV_EN_GPIO    18
// #define BLDC_DRV_FAULT_GPIO 19
// #define BLDC_DRV_OVER_CURRENT_FAULT MCPWM_SELECT_F0

#include "driver/gpio.h"

#define GPIO_PWM0A_OUT 25   //Set GPIO 25 as PWM0A
#define GPIO_PWM0B_OUT 26   //Set GPIO 26 as PWM0B

#define BLDC_DRV_EN_GPIO 22

void gpio_init(void);
