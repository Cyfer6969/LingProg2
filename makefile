
CC = g++
LD = g++

CFLAGS = -Wall
LFLAGS = -Wall

LINGPROGOBJS = filedir.o files.o main.o

EXECS = trab2


.c.o:
	$(CC)	$(CFLAGS) -c $<

all: $(EXECS)


trab2: $(LINGPROGOBJS)
	$(LD) $(LFLAGS) -o $@ $(LINGPROGOBJS)