
#define RCC_AHB1ENBR_baseAddress 0x40023800
#define RCC_AHB1ENBR_offset 0x30

#define RCC_APB2ENBR_baseAddress 0x40023800

#define RCC_APB2ENBR_offset 0x44

#define ADC_CCR_baseAddress 0x40012300

#define ADC_CCR_offset 0x04

#define RCC_AHB1ENBR *((volatile unsigned int*)(RCC_AHB1ENBR_baseAddress + RCC_AHB1ENBR_offset))
#define RCC_APB2ENBR *((volatile unsigned int*)(RCC_APB2ENBR_baseAddress + RCC_APB2ENBR_offset))
#define ADC_CCR *((volatile unsigned int*)(ADC_CCR_baseAddress + ADC_CCR_offset))