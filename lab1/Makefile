Pokedex: main.o Pokemon.o Executive.o
	g++ -std=c++11 -g -Wall main.o Pokemon.o Executive.o -o Pokedex

main.o: main.cpp Executive.h
	g++ -std=c++11 -g -Wall -c main.cpp

Executive.o: Executive.h Executive.cpp Pokemon.h
	g++ -std=c++11 -g -Wall -c Executive.cpp

Pokemon.o: Pokemon.cpp Pokemon.h
	g++ -g -std=c++11 -c Pokemon.cpp


clean:
	rm *.o Pokedex
