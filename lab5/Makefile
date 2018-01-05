lab5: main.o Theater.o PreconditionViolationException.o
		g++ -g -std=c++11 -Wall main.o Theater.o PreconditionViolationException.o -o lab5

main.o: main.cpp Stack.h StackInterface.h QueueInterface.h Queue.h  LinkedList.h Node.h Node.hpp PreconditionViolationException.h Theater.h
		g++ -g -std=c++11 -Wall -c main.cpp

Theater.o: Theater.h Theater.cpp
		g++ -std=c++11 -g -Wall -c Theater.cpp

PreconditionViolationException.o: PreconditionViolationException.h PreconditionViolationException.cpp
		g++ -std=c++11 -g -Wall -c PreconditionViolationException.cpp

clean:
		rm *.o lab5
 
