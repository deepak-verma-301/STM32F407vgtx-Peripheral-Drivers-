#include<gpio.h>
#include<usart.h>


int main(){

    gpio_init(GPIOD);    
    gpio_mode(GPIOD,OUTPUT,12);
    gpio_mode(GPIOD,OUTPUT,13);
    gpio_mode(GPIOD,OUTPUT,14);
    gpio_mode(GPIOD,OUTPUT,15);

    gpio_init(GPIOA);
    gpio_mode(GPIOA,AF,2);
    gpio_mode(GPIOA,AF,3);
    gpio_af(GPIOA,2,AF7);
    gpio_af(GPIOA,3,AF7);

    usart_init(USART2);
    usart_baud_rate(USART2,115200);
    usart_data_length(USART2,8);
    usart_stop_bit(USART2,1);
    usart_start(USART2);

    while(1){
        usart_write(USART2,"hello world\n");
        for(volatile uint32_t i=0;i<1000;i++){}
    }



    return 0;
}