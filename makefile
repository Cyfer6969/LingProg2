
CC = g++
LD = g++

CFLAGS = -Wall $(shell perl -MExtUtils::Embed -e ccopts) -DDEBUGMODE
<<<<<<< HEAD
LFLAGS = -Wall -L/./ $(shell perl -MExtUtils::Embed -e ldopts)
=======
LFLAGS = -Wall -L/usr/lib/i386-linux-gnu $(shell perl -MExtUtils::Embed -e ldopts)
>>>>>>> 89c8453233ea3dcd0eb8d0d72390d2fab618890c

LINGPROGOBJS = main.o filedir.o files.o  PerlInterpreter.o

EXECS = trab2


.c.o:
	$(CC) $(CFLAGS) -c $<

all: $(EXECS)


trab2: $(LINGPROGOBJS)
	$(LD) -o $@ $(LINGPROGOBJS) $(LFLAGS)

clean:
<<<<<<< HEAD
	rm -f *.o $(LINGPROGOBJS)
=======
	rm -f *.o $(LINGPROGOBJS)
>>>>>>> 89c8453233ea3dcd0eb8d0d72390d2fab618890c
