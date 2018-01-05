//Author: Chris Watkins
//Assignment: EECS268 lab3
//Description: Definitions of my City methods
//Date: 2/5/17

#include<iostream>
#include<string>
using namespace std;

City::City()
{

}

City::City(string nm, int pop, int level)
{
  name = nm;
  population = pop;
  IFNlevel = level;
}

City::~City()
{

}

void City::setPop(int pop)
{
  population = pop;
}

string City::getName()
{
  return(name);
}
int City::getPop()
{
  return(population);
}
int City::getIFNlevel()
{
  return(IFNlevel);
}
void City::setIFNlevel(int level)
{
  IFNlevel = level;
}

void City::incIFNlevel()
{

  IFNlevel = (IFNlevel + 1);

}

void City::decPop(int factor)
{
  if(factor==10)
  {
    population = (((population)*9)/10);
  }
  else if(factor==20)
  {
    population = (((population)*8)/10);
  }
  else if(factor==25)
  {
    population = (((population)*75)/100);
  }
}
