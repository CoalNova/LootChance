CC=clang++
CFLAGS=-I.
DEPS = lootoutput.h lootinput.h lootproc.h

%.o: %.c $(DEPS)
	$(CC) -c -o -O3 -Wall $@ $< $(CFLAGS)

lootchance: loot.o lootoutput.o lootinput.o lootproc.o
	$(CC) -o loot loot.o lootoutput.o lootinput.o lootproc.o