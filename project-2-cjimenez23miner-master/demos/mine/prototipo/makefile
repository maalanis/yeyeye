
CC=msp430-gcc
CFLAGS=-Os -Wall -g -mmcu=msp430g2231

OBJS=proto.o


main.elf: $(OBJS)
	$(CC) $(CFLAGS) -o main.elf $(OBJS)

proto.o: proto.c proto.h
	$(CC) $(CFLAGS) -c $<

clean:
	rm -fr main.elf $(OBJS)

download: main.elf
	mspdebug rf2500 "prog main.elf"