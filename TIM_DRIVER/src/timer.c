#include<timer.h>


void tim_init(TIM_TypeDef *tim){
    if(tim == TIM11){
        RCC->APB2ENR |= RCC_APB2ENR_TIM11EN;
    }
    else if(tim == TIM10){
        RCC->APB2ENR |= RCC_APB2ENR_TIM10EN;
    }
    else if(tim == TIM9){
        RCC->APB2ENR |= RCC_APB2ENR_TIM9EN;
    }
    else if(tim == TIM8){
        RCC->APB2ENR |= RCC_APB2ENR_TIM8EN;
    }
    else if(tim == TIM1){
        RCC->APB2ENR |= RCC_APB2ENR_TIM1EN;
    }
    else if(tim == TIM14){
        RCC->APB1ENR |= RCC_APB1ENR_TIM14EN;
    }
    else if(tim == TIM13){
        RCC->APB1ENR |= RCC_APB1ENR_TIM13EN;
    }
    else if(tim == TIM12){
        RCC->APB1ENR |= RCC_APB1ENR_TIM12EN;
    }
    else if(tim == TIM7){
        RCC->APB1ENR |= RCC_APB1ENR_TIM7EN;
    }
    else if(tim == TIM6){
        RCC->APB1ENR |= RCC_APB1ENR_TIM6EN;
    }
    else if(tim == TIM5){
        RCC->APB1ENR |= RCC_APB1ENR_TIM5EN;
    }
    else if(tim == TIM4){
        RCC->APB1ENR |= RCC_APB1ENR_TIM4EN;
    }
    else if(tim == TIM3){
        RCC->APB1ENR |= RCC_APB1ENR_TIM3EN;
    }else if(tim == TIM2){
        RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;
    }
}


void tim_dir(TIM_TypeDef *tim, bool upORdown){
    if(upORdown){
        tim->CR1 |= TIM_CR1_DIR;
    }
    else{
        tim->CR1 &= ~TIM_CR1_DIR;
    }
}

void tim_psc(TIM_TypeDef *tim, uint16_t value){
        tim->PSC = value;
}
void tim_arr(TIM_TypeDef *tim, uint16_t value){
    tim->ARR = value;
}
uint32_t tim_counter(TIM_TypeDef *tim){
    return tim->CNT;
}
void tim_start(TIM_TypeDef *tim){
    tim->EGR |= TIM_EGR_UG;
    tim->CR1 |= TIM_CR1_CEN;
}

