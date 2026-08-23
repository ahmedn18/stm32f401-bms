#include "gpio.h"
#include "adc.h"

/* The task was amended for the Proteus simulation: the LEDs follow three
 * switches on PA4-PA6 instead of the ADC reading, because the ADC is not
 * mapped correctly to the CPU in some Proteus versions.
 *
 * The ADC driver is still part of the deliverable, so it is still configured
 * and sampled on every pass. The reading is kept here where a debugger or a
 * Proteus watch window can see it. */
volatile uint16_t battery_mv = 0U;

void setup(void) {
    GPIO_Init();
    ADC_Init(BATTERY_ADC_CHANNEL);
}

void loop(void) {
    battery_mv = ADC_ToMillivolts(ADC_Read());

    // each switch drives the LED beside it : PA4 -> PA0 , PA5 -> PA1 , PA6 -> PA2
    GPIO_SetLedMask(GPIO_ReadSwitches());
}

int main(void) {
    setup();
    while (1) {
        loop();
    }
}
