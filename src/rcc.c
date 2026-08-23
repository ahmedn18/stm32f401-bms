#include "rcc.h"
#include "stm32f401.h"
void rcc_init(void) {
    //for Gpio clock enable
    SET_BIT(RCC_AHB1ENBR, 0); //enable clock for GPIOA
    //for ADC clock enable
    SET_BIT(RCC_APB2ENBR, 8);//ADC1 clock enable
    //now to choose the prescaler for ADC , we need to know the frequency of the ADC from the datasheet , 
    //the max frequency that can be applied on the APB2 bus is 84 MHZ , for the 12 bit ADC
    //the typical fADC is 30Mhz , max is 36 MHz 
    //in case of VDDA = 2.4 to 3.6 V
    //so the frequency of the clock applied to the ADC is 84 MHz , so we need to divide it by 4 to get 21 MHz which is less than 30 MHz
    //𝑓𝐴𝐷𝐶=𝑓𝐴𝑃𝐵2/f Prescaler
    CLEAR_BIT(ADC_CCR , 17);
    SET_BIT(ADC_CCR, 16);//prescalar 4
    //once i gto here i thought i finished , but there is the PLL configuration that i didn't know about
    // the PLL takes the HSI(high speed internal clock ) , in the data sheet it's 16MHz 
    //the equations are the follwing :
    // VCO_input  = HSI / PLLM (VCO input is in range of 0.95-2.1 with typical of 1 , HSI = 16 , therfore i use PLLM as 16)
    //VCO_output = VCO_input(1) * PLLN
    //PLL_output (SYSCLK = 84) = VCO_output / PLLP 
    // PLLP can only be 4 numbers ( 2,4,6,8) , VCO output has a range of (192-432) , if we pick the pllp as 4 
    //the VCO out will be 84*4 = 336 , within range 
    // PLLN = 336/1 = 336 
    CLEAR_BIT(RCC_PLLCFGR , 17); 
    SET_BIT(RCC_PLLCFGR , 16);//set pllp as 4

    RCC_PLLCFGR &= ~(0x3F << 0);
    RCC_PLLCFGR |= (16 << 0); //pllm = 16
   
    RCC_PLLCFGR &= ~(0x1FF << 6);
    RCC_PLLCFGR |= (336 << 6); // set plln = 336 
    //also pll must be enabled for the systmen to work
    SET_BIT(RCC_CR , 24);
    while (!GET_BIT(RCC_CR, 25));//we must wait until it is high first , this is PLLRDY: Main PLL (PLL) clock ready flag
    //now from data sheet the frequency on APB1 is 42 MHz , so we need a prescalar 2
    SET_BIT(RCC_CFGR, 12);
    CLEAR_BIT(RCC_CFGR,11); 
    CLEAR_BIT(RCC_CFGR, 10);
    //the pll must me selected as system clock by code
    SET_BIT(RCC_CFGR ,1);
    CLEAR_BIT(RCC_CFGR,0);
   
  