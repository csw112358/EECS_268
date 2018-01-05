//Author: Chris Watkins
//Assignment: EECS268 lab3
//Description: City class declaration
//Date: 1/25/17
#ifndef CITY_H
#define CITY_H
#include<string>
#include"LinkedList.h"
#include"Node.h"
using namespace std;

class City
{
private:
  string name;
  int population;
  int IFNlevel;
public:
  City(string nm, int pop, int level);
  //@pre none
  //@post creates city object with variables passed in
  City();
  //@pre none
  //@post creates city object (default city object constructor)
  ~City();
  //@pre none
  //@post deletes city object
  string getName();
  //@pre none
  //@post returns name of city
  int getPop();
  //@pre none
  //@post returns popultion of city
  int getIFNlevel();
  //@pre none
  //@post returns IFN level of city
  void setIFNlevel(int level);
  //@pre none
  //@post sets IFN level of city to passed in value
  void incIFNlevel();
  //@pre none
  //@post increases IFN level of city by 1
  void decPop(int factor);
  //@pre none
  //@post decreases the popultion of a city by the factor passed in
  void setPop(int pop);
  //@pre none
  //@post sets population value for city to passed in integer

};

#include"City.hpp"
#endif
