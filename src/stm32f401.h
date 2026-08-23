#ifndef STM32F401_H
#define STM32F401_H

#define REG32(ADDR) (*((volatile unsigned int *)(ADDR)))

/* ---- peripheral base addresses (RM0368, memory map) ---- */
#define RCC_baseAddress        0x40023800U
#define FLASH_IF_baseAddress   0x40023C00U
#define PWR_baseAddress        0x40007000U
#define ADC1_baseAddress       0x40012000U
#define ADC_COMMON_baseAddress 0x40012300U

/* ---- register offsets ---- */
#define RCC_CR_offset       0x00U
#define RCC_PLLCFG_offset   0x04U
#define RCC_CFGR_offset     0x08U
#define RCC_AHB1ENBR_offset 0x30U
#define RCC_APB1ENR_offset  0x40U
#define RCC_APB2ENBR_offset 0x44U

#define FLASH_ACR_offset    0x00U
#define PWR_CR_offset       0x00U

#define ADC_SR_offset       0x00U
#define ADC_CR1_offset      0x04U
#define ADC_CR2_offset      0x08U
#define ADC_SMPR1_offset    0x0CU
#define ADC_SMPR2_offset    0x10U
#define ADC_SQR1_offset     0x2CU
#define ADC_SQR3_offset     0x34U
#define ADC_DR_offset       0x4CU
#define ADC_CCR_offset      0x04U

/* ---- registers ---- */
#define RCC_CR       REG32(RCC_baseAddress + RCC_CR_offset)
#define RCC_PLLCFGR  REG32(RCC_baseAddress + RCC_PLLCFG_offset)
#define RCC_CFGR     REG32(RCC_baseAddress + RCC_CFGR_offset)
#define RCC_AHB1ENBR REG32(RCC_baseAddress + RCC_AHB1ENBR_offset)
#define RCC_APB1ENR  REG32(RCC_baseAddress + RCC_APB1ENR_offset)
#define RCC_APB2ENBR REG32(RCC_baseAddress + RCC_APB2ENBR_offset)

#define FLASH_ACR    REG32(FLASH_IF_baseAddress + FLASH_ACR_offset)
#define PWR_CR       REG32(PWR_baseAddress + PWR_CR_offset)

#define ADC1_SR      REG32(ADC1_baseAddress + ADC_SR_offset)
#define ADC1_CR1     REG32(ADC1_baseAddress + ADC_CR1_offset)
#define ADC1_CR2     REG32(ADC1_baseAddress + ADC_CR2_offset)
#define ADC1_SMPR1   REG32(ADC1_baseAddress + ADC_SMPR1_offset)
#define ADC1_SMPR2   REG32(ADC1_baseAddress + ADC_SMPR2_offset)
#define ADC1_SQR1    REG32(ADC1_baseAddress + ADC_SQR1_offset)
#define ADC1_SQR3    REG32(ADC1_baseAddress + ADC_SQR3_offset)
#define ADC1_DR      REG32(ADC1_baseAddress + ADC_DR_offset)
#define ADC_CCR      REG32(ADC_COMMON_baseAddress + ADC_CCR_offset)

#endif
