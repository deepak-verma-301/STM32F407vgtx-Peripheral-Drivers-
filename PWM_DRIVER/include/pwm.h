#ifndef PWM_H
#define PWM_H

#include<stm32f407xx.h>
#include<stdint.h>
#include<stdbool.h>
#include<string.h>


#define CH1      1
#define CH2      2
#define CH3      3
#define CH4      4

void pwm_init(TIM_TypeDef *tim , uint8_t channel);
void pwm_freq(TIM_TypeDef *tim, uint32_t val);
void pwm_duty_cycle(TIM_TypeDef *tim, uint8_t channel, uint32_t val);
void pwm_start(TIM_TypeDef *tim, uint8_t channel);









#endif