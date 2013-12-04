ENTRY(_Reset)
SECTIONS
{
 . = 0x10000;
 .startup . : { ../build/startup.o(.text) }
 .text : { *(.text) }
 .data : { *(.data) }
 .bss : { *(.bss COMMON) }
 . = ALIGN(8);
 __exidx_start = .;
 .ARM.exidx   : { *(.ARM.exidx* .gnu.linkonce.armexidx.*) }
 __exidx_end = .;
 . = . + 0x2000; /* 4kB of stack memory */
 stack_top = .;
}
