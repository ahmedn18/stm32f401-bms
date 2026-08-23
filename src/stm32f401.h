#ifndef STM32F401_H
#define STM32F401_H

#define RCC_AHB1ENBR_baseAddress 0x40023800
#define RCC_AHB1ENBR_offset 0x30
#define RCC_APB2ENBR_baseAddress 0x40023800
#define RCC_APB2ENBR_offset 0x44
#define ADC_CCR_baseAddress 0x40012300
#define ADC_CCR_offset 0x04
#define RCC_PLLCFG_baseAddress 0x40023800
#define RCC_CFGR_offset 0x08
#define RCC_CFGR_baseAddress 0x40023800
#define RCC_PLLCFG_offset 0x04
#define RCC_PLLCFG_baseAddress 0x40023800
#define RCC_CR_baseAddress 0x40023800
#define RCC_CR_offset 0x00

#define RCC_CR *((volatile unsigned int *)(RCC_CR_baseAddress + RCC_CR_offset))
#define RCC_AHB1ENBR                                                           \
  *((volatile unsigned int *)(RCC_AHB1ENBR_baseAddress + RCC_AHB1ENBR_offset))
#define RCC_APB2ENBR                                                           \
  *((volatile unsigned int *)(RCC_APB2ENBR_baseAddress + RCC_APB2ENBR_offset))
#define ADC_CCR                                                                \
  *((volatile unsigned int *)(ADC_CCR_baseAddress + ADC_CCR_offset))
#define RCC_PLLCFGR                                                            \
  *((volatile unsigned int *)(RCC_PLLCFG_baseAddress + RCC_PLLCFG_offset))
#define RCC_CFGR                                                               \
  *((volatile unsigned int *)(RCC_CFGR_baseAddress + RCC_CFGR_offset))

#endif
