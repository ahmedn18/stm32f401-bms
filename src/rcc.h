#ifndef RCC_H
#define RCC_H

#include "bit_math.h"

// registers needed for the RCC peripheral
//  RCC AHB1ENBR , for gpio clock enable
//  RCC APB2 , RCC APB2ENBR , for ADC clock enable
//  ADC_CCR,Bits 17:16 ADCPRE: ADC prescaler
void rcc_init(void);

#endif
