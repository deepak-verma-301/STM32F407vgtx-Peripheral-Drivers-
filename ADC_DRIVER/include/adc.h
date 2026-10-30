#ifndef ADC_H
#define ADC_H


#include<stm32f407xx.h>
#include<stdint.h>
#include<stdbool.h>

#define RES_12_Bit  0U
#define RES_10_Bit  1U
#define RES_8_Bit   2U
#define RES_6_Bit   3U

#define cycle3    0U
#define cycle15   1U
#define cycle28   2U
#define cycle56   3U
#define cycle84   4U
#define cycle112  5U
#define cycle144  6U
#define cycle480  7U

void adc_init(ADC_TypeDef *adc);
void adc_enable(ADC_TypeDef *adc);
void adc_noOfChannel(ADC_TypeDef *adc, uint8_t no);
void adc_channelRank(ADC_TypeDef *adc,uint8_t ch,uint8_t rank);
void adc_resolution(ADC_TypeDef *adc,uint8_t res);
void adc_cycle(ADC_TypeDef *adc,uint8_t ch,uint8_t cycle);
void adc_startConv(ADC_TypeDef *adc,uint8_t ch);
uint16_t adc_read(ADC_TypeDef *adc,uint8_t ch);






#endif