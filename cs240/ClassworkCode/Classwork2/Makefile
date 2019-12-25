P=hello
CFLAGS = -g -Wall

all: $(P)

$(P): $(P).o
	g++ $(CFLAGS) $(P).o -o $(P)

$(P).o: $(P).cpp
	g++ $(CFLAGS) -c $(P).cpp -o $(P).o
clean:
	rm $(P).o $(P)
run: all
	./$(P)
