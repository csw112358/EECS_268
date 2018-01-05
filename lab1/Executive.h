//Author: Chris Watkins
//Assignment: EECS268 lab1
//Description: Poxedex program
//Date: 1/25/17
#ifndef EXECUTIVE_H
#define EXECUTIVE_H
#include"Pokemon.h"
#include<string>
#include<fstream>
#include<iostream>

using namespace std;

class Executive
{
private:
   string fileName;
   int count;
   Pokemon** pokemonArray;

public:
  Executive(string fileName);
  ~Executive();
  void run();
  void printMenu();
  void printPokeData(int ID);
  void writeJapToFile(string fileName);


};
#endif
