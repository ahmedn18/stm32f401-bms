#ifndef GPIO_H
#define GPIO_H

// PA3 = ADC1_IN3 , the pin the battery divider feeds
#define BATTERY_ADC_CHANNEL 3U

void GPIO_Init(void);
void GPIO_SetLeds(unsigned int number);

#endif
