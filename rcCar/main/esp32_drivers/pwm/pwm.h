/**
* PWM header file
* Create by Fabio Slika Stella
* 04/11/2024
*
*/

void PWM_init(int gpio, int channel, int mode, int timer, int res, int freq, int clock);
void update_duty_cicle(int duty, int channel);
