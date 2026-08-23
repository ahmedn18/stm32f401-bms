/* What runs before main().
 *
 * Every symbol used here comes from linker.ld: _estack is the top of RAM,
 * _sidata is where the initialised data sits in flash, and _sdata/_edata and
 * _sbss/_ebss bracket the two RAM regions that have to be prepared.
 */

#include <stdint.h>

extern uint32_t _sidata, _sdata, _edata, _sbss, _ebss, _estack;

int main(void);

void reset_handler(void) {
    uint32_t *src = &_sidata;
    uint32_t *dst = &_sdata;

    // initialised globals are stored in flash , copy them into RAM
    while (dst < &_edata) {
        *dst++ = *src++;
    }

    // C says uninitialised globals start at zero , so clear .bss
    for (dst = &_sbss; dst < &_ebss; ) {
        *dst++ = 0U;
    }

    main();

    // main() never returns , but if it ever did there is nowhere to go
    for (;;) { }
}

static void default_handler(void) {
    for (;;) { }
}

/* The vector table must be the first thing in flash. On reset the core loads
 * the stack pointer from offset 0x00 and jumps to the address at 0x04, before
 * a single instruction of ours has run. linker.ld KEEPs this section so
 * --gc-sections cannot discard it, and everything else is reachable from here.
 */
__attribute__((section(".isr_vector"), used))
void (* const vector_table[])(void) = {
    (void (*)(void))&_estack,   // 0x00 initial stack pointer
    reset_handler,              // 0x04 reset
    default_handler,            // 0x08 NMI
    default_handler,            // 0x0C hard fault
    default_handler,            // 0x10 memory management fault
    default_handler,            // 0x14 bus fault
    default_handler,            // 0x18 usage fault
};
