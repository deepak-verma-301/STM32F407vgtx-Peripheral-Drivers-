#include<gpio.h>
#include<usart.h>
#include<adc.h>
#include<string.h>
#include<stdio.h>


int main(){


    gpio_init(GPIOA);
    gpio_init(GPIOD);
    
    gpio_mode(GPIOA,AF,2);
    gpio_mode(GPIOA,AF,3);
    gpio_mode(GPIOA,ANALOG,5);

    gpio_af(GPIOA,2,AF7);
    gpio_af(GPIOA,3,AF7);

    usart_init(USART2);
    usart_baud_rate(USART2,115200);
    usart_data_length(USART2,8);
    usart_stop_bit(USART2,1);
    usart_start(USART2);

    adc_init(ADC1);
    adc_enable(ADC1);
    adc_channelRank(ADC1,5,1);
    adc_noOfChannel(ADC1,1);
    adc_resolution(ADC1,RES_12_Bit);
    adc_cycle(ADC1,5,cycle56);
    adc_startConv(ADC1,5);


    while(1){
        uint16_t potval = adc_read(ADC1,5);
        char message[20];
        snprintf(message,sizeof(message),"%d",potval);
        usart_write(USART2,message);
        usart_write_char(USART2,'\n');

        for(volatile uint32_t i=0;i<=10000;i++){__asm("NOP");}
    }





}
