#include "ADC.h"

void ADC_Init(uint8_t channel) {

    ADC1_COMMON->CCR &= ~ADC_CCR_ADCPRE;     
    ADC1_COMMON->CCR |= ADC_CCR_ADCPRE_0;    

    ADC1->CR1 &= ~ADC_CR1_RES;               
    ADC1->CR1 &= ~ADC_CR1_SCAN;              

    ADC1->CR2 &= ~ADC_CR2_ALIGN;             
    ADC1->CR2 |= ADC_CR2_CONT;               

    if (channel < 10) {
        ADC1->SMPR2 &= ~(7U << (3 * channel));   
        ADC1->SMPR2 |= (7U << (3 * channel));     
    } else if (channel < 19) {
        ADC1->SMPR1 &= ~(7U << (3 * (channel - 10))); 
        ADC1->SMPR1 |= (7U << (3 * (channel - 10)));  
    }

    ADC1->SQR1 &= ~ADC_SQR1_L;               
    ADC1->SQR3 &= ~ADC_SQR3_SQ1;             
    ADC1->SQR3 |= (channel & 0x1F);          
    ADC1->CR2 |= ADC_CR2_ADON;

    for (volatile uint32_t i = 0; i < 2000; i++) {
        __asm__("nop"); 
    }
}

uint16_t ADC_Read(void) {
    if (ADC1->SR & ADC_SR_OVR) {
        ADC1->SR &= ~ADC_SR_OVR; 
    }

    ADC1->CR2 |= ADC_CR2_SWSTART;

    return (uint16_t)(ADC1->DR & 0xFFF); 
}

float ADC_ToVoltage(uint16_t raw) {
    // 0-4095 mapped to 0.0 - 3.3V
    return ((float)raw * 3.3f) / 4095.0f;
}