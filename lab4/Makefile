lab4: main.o StarWarsShip.o StarTrekShip.o FightManager.o
		g++ -g -std=c++11 -Wall main.o StarWarsShip.o StarTrekShip.o FightManager.o -o lab4

main.o: main.cpp LinkedList.h LinkedList.hpp Node.h Node.hpp SpaceShip.h StarWarsShip.h StarTrekShip.h FightManager.h
		g++ -g -std=c++11 -Wall -c main.cpp

StarWarsShip.o: StarWarsShip.h StarWarsShip.cpp
		g++ -std=c++11 -g -Wall -c StarWarsShip.cpp

StarTrekShip.o: StarTrekShip.h StarTrekShip.cpp
		g++ -std=c++11 -g -Wall -c StarTrekShip.cpp

FightManager.o: FightManager.h FightManager.cpp
		g++ -std=c++11 -g -Wall -c FightManager.cpp
clean:
		rm *.o lab4
