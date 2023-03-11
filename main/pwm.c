
#include <stdio.h>
#include "driver/ledc.h"

#include "pwm.h"

#define LEDC_TIMER              LEDC_TIMER_0
#define LEDC_MODE               LEDC_LOW_SPEED_MODE

#define LEDC_DUTY_RES           LEDC_TIMER_13_BIT // Set duty resolution to 13 bits




    void pwm_timer_init(int frequency)
    { // Prepare and then apply the LEDC PWM timer configuration
            ledc_timer_config_t ledc_timer = {
                .speed_mode       = LEDC_MODE,
                .timer_num        = LEDC_TIMER,
                .duty_resolution  = LEDC_DUTY_RES,
                .freq_hz          = frequency,  // Set output frequency at 5 kHz
                .clk_cfg          = LEDC_AUTO_CLK
            };
            ledc_timer_config(&ledc_timer);
    }
    // Prepare and then apply the LEDC PWM channel configuration
    void pwm_chanel_config(int pin, int chanel)
    {
        ledc_channel_config_t ledc_channel = {
        .speed_mode     = LEDC_MODE,
        .channel        = chanel,
        .timer_sel      = LEDC_TIMER,
        .intr_type      = LEDC_INTR_DISABLE,
        .gpio_num       = pin,
        .duty           = 0, // Set duty to 0%
        .hpoint         = 0
        };
    
    ledc_channel_config(&ledc_channel);
    }
 
    void pwm_set_duty(int chanel, float duty)
    {
        ledc_set_duty(LEDC_LOW_SPEED_MODE,chanel,duty);
        ledc_update_duty(LEDC_LOW_SPEED_MODE,chanel);
    }