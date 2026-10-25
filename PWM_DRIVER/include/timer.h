#ifndef USART_H
#define USART_H

#include<stm32f407xx.h>
#include<stdint.h>
#include<stdbool.h>
#include<string.h>


void tim_init(TIM_TypeDef *tim);

#define UP     0
#define DOWN   1
void tim_dir(TIM_TypeDef *tim, bool upORdown);

void tim_psc(TIM_TypeDef *tim, uint16_t value);
void tim_arr(TIM_TypeDef *tim, uint16_t value);
uint32_t tim_counter(TIM_TypeDef *tim);
void tim_start(TIM_TypeDef *tim);



#endif
