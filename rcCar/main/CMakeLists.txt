idf_component_register(SRCS "rcCar.c"
                            "esp32_drivers/adc/adc.c"
                            "esp32_drivers/pwm/pwm.c"
                            "application/motor.c"
                    INCLUDE_DIRS "."
                                 "esp32_drivers/pwm/"
                                 "esp32_drivers/adc/"
                                 )
