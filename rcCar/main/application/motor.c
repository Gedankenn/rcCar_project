#include "motor.h"
#include "adc.h"
#include "pwm.h"

#define xDelay 1000 / portTICK_PERIOD_MS

#define LEDC_TIMER              LEDC_TIMER_0
#define LEDC_MODE               LEDC_HIGH_SPEED_MODE
#define PINA                    25  // Define the output GPIO for PWM on pin 25
#define PINB                    26  // Define the output GPIO for PWM on pin 26
#define FOWARD                  LEDC_CHANNEL_0
#define BACKWARD                LEDC_CHANNEL_1
#define LEDC_DUTY_RES           LEDC_TIMER_13_BIT  // Resolution of PWM duty
#define LEDC_DUTY               4000               // Duty cycle (0-8191 for 13-bit)
#define LEDC_FREQUENCY          5000               // Frequency in Hertz. Set frequency at 5 kHz

void cc_driver(void *args)
{
    int adc_raw;
    printf("Motor driver\n");
    while (1)
    {
        printf("Motor running\n");
        adc_raw = adc1_read(PINA);
        // Convert adc to voltage
        // float voltage = adc_value * 3.3 / 4095;
        float voltage = adc_raw * 3.3 / 4095;
        printf("ADC value: %d Voltage: %2f\n", adc_raw, voltage);
        vTaskDelay(xDelay);
    }
}

