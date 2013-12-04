CPU = cortex-a9
CCROOT = /home/s-kovba/work/experiment/gcc-arm-none-eabi-4_7-2013q1
CCPREFIX = $(CCROOT)/bin/arm-none-eabi
CCP_INC = $(CCROOT)/lib/gcc/arm-none-eabi/4.7.3/include
CFLAGS = -mcpu=$(CPU) -Os -g -fno-strict-aliasing -fno-stack-protector -fno-builtin -ffreestanding -nostdinc -pipe -DCONFIG_ARM -D__ARM__ -mno-thumb-interwork -Wall -Wstrict-prototypes -isystem $(CCP_INC)
ASMFLAGS = -D__ARM_ARCH_7A__ -D__ASSEMBLY__
BDIR = ../build
BINDIR = ../bin
INC = -I. -Imemroutines -Iutility
LIBS = -L$(CCROOT)/lib/gcc/arm-none-eabi/4.7.3 -lgcc

OBJ_CORE = $(BDIR)/init.o $(BDIR)/startup.o $(BDIR)/kprint.o
OBJ_UTILITIES = $(BDIR)/vsprintf.o $(BDIR)/abort.o
OBJ_MEMROUTINES = $(BDIR)/memcmp.o $(BDIR)/memcpy.o $(BDIR)/memset.o $(BDIR)/strcmp.o $(BDIR)/strcpy.o


all: dir memroute core utilities
	$(CCPREFIX)-ld -T linker.ld -g $(OBJ_CORE) $(OBJ_UTILITIES) $(OBJ_MEMROUTINES) $(LIBS) -o $(BDIR)/qernel.elf
	$(CCPREFIX)-objcopy -O binary $(BDIR)/qernel.elf $(BDIR)/qernel.img
	cp $(BDIR)/qernel.elf $(BINDIR)/
	cp $(BDIR)/qernel.img $(BINDIR)/

core:
	$(CCPREFIX)-gcc $(INC) -c $(CFLAGS) $(ASMFLAGS) startup.S -o $(BDIR)/startup.o
	$(CCPREFIX)-gcc $(INC) -c $(CFLAGS) init.c -o $(BDIR)/init.o
	$(CCPREFIX)-gcc $(INC) -c $(CFLAGS) kprint.c -o $(BDIR)/kprint.o

utilities:
	$(CCPREFIX)-gcc $(INC) -c $(CFLAGS) utility/vsprintf.c -o $(BDIR)/vsprintf.o
	$(CCPREFIX)-gcc $(INC) -c $(CFLAGS) utility/abort.c -o $(BDIR)/abort.o

memroute:
	$(CCPREFIX)-gcc $(INC) -c $(CFLAGS) $(ASMFLAGS) memroutines/memcmp.S -o $(BDIR)/memcmp.o
	$(CCPREFIX)-gcc $(INC) -c $(CFLAGS) $(ASMFLAGS) memroutines/memcpy.S -o $(BDIR)/memcpy.o
	$(CCPREFIX)-gcc $(INC) -c $(CFLAGS) $(ASMFLAGS) memroutines/memset.S -o $(BDIR)/memset.o
	$(CCPREFIX)-gcc $(INC) -c $(CFLAGS) $(ASMFLAGS) memroutines/strcmp.S -o $(BDIR)/strcmp.o
	$(CCPREFIX)-gcc $(INC) -c $(CFLAGS) $(ASMFLAGS) memroutines/strcpy.S -o $(BDIR)/strcpy.o

dir:
	mkdir -p $(BDIR)
	mkdir -p $(BINDIR)

clean:
	rm -Rf $(BDIR)
	rm -Rf $(BINDIR)