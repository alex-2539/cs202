all: slot

slot: string.h machine.h main.cpp string.o machine.o
	g++ -o slot main.cpp string.o machine.o

string.o: string.h string.cpp
	g++ -c string.cpp

machine.o: machine.h machine.cpp
	g++ -c machine.cpp

clean:
	rm-rf *.o slot

