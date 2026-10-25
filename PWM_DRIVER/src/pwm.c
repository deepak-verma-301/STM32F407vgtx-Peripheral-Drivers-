#include<pwm.h>
#include<timer.h>


void pwm_init(TIM_TypeDef *tim , uint8_t channel){
    tim_init(tim);
    if(channel == CH1){
        tim->CCMR1 |= 6 << TIM_CCMR1_OC1M_Pos;
        tim->CCMR1 |= TIM_CCMR1_OC1PE;
    }
    else if(channel == CH2){
        tim->CCMR1 |= 6 << TIM_CCMR1_OC2M_Pos;
        tim->CCMR1 |= TIM_CCMR1_OC2PE;
    }
    else if(channel == CH3){
        tim->CCMR2 |= 6 << TIM_CCMR2_OC3CE_Pos;
        tim->CCMR2 |= TIM_CCMR2_OC3PE;
    }
    else if(channel == CH4){
        tim->CCMR2 |= 6 << TIM_CCMR2_OC4CE_Pos;
        tim->CCMR2 |= TIM_CCMR2_OC4PE;
    }

    tim->CR1 |= TIM_CR1_ARPE;

}
void pwm_freq(TIM_TypeDef *tim, uint32_t val){   //val in KHz    
    tim->ARR = 99;
    tim->PSC = (SystemCoreClock/(100*val*1000)) -1;
}
void pwm_duty_cycle(TIM_TypeDef *tim, uint8_t channel, uint32_t val){

    if(val > 100){val = 100;}
    if(channel == CH1){
        tim->CCR1 = val;
    }
    else if(channel == CH2){
        tim->CCR2 = val;
    }
    else if(channel){   
        tim->CCR3 = val;
    }
    else if(channel == CH4){
        tim->CCR4 = val;
    }
}
void pwm_start(TIM_TypeDef *tim, uint8_t channel){
    if(channel == CH1){
        tim->CCER |= TIM_CCER_CC1E;
    }
    else if(channel == CH2){
        tim->CCER |= TIM_CCER_CC2E;
    }
    else if(channel){   
        tim->CCER |= TIM_CCER_CC3E;
    }
    else if(channel == CH4){
        tim->CCER |= TIM_CCER_CC4E;
    }

    tim->EGR |= TIM_EGR_UG;
    tim->CR1 |= TIM_CR1_CEN;
}