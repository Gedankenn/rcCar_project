#include "pwm.h"
#include "driver/ledc.h"

#define LEDC_TIMER              LEDC_TIMER_0
#define LEDC_MODE               LEDC_HIGH_SPEED_MODE
#define LEDC_OUTPUT_IO_1        25  // Define the output GPIO for PWM on pin 25
#define LEDC_OUTPUT_IO_2        26  // Define the output GPIO for PWM on pin 26
#define LEDC_CHANNEL_1          LEDC_CHANNEL_0
#define LEDC_CHANNEL_2          LEDC_CHANNEL_1
#define LEDC_DUTY_RES           LEDC_TIMER_13_BIT  // Resolution of PWM duty
#define LEDC_DUTY               4000               // Duty cycle (0-8191 for 13-bit)
#define LEDC_FREQUENCY          5000               // Frequency in Hertz. Set frequency at 5 kHz

void PWM_init(void)
{
    // Prepare and initialize configuration for the LEDC timer
    ledc_timer_config_t ledc_timer = {
        .speed_mode       = LEDC_MODE,
        .timer_num        = LEDC_TIMER,
        .duty_resolution  = LEDC_DUTY_RES,
        .freq_hz          = LEDC_FREQUENCY,   // Set output frequency at 5 kHz
        .clk_cfg          = LEDC_AUTO_CLK
    };
    
    // Set configuration of the LEDC timer
    ledc_timer_config(&ledc_timer);

    // Prepare and initialize configuration for the LEDC channel (GPIO 25)
    ledc_channel_config_t ledc_channel_1 = {
        .speed_mode     = LEDC_MODE,
        .channel        = LEDC_CHANNEL_1,
        .timer_sel      = LEDC_TIMER,
        .intr_type      = LEDC_INTR_DISABLE,
        .gpio_num       = LEDC_OUTPUT_IO_1,
        .duty           = 0,                // Set duty cycle to 0 initially
        .hpoint         = 0
    };

    // Set configuration of the LEDC channel (GPIO 26)
    ledc_channel_config_t ledc_channel_2 = {
        .speed_mode     = LEDC_MODE,
        .channel        = LEDC_CHANNEL_2,
        .timer_sel      = LEDC_TIMER,
        .intr_type      = LEDC_INTR_DISABLE,
        .gpio_num       = LEDC_OUTPUT_IO_2,
        .duty           = 0,                // Set duty cycle to 0 initially
        .hpoint         = 0
    };

    // Set configuration for the channels
    ledc_channel_config(&ledc_channel_1);
    ledc_channel_config(&ledc_channel_2);

    // Set duty cycle for GPIO 25
    ledc_set_duty(LEDC_MODE, LEDC_CHANNEL_1, LEDC_DUTY);
    ledc_update_duty(LEDC_MODE, LEDC_CHANNEL_1);

    // Set duty cycle for GPIO 26
    ledc_set_duty(LEDC_MODE, LEDC_CHANNEL_2, LEDC_DUTY);
    ledc_update_duty(LEDC_MODE, LEDC_CHANNEL_2);

}

void update_duty_cicle(int duty, int channel)
{
    ledc_set_duty(LEDC_MODE, channel, duty);
    ledc_update_duty(LEDC_MODE, channel);
}
