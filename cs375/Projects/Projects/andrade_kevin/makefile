exec = BestFirstSearch
all: main.o Item.o Node.o BestFirstTreeSearch.o
	g++ -std=c++14 -g -Wall main.o Item.o Node.o BestFirstTreeSearch.o -o $(exec)

main.o: main.cpp
	g++ -std=c++14 -g -Wall -c main.cpp

Item.o: Item.h Item.cpp
	g++ -std=c++14 -g -Wall -c Item.cpp

Node.o: Node.h Node.cpp
	g++ -std=c++14 -g -Wall -c Node.cpp

BestFirstSearch.o: BestFirstTreeSearch.h BestFirstTreeSearch.cpp
	g++ -std=c++14 -g -Wall -c BestFirstTreeSearch.cpp

clean:
	rm -rf *.o *~ BestFirstSearch
