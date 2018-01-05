lab8: main.o Pokemon.o ValueNotFoundException.o
		g++ -g -std=c++11 -Wall main.o Pokemon.o ValueNotFoundException.o -o lab8

main.o: main.cpp BSTI.h BST.h BST.hpp Node.h Node.hpp Pokemon.h ValueNotFoundException.h
		g++ -g -std=c++11 -Wall -c main.cpp

Pokemon.o: Pokemon.h Pokemon.cpp
		g++ -std=c++11 -g -Wall -c Pokemon.cpp

ValueNotFoundException.o: ValueNotFoundException.h ValueNotFoundException.cpp
		g++ -std=c++11 -g -Wall -c ValueNotFoundException.cpp

clean:
		rm *.o lab8
