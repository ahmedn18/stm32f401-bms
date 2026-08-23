#include "adc.h"
#include "stm32f401.h"
#include "bit_math.h"

void ADC_Init(uint8_t channel) {
    // 12 bit resolution , CR1 RES = 00
    ADC1_CR1 &= ~(0x3U << 24);
    CLEAR_BIT(ADC1_CR1, 8);   // SCAN off , we only convert one channel

    CLEAR_BIT(ADC1_CR2, 11);  // ALIGN = right , so DR holds a plain 0-4095
    SET_BIT(ADC1_CR2, 1);     // CONT = keep converting on its own

    // longest sampling time (111 = 480 cycles) , the source impedance of a
    // battery divider is high and a short sample would not settle
    if (channel < 10U) {
        ADC1_SMPR2 &= ~(0x7U << (3U * channel));
        ADC1_SMPR2 |=  (0x7U << (3U * channel));
    } else {
        ADC1_SMPR1 &= ~(0x7U << (3U * (channel - 10U)));
        ADC1_SMPR1 |=  (0x7U << (3U * (channel - 10U)));
    }

    ADC1_SQR1 &= ~(0xFU << 20);      // L = 0 , one conversion in the sequence
    ADC1_SQR3 &= ~0x1FU;
    ADC1_SQR3 |= (channel & 0x1FU);  // SQ1 = our channel

    SET_BIT(ADC1_CR2, 0);            // ADON
    for (volatile uint32_t i = 0U; i < 2000U; i++) {
        __asm__ volatile ("nop");    // tSTAB before the first conversion
    }
    SET_BIT(ADC1_CR2, 30);           // SWSTART , continuous mode runs from here
}

uint16_t ADC_Read(void) {
    while (GET_BIT(ADC1_SR, 1) == 0U) { /* wait for EOC */ }
    return (uint16_t)(ADC1_DR & 0x0FFFU); // reading DR clears EOC
}

uint16_t ADC_ToMillivolts(uint16_t raw) {
    return (uint16_t)(((uint32_t)raw * 3300U) / 4095U);
}
