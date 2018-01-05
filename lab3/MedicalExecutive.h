//Author: Chris Watkins
//Assignment: EECS268 lab3
//Description: MedicalExecutive class declaration
//Date: 1/25/17
#ifndef MEEDICAL_EXECUTIVE_H
#define MEEDICAL_EXECUTIVE_H
#include"City.h"
#include<string>
using namespace std;

class MedicalExecutive
{
private:
  LinkedList<City> cityList;
  LinkedList<City> quarantineList;
public:
  MedicalExecutive(string fileName);
  //@pre none
  //@post creates a MedicalExecutive class with a passed in fileName
  ~MedicalExecutive();
  //@pre none
  //@post deconstructs lists inside MedicalExecutive object
  void run();
  //@pre none
  //@post executes the functions and handles user interaction
  void printMenu();
  //@pre none
  //@post prints menu
  void addCityToList(City c);
  //@pre none
  //@post adds passed in city object to the cityList LinkedList
  void addCityToQList(City c);
  //@pre none
  //@post adds passed in city object to the quarantineList LinkedList
  void upIFNlevel(string cityName);
  //@pre none
  //@post increases IFN level of city associated with passed in string name
  void upIFNlevelALL();
  //@pre none
  //@post increases IFN level of all cities
  void requiredActions();
  //@pre linked lists must be created already
  //@post prefomrs operations on lists according to the cities' IFN level
  void removeCityFromList(City c);
  //@pre none
  //@post removes city from cityList LinkedList
  void printCity(string cityName);
  //@pre none
  //@post prints info for a city (name, population, IFN level)
  

};

#include"MedicalExecutive.hpp"
#endif
