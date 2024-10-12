#include "motor.h"
#include "adc.h"
#include "pwm.h"

#define xDelay 1000 / portTICK_PERIOD_MS

void update_motor_speed()
{
    // Update motor speed
    int reading = adc_read();
    if (reading >= 2048)
    {
        int duty = (reading - 2048) * 8191 / 2047;
        printf("Duty: %d on FOWARD\n", duty);
        update_duty_cicle(duty, FOWARD);
        update_duty_cicle(0, BACKWARD);
    }
    else
    {
        int duty = (2048 - reading) * 8191 / 2047;
        printf("Duty: %d on BACKWARD\n", duty);
        update_duty_cicle(0, FOWARD);
        update_duty_cicle(duty, BACKWARD);
    }

}

void cc_driver(void *args)
{
    float adc_value;
    printf("Motor driver\n");
    while (1)
    {
        printf("Motor running\n");
        adc_value = adc_read();
        // Convert adc to voltage
        // float voltage = adc_value * 3.3 / 4095;
        float voltage = adc_value * 3.3 / 4095;
        printf("ADC value: %2f Voltage: %2f\n", adc_value, voltage);
        update_motor_speed();
        vTaskDelay(xDelay);
    }
}

