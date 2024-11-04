/**
* Author: Fabio Slika Stella
* Date: 2024/09/27
* Version: 0.1
* Description: This is a simple program to control a RC car using a ESP32
**/

#include <stdio.h>
#include "application/motor.h"

#include "pwm.h"
#include "adc.h"

const TickType_t xDelay = 100 / portTICK_PERIOD_MS;
TaskHandle_t handle_cc = NULL;

void app_main(void)
{
    adc1_init(); 
    printf("Minimum free heap size: %" PRIu32 " bytes\n", esp_get_minimum_free_heap_size());
    xTaskCreate(cc_driver, "CC_motor", 2048, NULL, 10, &handle_cc);

    while (1)
    {
        vTaskDelay(xDelay);
    }
}
