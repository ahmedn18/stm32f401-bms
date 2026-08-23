#include "gpio.h"

static void delay(volatile unsigned int count) {
    while (count--){
        __asm__ volatile ("nop");
    }
}

void setup() {
    GPIO_Init();
}

void loop() {
    GPIO_SetLeds(adc_read()); // Read ADC value and set LEDs accordingly
}

int main(void) {
    setup();
    while (1) {
        loop();
    }
}