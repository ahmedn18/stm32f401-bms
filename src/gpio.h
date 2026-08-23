#ifndef GPIO_H
#define GPIO_H

// PA3 = ADC1_IN3 , the pin the battery divider feeds
#define BATTERY_ADC_CHANNEL 3U

// PA4 , PA5 , PA6 : the three switches that drive the LEDs in the simulation
#define SWITCH_FIRST_PIN 4U

void GPIO_Init(void);
unsigned int GPIO_ReadSwitches(void);
void GPIO_SetLedMask(unsigned int mask);
void GPIO_SetLeds(unsigned int number);

#endif
