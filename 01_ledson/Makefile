#
# Makefile for msp430
#
# 'make' builds everything
# 'make clean' deletes everything except source files and Makefile
# You need to set TARGET, MCU and SOURCES for your project.
# TARGET is the name of the executable file to be produced 
# $(TARGET).elf $(TARGET).hex and $(TARGET).txt nad $(TARGET).map are all generated.
# The TXT file is used for BSL loading, the ELF can be used for JTAG use
# 
TARGET     = ledson
MCU        = msp430g2553
# List all the source files here
# eg if you have a source file foo.c then list it here
SOURCES = ledson.c
# Include are located in the Include directory
#INCLUDES = -IInclude
# Add or subtract whatever MSPGCC flags you want. There are plenty more
#######################################################################################
CFLAGS   = -mmcu=$(MCU) -Os
ASFLAGS  = -mmcu=$(MCU) 
LDFLAGS  = -mmcu=$(MCU) 
########################################################################################
CC       = msp430-gcc
LD       = msp430-ld
AR       = msp430-ar
AS       = msp430-gcc
GASP     = msp430-gasp
NM       = msp430-nm
OBJCOPY  = msp430-objcopy
RANLIB   = msp430-ranlib
STRIP    = msp430-strip
SIZE     = msp430-size
READELF  = msp430-readelf
MAKETXT  = srec_cat
CP       = cp -p
RM       = rm -f
MV       = mv
########################################################################################

all: $(TARGET).elf

$(TARGET).elf: $(TARGET).o
	$(CC) $(CFLAGS) $(TARGET).o $(LDFLAGS) -o $(TARGET).elf
	msp430-objdump -z -EL -D -W $(TARGET).elf >$(TARGET).lss
	msp430-size $(TARGET).elf
	msp430-objcopy -O ihex $(TARGET).elf $(TARGET).hex

install: all
	mspdebug --force-reset rf2500 "prog $(TARGET).elf"

cycle_count: all
	naken430util -disasm $(TARGET).hex > $(TARGET)_cc.txt

debug: all
	clear
	@echo -e "--------------------------------------------------------------------------------"
	@echo -e "-- Make sure you are running mspdebug in another window                       --"
	@echo -e "--------------------------------------------------------------------------------"
	@echo -e "$$ # you can start it like this:"
	@echo -e "$$ mspdebug rf2500 gdb\n"
	msp430-gdb --command=$(TARGET).gdb $(TARGET).elf

clean:
	rm -f $(TARGET).o $(TARGET).elf $(TARGET).lss $(TARGET).map $(TARGET).hex $(TARGET)_cc.txt
