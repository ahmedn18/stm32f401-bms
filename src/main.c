#include "gpio.h"
#include "adc.h"

// battery thresholds in millivolts , anything below LEVEL_MEDIUM still lights
// one LED so that a flat battery is told apart from a dead board
#define LEVEL_MEDIUM 1100U
#define LEVEL_HIGH   2200U

static unsigned int leds_for(uint16_t millivolts) {
    if (millivolts >= LEVEL_HIGH) {
        return 3U;
    }
    if (millivolts >= LEVEL_MEDIUM) {
        return 2U;
    }
    return 1U;
}

void setup(void) {
    GPIO_Init();
    ADC_Init(BATTERY_ADC_CHANNEL);
}

void loop(void) {
    GPIO_SetLeds(leds_for(ADC_ToMillivolts(ADC_Read())));
}

int main(void) {
    setup();
    while (1) {
        loop();
    }
}
