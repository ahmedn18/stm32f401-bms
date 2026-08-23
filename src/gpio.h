#ifndef GPIO_H
#define GPIO_H

// PA4 = ADC1_IN4 , the pin the battery is measured on
#define BATTERY_ADC_CHANNEL 4U

void GPIO_Init(void);
void GPIO_SetLeds(unsigned int number);

#endif
