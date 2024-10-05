#include "motor.h"
#include "adc.h"

#define xDelay 1000 / portTICK_PERIOD_MS

void cc_driver(void *args)
{
    int adc_value;
    printf("Motor driver\n");
    while (1)
    {
        printf("Motor running\n");
        vTaskDelay(xDelay);
    }
}
