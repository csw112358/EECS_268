//Author: Chris Watkins
//Assignment: EECS268 lab4
//Description: main.cpp where I take in the input file and turn contorl to filemanager's run function.
//Date: 2/15/17
#include "LinkedList.h"
#include "Node.h"
#include "SpaceShip.h"
#include "StarWarsShip.h"
#include "StarTrekShip.h"
#include "FightManager.h"
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char** argv)
{
  string fileName;
  if(argc<2)
  {
    cout<<"Incorrect number of parameters.\n";
  }
  else
  {
    fileName = argv[1];
  }

  FightManager fm = FightManager(fileName);
  fm.run();
  fm.~FightManager();


  return(0);
}
