#ifndef ADC_H
#define ADC_H

#include "stm32f401xc.h"
#include <stdint.h>

void ADC_Init(uint8_t channel);
uint16_t ADC_Read(void);
float ADC_ToVoltage(uint16_t raw);

#endif 