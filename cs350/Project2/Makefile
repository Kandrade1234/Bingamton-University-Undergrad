sleep_seconds=3

all: prog2 sne

prog2: prog2.c
	gcc  prog2.c -o $@

sne: sleep_and_echo.c Makefile
	gcc  -DSECS=$(sleep_seconds) sleep_and_echo.c -o $@

clean:
	rm -f prog2 sne
