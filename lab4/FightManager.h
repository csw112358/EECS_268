//Author: Chris Watkins
//Assignment: EECS268 lab4
//Description: Declaration of all my FightManager class
//Date: 2/18/17

#ifndef FIGHT_MANAGER
#define FIGHT_MANAGER

#include "SpaceShip.h"
#include"StarWarsShip.h"
#include"StarTrekShip.h"
#include"LinkedList.h"
#include "Node.h"
#include<iostream>
using namespace std;

class FightManager
{
private:
  LinkedList<SpaceShip*> SpaceShipList;

public:
  FightManager(string fileName);
  // @pre none.
  // @post constructs FightManager object
  // @return none
  ~FightManager();
  // @pre none.
  // @post deconstructs FightManager objec
  // @return none
  void run();
  // @pre FightManager object created.
  // @post runs methods to fight starships
  // @return none.

};
#endif
