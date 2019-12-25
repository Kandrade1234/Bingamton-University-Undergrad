P=lab5
Q=BSTree
CFLAGS = -g -Wall

all: $(P)

$(P): $(P).o $(Q).o
	g++ -std=c++11 $(CFLAGS) $(P).o $(Q).o -o $(P)

$(P).o: $(P).cpp
	g++ -std=c++11 $(CFLAGS) -c $(P).cpp -o $(P).o

$(Q).o: $(Q).cpp $(Q).h
	g++ -std=c++11 $(CFLAGS) -c $(Q).cpp -o $(Q).o

checkmem:all
	valgrind ./$(P)


clean:
	rm $(P).o $(P)
	rm $(Q).o
run: all
	./$(P)
