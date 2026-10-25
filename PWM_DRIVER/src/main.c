#include<gpio.h>
#include<pwm.h>


int main(){


    gpio_init(GPIOD);
    gpio_mode(GPIOD,AF,13);
    gpio_mode(GPIOD,AF,12);
    gpio_af(GPIOD,13,AF2);
    gpio_af(GPIOD,12,AF2);

    pwm_init(TIM4,CH2);
    pwm_init(TIM4,CH1);
    pwm_freq(TIM4,30);
    pwm_start(TIM4,CH2);
    pwm_start(TIM4,CH1);

    pwm_duty_cycle(TIM4,CH1,20);



    while(1){
        // for(uint8_t i=0;i<=100;i++){
        //     pwm_duty_cycle(TIM4,CH2,i);
        //     pwm_duty_cycle(TIM4,CH1,i);
        //     for(volatile uint32_t j=0;j<=10000;j++){}
        // }
        // for(uint8_t i=100;i>0;i--){
        //     pwm_duty_cycle(TIM4,CH2,i);
        //     pwm_duty_cycle(TIM4,CH1,i);
        //     for(volatile uint32_t j=0;j<=10000;j++){}
        // }
    }


    return 0;
}
