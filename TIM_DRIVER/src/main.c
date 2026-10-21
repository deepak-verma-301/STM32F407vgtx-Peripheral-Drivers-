#include<gpio.h>
#include<timer.h>



int main(){

    gpio_init(GPIOD);
    gpio_mode(GPIOD,OUTPUT,13);
    tim_init(TIM2);
    tim_dir(TIM2,UP);
    tim_psc(TIM2,15999);
    tim_arr(TIM2,1000);
    tim_start(TIM2);

    while(1){
        if(tim_counter(TIM2) > 500){
            gpio_set(GPIOD,13);
        }
        else{
            gpio_reset(GPIOD,13);
        }
    }

    return 0;
}