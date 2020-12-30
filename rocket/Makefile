MCU = atmega328p
F_CPU = 16000000
CC = avr-gcc
CXX = avr-g++
OBJDUMP = avr-objdump
OBJCOPY = avr-objcopy
CFLAGS = -std=gnu99 -Wall -g -Os -mmcu=${MCU} -DF_CPU=${F_CPU}
CXXFLAGS = -Wall -g -Os -mmcu=${MCU} -DF_CPU=${F_CPU}
ARDUINO_DIR = /usr/share/arduino/
TARGET = main
PROGRAMMER = arduino
PORT = /dev/ttyUSB0

SOURCES_DIR = src/
INCLUDE_DIRS = /usr/lib/avr/include include
BUILD_DIR = build/

ifdef ARDUINO_DIR
	INCLUDE_DIRS += ${ARDUINO_DIR}hardware/arduino/cores/arduino
	ifeq ($(MCU), atmega8)
		INCLUDE_DIRS += ${ARDUINO_DIR}hardware/arduino/variants/standard
	else ifeq ($(MCU), atmega128)
		INCLUDE_DIRS += ${ARDUINO_DIR}hardware/arduino/variants/eightanaloginputs
	else ifeq ($(MCU), atmega328)
		INCLUDE_DIRS += ${ARDUINO_DIR}hardware/arduino/variants/eightanaloginputs
	else ifeq ($(MCU), atmega328p)
		INCLUDE_DIRS += ${ARDUINO_DIR}hardware/arduino/variants/eightanaloginputs
	else ifeq ($(MCU), atmega2560)
		INCLUDE_DIRS += ${ARDUINO_DIR}hardware/arduino/variants/mega
	else ifeq ($(MCU), atmega1280)
		INCLUDE_DIRS += ${ARDUINO_DIR}hardware/arduino/variants/mega
	else ifeq ($(MCU), atmega32u4)
		INCLUDE_DIRS += ${ARDUINO_DIR}hardware/arduino/variants/leonardo
	else

	endif
else

endif


SOURCES = Main.cpp $(wildcard **/*.cpp) $(wildcard **/*.c)
INCLUDES += $(foreach d, ${INCLUDE_DIRS}, -I$d)
OBJECTS = $(patsubst %.c, %.o, $(SOURCES)) $(patsubst %.cpp, %.o, $(SOURCES))


all: $(OBJECTS)
	@echo Header dirs: ${INCLUDE_DIRS}
	@echo Source files: ${SOURCES}
	mkdir -p ${BUILD_DIR}
	${CXX} ${CXXFLAGS} -o ${BUILD_DIR}${TARGET}.elf $(shell find ${BUILD_DIR}objects/ -name '*.o')
	${OBJDUMP} -h -S ${BUILD_DIR}${TARGET}.elf > ${BUILD_DIR}${TARGET}.lst
	${OBJCOPY} -j .text -j .data -O ihex ${BUILD_DIR}${TARGET}.elf ${BUILD_DIR}${TARGET}.hex

%.o: %.c
	mkdir -p ${BUILD_DIR}objects/$(@D)
	${CC} ${CFLAGS} -c $<  $(INCLUDES) -o ${BUILD_DIR}objects/$@

%.o: %.cpp
	mkdir -p ${BUILD_DIR}objects/$(@D)
	${CXX} ${CXXFLAGS} -c $<  $(INCLUDES) -o ${BUILD_DIR}objects/$@

flash:
	avrdude -p ${MCU} -c ${PROGRAMMER} -U flash:w:${BUILD_DIR}${TARGET}.hex:i -F -P ${PORT}

size:
	avr-size -C ${BUILD_DIR}${TARGET}.bin

clean:
	rm -rf ${BUILD_DIR}
	rm -f *.i *.o *.s
