# makefile
COMMON_OBJECTS =
CPU		= MSP430G2553
CFLAGS		= -mmcu=${CPU} -Os -I../h
LDFLAGS		= -L../lib -L/opt/ti/msp430_gcc/include

CC		= msp430-elf-gcc
AS		= msp430-elf-as -mmcu=${CPU} -c
AR		= msp430-elf-ar

all: states.elf

states.elf: ${COMMON_OBJECTS} wdt_handler.o stateMachine.o assembly.o switches.o led.o buzzer.o triforce.o p2_interrupt_handler.o main.o ../lib/libTimer.a
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^ -lLcd -lp2sw -lTimer

load: states.elf
	msp430loader.sh states.elf

clean:
	rm -f *.o *.elf *~
