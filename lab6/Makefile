lab6: main.o MazeReader.o MazeWalker.o Exception.o
		g++ -g -std=c++11 -Wall main.o MazeReader.o MazeWalker.o Exception.o -o lab6

main.o: main.cpp MazeReader.h Exception.h MazeWalker.h
		g++ -g -std=c++11 -Wall -c main.cpp

MazeReader.o: MazeReader.h MazeReader.cpp
		g++ -std=c++11 -g -Wall -c MazeReader.cpp

MazeWalker.o: MazeWalker.h MazeWalker.cpp
		g++ -std=c++11 -g -Wall -c MazeWalker.cpp

Exception.o: Exception.h Exception.cpp
		g++ -std=c++11 -g -Wall -c Exception.cpp

clean:
		rm *.o lab6
