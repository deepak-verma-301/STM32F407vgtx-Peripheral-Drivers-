#include<adc.h>




void adc_init(ADC_TypeDef *adc){
    if(adc == ADC1){
        RCC->APB2ENR |= RCC_APB2ENR_ADC1EN;
    }
    else if(adc == ADC2){
        RCC->APB2ENR |= RCC_APB2ENR_ADC2EN;
    }
    else if(adc == ADC3){
        RCC->APB2ENR |= RCC_APB2ENR_ADC3EN;
    }
}

void adc_enable(ADC_TypeDef *adc){
    adc->CR2 &= ~ADC_CR2_ADON;
    adc->CR2 |= ADC_CR2_ADON;
}

void adc_noOfChannel(ADC_TypeDef *adc, uint8_t no){
    adc->SQR1 |= (no-1) << ADC_SQR1_L_Pos;
}

void adc_channelRank(ADC_TypeDef *adc,uint8_t ch,uint8_t rank){
    if(rank <=5){
            adc->SQR3 |= ch << ((rank-1)*5);
    }
    else if(rank>5 && rank <=11){
        adc->SQR2 |= ch << ((rank-1)*5);
    }
    else if(rank>11 && rank <=15){
        adc->SQR1 |= ch << ((rank-1) * 5);
    }
}
void adc_resolution(ADC_TypeDef *adc,uint8_t res){
    adc->CR1 |= res << ADC_CR1_RES_Pos;   
}

void adc_cycle(ADC_TypeDef *adc,uint8_t ch,uint8_t cycle){
    if(ch<=9){
        adc->SMPR2 |= cycle << ((ch) * 3);
    }
    else if(ch>9 && ch <=15){
        adc->SMPR1 |= cycle << ((ch) *3);
    }
}

void adc_startConv(ADC_TypeDef *adc,uint8_t ch){
    adc->CR2 |= ADC_CR2_CONT; 
    adc->CR2 |= ADC_CR2_SWSTART;
     
}
uint16_t adc_read(ADC_TypeDef *adc,uint8_t ch){
    while(!(adc->SR & ADC_SR_EOC)){}
    return adc->DR;
}


