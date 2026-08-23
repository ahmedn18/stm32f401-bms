#ifndef RCC_H
#define RCC_H

# define SET_BIT(REG,BIT)     (REG |= (1 << BIT))
# define CLEAR_BIT(REG,BIT)   (REG &= ~(1 << BIT))
# define TOGGLE_BIT(REG,BIT)  (REG ^= (1 << BIT))
# define GET_BIT(REG,BIT)     ((REG & (1 << BIT)) ? 1 : 0)
//registers needed for the RCC peripheral
// RCC AHB1ENBR , for gpio clock enable
// RCC APB2 , RCC APB2ENBR , for ADC clock enable
// ADC_CCR,Bits 17:16 ADCPRE: ADC prescaler
void rcc_init(void);
#endif