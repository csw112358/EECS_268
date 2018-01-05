lab7: main.o SortTimer.o
		g++ -g -std=c++11 -Wall main.o SortTimer.o -o lab7

main.o: main.cpp Sorts.h Sorts.hpp SortTimer.h
		g++ -g -std=c++11 -Wall -c main.cpp

SortTimer.o: SortTimer.h SortTimer.cpp
		g++ -g -std=c++11 -Wall -c SortTimer.cpp

clean:
		rm *.o lab7
