#ifndef ADC_H
#define ADC_H

#include <stdint.h>

void     ADC_Init(uint8_t channel);
uint16_t ADC_Read(void);
uint16_t ADC_ToMillivolts(uint16_t raw);

#endif
