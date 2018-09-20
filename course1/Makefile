#******************************************************************************
# Copyright (C) 2018 by Kaspar Jürgensen
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software.
#
#*****************************************************************************

#------------------------------------------------------------------------------
# Makefile for running program on multitarget platforms
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#     	<FILE>.o - Builds <FILE>.o object file
#		build - Builds and links all source files
#		compile-all - Generate object files
#		clean - Removes all generated files
#
# Platform Overrides:
# 		PLATFORM = HOST
#		PLATFORM = MSP432
#------------------------------------------------------------------------------
include sources.mk

# Platform Overrides
PLATFORM ?= HOST

TARGET = c1m2

# Compiler Flags and Defines
CC := gcc 
LD := ld
CFLAGS := -Wall -Werror -g -O0 -std=c99 
LDFLAGS := -Wl,-Map=$(TARGET).map
OBJDUMP := objdump
CPPFLAGS := $(INCLUDES) -D$(PLATFORM)
SIZE := size

# MSP432 platform
ifeq ($(PLATFORM),MSP432)

	# Architectures Specific Flags
	LINKER_FILE := ./msp432p401r.lds
    CPU := cortex-m4
	ARCH := thumb
	ARM_FLAGS := -march=armv7e-m -mfloat-abi=hard -mfpu=fpv4-sp-d16
	SPECS := nosys.specs

	# Compiler Flags and Defines
    CC := arm-none-eabi-gcc
    LD := arm-none-eabi-ld
    CFLAGS += -mcpu=$(CPU) -m$(ARCH) $(ARCH_FLAGS) --specs=$(SPECS)
    LDFLAGS += -T $(LINKER_FILE) $(PLATFORM_FLAGS) 
    OBJDUMP := arm-none-eabi-objdump
    SIZE := arm-none-eabi-size

endif

# Generating files within each compilation stage
PREP := $(SOURCES:.c=.i)
%.i : %.c
	$(CC) $(CPPFLAGS) -E $< $(CFLAGS) -o $@

ASMS := $(SOURCES:.c=.asm)
%.asm : %.c
	$(CC) $(CPPFLAGS) -S $< $(CFLAGS) -o $@

OBJS := $(SOURCES:.c=.o)
%.o : %.c
	$(CC) $(CPPFLAGS) -c $< $(CFLAGS) -o $@

DEPS := $(SOURCES:.c=.d)
%.d : %.c
	$(CC) $(CPPFLAGS) -M $< $(CFLAGS) -o $@

$(TARGET).asm: $(TARGET).out
	$(OBJDUMP) -d $(TARGET).out >> $@

# PHONY commands
.PHONY : build
build: $(TARGET).out  objdump size

$(TARGET).out : $(OBJS) $(PREP) $(ASMS) $(DEPS) 
	$(CC) $(CPPFLAGS) $(OBJS) $(CFLAGS) $(LDFLAGS) -o $@

objdump: $(TARGET).out
	$(OBJDUMP) -S $(TARGET).out > $(TARGET).asm

.PHONY : size
size: $(TARGET).out
	$(SIZE) -Ad $(TARGET).out

.PHONY : compile-all
compile-all : $(OBJS)
	$(CC) $(CPPFLAGS) $(OBJS) $(CFLAGS) -o $@

.PHONY : clean
clean :
	rm -f   $(PREP) $(ASMS) $(OBJS) $(DEPS) $(TARGET) \
	      $(TARGET).out $(TARGET).map $(TARGET).asm
