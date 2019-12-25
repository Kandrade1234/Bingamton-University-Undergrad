all: program1 program2 program3

program1: program1.cpp common.h
	g++ program1.cpp -o program1

program2: program2.cpp common.h
	g++ program2.cpp -o program2

program3: program3.cpp common.h
	g++ program3.cpp -o program3

clean:
	rm -rf *.o *~ program1 program2 program3 output*.txt
