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
# Simple makefile for the cortex-M0+ build system
#
# Use: make [TARGET] [OVERRIDES]
#
# Build Targets:
#      <FILE>.o - Builds <FILE>.o object file
#      build - Builds and links all source files
#      all - Same as build
#      clean - removes all generated files
#
# Overrides:
#      CPU - ARM Cortex Architecture (cortex-m0plus, cortex-m4)
#      ARCH - ARM Architecture (arm, thumb)
#      SPECS - Specs file to give the linker (nosys.specs, nano.specs)
#
#
#------------------------------------------------------------------------------
include sources.mk


TARGET := test
OBJECTS := main.o my_file.o my_memory.o

# This is a comment line
CC := gcc
CFLAGS := -c

OBJS = $(SOURCES:.c=.o)

%.o : %.c
	$(CC) -c $< -o $@

# CFLAGS will be the options passed to the compiler.
all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) -o $(TARGET) main.o my_file.o my_memory.o

main.o: main.c
	$(CC) -c main.c $(INCLUDES)

my_file.o: my_file.c
	$(CC) -c my_file.c $(INCLUDES)

my_memory.o: my_memory.c
	$(CC) -c my_memory.c $(INCLUDES)

.PHONY: clean
clean:
	rm -f $(OBJS) $(TARGET).out #$(TARGET).map

