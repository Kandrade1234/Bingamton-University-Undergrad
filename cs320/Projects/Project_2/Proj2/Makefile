P=cache-sim
CFLAGS = -Wall -std=c++11

all: $(P)

$(P): $(P).o
	g++ $(CFLAGS) $(P).o  -o $(P)

$(P).o: $(P).cpp
	g++ $(CFLAGS) -c $(P).cpp -o $(P).o


checkmem:all
	valgrind ./$(P)


clean:
	rm $(P).o $(P)

run: all
	./$(P)
