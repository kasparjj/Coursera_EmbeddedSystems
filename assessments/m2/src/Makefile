#******************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material. 
#
#*****************************************************************************

#------------------------------------------------------------------------------
# Makefile for multitarget platforms
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#     	<FILE>.o - Builds <FILE>.o object file
#		build - Builds and links all source files
#		all - Same as build
#		clean - Removes all generated files
#
# Platform Overrides:
# 		PLATFORM - Platform (HOST, MSP432)
#
#------------------------------------------------------------------------------
include sources.mk

# Platform Overrides
ifeq ($(PLATFORM),HOST)

	# Compiler Flags and Defines
	CC = gcc
	LD = ld
	LDFLAGS = -Wl,-Map=$(TARGET).map
	OBJDUMP = objdump

	SIZE = size

else

	# Platform Specific Flags
	LINKER_FILE = ../msp432p401r.lds

	# Architectures Specific Flags
    CPU = cortex-m4
	ARCH = thumb
	SPECS = nosys.specs

	# Compiler Flags and Defines
    CC = arm-none-eabi-gcc
    LD = arm-none-eabi-ld
    CFLAGS = -mcpu=$(CPU) -m$(ARCH) --specs=$(SPECS) -march=armv7e-m -mfloat-abi=hard -mfpu=fpv4-sp-d16
    LDFLAGS = -Wl,-Map=$(TARGET).map -T $(LINKER_FILE)
    OBJDUMP = arm-none-eabi-objdump

    SIZE = arm-none-eabi-size

endif

TARGET = c1m2

# Compiler Flags and Defines
CFLAGS += -Wall -Werror -g -O0 -std=c99 -D$(PLATFORM) 

OBJS = $(SOURCES:.c=.o)
PREP = $(SOURCES:.c=.i)
ASMS = $(SOURCES:.c=.asm)
DEPS = $(SOURCES:.c=.d)

# Generating files within each compilation stage
%.o : %.c
	$(CC) -c $(CFLAGS) $< $(INCLUDES) -o $@

%.i : %.c
	$(CC) -E $(CFLAGS) $< $(INCLUDES) -o $@

%.asm : %.c
	$(CC) -S $(CFLAGS) $< $(INCLUDES) -o $@

%.d : %.c
	$(CC) -M $(CFLAGS) $< $(INCLUDES) -o $@

$(TARGET).asm : $(TARGET).out
	$(OBJDUMP) -d $(TARGET).out >> $@

# PHONY commands
.PHONY : compile-all
compile-all : $(OBJS)
	$(CC) $(INCLUDES) $(OBJS) -c $(CFLAGS) -o $(TARGET).o

.PHONY : build
build: $(TARGET).out $(TARGET).asm
	
$(TARGET).out : $(OBJS) $(DEPS)
	$(CC) $(CFLAGS) $(LDFLAGS) $(INCLUDES) -o $@ $(OBJS)
	$(SIZE) -Atd $(TARGET).out
	$(SIZE) $(TARGET).out

.PHONY : clean
clean :
	rm -f $(TARGET).out $(TARGET).map *.o *.i *.asm *.d