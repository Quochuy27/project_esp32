#ifndef PWM_H_
#define PWM_H_

void pwm_timer_init(int frequency);
void pwm_chanel_config(int pin, int chanel);
void pwm_set_duty(int chanel, float duty);

#endif