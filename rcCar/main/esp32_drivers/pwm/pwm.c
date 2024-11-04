#include "pwm.h"
#include "driver/ledc.h"
#include "hal/ledc_types.h"

void PWM_init(int gpio, int channel, int mode, int timer, int res, int freq, int clock)
{
    // Prepare and initialize configuration for the LEDC timer
    ledc_timer_config_t ledc_timer = {
        .speed_mode       = mode,
        .timer_num        = timer,
        .duty_resolution  = res,
        .freq_hz          = freq,   // Set output frequency at 5 kHz
        .clk_cfg          = clock
    };
    
    // Set configuration of the LEDC timer
    ledc_timer_config(&ledc_timer);

    // Prepare and initialize configuration for the LEDC channel (GPIO 25)
    ledc_channel_config_t ledc = {
        .speed_mode     = mode,
        .channel        = channel,
        .timer_sel      = timer,
        .intr_type      = LEDC_INTR_DISABLE,
        .gpio_num       = gpio,
        .duty           = 0,                // Set duty cycle to 0 initially
        .hpoint         = 0
    };

    // Set configuration for the channels
    ledc_channel_config(&ledc);
}

void update_duty_cicle(int duty, int channel)
{
    // Set duty cycle for GPIO 25
    // duty = 0-8191 for 13-bit
    
    ledc_set_duty(LEDC_HIGH_SPEED_MODE, channel, duty);
    ledc_update_duty(LEDC_HIGH_SPEED_MODE, channel);
}
