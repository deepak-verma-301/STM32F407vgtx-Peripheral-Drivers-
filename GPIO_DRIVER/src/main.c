#include<gpio.h>


int main(){

    gpio_init(GPIOD);
    gpio_mode(GPIOD,OUTPUT,12);
    
    while(1){
        gpio_set(GPIOD,12);
        for(volatile uint32_t i=0;i<=100000;i++){}
        gpio_reset(GPIOD,12);
        for(volatile uint32_t i=0;i<=100000;i++){} 
    }

    return 0;
}
