
CC = g++
LD = g++

CFLAGS = -Wall $(shell perl -MExtUtils::Embed -e ccopts) -DDEBUGMODE
LFLAGS = -Wall -L/usr/lib/i386-linux-gnu $(shell perl -MExtUtils::Embed -e ldopts)

LINGPROGOBJS = main.o filedir.o files.o  PerlInterpreter.o

EXECS = trab2


.c.o:
	$(CC) $(CFLAGS) -c $<

all: $(EXECS)


trab2: $(LINGPROGOBJS)
	$(LD) -o $@ $(LINGPROGOBJS) $(LFLAGS)

clean:
	rm -f *.o $(LINGPROGOBJS)