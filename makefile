
CC = g++
LD = g++

CFLAGS = -Wall $(shell perl -MExtUtils::Embed -e ccopts)
LFLAGS = -Wall $(shell perl -MExtUtils::Embed -e ldopts)

LINGPROGOBJS = main.o filedir.o files.o  Aperl.o

EXECS = trab2


.c.o:
	$(CC) $(CFLAGS) -c $<

all: $(EXECS)


trab2: $(LINGPROGOBJS)
#	$(LD) $(LFLAGS) -o $@ $(LINGPROGOBJS) 
	$(LD) -o $@ $(LINGPROGOBJS) $(LFLAGS)

clean:
	rm -f *.o $(LINGPROGOBJS)