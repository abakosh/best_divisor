CC ?= gcc
CFLAGS = -Wall -Wextra -g  

FILES = best_divisor.c

all: $(FILES)
	$(CC) $(CFLAGS) -o best_divisor.exe $(FILES) $(LIBS) 

clean:
	-rm -f *.exe *.o
