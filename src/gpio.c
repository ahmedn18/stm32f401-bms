#include "gpio.h"
#include "rcc.h"
#include "bit_math.h"

#define GPIOA_BASE_ADDR 0x40020000
#define GPIO_MODER_OFFSET 0x00
#define GPIO_OTYPER_OFFSET 0x04
#define GPIOA_PUPDR_OFFSET 0x08
#define GPIOA_ODR_OFFSET 0x14
#define GPIOA_MODER (*(volatile unsigned int*)(GPIOA_BASE_ADDR + GPIO_MODER_OFFSET))
#define GPIOA_OTYPER (*(volatile unsigned int*)(GPIOA_BASE_ADDR + GPIO_OTYPER_OFFSET))
#define GPIOA_PUPDR (*(volatile unsigned int*)(GPIOA_BASE_ADDR + GPIOA_PUPDR_OFFSET))
#define GPIOA_ODR (*(volatile unsigned int*)(GPIOA_BASE_ADDR + GPIOA_ODR_OFFSET))

void GPIO_Init(void) {
    rcc_init();
    // Configure GPIOA pins 0, 1, and 2 as output
    SET_BIT(GPIOA_MODER, 0);
    CLEAR_BIT(GPIOA_MODER, 1);
    SET_BIT(GPIOA_MODER, 2);
    CLEAR_BIT(GPIOA_MODER, 3);
    SET_BIT(GPIOA_MODER, 4);
    CLEAR_BIT(GPIOA_MODER, 5);

    // Configure GPIOA pins 0, 1, and 2 as push-pull
    CLEAR_BIT(GPIOA_OTYPER, 0);
    CLEAR_BIT(GPIOA_OTYPER, 1);
    CLEAR_BIT(GPIOA_OTYPER, 2);

    // no pull-up / pull-down : PA0-PA2 are push-pull outputs, they are driven
    // at both levels so they can never float
    CLEAR_BIT(GPIOA_PUPDR, 0);
    CLEAR_BIT(GPIOA_PUPDR, 1);
    CLEAR_BIT(GPIOA_PUPDR, 2);
    CLEAR_BIT(GPIOA_PUPDR, 3);
    CLEAR_BIT(GPIOA_PUPDR, 4);
    CLEAR_BIT(GPIOA_PUPDR, 5);

    // PA3 is the battery input (ADC1_IN3) : analog mode is MODER = 11
    SET_BIT(GPIOA_MODER, 6);
    SET_BIT(GPIOA_MODER, 7);
    // an analog input must have no pull-up / pull-down or it skews the reading
    CLEAR_BIT(GPIOA_PUPDR, 6);
    CLEAR_BIT(GPIOA_PUPDR, 7);
}

void GPIO_SetLeds(unsigned int number) {
    if (number > 3){
        number = 3; // Limit the number of LEDs to 3
    }

    GPIOA_ODR &= ~(0x07);
    GPIOA_ODR |= (1U << number) - 1; // Set the corresponding LED pin

}
