/* STM32F401CC : 256K flash at 0x08000000, 64K RAM at 0x20000000.
 *
 * src/startup.c has to provide these, or the link fails:
 *   reset_handler          the entry point named below
 *   .isr_vector section    stack top first, then reset_handler
 * and it consumes the symbols this script defines:
 *   _estack _sidata _sdata _edata _sbss _ebss
 */

ENTRY(reset_handler)

MEMORY
{
  FLASH (rx)  : ORIGIN = 0x08000000, LENGTH = 256K
  RAM   (rwx) : ORIGIN = 0x20000000, LENGTH = 64K
}

_estack = ORIGIN(RAM) + LENGTH(RAM);   /* stack grows down from the top of RAM */

SECTIONS
{
  /* vector table must sit at the very start of flash */
  .isr_vector : {
    . = ALIGN(4);
    KEEP(*(.isr_vector))
    . = ALIGN(4);
  } > FLASH

  .text : {
    . = ALIGN(4);
    *(.text*)
    *(.rodata*)
    . = ALIGN(4);
  } > FLASH

  /* initialised data lives in flash and is copied into RAM by reset_handler */
  _sidata = LOADADDR(.data);
  .data : {
    . = ALIGN(4);
    _sdata = .;
    *(.data*)
    . = ALIGN(4);
    _edata = .;
  } > RAM AT > FLASH

  .bss : {
    . = ALIGN(4);
    _sbss = .;
    *(.bss*)
    *(COMMON)
    . = ALIGN(4);
    _ebss = .;
  } > RAM

  /* no C++ exceptions or unwinding on this target */
  /DISCARD/ : {
    *(.ARM.exidx*)
    *(.ARM.extab*)
  }
}
